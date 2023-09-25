#include<stdio.h> //HEADER FILES
#include<unistd.h>
#include<stdlib.h>
int main() //MAIN FUNCTION
{
pid_t pid;
pid=fork(); //CALLING FORK TO CREATE A CHILD PROCESS
if(pid!=0)
{
while(1)
sleep(50);
}
else
{
exit(0);
}
}
