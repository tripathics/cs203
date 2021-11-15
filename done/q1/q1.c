#include<stdio.h>

int f = -1,r = -1;

// function prototypes
void enqueue(int *queue, int data,int size);
void print(int *queue);
void reverse(int *queue_orig, int *queue_rev);

int main(void)
{
	int size,i=0,t;
	
	printf("Enter the size of Queue: ");
	scanf("%d",&size);

	// original queue
	int queue[size];

	// new queue (reversed)
	int rev_queue[size];

	// populating the queue
	printf("\nEnter the data for Queue: ");
	for (int i = 0; i < size; i++)
	{
		scanf("%d",&t);
		enqueue(queue, t, size);
	}

	printf("\nQueue which you have entered: ");
	print(queue);

	// reversing the queue into the new queue (rev_queue)
	reverse(queue, rev_queue);

	printf("Original queue:\n");
	print(queue);
	printf("\nReversed queue:\n");
	print(rev_queue);

	return 0;	
}

void enqueue(int *queue, int data,int size)//Enqueue for inserting data
{
	if(r==size-1){
		printf("Queue is full");
	}
	else if((f==-1)&&(r==-1)){
		f = r = 0;
		queue[r] = data;
	}
	else
	{
		r++;
		queue[r] = data;	
	}
}

void print(int *queue)//Print function for printing the data
{
	int i;
	for(i=f;i<=r;i++)
		printf("%d ",queue[i]);
	printf("\n");
}

void reverse(int *queue_orig, int *queue_rev)//reverse function for reversing the data
{
	int i,j;
	for(i=f,j=r; j >= 0; i++, j--)
		queue_rev[j] = queue_orig[i];
}