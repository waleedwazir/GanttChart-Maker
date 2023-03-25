//
// Created by Walee on 13/03/2023.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Functions.h"
#include "time.h"

//method to print 3d array
void printGanttChart(char arr[][30][80],int numoftasks) {

    for (int i = 0; i < numoftasks; i++) {
        printf("\n----------------------------------------------------------------------------------------------------------------------\n");
        for (int j = 0; j < 30; j++) {
            printf("%s", arr[i][j]);
        }
    }
    printf("\n----------------------------------------------------------------------------------------------------------------------\n");
}

void preGenerated(char arr[][30][80], int numOfTasks, task tasks[]){
    char task[20] = "Task";
    char c[20];
    int lenght, month = 0;

    for (int i = 1; i < numOfTasks + 1; i++) {
        sprintf(c, "%d", i);

        strcpy(tasks[i-1].name, task);
        strcat(tasks[i-1].name, c);

        lenght = strlen(tasks[i-1].name);
        strcpy(arr[i][0], arr[i][0] + lenght);
        strcat(arr[i][0], tasks[i-1].name);

        tasks[i-1].start_month = i;
        tasks[i-1].end_month = i;

        month += 2;
        lenght = strlen(arr[i][month]);
        strcpy(arr[i][month], arr[i][month] + lenght);
        strcat(arr[i][month], "xxx");

    }

    //add dependencies
    srand(time(NULL));

    for (int i = 0;i < numOfTasks;i++)
    {
        tasks[i].num_dependencies = ((rand() % 3));
        for (int j = 0;j < tasks[i].num_dependencies;j++)
        {

            do{
                tasks[i].dependencies[j] = rand() % 9;
                arr[i + 1][26][0 + (2 * j)] = tasks[i].dependencies[j] + 49;
                arr[i + 1][26][1 + (2 * j)] = ' ';
            }while (tasks[i].dependencies[j] == i);
        }
    }

}

void checkMonth(enum month MONTH, int numMonth, int tasknum, char arr[][30][80]){
    MONTH = numMonth;
    int lenght;
    tasknum += 1;

    switch (MONTH) {
        case Jan:
            lenght = strlen(arr[tasknum][2]);
            strcpy(arr[tasknum][2], arr[tasknum][2] + lenght);
            strcat(arr[tasknum][2], "xxx");
            break;
        case Feb:
            lenght = strlen(arr[tasknum][4]);
            strcpy(arr[tasknum][4], arr[tasknum][4] + lenght);
            strcat(arr[tasknum][4], "xxx");
            break;
        case Mar:
            lenght = strlen(arr[tasknum][6]);
            strcpy(arr[tasknum][6], arr[tasknum][6] + lenght);
            strcat(arr[tasknum][6], "xxx");
            break;
        case April:
            lenght = strlen(arr[tasknum][8]);
            strcpy(arr[tasknum][8], arr[tasknum][8] + lenght);
            strcat(arr[tasknum][8], "xxx");
            break;
        case May:
            lenght = strlen(arr[tasknum][10]);
            strcpy(arr[tasknum][10], arr[tasknum][10] + lenght);
            strcat(arr[tasknum][10], "xxx");
            break;
        case June:
            lenght = strlen(arr[tasknum][12]);
            strcpy(arr[tasknum][12], arr[tasknum][12] + lenght);
            strcat(arr[tasknum][12], "xxx");
            break;
        case July:
            lenght = strlen(arr[tasknum][14]);
            strcpy(arr[tasknum][14], arr[tasknum][14] + lenght);
            strcat(arr[tasknum][14], "xxx");
            break;
        case Aug:
            lenght = strlen(arr[tasknum][16]);
            strcpy(arr[tasknum][16], arr[tasknum][16] + lenght);
            strcat(arr[tasknum][16], "xxx");
            break;
        case Sep:
            lenght = strlen(arr[tasknum][18]);
            strcpy(arr[tasknum][18], arr[tasknum][18] + lenght);
            strcat(arr[tasknum][18], "xxx");
            break;
        case Oct:
            lenght = strlen(arr[tasknum][20]);
            strcpy(arr[tasknum][20], arr[tasknum][20] + lenght);
            strcat(arr[tasknum][20], "xxx");
            break;
        case Nov:
            lenght = strlen(arr[tasknum][22]);
            strcpy(arr[tasknum][22], arr[tasknum][22] + lenght);
            strcat(arr[tasknum][22], "xxx");
            break;
        case Dec:
            lenght = strlen(arr[tasknum][24]);
            strcpy(arr[tasknum][24], arr[tasknum][24] + lenght);
            strcat(arr[tasknum][24], "xxx");
            break;
    }
}


