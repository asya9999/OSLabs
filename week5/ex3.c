#include <stdio.h>
#include <time.h>
#include <pthread.h>
#define N 100

int count = 0;
char buffer[N];
time_t start;
int i = 0;
pthread_mutex_t m;
pthread_cond_t c, p;

void *producer(void *ptr)
{

 while (1) { 
  pthread_mutex_lock(&m);
  
  if (count == N){
   pthread_cond_wait(&p, &m);
  }
  buffer[count] = 'p';
  count = count + 1;
  time_t end = time(NULL);
  double fraction = (double)(end - start);

  if(fraction > i*60){
   printf("Time:%f\n", ((double)(end - start)));
   i++;
  }

  if (count == 1){
   pthread_cond_signal(&c);
   pthread_mutex_unlock(&m);
  }
 }
}

void *consumer(void *ptr)
{
 while (1) {
  pthread_mutex_lock(&m);
  if (count == 0){
    pthread_cond_wait(&c, &m);
  }
  buffer[count] = 'c';
  count = count - 1;
  if (count == N - 1){
   pthread_cond_signal(&p);
   pthread_mutex_unlock(&m);
  }
 }
}

int main()
{
    return 0;
}