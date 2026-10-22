#include <cstdio>
#include <iostream>
#include <unistd.h>

using namespace std;

int main(int agrc, char **argv)
{
  int num;

  FILE *fp = fopen(argv[1], "r");
  dup2(fileno(fp), fileno(stdin));

  fp = fopen ("oputput.txt", "w");
  dup2(fileno(fp), fileno(stdout));  
  
  cin >> num;
  cout << num*num <<endl;
  
  return 0;
}
