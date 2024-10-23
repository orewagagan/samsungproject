#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Day 
{
    char *dayName;
    int date;
    char *activity;
};
struct Day create() 
{
    struct Day newDay;
    newDay.dayName = (char *)malloc(50 * sizeof(char));
    newDay.activity = (char *)malloc(100 * sizeof(char));


    
    printf("Enter day name: ");
    scanf("%s", newDay.dayName);
    
    printf("Enter date: ");
    scanf("%d", &newDay.date);

    printf("Enter activity description: ");
    scanf(" %s", newDay.activity);

    return newDay;
}


void read(struct Day week[]) {
	int i;
    for (i = 0; i < 7; ++i) {
        printf("Enter details for day %d:\n", i + 1);
        week[i] = create();
    }
}


void display(struct Day week[]) 
{
    printf("\n\t\t\t\t\tWeek's Activity Details:\n");
    printf("\n----------------------------------------------------------------------------------------\n");
    printf("\tDATE\t\t|\t\tDAY\t\t|\t\tACTIVITY\n");
   int i;
    for (i = 0; i < 7; ++i) 
	{
        printf("\n\t%s\t\t|\t\t%d\t\t|\t\t", week[i].dayName, week[i].date);
        printf("%s\n", week[i].activity);
    }
    printf("\n----------------------------------------------------------------------------------------\n");
}


int main() 
{
    struct Day *calendar = (struct Day *)malloc(7 * sizeof(struct Day));
    read(calendar);
    display(calendar);
    return 0;
}

