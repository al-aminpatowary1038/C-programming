#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

#define Enter 13
#define Tab 9
#define Backsp 8

FILE *file; // File for Store User Information;
FILE *Sfile; // File for store Student Information;

// User Define Data type for User;
 struct user{
    char fname[50];
    char email[50];
    char pass[50];
    char usname[50];
    char phone[50];
};
struct user User;

//User Define Data type for Student Course Information;
struct Course{
    char courname [50];
    char courCode[6];
};
struct Course courInfo[8];


//User Define Data type for Student Information;
struct student{
    char Sname [50];
    char Semail [50];
    char Sid [15];
    char Sphone [16];
    char Semester[15];
    int courseNum;
    struct Course courInfo[8];
};
struct student stuInfo;



//User Define Function For Generate username
void g_username(char email[50], char userName[50]){

    for(int i=0; i<strlen(email);i++){
        if(email[i]== '@'){
            userName[i] = '\0';
            break;
        }
        else{
            userName[i] = email[i];
        }
    }
}

// User Define Function For Hiding Password;
void pswd(char password2[50]){
    char ch;
    int i;
    while(1){
        ch = getch();
        if (ch == Enter || ch == Tab){
            password2 [i]= '\0';
            break;
        }

        else if(ch== Backsp){
                if(i>0){
                    i--;
                    printf("\b \b");
                }
        }
        else{
            password2[i++] = ch;
            printf("*");
        }
    }
}
// Registration System;
void Regi(){
    char password2[50];
    int NF =0,Co=0,Ps=0,flag=0;
    system("cls");
    printf("\t\t\t\t****Welcome To Registration Functionality****\n");
    while(NF==0)
    {
        printf("Enter your Full Name: \t");
        fgets(User.fname,50,stdin);
        for(int i=0; i<strlen(User.fname); i++)
        {
            if(User.fname[i]>= 'A' && User.fname [i]<= 'Z' || User.fname[i]>= 'a' && User.fname [i]<= 'z')
            {
                NF = 1;
                break;
            }
        }
        if(NF==1)
        {
            while(Co==0)
            {
                printf("Enter your Contact No: \t");
                fgets(User.phone,50,stdin);
                for(int i=0; i<strlen(User.phone); i++)
                {
                    if(User.phone[i]>= '0' && User.phone [i]<= '9')
                    {
                         Co=1;
                        break;

                    }
                }
                if(Co==1)
                {
                    while(flag ==0)
                    {
                        printf("Enter your Email Id: \t");
                        fgets(User.email,50,stdin);
                        for(int i=0; i<strlen(User.email); i++)
                        {
                            if(User.email[i]== '@')
                            {
                                flag =1;
                                break;
                            }
                        }
                        if(flag==1)
                        {

                            printf("Enter your Password: \t");
                            pswd(User.pass);
                            printf("\nConfirm Your Password: \t");
                            pswd(password2);
                        }
                        else
                        {
                            printf("Please Enter  a Valid Email Id\n");
                        }
                    }
                }
                else{
                    printf("Enter a Valid Number\n");
                }
            }
        }
        else
        {
            printf("Please Enter  a Valid Name\n");
        }
    }


    if(strcmp(User.pass,password2)==1){
        printf("\nYour Password Don't Match\n");
    }
    else{
        g_username(User.email, User.usname);
          file = fopen("UserInfo.txt","a+");
          if(file == NULL){
            printf("\nSorry! Something went wrong while opening the file\n");
            return ;
          }
           if(fwrite(&User, sizeof(struct user),1,file)){
            printf("\nYour Registration is Successfully Completed");
            printf("\nYour User name is : \t%s",User.usname);
          }
          else{
                printf("\nSorry!! Something went wrong\n");
          }
          fclose(file);
    }
    Gomain();
}
// Login System;
void Login()
{
    system("cls");
    char username[50],pword[50];
    int usrfound =0;
    printf("\t\t\t\t------Hey!! Welcome To Login Functionality ------\n");
    printf("\nEnter Your Username:\t");
    fgets(username,50,stdin);
    username[strcspn(username, "\n")] = 0;
    printf("Enter Your Password:\t");
    pswd(pword);
    system("cls");
    file =fopen("UserInfo.txt","r");
    if (file == NULL)
    {
        printf("\nSorry!! Something went wrong while opening the file\n");
        return;
        }
        while(fread(&User,sizeof(struct user),1,file))
        {
            if(strcmp(User.usname,username)==0)
            {
                if(strcmp(User.pass,pword)==0)
                {
                    printf("\n\t\t\tWelcome %s\n\n",User.fname);
                   Functions();
                }
                else
                {
                    printf("\nInvalid Password!!\n");
                }
                usrfound = 1;
                break;
            }
        }
        if(!usrfound)
        {
            printf("\nUser is not Found\n");
        }
        fclose(file);
    }

