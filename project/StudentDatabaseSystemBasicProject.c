#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define Enter 13
#define Tab 9
#define Backsp 8

FILE *file;
FILE *Sfile;
FILE *tempFile;
FILE *stufile;

// User Define Data type for faculty User;
struct user {
    char fname[50];
    char email[50];
    char pass[50];
    char usname[50];
    char phone[50];
};
struct user User;

//user define data type Student user
struct suser {
    char sname[50];
    char semail[50];
    char spass[50];
    char susname[50];
    char sphone[50];
};
struct suser sUser;

// User Define Data type for Student Course Information;
struct Course {
    char courname[50];
    char courCode[6];
};
struct Course courInfo[8];

// User Define Data type for Student Information;
struct student {
    char Sname[50];
    char Semail[50];
    char Sid[15];
    char Sphone[16];
    char Semester[15];
    int courseNum;
    struct Course courInfo[8];
};
struct student stuInfo;

// User Define Function For Generate username
void g_username(char email[50], char userName[50]) {
    for (int i = 0; i < strlen(email); i++) {
        if (email[i] == '@') {
            userName[i] = '\0';
            break;
        } else {
            userName[i] = email[i];
        }
    }
}

// User Define Function For Hiding Password;
void pswd(char password2[50]) {
    char ch;
    int i = 0; // Initialize i
    while (1) {
        ch = getch();
        if (ch == Enter || ch == Tab) {
            password2[i] = '\0';
            break;
        } else if (ch == Backsp) {
            if (i > 0) {
                i--;
                printf("\b \b");
            }
        } else {
            password2[i++] = ch;
            printf("*");
        }
    }
}

// faculty Registration System;
void Regi() {
    char password2[50];
    int NF = 0, Co = 0, Ps = 0, flag = 0;
    system("cls");
    printf("\t\t\t\t****Welcome To Registration Functionality****\n");
    printf("\t\t\t|================================================================|\n\n");
    while (NF == 0) {
        printf("Enter your Full Name: \t");
        fgets(User.fname, 50, stdin);
        User.fname[strcspn(User.fname, "\n")] = 0; // Remove newline character
        for (int i = 0; i < strlen(User.fname); i++) {
            if ((User.fname[i] >= 'A' && User.fname[i] <= 'Z') || (User.fname[i] >= 'a' && User.fname[i] <= 'z')) {
                NF = 1;
                break;
            }
        }
        if (NF == 1) {
            while (Co == 0) {
                printf("Enter your Contact No: \t");
                fgets(User.phone, 50, stdin);
                User.phone[strcspn(User.phone, "\n")] = 0; // Remove newline character
                for (int i = 0; i < strlen(User.phone); i++) {
                    if (User.phone[i] >= '0' && User.phone[i] <= '9') {
                        Co = 1;
                        break;
                    }
                }
                if (Co == 1) {
                    while (flag == 0) {
                        printf("Enter your Email Id: \t");
                        fgets(User.email, 50, stdin);
                        User.email[strcspn(User.email, "\n")] = 0; // Remove newline character
                        for (int i = 0; i < strlen(User.email); i++) {
                            if (User.email[i] == '@') {
                                flag = 1;
                                break;
                            }
                        }
                        if (flag == 1) {
                            printf("Enter your Password: \t");
                            pswd(User.pass);
                            printf("\nConfirm Your Password: \t");
                            pswd(password2);
                        } else {
                            printf("Please Enter a Valid Email Id\n");
                        }
                    }
                } else {
                    printf("Enter a Valid Number\n");
                }
            }
        } else {
            printf("Please Enter a Valid Name\n");
        }
    }

    if (strcmp(User.pass, password2) != 0) { // Use != 0 for mismatch
        printf("\nYour Password Don't Match\n");
    } else {
        g_username(User.email, User.usname);
        file = fopen("UserInfo.txt", "a+");
        if (file == NULL) {
            printf("\nSorry! Something went wrong while opening the file\n");
            return;
        }
        if (fwrite(&User, sizeof(struct user), 1, file)) {
            printf("\nYour Registration is Successfully Completed");
            printf("\nYour User name is : \t%s", User.usname);
        } else {
            printf("\nSorry!! Something went wrong\n");
        }
        fclose(file);
    }
    Gomain();
}

