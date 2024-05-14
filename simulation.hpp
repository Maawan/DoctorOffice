#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "simulation.h"
#include<iostream>
using namespace std;
// Constructor implementation
simulation::simulation(int sim_time, int num_doctors, int appointment_time, int time_between_arrival){
    this->sim_time = sim_time;
    this->num_doctors = num_doctors;
    this->appointment_time = appointment_time;
    this->time_between_arrival = time_between_arrival;
    this->patients_arrived = 0;
    this->total_wait_time = 0;
}

// Destructor implementation
simulation::~simulation() {}

// Run the simulation implementation
void simulation::run_simulation() {
    for (int time = 0; time < sim_time; time++) {
        office.update_doctors(time);

        if (!waiting_queue.empty()) {
            LQueue<patient> temp_queue = waiting_queue; // Create a temporary queue to iterate over
            
            // std::cout << "Before " << std::endl;
            // while (!temp1.empty()) {
            //     std :: cout <<"Waiting time " << temp1.dequeue().get_waiting_time();
            //     // Increment waiting time of each patient
            // }
            // std::cout<<std::endl;
            // while (!temp_queue.empty()) {
            //     temp_queue.dequeue().increment_waiting_time();
            //     // Increment waiting time of each patient
            // }
            // std::cout<<std::endl;
            // while (!temp2.empty()) {
            //     std :: cout <<"Waiting time " << temp2.dequeue().get_waiting_time();
            //     // Increment waiting time of each patient
            // }
            // std::cout<<std::endl;

        }

        if (has_patient_arrived(time_between_arrival)) {
            int patient_number = patients_arrived++;
            display_patient_arrived(patient_number, time);
            patient temp =  patient(patient_number, time, 0, appointment_time);
           // std::cout << temp.get_patient_number() << "Patient Number" << std:: endl;
            waiting_queue.enqueue(temp); // Enqueue the arrived patient
        }
        //std::cout<<"gaand mar gai";
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

// Return a reference to the doctor's office used in the simulation implementation
doctors_office& simulation::get_office() {
    return office;
}

// Return a reference to the patient queue used in the simulation implementation
LQueue<patient>& simulation::get_patient_queue() {
    return waiting_queue;
}

// Return the total time patients spent waiting during the simulation implementation
int simulation::get_total_wait_time() {
    return total_wait_time;
}

// Return the number of patients that arrived throughout the simulation implementation
int simulation::get_num_patients_arrived() {
    return patients_arrived;
}

#endif
