#include <iostream>

#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main (int argc, char **argv)
{
  int *n = new int;

  *n=10;

  cout << "before fork(), n= " << *n <<endl;
  int pid=fork();

  if (pid!=0) // if in parent
    {
      waitpid(pid, NULL, 0);
      cout << "Parent done waiting for child"
	   << endl;
    }

  *n += 10;
  cout << "add 10 to n, n is now: " << *n <<endl;

  return 1;
}
