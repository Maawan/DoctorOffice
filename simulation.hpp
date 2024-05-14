#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "simulation.h"

// Constructor implementation
simulation::simulation(int sim_time, int num_doctors, int appointment_time, int time_between_arrival){
    this->sim_time = sim_time;
    this->num_doctors = num_doctors;
    this->appointment_time = appointment_time;
    this->time_between_arrival = time_between_arrival;
    this->patients_arrived = 0;
    this->total_wait_time = 0;
    this->office = doctors_office(this->num_doctors);
}

// Destructor implementation
simulation::~simulation() {
    
}

// Run the simulation 
void simulation::run_simulation() {
    for (int time = 0; time < sim_time; time++) {
        office.update_doctors(time); // Update the office, whether any patient's appointment is completed or not
        /*
            We cannot iterate in the queue, so a tempQueue is created 
            One by one patients are removed from waiting queue and transfered to temp_queue
            By transfering, also increasing the waiting time
            Once waiting queue is empty then again populating by from tempQueue so order
            of patients is not disturbed
        */
        if (!waiting_queue.empty()) {
            LQueue<patient> temp_queue; // Create a temporary queue to iterate over
            while(!waiting_queue.empty()){
                patient p = waiting_queue.dequeue();
                p.increment_waiting_time();
                temp_queue.enqueue(p);
            }
            while(!temp_queue.empty()){
                waiting_queue.enqueue(temp_queue.dequeue());
            }
        }
        /*
            If any patient has arrived, then displaying to screen and adding it to the 
            waitingQueue
        */
        if (has_patient_arrived(time_between_arrival)) {
            int patient_number = patients_arrived++;
            display_patient_arrived(patient_number, time);
            patient temp =  patient(patient_number, time, 0, appointment_time);
            waiting_queue.enqueue(temp); 
        }
        /*
            If any doctor is free and there are some patient in the waitingQueue
            Remove the patient from queue and assign it to the free doctor and display 
            it on screen
            On assigning the doctor to a patient, increase total_waiting_time from
            patient's waiting time
        */
        int free_doctor_number = office.get_free_doctor_ID();
        if (free_doctor_number != -1 && !waiting_queue.empty()) {
            patient next_patient = waiting_queue.dequeue();
             // Dequeue the patient
            total_wait_time += next_patient.get_waiting_time();
            office.set_doctor_busy(free_doctor_number, next_patient, appointment_time);
            display_patient_seen(free_doctor_number, next_patient.get_patient_number(), time);
        }
        
    }
}

// Return a reference to the doctor's office
doctors_office& simulation::get_office() {
    return office;
}

// Return a reference to the patient queue 
LQueue<patient>& simulation::get_patient_queue() {
    return waiting_queue;
}

// Return the total time patients spent waiting 
int simulation::get_total_wait_time() {
    return total_wait_time;
}

// Return the number of patients that arrived 
int simulation::get_num_patients_arrived() {
    return patients_arrived;
}

#endif
