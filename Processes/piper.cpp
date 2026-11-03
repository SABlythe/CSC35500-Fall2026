#include <cstdio>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main(int argc, char **argv)
{
  int pipeInfo[2];
  int myPipe = pipe(pipeInfo);

  if (myPipe!=0)
    {
      cout << "Pipe error!!" << endl;
      exit(1);
    }
  
  int pid = fork();

  if (pid != 0)
    {
      
      close(pipeInfo[1]);
      dup2(pipeInfo[0], fileno(stdin));
      char * args[2];
      args[0] = new char[3]; strcpy(args[0], "wc");
      args[1] = nullptr;
      execvp(args[0], args);
    }
  else
    {
      close(pipeInfo[0]);
      dup2(pipeInfo[1], fileno(stdout));
      
      char * args[3];
      args[0] = new char[3]; strcpy(args[0], "ls");
      args[1] = new char[3]; strcpy(args[1], "-l");
      args[2] = nullptr;
      execvp(args[0], args);
    }

  cout << "process ending!!" << endl;
  return 0;
}
