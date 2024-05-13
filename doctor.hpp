#ifndef DOCTOR_HPP
#define DOCTOR_HPP

#include "doctor.h"

// Constructor implementation
doctor::doctor(){
    is_busy = false;
    remaining_appointment_time = 0;
}

// Destructor implementation
doctor::~doctor() {}

// Check if the doctor is free implementation
bool doctor::is_free() const {
    return !is_busy;
}

// Set the doctor as busy implementation
void doctor::set_busy() {
    is_busy = true;
}

// Set the doctor as free implementation
void doctor::set_free() {
    is_busy = false;
}

// Set the remaining appointment time according to the parameter implementation
void doctor::set_remaining_appointment_time(int t) {
    remaining_appointment_time = t;
}

// Set the remaining appointment time according to the patient implementation
void doctor::set_remaining_appointment_time() {
    remaining_appointment_time = current_patient.get_appointment_length();
}

// Get the remaining time in the current appointment implementation
int doctor::get_remaining_appointment_time() const {
    return remaining_appointment_time;
}

// Decrement the time remaining in the current appointment by 1 unit implementation
void doctor::decrement_remaining_appointment_time() {
    if (remaining_appointment_time > 0) {
        remaining_appointment_time--;
    }
}

// Set the current patient to the supplied patient implementation
void doctor::set_current_patient(const patient& pat) {
    current_patient = pat;
}

// Return the patient number of the current patient implementation
int doctor::get_current_patient_number() const {
    return current_patient.get_patient_number();
}

// Return the arrival time of the current patient implementation
int doctor::get_current_patient_arrival_time() const {
    return current_patient.get_arrival_time();
}

// Return the waiting time of the current patient implementation
int doctor::get_current_patient_waiting_time() const {
    return current_patient.get_waiting_time();
}

// Return the appointment time of the current patient implementation
int doctor::get_current_patient_appointment_length() const {
    return current_patient.get_appointment_length();
}

#endif
