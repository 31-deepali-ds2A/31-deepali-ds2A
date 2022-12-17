#include<stdio.h>
#include<stdlib.h>
struct node{
      int data;
      struct node *link;
  };
struct node* mergeList(struct node* l1, struct node* l2) {
    if(l1==NULL)
    {return l2;}
    if(l2==NULL)
    {return l1;}
    struct node* result=(struct node*)malloc(sizeof(struct node));
    struct node* p=result;
    while(l1!=NULL&&l2!=NULL)
    {
        if(l1->data>l2->data)
        {
            result->link=l2;
            result=result->link;
            l2=l2->link;
        }else
        {
            result->link=l1;
            result=result->link;
            l1=l1->link;
        }
    }
    if(l1==NULL)
    {
        result->link=l2;
    }else if(l2==NULL)
    {
        result->link=l1;
    }
    return p->link;
}
void add_beg(int d,struct node**h1){
	if(h1==NULL){
		struct node*ptr=(struct node*)malloc(sizeof(struct node));
		ptr->data=d;
		ptr->link=NULL;
		*h1=ptr;
	}
	else{
		struct node *temp=(struct node*)malloc(sizeof(struct node));
		temp->data=d;
		temp->link=*h1;
		*h1=temp;	
	}}
void print(struct node*p){
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
	printf("%d",temp->data);	
}
 int main(){
 
 struct node *a = NULL, *b = NULL;
        add_beg(3,&a);
        add_beg(2,&a);
        add_beg(1,&a);
 
    for (int i = 10; i >6; i --) {
        add_beg(i,&b);
    }
 
    // print both lists
    printf("\nFirst List: ");
    print(a);
 
    printf("\nSecond List: ");
    print(b);
 
    struct node* head = mergeList(a, b);
    printf("\nAfter Merge: ");
    print(head);
 
    return 0;
}
