#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

struct node{
    int phoneNumber;
    char name[20];
    struct node *newnode;
};


struct node* insAtBeg(char x[20],int number, struct node *first){  //insert at begining of newnodeed list
	struct node *new;
	new=(struct node*)malloc(sizeof(struct node));
	if(new == NULL){
		printf("overfowed\n");
		return first;
	}
	else{
        for(int i=0;i<20;i++)
		    new->name[i]=x[i];
        new->phoneNumber = number;
		new->newnode=first;	
		return new;
	}
}

bool search(char x[20]){
    struct node *new;
    new =(struct node*) malloc(sizeof(struct node));
    if(new->name == x){
        return true;
    }
    else{
        return false;
    }
}

// void sort(struct node *first){
//     if()

// }

struct node* insOrd(char x[20],int number, struct node *first){    //inserts in ordered newnodeed list in ordered manner
	struct node *new;
	new=(struct node*)malloc(sizeof(struct node));
	struct node *save;
	
	save= first;
	
	if(save == NULL){
		printf("empty\n");
		return new;
	}
	

    for(int i=0;i<20;i++)
        new->name[i]=x[i];	
    new->phoneNumber = number;
	if(new->name <= first->name){
		new->newnode=first;
		return new;
	}
	
	while(save->newnode != NULL && new->name >= save->newnode->name){
		save=save->newnode;
	}
	
	new->newnode =save->newnode;
	save->newnode=new;
	return first;
}
int main(){
    int option;
    int number;
    char name[20];
    struct node * first;

	first = (struct node*)malloc(sizeof(struct node));
    while(1){
        printf("Enter :\n1 to insert\n2 to search\n3 to read\n4 to sort\n5 to delete\n");
        scanf("%d",&option);
        switch (option)
        {
        case 1:
            printf("insertion\n");
            printf("enter name:");
            scanf("%s",name);
            printf("enter number:");
            scanf("%d",number);
            insAtBeg(name, number, first );
            break;
        case 2:
            printf("search");
            break;
        case 3:
            printf("read");
            break;
        case 4:
            printf("short");
            break;
        case 5:
            printf("delete");
            break;
        default:
        printf("invalid option");
            break;
        }
        
    }
}
