typedef struct {
  int pid;
  int priv;
} Process;

enum Status { waiting = 0, working = 1 };

struct {
  Status status = waiting;
  Process process;
} cpu;