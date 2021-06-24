#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
#define maxBuf 8291

int main(int argc,char *argv[]){
    int fd;
    int filesize;
    char buf[maxBuf];
    char *ptr;
    int i=0;
    fd = open(argv[1],O_RDWR);
    if(fd<1){
        fprintf(stderr,"open error\n");
        exit(1);
    }
    filesize = lseek(fd,0,SEEK_END);
    lseek(fd,0,SEEK_SET);
    read(fd,buf,filesize);
    while(i<filesize){
        buf[i] = tolower(buf[i]);
        i++;
    }
    lseek(fd,0,SEEK_SET);
    write(fd,buf,filesize);
}
