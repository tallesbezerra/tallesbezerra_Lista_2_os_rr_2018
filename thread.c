// compilar: gcc -pthread thread.c -o thread
// executar: ./thread

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int primo(int num){
    int i = 2;

    if(num<2)
        return 0;

    while(i<=num/2){
        if(num%i==0){
            return 0;
        }
        i+=1;
    }
    return 1;
}

void *primo_thread10(){
    int n;
    for(n=0; n<10000; n++){
        if(primo(n)){
            printf("%d ", n);
        }
    }
}
void *primo_thread20(){
    int n;
    for(n=10000; n<20000; n++){
        if(primo(n)){
            printf("%d ", n);
        }
    }
}
void *primo_thread30(){
    int n;
    for(n=20000; n<30000; n++){
        if(primo(n)){
            printf("%d ", n);
        }
    }
}
void *primo_thread40(){
    int n;
    for(n=30000; n<40000; n++){
        if(primo(n)){
            printf("%d ", n);
        }
    }
}
void *primo_thread50(){
    int n;
    for(n=40000; n<50000; n++){
        if(primo(n)){
            printf("%d ", n);
        }
    }
}
void *primo_thread60(){
    int n;
    for(n=50000; n<60000; n++){
        if(primo(n)){
            printf("%d ", n);
        }
    }
}
void *primo_thread70(){
    int n;
    for(n=60000; n<70000; n++){
        if(primo(n)){
            printf("%d ", n);
        }
    }
}
void *primo_thread80(){
    int n;
    for(n=70000; n<80000; n++){
        if(primo(n)){
            printf("%d ", n);
        }
    }
}
void *primo_thread90(){
    int n;
    for(n=80000; n<90000; n++){
        if(primo(n)){
            printf("%d ", n);
        }
    }
}

void *primo_thread100(){
    int n;
    for(n=90000; n<100000; n++){
        if(primo(n)){
             printf("%d ", n);
        }
    }
}

int main(){

    pthread_t threads[10];

    pthread_create(&threads[0],NULL,primo_thread10,NULL);
    pthread_create(&threads[1],NULL,primo_thread20,NULL);
    pthread_create(&threads[2],NULL,primo_thread30,NULL);
    pthread_create(&threads[3],NULL,primo_thread40,NULL);
    pthread_create(&threads[4],NULL,primo_thread50,NULL);
    pthread_create(&threads[5],NULL,primo_thread60,NULL);
    pthread_create(&threads[6],NULL,primo_thread70,NULL);
    pthread_create(&threads[7],NULL,primo_thread80,NULL);
    pthread_create(&threads[8],NULL,primo_thread90,NULL);
    pthread_create(&threads[9],NULL,primo_thread100,NULL);
    

    pthread_join(threads[0],NULL);
    pthread_join(threads[1],NULL);
    pthread_join(threads[2],NULL);
    pthread_join(threads[3],NULL);
    pthread_join(threads[4],NULL);
    pthread_join(threads[5],NULL);
    pthread_join(threads[6],NULL);
    pthread_join(threads[7],NULL);
    pthread_join(threads[8],NULL);
    pthread_join(threads[9],NULL);

    return 0;
}