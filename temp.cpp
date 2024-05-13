#include<iostream>
#include "lqueue.h"
#include "patient.h"
#include "doctor.h"
using namespace std;
int main(){
    LQueue<int> queue;
    queue.enqueue(12);
    queue.enqueue(30);
    queue.enqueue(90);
    for(int i = 0 ; i < 3 ; i++){
        cout << queue.dequeue() << " " << endl;
    }

    patient p(786 , 1,2,3);
    doctor d;
    d.set_current_patient(p);

    //cout << p.get_appointment_length() << " " << p.get_arrival_time() << " " << p.get_patient_number() << " " << p.get_waiting_time() << endl;
    cout << d.get_current_patient_appointment_length() << " " << d.is_free() << " " << d.get_remaining_appointment_time() ;
    return 0;
}