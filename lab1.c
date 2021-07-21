#include "types.h"
#include "user.h"


int exitWaitTest(void);
int waitPidTest(void);

int main(int argc, char *argv[])
{
  if (atoi(argv[1]) == 1)
	exitWaitTest();
  else if (atoi(argv[1]) == 2)
	waitPidTest();
  else
        printf(0,"\nType \"lab1 1\" to test exit and wait and \"lab1 2\" to test waitpid\n");

  EXIT(0);
  return 0;
 }
  
int exitWaitTest(void) {
  int pid, c_pid, exit_status, i;

  for (i = 0; i < 2; i++) {
    pid = fork();//make new processes
    if (pid == 0) {//only child processes will execute these code
      if (i == 0)
      {
      	printf(0,"\nChild process %d exit with status %d\n", getpid(), 0);
      	EXIT(0);
      }
      else
      {
	printf(0,"\nChild process %d exit with status %d\n" ,getpid(), -1);
      	EXIT(-1);
      } 
    } 
    else if (pid > 0) {//only parent process will execute these code
      c_pid = wait(&exit_status);//get the pid of each child processes
      printf(0,"\nParent process: child with PID# %d has exited with status %d\n", c_pid, exit_status);
    }
  }
  return 0;
}

int waitPidTest(void){
	
  int c_pid, exit_status, i;
  int pid_a[3]={0, 0, 0};

  for (i = 0; i <3 ; i++) {
	pid_a[i] = fork();
	if (pid_a[i] == 0) { // only child processes executed these code
		printf(0, "\n This is child with PID# %d and I will exit with status %d\n", getpid(), getpid());
		EXIT(0);
	}
  }     
  printf(0,"\n Waiting for child process %d\n",pid_a[0]);
  sleep(3);
  c_pid = waitpid(pid_a[0], &exit_status, getpid());
  printf(0,"\n Child process %d exited with status %d\n",c_pid, exit_status);
  
  printf(0,"\n Waiting for child process %d\n",pid_a[1]);
  sleep(3);  
  c_pid = waitpid(pid_a[1], &exit_status, getpid());
  printf(0,"\n Child# %d exited with status %d\n",c_pid, exit_status);
  
  printf(0,"\n Waiting for child process %d\n",pid_a[2]);
  sleep(3);
  c_pid = waitpid(pid_a[2], &exit_status, getpid());
  printf(0,"\n Child process %d exited with status %d\n",c_pid, exit_status);
  
  return 0;
}
