#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <vector>
#include "os_struct.h"

using namespace std;

void view();
void create();
void list();
void kill();
void setting();
void release();

vector<Process> ready;
vector<Process> suspend;

int main() {
  while (1) {
    view();
  }
  return 0;
}

void view() {
  cout << "*********************************" << endl;
  cout << "******Process System Demo********" << endl;
  cout << "* 1.Create new process" << endl;
  cout << "* 2.List process" << endl;
  cout << "* 3.Delete process" << endl;
  cout << "* 4.release memory" << endl;
  cout << "* 5.System settings" << endl;
  cout << "* 6.Exit" << endl;
  cout << "*********************************" << endl;
  cout << "$ Enter your command: ";
  int i;
  cin >> i;
  switch (i) {
    case 1:
      create();
      break;
    case 2:
      list();
      break;
    case 3:
      kill();
      break;
    case 4:
      release();
      break;
    case 5:
      setting();
      break;
    case 6:
      exit(0);
  }
}

void create() {
  Process tmp;
  cout << "$ Enter the pid of new process: ";
  cin >> tmp.pid;
  cout << "$ Enter the priority of new process (start form 1, priority "
          "decrease progressively): ";
  cin >> tmp.priv;
  if (cpu.status == waiting) {
    cpu.process = tmp;
    cpu.status = working;
  } else {
    ready.push_back(tmp);
  }
}

void list() {
  cout << endl;
  if (cpu.status == waiting) {
    cout << "- cpu status: free " << endl;
  } else {
    cout << "- cpu status: working" << endl;
    cout << "    - pid of running process: " << cpu.process.pid << endl;
    cout << "    - priv of running process: " << cpu.process.priv << endl;
  }
  cout << endl;

  cout << "- number of process in ready queue: " << ready.size() << endl;
  for (vector<Process>::iterator iter = ready.begin(); iter != ready.end();
       ++iter) {
    cout << "   ****************" << endl;
    cout << "   * pid   : " << iter->pid << endl;
    cout << "   * priv  : " << iter->priv << endl;
    cout << "   ****************" << endl;
    cout << endl;
  }

  cout << "- number of process in suspend queue: " << suspend.size() << endl;
  for (vector<Process>::iterator iter = suspend.begin(); iter != suspend.end();
       ++iter) {
    cout << "   ****************" << endl;
    cout << "   * pid   : " << iter->pid << endl;
    cout << "   * priv  : " << iter->priv << endl;
    cout << "   ****************" << endl;
    cout << endl;
  }
}

void kill() {
  cout << endl;
  cout << "- running process: " << cpu.process.pid << endl;
  cout << "- process in the ready queue: ";
  for (vector<Process>::iterator iter = ready.begin(); iter != ready.end();
       ++iter) {
    cout << iter->pid << " ";
  }
  cout << endl;
  cout << "- process in the suspend queue: ";
  for (vector<Process>::iterator iter = suspend.begin(); iter != suspend.end();
       ++iter) {
    cout << iter->pid << " ";
  }
  cout << endl;
  cout << "Chose a pid of the process that you want to delete from above list: ";
  int i = 0;
  cin >> i;
  int flag = 0;
  if (i == cpu.process.pid) {
    cpu.process = ready.front();
    ready.erase(ready.begin());
    flag = 1;
  }
  if (!flag) {
    for (vector<Process>::iterator iter = ready.begin(); iter != ready.end();
         ++iter) {
      if (i == iter->pid) {
        ready.erase(iter);
        flag = 1;
        break;
      }
    }
  }
  if (!flag) {
    for (vector<Process>::iterator iter = suspend.begin();
         iter != suspend.end(); ++iter) {
      if (i == iter->pid) {
        suspend.erase(iter);
        flag = 1;
        break;
      }
    }
  }
  if (flag) {
    cout << "Successfully delete." << endl;
  } else {
    cout << "The pid don't exist!" << endl;
  }
}
void setting() { NULL; }

void release() { NULL; }
