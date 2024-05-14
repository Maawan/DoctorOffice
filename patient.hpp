#include "patient.h"

// Constructor implementation
patient::patient(int pat_num, int arrive_time, int wait_time, int app_length) {
    this->patient_number = pat_num;
    this->arrival_time = arrive_time;
    this->waiting_time = wait_time;
    this->appointment_length = app_length;
    
}
// Destructor implementation
patient::~patient() {}

// Update patient information 
void patient::set_patient_info(int pat_num, int arrive_time, int wait_time, int app_length) {
    this->patient_number = pat_num;
    this->arrival_time = arrive_time;
    this->waiting_time = wait_time;
    this->appointment_length = app_length;
    
}

// Get waiting time 
int patient::get_waiting_time() const {
    return this->waiting_time;
}

// Set waiting time 
void patient::set_waiting_time(int time) {
    this->waiting_time = time;
}

// Increment waiting time 
void patient::increment_waiting_time() {
    this->waiting_time++;
}

// Get arrival time 
int patient::get_arrival_time() const {
    return this->arrival_time;
}

// Get appointment length 
int patient::get_appointment_length() const {
    return this->appointment_length;
}

// Get patient number implementation
int patient::get_patient_number() const {
    return patient_number;
}
