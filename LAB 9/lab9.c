#include <stdio.h>
#include <stdlib.h>

struct student{
	int number;
	char name[20];
	float midterm;
	float final_grade;
	struct student *next;
};

struct student *head=NULL;


struct student *insert(struct student *head){ //veri giriþi;
	
	struct student *student=(struct student *)malloc(sizeof(struct student));
	printf("enter student number:");
	scanf("%d",&student->number);
	printf("enter student name:");
	scanf("%s",student->name);
	printf("enter midterm grade:");
	scanf("%f",&student->midterm);
	printf("enter final grade:");
	scanf("%f",&student->final_grade);
	student->next=NULL;
	printf("student is added to the list\n");
	
	if(head==NULL){ //liste boþsa;
		head=student;
	}
	else { //liste dolu deðilse;
		student->next=head;
		head=student;
	}
	return head;
}

void update(struct student *head,int std_no){
	
	struct student *temp=head;
	while(temp!=NULL){
		if(temp->number==std_no){
			
			printf("student with number %d is found\n",std_no);
			printf("enter a new name: ");
			scanf("%s",temp->name);
			printf("enter new midterm grade:");
			scanf("%f",&temp->midterm);
			printf("enter new final grade:");
			scanf("%f",&temp->final_grade);
			return ;
		}
		temp=temp->next;
	}
	printf("student with number %d is not found",std_no);
}

void average(struct student *head){
	struct student *temp=head;
	float average=0;
	int count=0;
	while(temp!=NULL){
		average += 0.4*temp->midterm + 0.6*temp->final_grade;
		count++;
		temp=temp->next;
	}
	printf("Average grade : %.2f\n",average/count);
}

void best_student(struct student *head){
	struct student *temp=head;
	struct student *best=head;
	
	while(temp!=NULL){
		if((0.4*temp->midterm + 0.6*temp->final_grade)>(0.4*best->midterm + 0.6*best->final_grade)){
			best=temp;
		}
		temp=temp->next;
	}
	printf("The best student number is %d and best student name is %s\n",best->number,best->name);
	
}

void list_records() {//ortalamasý 60 üstü olanlarý listeleme;
    
    struct student *temp = head
        
        while (temp != NULL) {
            float average = 0.4*temp->midterm + 0.6*temp->final_grade;
            if (average >= 60) {
                printf("Number: %d\n", temp->number);
            	printf("Name: %s\n", temp->name);
            	printf("Midterm Grade: %.2f\n", temp->midterm);
            	printf("Final Grade: %.2f\n", temp->final_grade);
            	printf("------------\n");
            }
            temp= temp->next;
        }
}

int main() {
	
	int i,choice,std_no;
	while(choice!=6){
		printf("1-Add new record\n");
		printf("2-List records\n");
		printf("3-Update records\n ");
		printf("4-Calculate class average\n");
		printf("5-Show best student\n");
		printf("6-Exit\n");
		
		printf("Enter choice: ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1 :
				head=insert(head);
				break;
			case 2 :
				list_records(head);
				break;
			case 3 :
				printf("Enter the student number to update:");
				scanf("%d",&std_no);
				update(head,std_no);
				break;
			case 4 :
				average(head);
				break;
			case 5 :
				best_student(head);
				break;
			case 6 :
				printf("The end of the program")
				break;			
		}
	}
	
	return 0;
}  
