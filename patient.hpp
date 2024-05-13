#include "patient.h"

// Constructor implementation
patient::patient(int pat_num, int arrive_time, int wait_time, int app_length) {
    patient_number = pat_num;
    arrival_time = arrive_time;
    waiting_time = wait_time;
    appointment_length = app_length;
    
}
// Destructor implementation
patient::~patient() {}

// Update patient information implementation
void patient::set_patient_info(int pat_num, int arrive_time, int wait_time, int app_length) {
    patient_number = pat_num;
    arrival_time = arrive_time;
    waiting_time = wait_time;
    appointment_length = app_length;
    
}

// Get waiting time implementation
int patient::get_waiting_time() const {
    return waiting_time;
}

// Set waiting time implementation
void patient::set_waiting_time(int time) {
    waiting_time = time;
}

// Increment waiting time implementation
void patient::increment_waiting_time() {
    waiting_time++;
}

// Get arrival time implementation
int patient::get_arrival_time() const {
    return arrival_time;
}

// Get appointment length implementation
int patient::get_appointment_length() const {
    return appointment_length;
}

// Get patient number implementation
int patient::get_patient_number() const {
    return patient_number;
}
