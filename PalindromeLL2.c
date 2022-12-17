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
// mid by Two Pointer
int TwoPointer(){
	struct node *A,*B;
	A=p;
	B=p;
	while(B!=NULL &&(B->link!=NULL && B->link && B->link->link!=NULL)){
		A=A->link;
		B=B->link->link;
	}
	return A->link;
}
int reverse(struct node*A) {
        struct node* pre=NULL;
       struct node* next=NULL;
        while(A!=NULL){
            next=A->link;
            A->link=pre;
            pre=A;
            A=next;
        }
        return pre;
    }
//palindrome
void isPalindrome(){
	struct node*res,*temp;
	temp=TwoPointer();
	res=reverse(temp);
	if(res->data==p->data){
		printf("\nPalindrome!");
	}
	else{
		printf("\nNot palindrome!");
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
	
	printf("LINKED LIST IS: ");
	print_list();
	isPalindrome();
}