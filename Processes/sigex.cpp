#include <iostream>

#include <signal.h>
#include <unistd.h>

using namespace std;

void doSomething(int signum)
{
  cout << "called handler with s=" << signum << endl;
}

int main (int argc, char **argv)
{
  int pid=fork();

  if (pid)
    {
      signal(SIGCHLD, doSomething);
      cout << "enter an integer: ";
      int stall;
      cin >> stall;
      cout << stall << " is a good number" << endl;
    }
  else
    {
      cout << "Child going to sleep ... ";
      cout.flush();
      sleep (10);
      cout << "child woke up " << endl;
    }
  return 0;
}
