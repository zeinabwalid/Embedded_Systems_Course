#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"access_fun.h"
#include "math.h"

extern subj dataset[11];
extern counter;



void access(char* file_name)
{   int i = 0;
    int j = 0;
    char *token;
    FILE *fp;
    char person[50];

   fp = fopen(file_name,"r");
   while(1) {
      if( feof(fp) ) {
         break ;
      }
      fgets(person, 50, fp);
      token = strtok(person, ",");
       counter ++;

        while(token != NULL)
        {
            if(i == 0){
            dataset[j].ID = token;
          }
          else if (i == 1){
            strcpy(dataset[j].name,token);
          }
          else if (i == 2){
            strcpy(dataset[j].phone,token);
          }
          else if (i == 3){
            strcpy(dataset[j].email,token);
          }
          i++;
          if(i == 4){
            i = 0;
            j++;
          }
            token = strtok(NULL, ",");
        }
   }
   fclose(fp);

}

void read(){
     unsigned int k;
     printf("Read option.....\n");
     for(k=1;k<counter-1;k++){
       printf("ID:%s\n",dataset[k].ID);
       printf("Name:%s\n",dataset[k].name);
       printf("Phone Number:%s\n",dataset[k].phone);
       printf("Email:%s\n",dataset[k].email);
     }
}

void delete_fun(){
    int i;
    int order;
    char deleted_name[10];
    printf("Delete option.....\n");
    printf("Type name to be deleted: ");
    scanf("%s",&deleted_name);
    for (i=0;i<=counter -1; i++){
        if (!(strcmp(dataset[i].name,deleted_name))){
                printf("Client %s is deleted \n\n",dataset[i].name);
                order =i;
                for(i=order;i<=counter-1;i++)
                {
                    dataset[i]=dataset[i+1];
                    dataset[i].ID = dataset[i].ID-1;
                }
            }
    }
    counter--;
}

void add_fun (subj new_person){

    dataset[counter -1]= new_person;
    printf("\n\n %s is added to Dataset \n",dataset[counter-1].name);
    printf("\n Name: %s\n Phone: %s\n Email: %s\n\n",dataset[counter-1].name,dataset[counter-1].phone,dataset[counter-1].email);
    counter++;


}

void modify_fun(){
        char modified_name[10];
        int i;
    printf("Modify option.....\n");
    printf("Type name to be modified: ");
    scanf("%s",&modified_name);
    for (i=0;i<=counter -1; i++){
            if (!(strcmp(dataset[i].name,modified_name))){
                    printf("This is the selected person name: %s\n",dataset[i].name);
                    printf("Phone: %s\n",dataset[i].phone);
                    printf("Email: %s\n",dataset[i].email);
                    printf("Please Enter the new data\n");
                    printf("New Name: ");
                    scanf("%s",&dataset[i].name);
                    printf("\n");
                    printf("New Phone: ");
                    scanf("%s",&dataset[i].phone);
                    printf("\n");
                    printf("New Email: ");
                    scanf("%s",&dataset[i].email);
            }

    }
}

void find_byname_fun(){
    char find_byname[10];
    int i;
    printf("Find By Name option.....\n");
    printf("Type needed name: ");
    scanf("%s",&find_byname);
    for (i=0;i<=counter -1; i++){
            if (!(strcmp(dataset[i].name,find_byname))){
                printf("Needed Person %s and his data: \n",dataset[i].name);
                printf("Phone: %s\n",dataset[i].phone);
                printf("Email: %s\n",dataset[i].email);

            }
            }
               printf("Not Found, please try again");
}

void find_byphone_fun(){
    char find_byphone[10];
    int i;
    printf("Find By Phone option.....\n");
    printf("Type needed Phone Number: ");
    scanf("%s",&find_byphone);
    for (i=0;i<=counter -1; i++){
            if (!(strcmp(dataset[i].phone,find_byphone))){
                printf("Detected Phone Number %s and other data: \n",dataset[i].phone);
                printf("Name: %s\n",dataset[i].name);
                printf("Email: %s\n",dataset[i].email);

            }


            }
                 printf("Not Found,Please try again");
}