//
void Functions()
{
    system("cls");
        Menu();
        int F;
        scanf("%d",&F);
        getchar();
        switch(F)
        {
        case 0:
            ExitProgram();
            break;
        case 1:
            Addstudent();
             GoBack();
            break;
        case 2:
            ShowAll();
             GoBack();
            break;
        case 3:
            Search_A_stu();
             GoBack();
            break;
        case 4:
            Edit_student();
             GoBack();
            break;
        case 5:
            DeleteStu();
             GoBack();
            break;
        case 6:
            DeleteAll();
             GoBack();
            break;
        case 7:
            system ("cls");
             GoBack();
            break;
        case 8:
            UserGuid();
             GoBack();
            break;
        case 9:
            About();
             GoBack();
            break;
        default :
            printf("\nWrong Choice\n");
        }
    }

// Main Menu
void Menu(){

    printf("\n\n\t~~~Student Database Management System~~~\n\n");
    printf("\t\t\tMAIN MENU\n");
    printf("\t\t=======================\n");
    printf("\t\t[1] Add A New student.\n");
    printf("\t\t[2] Show All students.\n");
    printf("\t\t[3] Search A student.\n");
    printf("\t\t[4] Edit A student.\n");
    printf("\t\t[5] Delete A student.\n");
    printf("\t\t[6] Delete All students.\n");
    printf("\t\t[7] Clear The window.\n");
    printf("\t\t[8] User Guideline.\n");
    printf("\t\t[9] About Us.\n");
    printf("\t\t[0] Exit the Program.\n");
    printf("\t\t=======================\n");
    printf("\nChoice a Functionality: ");

}

