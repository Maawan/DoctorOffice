#ifndef DOCTORS_OFFICE_HPP
#define DOCTORS_OFFICE_HPP

#include "doctors_office.h"

// Constructor implementation
doctors_office::doctors_office(int num_docs) {
    num_doctors = num_docs;
    doctors.resize(num_docs);
}


// Search free doctor and returning its index (Doctor ID)
int doctors_office::get_free_doctor_ID() const {
    for (long unsigned int i = 0; i < doctors.size(); ++i) {
        if (doctors[i].is_free()) {
            return i; // doctor numbers are 0-indexed
        }
    }
    return -1; // No free doctor found
}

// Get the number of doctors that are busy 
int doctors_office::get_number_of_busy_doctors() const {
    int count = 0;
    for (const auto& doctor : doctors) {
        if (!doctor.is_free()) {
            count++;
        }
    }
    return count;
}

// Set a doctor as busy with the specified patient 
void doctors_office::set_doctor_busy(int doc_ID, const patient& pat, int app_time) {
    doctors[doc_ID].set_busy();
    doctors[doc_ID].set_remaining_appointment_time(app_time);
    doctors[doc_ID].set_current_patient(pat);
}

// Set a doctor as busy with the specified patient 
void doctors_office::set_doctor_busy(int doc_ID, const patient& pat) {
    doctors[doc_ID].set_busy();
    doctors[doc_ID].set_remaining_appointment_time();
    doctors[doc_ID].set_current_patient(pat);
}

// Update the status of doctors, checking if they have become free 
void doctors_office::update_doctors(int time) {
    for (auto& doctor : doctors) {
        if (!doctor.is_free()) {
            doctor.decrement_remaining_appointment_time();
            if (doctor.get_remaining_appointment_time() == 0) {
                doctor.set_free();
                display_appointment_done(doctor.get_current_patient_number(), doctor.get_current_patient_number(), time);
            }
        }
    }
}

#endif