void editGantt(task taskslist[], char arr[][30][80], int numOfTasks, enum month MONTH){

    char taskname[20];
    char newtaskname[20];
    int i = 0;
    int startMonth, endMonth, lenght, lenght2;

    printf("Please enter the task name you which to change exactly: \n");

    fgets(taskname, 20, stdin);
    taskname[strcspn(taskname, "\n")] = 0;


    while(strcmp(taskname, taskslist[i].name) != 0){
        i++;
    }

    printf("Please enter the new task name or write its old one: \n");

    fgets(newtaskname, 20, stdin);
    newtaskname[strcspn(newtaskname, "\n")] = 0;

    strcpy(taskslist[i].name, "");
    strcpy(taskslist[i].name, newtaskname);

    printf("Start month (1-12):\n");
    scanf("%d",&startMonth);
    taskslist[i].start_month = startMonth;

    printf("End month (1-12):\n");
    scanf("%d",&endMonth);
    taskslist[i].end_month = endMonth;

    for (int m = 2; m <= 24; m++) {
        lenght = strlen(arr[i+1][m]);
        strcpy(arr[i+1][m], arr[i+1][m] + lenght);
        strcat(arr[i+1][m], "   ");
        m++;
    }


    for (int n = startMonth; n <= endMonth; n++) {
        checkMonth(MONTH, n,i,arr);
    }

    printf("Enter how many dependencies this task has\n");
    scanf("%d",&taskslist[i].num_dependencies);


    for (int j = 0;j < taskslist[i].num_dependencies;j++){
        printf("Enter dependent task number: \n");
        scanf("%d",&taskslist[i].dependencies[j]);
        arr[i + 1][26][0 + (2 * j)] = taskslist[i].dependencies[j] + 48;
        arr[i + 1][26][1 + (2 * j)] = ' ';
    }

    for (int k = 1; k < numOfTasks + 1; k++) {

        lenght = strlen(arr[k][0]);
        lenght2 = strlen(taskslist[k-1].name);


        strcpy(arr[k][0], arr[k][0] + lenght);
        for (int j = 0; j < 18 - lenght2; j++) {
            strcat(arr[k][0], " ");
        }
        strcat(arr[k][0], taskslist[k-1].name);

    }

}

void asciiArt(){
    printf("   _____             _   _    _____ _                _   \n"
           "  / ____|           | | | |  / ____| |              | |  \n"
           " | |  __  __ _ _ __ | |_| |_| |    | |__   __ _ _ __| |_ \n"
           " | | |_ |/ _` | '_ \\| __| __| |    | '_ \\ / _` | '__| __|\n"
           " | |__| | (_| | | | | |_| |_| |____| | | | (_| | |  | |_ \n"
           "  \\_____|\\__,_|_| |_|\\__|\\__|\\_____|_| |_|\\__,_|_|   \\__|\n"
           "                                                         \n"
           "                                                      \n");
}


//if user chooses to make custom chart
int gettasks(task tasklist[], char gantChart[12][30][80],enum month MONTH){

    printf("How many tasks would you like to add ? (1-10)\n");
    int y;

    scanf("%d",&y);

    for (int i = 0;i < y;i++){
        printf("Please enter the task name\n");
        getchar();
        strcpy(tasklist[i].name, "");
        fgets(tasklist[i].name,80,stdin);
        tasklist[i].name[strcspn(tasklist[i].name, "\n")] = 0;
        int lenght = strlen(gantChart[i+1][0]);
        int lenght2 = strlen(tasklist[i].name);


        strcpy(gantChart[i+1][0], gantChart[i+1][0] + lenght);
        for (int j = 0; j < 18 - lenght2; j++) {
            strcat(gantChart[i+1][0], " ");
        }
        strcat(gantChart[i+1][0], tasklist[i].name);

        printf("Start month (1-12):\n");
        scanf("%d",&tasklist[i].start_month);

        printf("End month (1-12):\n");
        scanf("%d",&tasklist[i].end_month);

        printf("Enter how many dependencies this task has\n");
        scanf("%d",&tasklist[i].num_dependencies);

        for (int j = 0;j < tasklist[i].num_dependencies;j++){
            printf("Enter dependent task number: \n");
            scanf("%d",&tasklist[i].dependencies[j]);
            gantChart[i + 1][26][0 + (2 * j)] = tasklist[i].dependencies[j] + 48;
            gantChart[i + 1][26][1 + (2 * j)] = ' ';
        }
        for (int n = tasklist[i].start_month; n <= tasklist[i].end_month; n++) {
            checkMonth(MONTH, n,i,gantChart);
        }


    }

    return y;
}


void test(task tsklist[],int id,int visited[])
{

    printf("%d-> ",id + 1);
    visited[id] = 1;
    for (int i = 0;i <tsklist[id].num_dependencies;i++)
    {
        int dependent = tsklist[id].dependencies[i];
        if (visited[dependent] == 0)
        {

            test(tsklist,dependent,visited);
        }
        else
        {
            printf("!!!! warning potential circular dependency !!!!");
            int f[20] = {0};
            if (checkcircle(tsklist,dependent,dependent,f))
                printf("!!!!!circular dependency found !!!!!!");
        }
    }
}

int checkcircle(task tsklist[], int id, int dependent, int visited[])
{
    visited[id] = 1;
    for (int i = 0; i < tsklist[dependent].num_dependencies; i++)
    {
        int next = tsklist[dependent].dependencies[i];
        if (next == id)
        {
            return 1;
        }
        else if (visited[next] == 0)
        {
            if (checkcircle(tsklist, id, next, visited))
            {
                return 1;
            }
        }
    }
    visited[id] = 0;
    return 0;
}



void driverCode(char input[20], char gantChart[][30][80], int numoftasks, enum month MONTH, task tasklist[]){



    while(strcmp(input, "quit") != 0){

        fgets(input, 20,stdin);
        input[strcspn(input, "\n")] = 0;

        if (strcasecmp("edit",input) == 0){
            editGantt(tasklist, gantChart, numoftasks, MONTH);
            printGanttChart(gantChart,numoftasks);
        }else if (strcasecmp("test",input) == 0){
            int visited[20] = {0};
            int x;
            printf("enter task you would like to test(1-10)\n");
            scanf("%d",&x);

            test(tasklist,x - 1,visited);
        }
    }
}







