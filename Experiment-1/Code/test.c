#include<linux/unistd.h>
#include<sys/syscall.h>
#include <stdio.h>
#include <stdlib.h>
//#define __NR_mysetnice 333
int main()
{
    int a,b,c;
    printf("Please input pid:");
    scanf("%d",&a);
    printf("Please select operation \"0\" as read \"1\" as change:");
    scanf("%d",&b);
    if(b==0){
        c=0;
    }
    else{
        printf("Please input nice value you want:");
        scanf("%d",&c);
    }
    syscall(333,a,b,c);
    printf("Program execute successfully! Please use dmesg to see the log.\n");
    return 0;
}