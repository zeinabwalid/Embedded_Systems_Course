#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"access_fun.h"
#include "math.h"



subj dataset[11];
int32_t counter =0;
int32_t options;

int32_t main(void)

{

    access("personal_data.csv");
     printf(" Our Dataset\n");
     printf("For more options, Please select a number from these numbers: \n");
     printf("1: Read Dataset\n");
     printf("2: Delete Person's Data from Dataset\n");
     printf("3: Add new person to Dataset\n");
     printf("4: Modify a person's data in Dataset without saving\n");
     printf("5: Find a person's data by his name in Dataset\n");
     printf("6: Find a person's data by his phone number in Dataset\n");

    scanf("%d", &options);
    printf("\n\n");
    if (options == 1)
    {

     read();

    }
    else if (options == 2)
    {

     delete_fun();
     read();

    }
    else if (options == 3)
    {
     subj new_p = {.ID= 0,.name={"zeinab"},.phone={"01234567891"},.email={"zeinab@gmail.com"}};
     printf("Add option.....\n");
    printf("Add Person Name: ");
    scanf("%s",new_p.name);
    printf("\n Add Person phone: ");
    scanf("%s",new_p.phone);
    printf("\n Add Person Email: ");
    scanf("%s",new_p.email);
    new_p.ID = counter-1;
    add_fun(new_p);

    }
    else if (options == 4)
    {

     modify_fun();
     read();

    }
    else if (options == 5)
    {

     find_byname_fun();


    }
     else if (options == 6)
    {

     find_byphone_fun();

    }


   return 0;
}
