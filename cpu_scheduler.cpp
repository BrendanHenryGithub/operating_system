#include <iostream>
#include "os_struct.h"

using namespace std;

void time_slice_cycle();

vector<Process> ready;
vector<Process> suspend;


int main(){
    time_slice_cycle();
    return 0;
}

void time_slice_cycle(){
    cout << "The order of time slice cycle is: " ;
    for (vector<Process>::iterator iter=ready.begin();iter!=ready.end();++iter){
        cout << ""
    }
}