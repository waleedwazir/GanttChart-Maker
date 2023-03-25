typedef struct{
    int start_month;
    int end_month;
    int num_dependencies;
    int dependencies[10];
    char name[80];
}task;

enum month{Jan=1, Feb=2, Mar=3, April=4, May=5, June=6, July=7, Aug=8, Sep=9, Oct=10, Nov=11, Dec=12};

void preGenerated(char arr[][30][80], int numOfTasks, task tasks[]);

void editGantt(task taskslist[], char arr[][30][80], int numOfTasks, enum month MONTH);

void printGanttChart(char arr[][30][80],int numoftasks);

int gettasks(task tasklist[],char gantChart[12][30][80],enum month MONTH);

void asciiArt();

void test(task tsklist[],int id,int visited[]);

int checkcircle(task tsklist[], int id, int dependent, int visited[]);

void driverCode(char input[20], char gantChart[][30][80], int numoftasks, enum month MONTH, task tasklist[]);

void checkMonth(enum month MONTH, int numMonth, int tasknum, char arr[][30][80]);