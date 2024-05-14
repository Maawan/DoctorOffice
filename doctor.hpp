#ifndef DOCTOR_HPP
#define DOCTOR_HPP

#include "doctor.h"

// Constructor Implementation
doctor::doctor(){
    this->is_busy = false;
    this->remaining_appointment_time = 0;
}

// Destructor implementation - No dynamic memory is used in this class
doctor::~doctor() {}

// Check if the doctor is free 
bool doctor::is_free() const {
    return !is_busy;
}

// Set the doctor as busy 
void doctor::set_busy() {
    this->is_busy = true;
}

// Set the doctor as free 
void doctor::set_free() {
    this->is_busy = false;
}

// Set the remaining appointment time according value passed
void doctor::set_remaining_appointment_time(int t) {
    remaining_appointment_time = t;
}

// Set the remaining appointment time according to the patient 
void doctor::set_remaining_appointment_time() {
    remaining_appointment_time = current_patient.get_appointment_length();
}

// Get the remaining time in the current appointment 
int doctor::get_remaining_appointment_time() const {
    return remaining_appointment_time;
}

// Decrement the time remaining in the current appointment by 1 unit 
void doctor::decrement_remaining_appointment_time() {
    if (remaining_appointment_time > 0) {
        remaining_appointment_time--;
    }
}

// Set the current patient to the supplied patient 
void doctor::set_current_patient(const patient& pat) {
    current_patient = pat;
}

// Return the patient number of the current patient 
int doctor::get_current_patient_number() const {
    return current_patient.get_patient_number();
}

// Return the arrival time of the current patient 
int doctor::get_current_patient_arrival_time() const {
    return current_patient.get_arrival_time();
}

// Return the waiting time of the current patient 
int doctor::get_current_patient_waiting_time() const {
    return current_patient.get_waiting_time();
}

// Return the appointment time of the current patient 
int doctor::get_current_patient_appointment_length() const {
    return current_patient.get_appointment_length();
}

#endif
