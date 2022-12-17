#include<stdio.h>
#include<stdlib.h>
//structure of single linked list
struct node
{
	int data;
	struct node*link;
}*p;
// add at head function
void add_beg(int d){
	if(p==NULL){
		struct node*ptr=(struct node*)malloc(sizeof(struct node));
		ptr->data=d;
		ptr->link=NULL;
		p=ptr;
	}
	else{
		struct node *temp=(struct node*)malloc(sizeof(struct node));
		temp->data=d;
		temp->link=p;
		p=temp;	
	}}
void rotateK(int k){
	struct node*temp,*prev;
	temp=p;
	while(k){
		while(temp->link!=NULL){
			prev=temp;
		temp=temp->link;
	}
	prev->link=NULL;
	temp->link=p;
	p=temp;
	k--;
	
	}
}
// print function
void print_list(){
	if(p==NULL){
		printf("linked list does not exit.");
	}
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	temp=NULL;
	temp=p;
	while(temp->link!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->link;
	}
	printf("%d ",temp->data);	
}
int main(){
	int n,d;
	printf("create Linked List:\n");
	printf("How Many numbers you want to enter:\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("enter element in %d position:",i);
		scanf("%d",&d);
		add_beg(d);
	}
	printf("LINKED LIST IS: \n");
	print_list();
	rotateK(2);
	printf("\nLINKED LIST AFTER ROTATION IS: ");
	print_list();
}