void Addstudent()
{
    int sn=0,id=0,em=0,sp=0;
    system("cls");
    Sfile = fopen("Studentinfo.txt","a");
    if(Sfile==NULL)
    {
        printf("Error Opening!\n");
        return;
    }
    while(sn==0)
    {
        printf("\nEnter Student Name: \t");
        fgets(stuInfo.Sname,50,stdin);
        stuInfo.Sname[strcspn(stuInfo.Sname,"\n")] = 0;
        for(int i=0; i<strlen(stuInfo.Sname); i++)
        {
            if(stuInfo.Sname[i]>= 'A' && stuInfo.Sname [i]<= 'Z' || stuInfo.Sname[i]>= 'a' && stuInfo.Sname [i]<= 'z' || stuInfo.Sname[i] == ' ')
            {
                sn=1;
                break;
            }
        }

        if(sn==1)
        {
            while(id==0)
            {
                printf("\tEnter Student Id: ");
                fgets(stuInfo.Sid,15,stdin);
                stuInfo.Sid[strcspn(stuInfo.Sid,"\n")] = 0;
                for(int i=0; i<strlen(stuInfo.Sid); i++)
                {
                    if(stuInfo.Sid[i]>= '0' && stuInfo.Sid[i] <= '9')
                    {
                        id=1;
                        break;
                    }
                }
                if(id == 1)
                {
                    while(em==0)
                    {
                        printf("\tEnter Student Email Id: ");
                        fgets(stuInfo.Semail,50,stdin);
                        stuInfo.Semail[strcspn(stuInfo.Semail,"\n")] = 0;
                        for(int i=0; i<strlen(stuInfo.Semail); i++)
                        {
                            if(stuInfo.Semail[i] == '@')
                            {
                                em=1;
                                break;
                            }
                        }

                        if(em == 1)
                        {
                            while(sp==0)
                            {
                                printf("\tEnter Student Contract No: ");
                                fgets(stuInfo.Sphone,16,stdin);
                                stuInfo.Sphone[strcspn(stuInfo.Sphone,"\n")] = 0;
                                for(int i=0; i<strlen(stuInfo.Sphone); i++)
                                {
                                    if(stuInfo.Sphone[i]>='0' && stuInfo.Sphone[i]<= '9')
                                    {
                                        sp=1;
                                        break;
                                    }
                                }
                                if(sp==1)
                                {
                                    printf("\tEnter Semester: ");
                                    fgets(stuInfo.Semester,15,stdin);
                                    stuInfo.Semester[strcspn(stuInfo.Semester,"\n")] = 0;

                                    printf("\nEnter Number of Course: ");
                                    scanf("%d",&stuInfo.courseNum);
                                    getchar();
                                    for(int i =0; i<stuInfo.courseNum; i++)
                                    {
                                        printf("\tEnter Course name %d: ",i+1);
                                        fgets(stuInfo.courInfo[i].courname, sizeof(stuInfo.courInfo[i].courname),stdin);
                                        printf("\tEnter Course Code %d: ",i+1);

                                        fgets(stuInfo.courInfo[i].courCode, sizeof(stuInfo.courInfo[i].courCode),stdin);
                                    }
                                    if(fwrite(&stuInfo, sizeof(struct student), 1, Sfile) != 1){
                                        printf("Something went Wrong!\n");
                                    }
                                    fclose(Sfile);
                                    printf("\nStudent Added Successfully!\n");
                                }
                                else
                                {
                                    printf("\nEnter a Valid Contract Number!");
                                }
                            }
                        }
                        else
                        {
                            printf("\nEnter a Valid Email Id!");
                        }
                    }
                }
                else
                {
                    printf("\nEnter a Valid Student Id!");
                }
            }
        }
        else
        {
            printf("\nEnter a Valid Name");
        }
    }
    GoBack();
}



void ShowAll() {
    system("cls");
    Sfile = fopen("Studentinfo.txt", "r");
    if (Sfile == NULL) {
        printf("\tSomething Went Wrong!\n");
        return;
    }
    printf("\n\t\t\t\t\tAll Student List\n\n");
    printf("|============|======================|==============================|==================|============|=============|\n");
    printf("|     ID     |         NAME         |            EMAIL             |       PHONE      |  Semester  |   NO.COURSE |\n");
    printf("|============|======================|==============================|==================|============|=============|\n");

    while (fread(&stuInfo, sizeof(struct student), 1, Sfile)) {
        printf("| %s", stuInfo.Sid);
        for (int i = 0; i < 11 - strlen(stuInfo.Sid); i++) {
            printf(" ");
        }
        printf("| %s", stuInfo.Sname);
        for (int i = 0; i < 21 - strlen(stuInfo.Sname); i++) {
            printf(" ");
        }
        printf("| %s", stuInfo.Semail);
        for (int i = 0; i < 29 - strlen(stuInfo.Semail); i++) {
            printf(" ");
        }
        printf("| %s", stuInfo.Sphone);
        for (int i = 0; i < 17 - strlen(stuInfo.Sphone); i++) {
            printf(" ");
        }
        printf("| %s", stuInfo.Semester);
        for (int i = 0; i < 11 - strlen(stuInfo.Semester); i++) {
            printf(" ");
        }
        printf("| %d", stuInfo.courseNum);
        for (int i = 0; i < 12 - snprintf(NULL, 0, "%d", stuInfo.courseNum); i++) {
            printf(" ");
        }
        printf("|\n");
        printf("|============|======================|==============================|==================|============|=============|\n");
    }
    fclose(Sfile);
}

