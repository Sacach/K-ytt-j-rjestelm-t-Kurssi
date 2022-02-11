#include <stdio.h>
#include <pthread.h>
#include <time.h>

char a='a',b='b',c='c',d='d';
int flaga=0, flagb=0, flagc=0, flagd=0;
int stop=0;

void *Task1(void *data)
{
	int nextp = 0;
	struct timespec mytime;
	mytime.tv_sec = 0;
	mytime.tv_nsec = 100000000;

	while (!stop) {
		printf("Task1 waiting a...\n"); /* resource allocation */
		nanosleep(&mytime,NULL);
		while(flaga) {
			nanosleep(&mytime,NULL);
		}
		flaga=1;
		printf("Task1 locked a\n");
		nanosleep(&mytime,NULL);
		printf("Task1 waiting b...\n");
		while(flagb) {
			nanosleep(&mytime,NULL);
		}
		flagb=1;
		printf("Task1 locked b\n");
		nanosleep(&mytime,NULL);
		printf("Task1 waiting c...\n");
		while(flagc) {
			nanosleep(&mytime,NULL);
		}
		flagc=1;
		printf("Task1 locked c\n");
		nanosleep(&mytime,NULL);
		c = a;
		a = b;
		b = c;
		flagc = 0;  /* release all resources */
		flagb = 0;
		flaga = 0;
		printf("Task1 done\n");
	}

	pthread_exit(0);
}


void *Task2(void *data)
{
	int nextc;
	struct timespec mytime;
	mytime.tv_sec = 0;
	mytime.tv_nsec = 100000000;

     while (!stop) {
		printf("Task2 waiting b...\n");
		nanosleep(&mytime,NULL);
		while(flagb){
            nanosleep(&mytime,NULL);
		}

		flagb = 1;
		printf("Task2 locked b\n");
		nanosleep(&mytime,NULL);
		printf("Task2 waiting c...\n");
		while(flagc){
            nanosleep(&mytime,NULL);
		}

		flagc = 1;
		printf("Task2 locked c\n");
		nanosleep(&mytime,NULL);
		printf("Task2 waiting d...\n");
		while(flagd){
            nanosleep(&mytime,NULL);
		}

		flagd = 1;
		printf("Task2 locked d\n");
		nanosleep(&mytime,NULL);
		c = b;
		d = b;
		b = c;
		flagb = 0;
		flagc = 0;
		flagd = 0;
		printf("Task2 done\n");
	}

	pthread_exit(0);
}


void *MonitorTask (void *data)
{
	getchar();
	stop = 1;
	pthread_exit(0);
}


int main(void)
{
	pthread_t task1;
	pthread_t task2;
	pthread_t task3;

	pthread_create (&task1, NULL, Task1, NULL);
	pthread_create (&task2, NULL, Task2, NULL);
	pthread_create (&task3, NULL, MonitorTask, NULL);

	pthread_join(task1,NULL);
	pthread_join(task2,NULL);
	pthread_join(task3,NULL);

	printf("Main program exiting.\n");

	return 0;
}
