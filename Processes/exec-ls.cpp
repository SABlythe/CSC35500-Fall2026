#include <iostream>
#include <unistd.h>
#include <cstring>
using namespace std;

int main(int agrc, char **argv)
{
  char *args[3];
  args[0]=new char[strlen("ls")+1]; strcpy(args[0], "ls");
  args[1]=new char[strlen("-la")+1]; strcpy(args[1], "-la");
  args[2]=NULL;

  execvp(args[0], args);

  cout << "execvp failed!!" << endl;
  
  return 0;
}
