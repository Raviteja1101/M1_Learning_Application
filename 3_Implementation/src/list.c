#include <stdio.h> 
#include <stdlib.h>
#include <conio.h>
#include <windows.h> 
#include <string.h>  

COORD b = {1,0};

void a(int x,int y)
{
    b.X = x;
    b.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),b);
}

int main()   ///main function
{
    FILE *fp, *ft;  /// file open and close
    char another;
	char choice;
  
    struct emp
    {
        char name[40];  ///name of the employee
        int DOB;       /// date of birth of employee
        int age;     /// age of the employee
		char ms[40];   
		char qualification[40];  
		char employement[40];    
        float bs;        /// basic salary of employee
    };

    struct emp e; 
    char employeename[40]; 
    long int resize; 
    fp = fopen("EMP.DAT","rb+");  
    if(fp == NULL)  
    {
        fp = fopen("EMP.DAT","wb+"); 
        if(fp == NULL)
        {
            printf("Connot open file"); 
            exit(1);
        }
    }

    resize = sizeof(e);
    while(1)
    {
        system("cls"); 
        a(20,5);
        printf("2. show Records"); /// listing record
        a(20,9);
        printf("Your Choice: "); /// entering our choice
        fflush(stdin); 
        choice = getchar(); 
        switch(choice)
        {
            case '2':
        
            system("cls");
            rewind(fp); 
            while(fread(&e,resize,1,fp)==1)  
            {
                printf("\n%s %d %d %s %s %s %.2f",e.name,e.DOB,e.age,e.ms,e.qualification,e.employement,e.bs); 
            }
            getch();
            break;
        }
    }

    return 0;
}