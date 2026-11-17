#include <iostream>

#include <unistd.h>
#include <sys/wait.h>

#include <sys/shm.h>

using namespace std;

int main (int argc, char **argv)
{
  if (argc!=2)
    {
      cerr << "Usage: " << argv[0] << " <key number>"
	   << endl;
      return 1;
    }

  int myKeyValue = stoi(argv[1]);

  int shm_id = shmget(myKeyValue, 1024 /*1 KB*/,
		      0);
  
  if (shm_id==-1)
    {
      shm_id = shmget(myKeyValue, 1024 /*1 KB*/,
      		      IPC_CREAT | IPC_EXCL | 0666);

      if (shm_id==-1)
	{
	  cerr << "shmget() failed!"
	       << " with errno = " << errno << endl;
	  return 1;
	}
    }

  //int *n = new int;
  int *n = (int *) shmat(shm_id, nullptr, 0);

  if (n == (int *) -1)
    {
      cerr << "shmat() failed!"
	   << " with errno = " << errno << endl;
      return 1;
    }

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
