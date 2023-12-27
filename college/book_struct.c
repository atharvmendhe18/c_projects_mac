// WAP to store the information of a book i.e. its title, author’s name, publisher’s name, edition and ISBN number

#include <stdio.h>

struct book
{
    char title[20];
    int edition;
    int isbn_number;
    struct author_name
    {
        char first_name[10];
        char last_name[10];
    } author;
    struct pubilisher_name
    {
        char first_name[10];
        char last_name[10];
    } publisher;
};

int main(void)
{
    struct book book1;
    printf("Please enter the title of the book: ");
    scanf("%s", book1.title);
    printf("\nPlease enter authors first name: ");
    scanf("%s", book1.author.first_name);
    printf("\nPlease enter authors last name: ");
    scanf("%s", book1.author.last_name);
    printf("\nPlease enter publishers first name: ");
    scanf("%s", book1.publisher.first_name);
    printf("\nPlease enter publishers last name: ");
    scanf("%s", book1.publisher.last_name);
    printf("\nPlease enter the edition of the book: ");
    scanf("\n%i", &book1.edition);
    printf("\nPlease enter the ISBN no: ");
    scanf("\n%i", &book1.isbn_number);
}