// faculty Login System;
void Login() {
    system("cls");
    
    char username[50], pword[50];
    int usrfound = 0;
    printf("\t\t\t\t------Hey!! Welcome To Login Functionality ------\n");
    printf("\t\t\t|================================================================|\n\n");
    printf("\nEnter Your Username:\t");
    fgets(username, 50, stdin);
    username[strcspn(username, "\n")] = 0;
    printf("Enter Your Password:\t");
    pswd(pword);
    system("cls");
    file = fopen("UserInfo.txt", "r");
    if (file == NULL) {
        printf("\nSorry!! Something went wrong while opening the file\n");
        return;
    }
    while (fread(&User, sizeof(struct user), 1, file)) {
        if (strcmp(User.usname, username) == 0) {
            if (strcmp(User.pass, pword) == 0) {
                printf("\n\t\t\tWelcome %s\n\n", User.fname);
                Functions();
            } else {
                printf("\nInvalid Password!!\n");
            }
            usrfound = 1;
            break;
        }
    }
    if (!usrfound) {
        printf("\nUser is not Found\n");
    }
    fclose(file);
}

void Functions() {
    system("cls");
    Menu();
    int F;
    scanf("%d", &F);
    getchar(); // Clear newline after scanf
    switch (F) {
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
            deleteAllStudents();
            GoBack();
            break;
        case 7:
            system("cls");
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
        default:
            printf("\nWrong Choice\n");
    }
}

// Main Menu
void Menu() {
    printf("\n\n\t\t\t~~~Student Database Management System~~~\n\n");
         printf("\t|================================================================|\n\n");
    printf("\t\t\tMAIN MENU\n");
    printf("\t\t=======================\n");
    printf("\t\t[1] Add A New Student.\n");
    printf("\t\t[2] Show All Students.\n");
    printf("\t\t[3] Search A Student.\n");
    printf("\t\t[4] Edit A Student.\n");
    printf("\t\t[5] Delete A Student.\n");
    printf("\t\t[6] Delete All Data.\n");
    printf("\t\t[7] Clear The window.\n");
    printf("\t\t[8] User Guideline.\n");
    printf("\t\t[9] About Us.\n");
    printf("\t\t[0] Logout.\n");
    printf("\t\t=======================\n");
    printf("\nChoice a Functionality: ");
}


