#include<stdio.h>
#include<unistd.h>

int main()
{
    
int fd[2];
int pid;
 char msg1[] = "hi";
 char msg2 []= "hello";
 char readmsg[20];

 pipe(fd);

 pid = fork();

 if(pid==0)
 {
    read(fd[0], readmsg,sizeof(readmsg));
    printf("child reads : %s\n", readmsg);

    read(fd[0], readmsg , sizeof(readmsg));
    printf("child reads : %s\n", readmsg);

 }
 else 
 {
    printf("parent writes :%s \n", msg1);
    write(fd[1],  msg1 , sizeof(msg1));

    printf("parent writes :%s\n", msg2);
    write(fd[1], msg2, sizeof(msg2));
 }
 return 0;
}