void Search_A_stu(){

    char Id [15];
    int fo =0;
    system("cls");
  Sfile = fopen("Studentinfo.txt","r");
  if(Sfile == NULL){
    printf("Something Went Wrong");
  }
  printf("Enter Student Id: ");
  fgets(Id,10,stdin);
  Id[strcspn(Id,"\n")] = 0;

  while(fread(&stuInfo, sizeof(struct student),1,Sfile)){

    if(strcmp(stuInfo.Sid , Id)==0){
        printf("\nStudent Name:     %s",stuInfo.Sname);
        printf("\nStudent ID:       %s",stuInfo.Sid);
        printf("\nStudent Email:    %s",stuInfo.Semail);
        printf("\nStudent Phone NO: %s",stuInfo.Sphone);
        printf("\nSemester:         %s\n",stuInfo.Semester);
        printf("Number Of Courses:  %d\n",stuInfo.courseNum);
        for(int i=0;i<stuInfo.courseNum;i++){

            printf("Course %d Name:\t%s",i+1,stuInfo.courInfo[i].courname);
            printf("Course %d Code:\t%s",i+1,stuInfo.courInfo[i].courCode);
        }
        fo = 1;
        break;
    }
  }
  if(fo==0){
    printf("Student Not Found!\n");
  }
  fclose(Sfile);

}

void Edit_student(){
    system("cls");
    printf("")
}


void DeleteStu(){
}

void DeleteAll(){
}

void UserGuid(){
    system("cls");
    printf("\n\t\t\tHow To Work Our System\n\n");
    printf("\t=> You Will Able to Store Student Data, Like: Student Name,ID,Email,Phone,Course Information\n");
    printf("\t=> Student Name can be 50 characters long\n");
    printf("\t=> Student Id can be unique for every student and Maximum 15 Characters long\n");
    printf("\t=> Every student have unique email id and email id can be maximum 50 characters long\n");
    printf("\t=> Course Name can be 15 character long\n");
    printf("\t=> Course Code can be 6 character long\n ");
    printf("\t=> Student can have maximum 8 courses and minimum 1 course\n");
    printf("\t=> Phone Number should be 16 character long\n");
}

void About(){
    system("cls");
    printf("\n\t\t\t~~~~~ About Us ~~~~~\n\n");
    printf("\tThis Is a simple Student Database Management System\n");
    printf("\tTeam WXYZ developed this system for their course output\n");
    printf("\tOur course name is Software Development Capstone Project\n");
    printf("\tWe are students of Software Engineering Department\n");
}


void Gofunc(){
    getchar();
    system("cls");
    Functions();
}

void GoBack(){
    getchar();
    char a;
    printf("\n\nFor Go Back Press [B]");
    printf("\t\tFor Go Back To Home Page Press [H]\t\t");
    printf("For Exit This System Press [0]\n");
    printf("Enter Your choice: ");
    scanf("%c",&a);
    getchar();
    if(a== 'H' || a== 'h'){
    system("cls");
        main();
    }
    else if(a=='B' || a=='b'){
         Functions();
    }
    else{
        ExitProgram();
    }
}

void Gomain(){
    getchar();
    char mm;
    printf("\n\nFor Go Back To Home Page Press [H]\t\t");
    printf("For Exit This System Press [0]\n");
    printf("Enter Your choice: ");
    scanf("%c",&mm);
    getchar();
    if(mm == 'H' || mm == 'h'){
    system("cls");
       main();
    }
    else{
        ExitProgram();

    }
}

void ExitProgram(){
    system("cls");
    char mas[10000]= "~~~~~~Thanks For visiting us~~~~~~";
    printf("\n\n\t\t\t");
    for(int i=0;i<strlen(mas);i++)
    {
        printf("%c",mas[i]);
    }
    printf("\n\n\n");
    exit(0);
}


int main(){

    system("color B0");
    int a;
    printf("\t\t\t\t------ Welcome to Student Database System ------");
    printf("\n\n\tPlease Choose Your Option");
    printf("\n\t1. Signup");
    printf("\n\t2. Login");
    printf("\n\t3. Exit");
    printf("\n\nEnter Your Choice: ");
    scanf("%d",&a);
    getchar();
    switch(a){
    case 1:
        Regi();
        break;
    case 2:
       Login();
        break;
    case 3:
       ExitProgram();
        break;
        default : {
        printf("\nWrong Choice!");
        }
     }
    getchar();
}
