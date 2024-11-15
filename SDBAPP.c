#include <stdio.h>
#include <stdlib.h>
#include "SDB.h"
#include "SDBAPP.h"

//This function is used to display options to user then takes his choice to call the function responsible for achieving his choice
void SDB_APP(){
    uint8 choice;
    while(!start){
            printf("\t____________________________________________\n\n");
        printf("To add entry, enter 1\n");
        printf("To get used size in database, enter 2\n");
        printf("To read student data, enter 3\n");
        printf("To get the list of all student IDs, enter 4\n");
        printf("To check is ID is existed, enter 5\n");
        printf("To delete student data, enter 6\n");
        printf("To check if the database is full, enter 7\n");
        printf("To exit enter 0\n");
        printf("\nWhat is your choice : ");
        scanf("%d",&choice);
           printf("\n\t____________________________________________\n\n");
        SDB_action (choice);
    }
}

void SDB_action (uint8 choice){


    switch(choice){
    case 1:

        checker=SDB_AddEntry();
        if(checker==1){
            printf("\nThe data is added successfully.\n\n");
        }
        else{
            printf("\nThe data is not added to your database.\n");
        }
        break;

    case 2:

        printf("\nThe number of students in the database %d\n\n",SDB_GetUsedSize());
        break;

    case 3:

        if(pHead==NULL){
            printf("\nThe database is already empty.\n\n");
            break;
        }
        printf("Please Enter the student ID : ");
        scanf("%d",&id);
        checker=SDB_ReadEntry(id);
        if(checker==0){
            printf("\nThis ID is not in your database.\n\n");
        }
        break;

    case 4:

        count = SDB_GetUsedSize();
        SDB_GetList(&count,List);
        break;

    case 5:

        if(pHead==NULL){
            printf("\nThe database is already empty.\n\n");
            break;
        }
        printf("Please Enter the student ID : ");
        scanf("%d",&id);
        checker=SDB_IsIdExist(id);
        if(checker==1){
            printf("\nThe ID is exist.\n\n");
        }
        else{
            printf("\nThe ID is not found.\n\n");
        }
        break;

    case 6:

        if(pHead==NULL){
            printf("\nThe database is already empty.\n\n");
            break;
        }
        printf("Please Enter the student ID : ");
        scanf("%d",&id);
        SDB_DeletEntry(id);
        break;

    case 7:

        if(SDB_IsFull()){
            printf("\nThe database is full.\n\n");
        }
        else{
            printf("\nThe database is not full.\n\n");
        }
        break;

    default:
        if(SDB_GetUsedSize()<3){
            start=0;
            printf("\nYou can not exist as the database must contain at least 3 students.\n\n");
        }
        else{
            start=1;
        }

        break;

    }
}
