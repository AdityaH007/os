#include<stdio.h>

int main()
{
    printf("Process id ID %d",getpid());
}


// Fork
fork();

// Process with fork
int pid;
pid=fork();

if(pid>0)
{
    printf("Parent");
}

else{
    printf("child");
}


// Making child a orphan

int pid1,pid2;
pid1=fork();
if(pid1>0){
    printf("parent")
}

else{
    sleep(1)
    printf("child");
}

// parent wait till child over+

if(pid==0)
{
    printf("child process")
}
else{
    wait(0);
    printf("parent");
}

//child exit(-1)
//parent exit(0)


//exec- replace current process image with new
if(pid==0){
    execve("/bin/date\n",NULL,NULL);
    exit(0);
}