//Add Student In data base
void Addstudent() {
    int sn = 0, id = 0, em = 0, sp = 0;
    system("cls");
    printf("\n\t\t\t\t\t\tStudent ADD Functionality \n");
    printf("\t\t\t|================================================================|\n\n");
    Sfile = fopen("infgo.txt", "a");
    if (Sfile == NULL) {
        printf("Error Opening!\n");
        return;
    }
    while (sn == 0) {
        printf("\n\tEnter Student Name: \t");
        fgets(stuInfo.Sname, 50, stdin);
        stuInfo.Sname[strcspn(stuInfo.Sname, "\n")] = 0;
        for (int i = 0; i < strlen(stuInfo.Sname); i++) {
            if (stuInfo.Sname[i] >= 'A' && stuInfo.Sname[i] <= 'Z' || stuInfo.Sname[i] >= 'a' && stuInfo.Sname[i] <= 'z' || stuInfo.Sname[i] == ' ') {
                sn = 1;
                break;
            }
        }

        if (sn == 1) {
            while (id == 0) {
                printf("\tEnter Student Id:\t");
                fgets(stuInfo.Sid, 15, stdin);
                stuInfo.Sid[strcspn(stuInfo.Sid, "\n")] = 0;
                for (int i = 0; i < strlen(stuInfo.Sid); i++) {
                    if (stuInfo.Sid[i] >= '0' && stuInfo.Sid[i] <= '9') {
                        id = 1;
                        break;
                    }
                }
                if (id == 1) {
                    while (em == 0) {
                        printf("\tEnter Student Email Id:\t");
                        fgets(stuInfo.Semail, 50, stdin);
                        stuInfo.Semail[strcspn(stuInfo.Semail, "\n")] = 0;
                        for (int i = 0; i < strlen(stuInfo.Semail); i++) {
                            if (stuInfo.Semail[i] == '@') {
                                em = 1;
                                break;
                            }
                        }

                        if (em == 1) {
                            while (sp == 0) {
                                printf("\tEnter Student Contract No:\t");
                                fgets(stuInfo.Sphone, 16, stdin);
                                stuInfo.Sphone[strcspn(stuInfo.Sphone, "\n")] = 0;
                                for (int i = 0; i < strlen(stuInfo.Sphone); i++) {
                                    if (stuInfo.Sphone[i] >= '0' && stuInfo.Sphone[i] <= '9') {
                                        sp = 1;
                                        break;
                                    }
                                }
                                if (sp == 1) {
                                    printf("\tEnter Semester:\t");
                                    fgets(stuInfo.Semester, 15, stdin);
                                    stuInfo.Semester[strcspn(stuInfo.Semester, "\n")] = 0;

                                    printf("\n\tEnter Number of Courses:\t");
                                    scanf("%d", &stuInfo.courseNum);
                                    getchar();
                                    for (int i = 0; i < stuInfo.courseNum; i++) {
                                        printf("\tEnter Course name %d:\t", i + 1);
                                        fgets(stuInfo.courInfo[i].courname, sizeof(stuInfo.courInfo[i].courname), stdin);
                                        stuInfo.courInfo[i].courname[strcspn(stuInfo.courInfo[i].courname, "\n")] = 0;
                                        printf("\tEnter Course Code %d: ", i + 1);
                                        fgets(stuInfo.courInfo[i].courCode, sizeof(stuInfo.courInfo[i].courCode), stdin);
                                        stuInfo.courInfo[i].courCode[strcspn(stuInfo.courInfo[i].courCode, "\n")] = 0;
                                    }
                                    if (fwrite(&stuInfo, sizeof(struct student), 1, Sfile) != 1) {
                                        printf("Something went Wrong!\n");
                                    } else {
                                        printf("\nStudent Added Successfully!\n");
                                    }
                                    fclose(Sfile);
                                } else {
                                    printf("\nEnter a Valid Contract Number!");
                                }
                            }
                        } else {
                            printf("\nEnter a Valid Email Id!");
                        }
                    }
                } else {
                    printf("\nEnter a Valid Student Id!");
                }
            }
        } else {
            printf("\nEnter a Valid Name");
        }
    }
    GoBack();
}

