#include <iostream>
#include <cerrno>
#include <cstdlib>

#include <sys/shm.h>

using namespace std;

int main(int argc, char **argv)
{
  if (argc!=2)
    {
      cerr << "Usage: " << argv[0] << " <key number>"
	   << endl;
      return 1;
    }

  int myKeyValue = stoi(argv[1]);

  int shm_id = shmget(myKeyValue, 1024 /*1 KB*/,
		      IPC_CREAT | IPC_EXCL | 0666);

  if (shm_id==-1)
    {
      cerr << "shmget() failed!"
	   << " with errno = " << errno << endl;
      return 1;
    }
  
  return 0;
}


