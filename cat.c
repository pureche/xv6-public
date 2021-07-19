#include "types.h"
#include "stat.h"
#include "user.h"

char buf[512];

void
cat(int fd)
{
  int n;

  while((n = read(fd, buf, sizeof(buf))) > 0) {
    if (write(1, buf, n) != n) {
      printf(1, "cat: write error\n");
      exit(1); //LAB1A error has occurred here//
    }
  }
  if(n < 0){
    printf(1, "cat: read error\n");
    exit(1); //LAB1A error, exit 1//
  }
}

int
main(int argc, char *argv[])
{
  int fd, i;

  if(argc <= 1){
    cat(0);
    exit(1); //LAB1A error bc argc must be at least 2 in order to cat//
  }

  for(i = 1; i < argc; i++){
    if((fd = open(argv[i], 0)) < 0){
      printf(1, "cat: cannot open %s\n", argv[i]);
      exit(1); //LAB1A error ^//
    }
    cat(fd);
    close(fd);
  }
  exit(0); //LAB1A reached end, success//
}
