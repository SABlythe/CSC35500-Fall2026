#include <iostream>
#include <unistd.h>

using namespace std;

int main (int argc, char **argv)
{

  while(1)
    fork();

  cout << "a process" << endl;
  
  return 0;
}
