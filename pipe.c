#include <errno.h>
#include<string.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
int main(){
   int Pipe[2];
   char string[100];
   if (pipe(Pipe) == -1){
      perror("Filed to create pipe");
      exit(1);
   }
   scanf("%s", string);
   write(Pipe[1], string, strlen(string)+1);
   printf("\n");
   read(Pipe[0], string, 5);
   printf("%s", string);
}
