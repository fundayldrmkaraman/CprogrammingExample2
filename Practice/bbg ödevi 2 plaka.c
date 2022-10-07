#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <ctype.h>

#include <conio.h>

//struct of plate information

typedef struct plateInfo

{

int plateCode;

char letters[100];

int number;

}

plateInfo;

//struct of city plates

typedef struct plates

{

int plateCount;

plateInfo *cityPlates;

}

plates;

int checkAlphabet(char *s)

{

int i,flag = 1;

for(i = 0; s[i] != '\0';i++)

{

if(!isalpha(s[i]))

{

flag = 0;

break;

}

}

return  flag;

}

int checkDigit(char *s)

{

int i,flag = 1;

for(i = 0; s[i] != '\0';i++)

{

if(!isdigit(s[i]))

{

flag = 0;

break;

}

}

return  flag;

}

plateInfo input()

{

plateInfo *p = (plateInfo*)calloc(1,(sizeof(plateInfo)));

    // I get the plate code

while(1)

{

//I'm checking whether it contains only the number of entries received

char temp[100];

printf("\nEnter Plate Code :\n");

scanf("%s",temp);

if(atoi(temp) !=0 && checkDigit(temp)) 

{

p->plateCode = atoi(temp);

if(p->plateCode <=81 && p->plateCode >=1) //between 1 and 81

break;

}

}

//I get the plate letters

while(1)

{

char temp[100];

puts("\nEnter Plate Letter :");

    scanf("%s",temp);

    if(checkAlphabet(temp))//if it contains only letters

    {

    strcpy(p->letters,temp);

if(strlen(p->letters) >= 2 && strlen(p->letters) <= 3 )//srtlen is between 2 and 3

{

strupr(p->letters); // upper string

break;

}

     	}

}

//I get the plate number

while(1)

{

char temp[100];

printf("\nEnter Plate Number :\n");

scanf("%s",temp);

if(atoi(temp) !=0 && checkDigit(temp)) //  the same logic with the plate code 

{

p->number = atoi(temp);

if(p->number <=9999 && p->number >=10) //between 10 and 9999

break; 

}

}

return *p;

}

int addPlate(plates *plates , plateInfo p)

{

int i,flag=1;

//initialization plate struct

if(plates[p.plateCode].plateCount == 0)

{

  plates[p.plateCode].cityPlates = (plateInfo*)calloc(1,(sizeof(plateInfo)));

plates[p.plateCode].cityPlates[0].plateCode = p.plateCode;

  strcpy(plates[p.plateCode].cityPlates[0].letters,p.letters);

  plates[p.plateCode].cityPlates[0].number = p.number;

plates[p.plateCode].plateCount++;

  plates[0].plateCount++;

  return flag;

}

//check same plate control

for(i=0; i < plates[p.plateCode].plateCount;i++)

  {

  if(plates[p.plateCode].cityPlates[i].plateCode == p.plateCode && 

strcmp(plates[p.plateCode].cityPlates[i].letters,p.letters) == 0 &&

  plates[p.plateCode].cityPlates[i].number == p.number)

  {

  flag =0;

  break;

}

  }

    //add new plate

if(flag)

{

plates[p.plateCode].cityPlates = (plateInfo*)realloc(plates[p.plateCode].cityPlates,sizeof(plateInfo)*1);

plates[p.plateCode].cityPlates[plates[p.plateCode].plateCount].plateCode =p.plateCode; 

strcpy(plates[p.plateCode].cityPlates[plates[p.plateCode].plateCount].letters , p.letters); 

plates[p.plateCode].cityPlates[plates[p.plateCode].plateCount].number = p.number;

plates[p.plateCode].plateCount++;

  plates[0].plateCount++;

      return flag;

}

return flag;

}

void display(plates *plates)

{

int i,j;

printf("\n----------------------------------\n");

printf("\nTotal plate count : %d\n",plates[0].plateCount);

printf("\n----------------------------------\n");

for(i = 1; i< 82;i++)

{

if(plates[i].plateCount == 0)continue;

printf("\n----------------------------------\n");

printf("The total number of units from %d plates : %d",i,plates[i].plateCount);

 	for(j = 0; j < plates[i].plateCount;j++)

{

printf("\n%d %s %d",plates[i].cityPlates[j].plateCode,plates[i].cityPlates[j].letters,plates[i].cityPlates[j].number);

}

printf("\n----------------------------------\n");

}

}

main()

{

    plates *plates = (plateInfo*)calloc(82,(sizeof(plateInfo))); // between 1 and 82

    int choice;

    while(1)

{

printf("\nChoose option :\n1 - Add Plate\n2 - List of plates by cities\n3 - Clean Screen\n0 - Exit\n");

scanf("%d",&choice);

switch(choice)

{

case 1 : {

plateInfo p = input();

if(addPlate(plates,p))

printf("\nSuccesful insertion :)\n");

else

printf("\nFails to Add :(\n");

break;

}

case 2:{

display(plates);

break;

}

case 3:{

system("cls");

break;

}

case 0:{

return 0;

}

default:{

printf("\nInvalid value\n");

break;

}

}

}

}
