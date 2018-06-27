#include "common.h"


//key
key_t key;

//shared memory
int shmid;
char * shmptr;
char input[SHM_SIZE];

//semaphore 
sem_t * full;
sem_t * mutex;
//end of semaphore


void Init()
{
	key = KEY_NUM;					//init key
	shmid  = GetShmId(key);			// init shared memory
	shmptr = shmat(shmid,NULL,0);		// attach segement to vitural ...?
	//semaphore init
	full = sem_open(FULL_NAME,O_CREAT);
	mutex = sem_open(MUTEX_NAME,O_CREAT);
}

void SaveMessage()//从读取的字符串中获取内容
{

	P(mutex);						
	strcpy(shmptr,input);
	V(mutex);

	V(full);
}

int main(int argc, char const *argv[])//读取字符串和调用主要函数
{
	
	
	Init();
	
	/*waiting for user to input message*/
	scanf("%s",input);					//input message from shell 
										// TODO input a whole line
	SaveMessage();
	
	printf("Sender:  Process End\n");
	return 0;
}