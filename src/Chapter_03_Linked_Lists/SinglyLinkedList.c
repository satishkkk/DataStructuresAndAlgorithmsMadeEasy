#include<stdio.h>
#include<stdlib.h>
struct listNode{
	int data;
	struct listNode *next;
};
int listLength(struct listNode *head){
	int count;
	struct listNode *current=head;
	while(current!=NULL){
		count++;
		current=current->next;	
	}
	return count;
}
void insertInLinkedList(struct listNode **head, int data, int pos){
	int k=1;
	struct listNode *q,*p;
	struct listNode *newNode=(struct listNode*)malloc(sizeof(struct listNode));
	if(!newNode){
		printf("Memory Error\n");
		return;
	}
	newNode->data=data;
	p=*head;
	if(pos==1 || p==NULL){
		newNode->next=*head;
		*head=newNode;
	}
	else{
		while(p!=NULL && (k<pos)){
			k++;
			q=p;
			p=p->next;
		}
		newNode->next=q->next;
		q->next=newNode;
	}
}
void deleteNodeFromLinkedList(struct listNode **head, int pos){
	int k=1;
	struct listNode *p,*q;
	p=*head;
	if(*head==NULL){
		printf("List Empty\n");
		return;
	}
	else if(pos==1){
		*head=(*head)->next;
		free(p);
	}
	else{
		while(p!=NULL && k<pos){
			k++;
			q=p;
			p=p->next;
		}
		if(p==NULL){
			printf("Position does not exist\n");
		}
		else{
			q->next=p->next;
			free(p);
		}
	}
}
void printList(struct listNode *head){
	while(head!=NULL){
		printf("%d ",head->data);
		head=head->next;
	}
	printf("\n");
}
int main(){
	struct listNode *head=NULL;
	insertInLinkedList(&head,5,5);
	insertInLinkedList(&head,2,5);
	printf("Elements in List:%d\n",listLength(head));
	printList(head);
	deleteNodeFromLinkedList(&head,1);
	printList(head);
	return 0;
}
