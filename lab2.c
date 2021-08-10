#include "types.h"
#include "user.h"

int main(int argc, char *argv[])
{
  int pid;
  int i, j, k;
  double l = 0;
  setPriority(getpid(), 13);
  for (i = 0; i < 3; i++)
  {
    pid = fork();
    if (pid != 0)
    { // Parent process execute following code
      printf(1, "Parent process %d created child process %d\n", getpid(), pid);
      wait(0);
    }
    else
    {
      printf(1, "Child process %d is created.\n", getpid());
      setPriority(getpid(), 10 - 2 * i);
      for (j = 0; j < 3; j++)
      {
        for (k = 0; k < 1000000000; k++)
          l += 38.54 * 1.23 * 0.2367;
        printf(1, "Child process %d is running.\n", getpid());
      }
      printf(1, "Child process %d finished running.\n");
      exit();
    }
  }
  exit();
}
