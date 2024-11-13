#include<stdio.h>


struct Address
{
    char city [50];
    int zip;
};
struct Address address[10000];

struct Student
{
    int roll;
    char name[50];
    struct Address address;
};
struct Student students[10000];


int main()
{
    int a;
    printf("Enter The Number of Students: ");
    scanf(" %d",&a);
    getchar();
    for(int i =0; i<a; i++)
    {

        printf("Enter student Name %d: ",i+1);
        gets(students[i].name);
        //getchar();

        printf("Enter Roll Number: ");
        scanf("%d", &students[i].roll);
        //getchar();

        printf("Enter City: ");
        gets(students[i].address.city);
        //getchar();

        printf("Enter ZIP Number: ");
        scanf("%d",&students[i].address.zip);
        getchar();
    }
    printf("\n");
    for(int i =0; i<a; i++)
    {
        printf("Name: %s\n",students[i].name);
        printf("Roll: %d\n", students[i].roll);
        printf("City: %s\n",students[i].address.city);
        printf("ZIP Number: %d\n",students[i].address.zip);
    }
    getchar();
}
