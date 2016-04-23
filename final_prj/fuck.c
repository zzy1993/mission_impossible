#include "types.h"
#include "user.h"

int val=0;
int pal=0;

int main()
{
    int p_c[2];
    int err_1=pipe(p_c);
    if(err_1 == -1)
    {
      //perror("pipe");
      return 1;
    }
    int c_p[2];
    int err_2=pipe(c_p);
    if(err_2 == -1)
    {
      //perror("pipe");
      return 1;
    } 
    int i;
    int j;
    int pid = fork();

    if(pid == 0)      //child
    {   
      pal=20; 
      close(p_c[1]);
      close(c_p[0]);
      for(j=0;j<5;j++)
      {
         read(p_c[0],&val,sizeof val);
         printf(1,"child process %d is child iteration %d\n", (int)getpid(), j);         
         //fflush(stdout);
         write(c_p[1],&pal,sizeof pal);
      }
      printf(1, "chind is about to exit\n");
      exit();
    }    
    else            //parent
    {
      val=100;
      close(p_c[0]);
      close(c_p[1]);
      for(i=0;i<5;i++)
      {
         printf(1, "parent process %d is parent iteration %d\n", (int)getpid(), i);
         //fflush(stdout);
         write(p_c[1],&val,sizeof val);
         read(c_p[0],&pal,sizeof pal);         
      }
       wait();
    }
    printf(1, "parent is about to exit\n");
    exit();
}
