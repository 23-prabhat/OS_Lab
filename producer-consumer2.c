#include<stdio.h>
#include<stdlib.h>

#define BUFFERSIZE 20

int n , empty , full = 0 , item , item1;
int buffer[20];
int in = 0 , out = 0;
int mutex = 1 ;

void wait(int s){
    while(s<0){
          printf("can't add  item");
          exit(0);
    }
    s--;

}

void signal(int s){
    s++;
}

void produce(){
    do{
      wait(empty);
      wait(mutex);
      printf("enter item : ");
      scanf("%d",&item);
      buffer[in] = item;
      in = in + 1;
      signal(mutex);
    signal(full);
    }
    while(in<n);
}

void consumer(){
    do
    {
        wait(full);
        wait(mutex);
        item1 = buffer[out];
        printf("consumed : %d", item1);
        out = out + 1;
        signal(mutex);
        signal(empty);
    } while (out < n);  
}

void main(){
    printf("enter the value of n : ");
    scanf("%d",&n);

    empty = n ;
    while(in < n){
        produce();
    }
    while(in!= out){
        consumer();
    }
}
