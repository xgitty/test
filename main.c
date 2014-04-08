#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct list{
	char name[20];
	int number;
	struct list *next;
	struct list *previous;

};

struct list *getRecords(){

	struct list *head,*tail,*curr,*temp;



   	head = NULL;
   	temp = NULL;
   	char string[30] = {'\0'};
   	char nameInput[20] = {'\0'};
   	int number;
   	char dot[] = ".";
   	bool terminate = false;


    	while(terminate == false){

	fgets(string, 30, stdin);
        sscanf(string, "%s %d", nameInput, &number);

	   if(strcmp(nameInput,dot)!=0){

		curr = malloc(sizeof(struct list));
        	strcpy(curr->name , nameInput);
		curr->number = number;



		if(head == NULL){
			head = curr;
			head->previous = NULL;
		}
		else{
			tail->next=curr;

		}

		tail = curr;
       		tail->previous = temp;
       		temp = curr;


		tail->next = NULL;
	   }
	   else{
		terminate = true;
	   }
        }

	return head;

}

struct list *sort (struct list *head){

	struct list  *currCheck, *currCopy;
	char insertionName[20];
	int insertionNumber;


	for (currCheck = head; currCheck != NULL; currCheck = currCheck->next){

		strcpy(insertionName,currCheck->next->name);
		insertionNumber = currCheck->next->number;
		currCopy = currCheck;

 		  while (currCopy != NULL && strcmp(insertionName,currCopy->name)<0){

			strcpy(currCopy->next->name, currCopy->name);
			currCopy->next->number = currCopy->number;
			currCopy=currCopy->previous;

		  }

 	strcpy(currCopy->next->name,insertionName);
	currCopy->next->number = insertionNumber;

        }

	return head;

 }

printRecords(struct list *head){

    struct list *curr;

    for(curr = head; curr != NULL; curr = curr->next){

	printf("\n");
        printf("%s %d", curr->name, curr->number);


    }

    printf("\n");


}

int main(void){

     char temp[]= "hello";
     char temp2[] = "abill";

     if(strcmp(temp,temp2)<0){

        printf("hello is higher");
     }

         return 0;


}
