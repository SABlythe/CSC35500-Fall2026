#include <iostream>

#include <signal.h>
#include <unistd.h>

using namespace std;

  int *p = nullptr;

void doSomething(int signum)
{
  cout << "called handler with s=" << signum << endl;

}

int main (int argc, char **argv)
{
  signal (SIGSEGV, doSomething);


  cout << *p << endl;

  cout << "got here!" << endl;
  
  return 0;
}
