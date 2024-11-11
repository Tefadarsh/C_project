#include <stdio.h>
#include <stdlib.h>
#include "SDB.h"


//This function creates the student's node
struct Node* createNode(){
   struct Node* pNode=(struct Node*)malloc(sizeof(struct Node));
   if(pNode==NULL){
        return pNode; //Return NULL if dynamic memory allocation fails
   }
   else{
        //Initialize the Node's data and pointers
        printf("\nEnter the student ID : ");
        scanf("%d",&pNode->data.Student_ID);
        //This condition is made to make sure that the user does not enter an ID that is already exist in SDB
        if(SDB_IsIdExist(pNode->data.Student_ID)){
           printf("\nThis ID is already exist in the database\n");
        }
        else{
            printf("\nEnter the student year : ");
            scanf("%d",&pNode->data.Student_year);
            printf("\nEnter the ID of the first course : ");
            scanf("%d",&pNode->data.Course1_ID);
            printf("\nEnter the grade of the first course : ");
            scanf("%d",&pNode->data.Course1_grade);
            printf("\nEnter the ID of the second course : ");
            scanf("%d",&pNode->data.Course2_ID);
            printf("\nEnter the grade of the second course : ");
            scanf("%d",&pNode->data.Course2_grade);
            printf("\nEnter the ID of the third course : ");
            scanf("%d",&pNode->data.Course3_ID);
            printf("\nEnter the grade of the third course : ");
            scanf("%d",&pNode->data.Course3_grade);
            pNode->pRight=NULL;
            pNode->pLeft=NULL;
            return pNode;
        }
   }

}

//This function counts how many students are in SDB
uint8 SDB_GetUsedSize(){


      return count;


}

//This function checks if SDB is full or not
bool SDB_IsFull(){
    if(SDB_GetUsedSize()==MAX_SIZE){
        return True;
    }
    else{
        return False;
    }
}

//This function adds Student to the SDB
bool SDB_AddEntry(){
    struct Node* pNode=createNode();
    //if dynamic memory allocation fails
    if(pNode==NULL){
            return False;
    }
    //if the SDB is full
    if (SDB_IsFull()){
        return False;
    }
    //if the SDB is empty
    if(pHead==NULL){
        pHead=pNode;
        pEnd=pNode;
    }
    //if the SDB has students but not full yet
    else{
        pEnd->pRight=pNode;
        pNode->pLeft=pEnd;
        pEnd=pNode;
    }
    count++;
    return True;


}


//This function delete a student from SDB by giving his id
void SDB_DeletEntry(uint32 id){

    struct Node* Temp=pHead;
    //if SDB contains one student
    if(SDB_GetUsedSize()==1 && Temp->data.Student_ID==id){
        pHead=NULL;
        pEnd=NULL;
        free(Temp);
        count--;
        return;
    }
    //if the student that will be deleted is the first one
    if(pHead->data.Student_ID==id){
        pHead=pHead->pRight;
        pHead->pLeft=NULL;
        free(Temp);
        count--;
        return;
    }
    //if the student that will be deleted is the last one
    if(pEnd->data.Student_ID==id){
        Temp=pEnd;
        pEnd=pEnd->pLeft;
        pEnd->pRight=NULL;
        free(Temp);
        count--;
        return;
    }
    //if the student that will be deleted is at the middle
    while(Temp!=NULL && Temp->data.Student_ID!=id){
            Temp=Temp->pRight;

    }
    if(Temp!=NULL){
        if(Temp->data.Student_ID==id){
           Temp->pLeft->pRight=Temp->pRight;
           Temp->pRight->pLeft=Temp->pLeft;
           free(Temp);
           count--;
           return;
        }
    }
    //if the student id does not exist
    printf("\nThis student ID does not exist in the database.\n");

}


//This function read student's data by giving student's id
bool SDB_ReadEntry(uint32 id){
    struct Node* Temp=pHead;
    //searching for a student with an id
    while(Temp!=NULL && Temp->data.Student_ID!=id){
        Temp=Temp->pRight;
    }
    //if id exist
    if(Temp!=NULL){
        if(Temp->data.Student_ID==id){
             printf("\nThe student ID is : %d",Temp->data.Student_ID);
             printf("\nThe student year is : %d",Temp->data.Student_year);
             printf("\nThe ID of the first course is : %d",Temp->data.Course1_ID);
             printf("\nThe grade of the first course is : %d",Temp->data.Course1_grade);
             printf("\nThe ID of the second course is : %d",Temp->data.Course2_ID);
             printf("\nThe grade of the second course is : %d",Temp->data.Course2_grade);
             printf("\nThe ID of the third course is : %d",Temp->data.Course3_ID);
             printf("\nThe grade of the third course is : %d\n\n",Temp->data.Course3_grade);
             return True;
        }
    }
    //if id does not exist
    else{
        return False;
    }
}

//This function check if student's id exist in the database by giving student's id
bool SDB_IsIdExist(uint32 id){
    struct Node* Temp=pHead;
    //searching for a student with an id
    while(Temp!=NULL && Temp->data.Student_ID!=id){
        Temp=Temp->pRight;
    }
    if(Temp!=NULL){
        if(Temp->data.Student_ID==id){
            return True;
        }
    }
    //if id does not exist
    else{
        return False;
    }
}


//This function display all ids that are in the database by giving the address of array and the number of students in SDB
void SDB_GetList(uint8*count,uint32*List){
    if(*count==0){
        printf("\nThe database is already empty.\n\n");
        return;
    }
    uint8 i;
    struct Node* Temp=pHead;
    for(i=0;i<*count;i++){
            List[i]=Temp->data.Student_ID;
            Temp=Temp->pRight;//at the last iteration Temp will be NULL

    }
    for(i=0;i<*count;i++){
        printf("\n%d",List[i]);
    }
    printf("\n\n");
}
