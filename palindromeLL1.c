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
// palindrome
void isPalindrome() {
    if(p==NULL||p->link==NULL){
	printf("Empty L.L");
	}
    struct node* head1=p;
    struct node* head2=p->link;
    int count=0;
    while(head1!=NULL){
        head1=head1->link;
        count++;
    }
    head1=p;
    p->link=NULL;
    for(int i=1;i<count/2;i++){
        struct node* r=head2->link;
        head2->link=head1;
        head1=head2;
        head2=r;
    }
    if(count%2!=0){
	head2=head2->link;
	}
	int c=0;
    while(head1!=NULL){
        if(head1->data!=head2->data){
		c++;
		}
        head1=head1->link;
        head2=head2->link;
    }
    if(c==0){
    printf("\nPalindrome!");}
    else{
    	printf("\nNot Palindrome!");
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