// Student Search Function;
void Search_A_stu() {
    system("cls");
    printf("\n\t\t\t\t\t\t Searching Functionality\n ");
         printf("\t\t\t|================================================================|\n\n");
    char searchId[10];
    int found = 0, fo = 0;

   Sfile = fopen("infgo.txt", "r");

    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter ID to search: ");
    fgets(searchId, sizeof(searchId), stdin);
    searchId[strcspn(searchId, "\n")] = 0; // Remove newline character

    while (fread(&stuInfo, sizeof(struct student), 1, file)) {
        if(strcmp(stuInfo.Sid , searchId)==0){
        printf("\nStudent Name:     %s",stuInfo.Sname);
        printf("\nStudent ID:       %s",stuInfo.Sid);
        printf("\nStudent Email:    %s",stuInfo.Semail);
        printf("\nStudent Phone NO: %s",stuInfo.Sphone);
        printf("\nSemester:         %s\n",stuInfo.Semester);
        printf("Number Of Courses:  %d\n",stuInfo.courseNum);
        for(int i=0;i<stuInfo.courseNum;i++){

            printf("Course %d Name:\t%s\n",i+1,stuInfo.courInfo[i].courname);
            printf("Course %d Code:\t%s\n",i+1,stuInfo.courInfo[i].courCode);
        }
        fo = 1;
        break;
    }
    }
    if(found = 0){
         while (fread(&stuInfo, sizeof(struct student), 1, tempFile)) {
        if(strcmp(stuInfo.Sid , searchId)==0){
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
    }

    if (found==0  && fo==0) {
        printf("Student not found!\n");
    }

    fclose(file);
}

//All Student list
void ShowAll() {
    system("cls");
    Sfile = fopen("infgo.txt", "r");
    if (Sfile == NULL) {
        printf("Something Went Wrong!\n");
        return;
    }
    printf("\n\t\t\t\t\t~~~~~ All Student List ~~~~~\n\n");
         printf("\t\t\t|================================================================|\n\n");
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

// student information update function
void Edit_student() {
    system("cls");
     char y;
     int newCourseNum;
    printf("\n\t\t\t\t\t ~~~~~ Update The  Student Details ~~~~~\n\n");
    printf("\t\t\t|================================================================|\n\n");
    char searchId[15];
    int found = 0;
    printf("Enter ID of the student to edit: ");
    fgets(searchId, sizeof(searchId), stdin);
    searchId[strcspn(searchId, "\n")] = 0;

    FILE *tempFile = fopen("temp.txt", "w");
    FILE *Sfile = fopen("infgo.txt", "r");
    if (Sfile == NULL || tempFile == NULL) {
        printf("Error opening file!\n");
        return;
    }

    while (fread(&stuInfo, sizeof(struct student), 1, Sfile)) {
        if (strcmp(stuInfo.Sid, searchId) == 0) {
            printf("Editing student with ID: %s\n", searchId);
            printf("Enter new name [For Skip this Press Enter]: ");
            char newName[50];
            fgets(newName, 50, stdin);
            newName[strcspn(newName, "\n")] = 0;
            if (strlen(newName) > 0) {
                strcpy(stuInfo.Sname, newName);
            }

            printf("Enter new email [For Skip this Press Enter]: ");
            char newEmail[50];
            fgets(newEmail, 50, stdin);
            newEmail[strcspn(newEmail, "\n")] = 0;
            if (strlen(newEmail) > 0) {
                strcpy(stuInfo.Semail, newEmail);
            }

            printf("Enter new phone [For Skip this Press Enter]: ");
            char newPhone[16];
            fgets(newPhone, 16, stdin);
            newPhone[strcspn(newPhone, "\n")] = 0;
            if (strlen(newPhone) > 0) {
                strcpy(stuInfo.Sphone, newPhone);
            }

            printf("Enter new semester [For Skip this Press Enter]: ");
            char newSemester[15];
            fgets(newSemester, 15, stdin);
            newSemester[strcspn(newSemester, "\n")] = 0;
            if (strlen(newSemester) > 0) {
                strcpy(stuInfo.Semester, newSemester);
            }

            printf("Do You Want To Change Course Information [Y/y or N/n]: ");
            scanf("%c", &y);
            getchar();
            if (y == 'y' || y == 'Y') {
                printf("Enter new number of courses: ");
                scanf("%d", &newCourseNum);
                getchar();
                stuInfo.courseNum = newCourseNum;
                for (int i = 0; i < newCourseNum; i++) {
                    printf("Enter new course name %d: ", i + 1);
                    fgets(stuInfo.courInfo[i].courname, sizeof(stuInfo.courInfo[i].courname), stdin);
                    stuInfo.courInfo[i].courname[strcspn(stuInfo.courInfo[i].courname, "\n")] = 0;
                    printf("Enter new course code %d: ", i + 1);
                    fgets(stuInfo.courInfo[i].courCode, sizeof(stuInfo.courInfo[i].courCode), stdin);
                    stuInfo.courInfo[i].courCode[strcspn(stuInfo.courInfo[i].courCode, "\n")] = 0;
                }
            } else {
                printf("Course Information is Unchanged\n");
            }

            found = 1;
        }
        fwrite(&stuInfo, sizeof(struct student), 1, tempFile);
    }

    fclose(Sfile);
    fclose(tempFile);

    remove("infgo.txt");
    rename("temp.txt", "infgo.txt");

    if (found) {
        printf("Student record updated successfully.\n");
    } else {
        printf("Student not found.\n");
    }
}

// Delete student data fuction
void DeleteStu() {
    system("cls");
    printf("\n\t\t\t\t    ~~~~~ Delete Student Detials ~~~~~\n\n");
         printf("\t\t\t|================================================================|\n\n");
   // char searchId[15];
    char searchId[15];
    int found = 0;

    FILE *Sfile = fopen("infgo.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w");

    if (Sfile == NULL || tempFile == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter ID to delete: ");
    fgets(searchId, sizeof(searchId), stdin);
    searchId[strcspn(searchId, "\n")] = 0; // Remove newline character

    while (fread(&stuInfo, sizeof(struct student), 1, Sfile)) {
        if (strcmp(stuInfo.Sid, searchId) != 0) {
            fwrite(&stuInfo, sizeof(struct student), 1, tempFile);
        } else {
            found = 1;
        }
    }

    fclose(Sfile);
    fclose(tempFile);

    if (found) {
        remove("infgo.txt");
        rename("temp.txt", "infgo.txt");
        printf("Student deleted successfully!\n");
    } else {
        printf("Student not found!\n");
        remove("temp.txt");
    }
}

void deleteAllStudents() {
     system("cls");
    int status = remove("infgo.txt");
    if (status == 0) {
        printf("\n\tAll student records deleted successfully!\n");
    } else {
        printf("\n\tError deleting student records!\n");
    }
    GoBack();
}


//User Guideline
void UserGuid() {
    system("cls");
    printf("\n\t\t\t\t\tHow To Work Our System\n\n");
    printf("\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    printf("\nIn Our System At First You Will Choose a Option Is You are a Faculty Member or You are a Student\n");
    printf("If You Choose Option [1]. Faculty Member Then: ");
    printf("\t=> You Will Able to Store Student Data, Like: Student Name, ID, Email, Phone, Course Information\n");
    printf("\t=> Student Name can be 50 characters long\n");
    printf("\t=> Student Id can be unique for every student and Maximum 15 Characters long\n");
    printf("\t=> Every student have unique email id and email id can be maximum 50 characters long\n");
    printf("\t=> Course Name can be 15 characters long\n");
    printf("\t=> Course Code can be 6 characters long\n");
    printf("\t=> Student can have maximum 8 courses and minimum 1 course\n");
    printf("\t=> Phone Number should be 16 characters long\n");
    printf("If You choose Option [2]. Student Then :");
    printf("\t=> You Will Only Able to Show Your Information Like: Your Name,ID,Email Id, Semester, Number of Courses and Course Information\n");
    printf("\t=> If you want to show your details at first you will Registration to our system.\n");
    printf("\t=> After The Registration Process system give a user name .\n");
    printf("\t=> You can Login in our system to use this user name and password\n");
}


void About() {
    system("cls");
    printf("\n\t\t\t\t\t  ~~~~~ About Us ~~~~~\n\n");
    printf("\t\t\t|================================================================|\n\n");
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
    printf("For Logout This System Press [0]\n");
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
    printf("For Logout This System Press [0]\n");
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
// exit function

void ExitProgram() {
    system("cls");
    char mas[] = "~~~~~~Thanks For visiting us~~~~~~";
    printf("\n\n\t\t\t");
    for (int i = 0; i < strlen(mas); i++) {
        printf("%c", mas[i]);
    }
    printf("\n\n\n");
    exit(0);
}

//Faculty memu
void Faculty() {
    system("cls");
    int fa;
    printf("\t\t\t\t------ Welcome to Faculty Members Interface ------\n");
    printf("\t\t\t|================================================================|\n\n");
    printf("\n\n\tPlease Choose Your Option");
    printf("\n\t1. Signup");
    printf("\n\t2. Login");
    printf("\n\t3. Exit");
    printf("\n\nEnter Your Choice: ");
    scanf("%d", &fa);
    getchar();
    switch (fa) {
        case 1:
            Regi();
            break;
        case 2:
            Login();
            break;
        case 3:
            ExitProgram();
            break;
        default:
            printf("\nWrong Choice!");
    }

}

// input Buffer clear
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Student details show
void see() {
    char searchId[15];
    int found = 0, fo = 0;

    printf("\nEnter ID to search: ");
    clearInputBuffer();  // Clear input buffer before taking new input
    fgets(searchId, sizeof(searchId), stdin);
    searchId[strcspn(searchId, "\n")] = 0;
    FILE *Sfile = fopen("infgo.txt", "r");

    if (Sfile == NULL) {
        printf("Error opening file!\n");
        return;
    }

    while (fread(&stuInfo, sizeof(struct student), 1, Sfile)) {
        if (strcmp(stuInfo.Sid, searchId) == 0) {
            printf("\nStudent Name:     %s", stuInfo.Sname);
            printf("\nStudent ID:       %s", stuInfo.Sid);
            printf("\nStudent Email:    %s", stuInfo.Semail);
            printf("\nStudent Phone NO: %s", stuInfo.Sphone);
            printf("\nSemester:         %s\n", stuInfo.Semester);
            printf("Number Of Courses:  %d\n", stuInfo.courseNum);
            for (int i = 0; i < stuInfo.courseNum; i++) {
                printf("Course %d Name:\t%s", i + 1, stuInfo.courInfo[i].courname);
                printf("Course %d Code:\t%s", i + 1, stuInfo.courInfo[i].courCode);
            }
            found = 1;
            break;
        }
    }
    if (found == 0 ) {
        printf("Student not found!\n");
    }

    fclose(Sfile);
    sGoBack();
}

// student Functionality
 void sFunctions(){
     char sc;
     system("cls");
        printf("\n\n\n\t\t\t\t~~~~~Welcome %s~~~~~\n",sUser.sname);
        printf("\t\t\t\t -------------------\n");
        printf("\n\tFor See Your Details Press [S]:\t");
        scanf("%c",&sc);
        if(sc == 's' || sc == 'S'){
            see();
        }
        else{
            printf("Wrong Choice!\n");
            sFunctions();
        }
 }


void sGoBack(){
    getchar();
    char a;
    printf("\n\nFor Refresh Press [R]");
    printf("\tFor Go Back Press [B]\t");
    printf("For Go Back To Home Page Press [H]");
    printf("\tFor Logout This System Press [0]\n");
    printf("\n\nEnter Your choice: ");
    scanf("%c",&a);
    getchar();
    if(a== 'H' || a== 'h'){
    system("cls");
     main();
    }
    else if(a=='B' || a=='b'){
         Student();
    }
    else if(a=='r' || a=='R'){
        sFunctions();
    }
    else{
        ExitProgram();
    }
}

void sGomain(){
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

//student registration system

void sRegi() {
    char password2[50];
    int NF = 0, Co = 0, Ps = 0, flag = 0;
    system("cls");
    printf("\t\t\t\t~~~~~Welcome To Student Registration Functionality~~~~~\n");
     printf("\t\t\t|================================================================|\n\n");
    while (NF == 0) {
        printf("Enter your Full Name: \t");
        fgets(sUser.sname, 50, stdin);
        sUser.sname[strcspn(sUser.sname, "\n")] = 0; // Remove newline character
        for (int i = 0; i < strlen(sUser.sname); i++) {
            if ((sUser.sname[i] >= 'A' && sUser.sname[i] <= 'Z') || (sUser.sname[i] >= 'a' && sUser.sname[i] <= 'z')) {
                NF = 1;
                break;
            }
        }
        if (NF == 1) {
            while (Co == 0) {
                printf("Enter your Contact No: \t");
                fgets(sUser.sphone, 50, stdin);
                sUser.sphone[strcspn(sUser.sphone, "\n")] = 0; // Remove newline character
                for (int i = 0; i < strlen(sUser.sphone); i++) {
                    if (sUser.sphone[i] >= '0' && sUser.sphone[i] <= '9') {
                        Co = 1;
                        break;
                    }
                }
                if (Co == 1) {
                    while (flag == 0) {
                        printf("Enter your Email Id: \t");
                        fgets(sUser.semail, 50, stdin);
                        sUser.semail[strcspn(sUser.semail, "\n")] = 0; // Remove newline character
                        for (int i = 0; i < strlen(sUser.semail); i++) {
                            if (sUser.semail[i] == '@') {
                                flag = 1;
                                break;
                            }
                        }
                        if (flag == 1) {
                            printf("Enter your Password: \t");
                            pswd(sUser.spass);
                            printf("\nConfirm Your Password: \t");
                            pswd(password2);
                        } else {
                            printf("Please Enter a Valid Email Id\n");
                        }
                    }
                } else {
                    printf("Enter a Valid Number\n");
                }
            }
        } else {
            printf("Please Enter a Valid Name\n");
        }
    }

    if (strcmp(sUser.spass, password2) != 0) { // Use != 0 for mismatch
        printf("\nYour Password Don't Match\n");
    } else {
        g_username(sUser.semail, sUser.susname);
        stufile = fopen("StuUserInfo.txt", "a+");
        if (stufile == NULL) {
            printf("\nSorry! Something went wrong while opening the file\n");
            return;
        }
        if (fwrite(&sUser, sizeof(struct suser), 1, stufile)) {
            printf("\nYour Registration is Successfully Completed");
            printf("\nYour User name is : \t%s", sUser.susname);
        } else {
            printf("\nSorry!! Something went wrong\n");
        }
        fclose(file);
    }
    sGoBack();
}

// student Login System;
void sLogin() {
    system("cls");
    char susername[50], pword[50];
    int susrfound = 0;
    printf("\t\t\t\t-----Welcome  To Student Login Functionality-----\n");
    printf("\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\nEnter Your Username:\t");
    fgets(susername, 50, stdin);
    susername[strcspn(susername, "\n")] = 0;
    printf("Enter Your Password:\t");
    pswd(pword);
    system("cls");
    stufile = fopen("StuUserInfo.txt", "r");
    if (stufile == NULL) {
        printf("\nSorry!! Something went wrong while opening the file\n");
        return;
    }
    while (fread(&sUser, sizeof(struct user), 1, stufile)) {
        if (strcmp(sUser.susname, susername) == 0) {
            if (strcmp(sUser.spass, pword) == 0) {
                printf("\n\t\t\tWelcome %s\n\n", sUser.sname);
                sFunctions();
            } else {
                printf("\nInvalid Password!!\n");
            }
            susrfound = 1;
            break;
        }
    }
    if (!susrfound) {
        printf("\nUser is not Found\n");
    }
    fclose(file);

}

//Student menu
void Student(){
    system("cls");
    int sa;
    printf("\n\n\n\t\t\t\t````````````````````````````````````````");
    printf("\n\t\t\t\t----------------------------------------");
    printf("\n\t\t\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    printf("\n\n\t\t\t\t   <--Welcome to Student Interface--> \n");
    printf("\t\t\t\t||==================================||\n");
    printf("\n\t\t\t\t\t1. Sign Up.");
    printf("\n\t\t\t\t\t2. Login.");
    printf("\n\t\t\t\t\t3. User Guideline.");
    printf("\n\t\t\t\t\t4. About US.");
    printf("\n\t\t\t\t\t5. logout.");
    printf("\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
     printf("\n\t\t\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    printf("\n\n\t\t\t\t<<<Enter Your Choice>>>: ");
    scanf("%d", &sa);
    getchar();
    switch (sa) {
        case 1:
            sRegi();
            break;
        case 2:
            sLogin();
            break;
        case 3:
            About();
            break;
        case 4:
             UserGuid();
             break;
        case 5:
            ExitProgram();
            break;
        default:
            printf("\nWrong Choice!");
    }
}

int main(){
    system("color B0");
    printf("\n\n\n\n\n\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n\t\t\t\t\t````````````````````````````````````````");
    int a;
    printf("\n\n\t\t\t\t\t--Welcome to Student Database System--\n");
    printf("\t\t\t\t\t||==================================||\n");
    printf("\n\t\t\t\t\t\t[1]. Faculty Member");
    printf("\n\t\t\t\t\t\t[2]. Student");
    printf("\n\t\t\t\t\t\t[3]. Exit");
    printf("\n\t\t\t\t\t----------------------------------------");
    printf("\n\t\t\t\t\t----------------------------------------\n");
    printf("\t\t\t\t\t====>>>");
    printf("Enter Your Choice: ");
    scanf("%d",&a);
    getchar();
    switch (a) {
        case 1:
            Faculty ();
            break;
        case 2:
           Student();
            break;
        case 3:
            ExitProgram();
            break;
        default:
            printf("\nWrong Choice!");
    }
    getch();
}
