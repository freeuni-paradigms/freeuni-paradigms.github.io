#include <pthread.h>
#define N 10;

typedef struct {
    int id;
    int amount;
    pthread_mutex_t* lock;
    pthread_cond_t* cond;
} Account;

void AmountIn(Account * fromAccount, Account * myAccount, int amount) {
    pthread_mutex_t* firstLock;
    pthread_mutex_t* secondLock;
    if (fromAccount->id < myAccount->id){
        firstLock = fromAccount->lock;
        secondLock = myAccount->lock;
    }else{
        firstLock = myAccount->lock;
        secondLock = fromAccount->lock;
    }
    pthread_mutex_lock(firstLock);
    pthread_mutex_lock(secondLock);
    if (fromAccount->amount >= amount){
        fromAccount->amount -= amount;
        myAccount->amount += amount;
        pthread_cond_broadcast(myAccount->cond);
    }
    pthread_mutex_unlock(firstLock);
    pthread_mutex_unlock(secondLock);
}


void AmountOut(Account * myAccount, Account * toAccount, int amount) {
    pthread_mutex_lock(myAccount->lock);
    while (myAccount->amount < amount){
        pthread_cond_wait(myAccount->cond, myAccount->lock);
    }
    myAccount->amount -= amount;
    pthread_mutex_unlock(myAccount->lock);

    pthread_mutex_lock(toAccount->lock);
    toAccount->amount += amount;
    pthread_mutex_unlock(toAccount->lock);
}
