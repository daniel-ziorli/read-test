#include <fcntl.h> // open
#include <unistd.h> // read
#include <sys/types.h> // read
#include <sys/uio.h> // read
#include <stdio.h> // fopen, fread
#include <stdlib.h>
#include <sys/time.h> // gettimeofday

struct timeval start, end; // maintain starting and finishing wall time.

void startTimer( ) { // memorize the starting time
    gettimeofday( &start, NULL );
}

void stopTimer( char *str ) { // checking the finishing time and computes the elapsed time
    gettimeofday( &end, NULL );
    printf("%s's elapsed time\t= %ld\n",str, ( end.tv_sec - start.tv_sec ) * 1000000 + (end.tv_usec - start.tv_usec ));
}

int main( int argc, char *argv[] ) {

    if( argc != 4 ) {
        fprintf(stderr, "usage: %s filename bytes typeofcallsused\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (atoi(argv[3]) != 1 && atoi(argv[3]) != 0){
        fprintf(stderr, "usage: %s filename bytes typeofcallsused\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if( access( argv[1], F_OK ) == -1 ){
        fprintf(stderr, "usage: %s filename bytes typeofcallsused\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if(atoi(argv[2]) <= 0){
        fprintf(stderr, "usage: %s filename bytes typeofcallsused\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int typeofcalls = atoi(argv[3]);
    int numberofbytes = atoi(argv[2]);
    char * filename = argv[1];
    char buffer[numberofbytes];

    // validate arguments
    // // implementation

    // Parsing the arguments passed to your C program
    // Including the number of bytes to read per read( ) or fread( ), and
    // the type of i/o calls used
    // implementation

    if (typeofcalls == 1) {
    // Use unix I/O system calls to
    // implementation
        int fd;
        int n;
        fd = open(filename, O_RDONLY);
        printf("Using Unix I/O systems calls to read a file by %d bytes per read\n", numberofbytes);
        startTimer();
        while((n = read(fd, buffer, numberofbytes)) > 0){ }
        stopTimer("Unix read's");
        close(fd);
    } else if (typeofcalls == 0) {
    // Use standard I/O
    // implementation
        FILE * fp;
        size_t n;
        fp = fopen(filename, "r");
        printf("Using C functions to read a file by %d bytes per fread\n", numberofbytes);
        if (numberofbytes == 1){
            startTimer();
            while (fgetc ( fp ) != EOF){ }            
            stopTimer("C fread's");
        }
        else{
            startTimer();
            while ((n = fread(buffer, 1, numberofbytes, fp)) > 0){ }
            stopTimer("C fread's");
        }
        
        fclose(fp);
    }

    return 0;
}