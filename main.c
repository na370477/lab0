//
//  main.c
//  Lab0
//
//  Created by Narek Abrahamian on 08/30/14.
//  Copyright (c) 2014 Narek Abrahamian. All rights reserved.
//

#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>

char* countones(char* input){
    int i;
    int counter = 0;
    for(i = 0;i < 8;i++){
        
        if(input[i]== 1){
            counter++;
        }
    }
    
    if(counter%2== 0){
        return "EVEN";
    }
    else {
        return "ODD";
    }
}

int string2decimal(char deci[]){
    
    int i;
    int num = 0;
    for(i=0; i<8; i++)
        num = num*10 + (deci[i] - '0');
    return num;
}

int binary2decimal(int n){
    
    int decimal = 0;
    int i = 0;
    int remainder;
    
    while (n!=0){
        remainder = n%10;
        n = n/10;
        decimal = decimal + remainder * pow(2,i);
        i++;
        
    }
    
    return decimal;
    
    
}


int main(int argc,char * argv[],char** envp) {
    
    char buffer[20];
    char *value=buffer;
    int fd;
    fd = open("test2.txt",O_RDONLY);
    int read_bytes;
    
    do {
        read_bytes = read(fd, buffer, 8);
        int i;
        for(i=0; i<8; i++) {
            if(!buffer[i]==' ') {
                buffer[i]=value[i];
            }
            printf("%c", value[i]);
            
        }
        
    }
    while (read_bytes != 0);
    
    printf("\nOriginal  ASCII  Decimal  Parity\n");
    printf("\n-------- - ----- - ------- - -------\n");
    
    if(!argc==1){
        printf("Error");
    }
    
    
    
    int y = string2decimal("");
    printf("%d\n",y);
    
    y = binary2decimal(y);
    printf("\n%d\n",y);
    
    
    char c = 'A' - 1 + y;
    printf("\n%c\n",c);
    
    //print statements
    //printf("%s \t %c \t %d \t %s", read8, ascii, decimal, parity);
}
