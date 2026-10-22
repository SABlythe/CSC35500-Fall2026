#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main(int agrc, char **argv)
{
  int pid=fork();

  if (pid!=0)
    {
      waitpid(pid, NULL, 0  );
      cout << "tantrum over!!!" << endl;
    }
  else
    {
      for(int tnum=1; tnum<=10; tnum++)
	{
	  cout << tnum << ") childish behavior" << endl;
	  sleep(1);
	}
    }
  return 0;
}
