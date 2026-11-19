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

  int *arr = (int *) shmat(shm_id, nullptr, 0);

  if (arr == (int *) -1)
    {
      cerr << "shmat() failed!"
	   << " with errno = " << errno << endl;
      return 1;
    }

  while(true)
    {
      arr[0] = 1;
      arr[0] = 3 *arr[0]  +7;  // should be 3*1 + 7 = 10
      if (arr[0] != 10)
	cout << "uh oh. not 10. It is " << arr[0] << endl;
    }
  
  return 1;
}
