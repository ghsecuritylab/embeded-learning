#include <stdio.h>

#define L (1<<4)
#define MODEADD(p) ((p)+1)&(L-1)

int ring[L];
int head,tail=0;



//入队
void Push(int e){
    ring[tail]=e;
    tail = MODEADD(tail);
}

//出队
int Pop() {
    int e=ring[head];
    head = MODEADD(head);

    return e;
}



//队列空
int IsEmpty(){
    return tail==head;
}

//队列满
int IsFull() {
    return MODEADD(tail)==head;
}

int PopArray(int array[]) {
    int i=0;
    while(!IsEmpty()){
        array[i++]=ring[head];
        head = MODEADD(head);
    }

    return i;
    
}

int main() {
    int recv[18]={0x00,0x01,0x02,0x3,0x04,0x05};

    int pick[9]={0x00};

    for(int i = 0; i < 18; i++)
    {
        Push(recv[i]);
    }

   int len = PopArray(pick);

   printf("length is %d\r\n",len);

   for(int i=0;i<len;i++){
       printf("%d\r\n",pick[i]);
   }
    
}