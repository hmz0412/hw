#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define maxBuf 8192

int main(int argc,char *argv[]){
    char buf[maxBuf];
    int fd_in, fd_out;
    int readcnt;
    if(argc!=3){
        fprintf(stderr,"usage: %s sourcefile targetfile",argv[0]);
    }
    fd_in = open(argv[1],O_RDONLY);
    if(fd_in<0){
        fprintf(stderr,"open error: %s",argv[1]);
    }
    fd_out = open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0600);
    if(fd_out<0){
        fprintf(stderr,"open error: %s",argv[2]);
    }
    while((readcnt = read(fd_in,buf,1))>0){
        write(fd_out,buf,1);
    }
}
