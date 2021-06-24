#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
#define maxBuf 8291

int main(int argc,char *argv[]){
    int fd;
    int filesize;
    char front[1];
    char back[1];
    int i=0;
    fd = open(argv[1],O_RDWR);
    if(fd<1){
        fprintf(stderr,"open error\n");
        exit(1);
    }
    filesize = lseek(fd,0,SEEK_END);
    lseek(fd,0,SEEK_SET);
     while(i<(filesize/2)){
        read(fd,front,1);
        lseek(fd,-2-i,SEEK_END);
        read(fd,back,1);
        lseek(fd,0+i,SEEK_SET);
        write(fd,back,1);//後面的寫到前面
        lseek(fd,-2-i,SEEK_END);
        write(fd,front,1);//前面寫到後面
        i++;
        lseek(fd,0+i,SEEK_SET);
    }
}
