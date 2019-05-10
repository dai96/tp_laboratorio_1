#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;

int getInt (char mensaje []);

float getFlotante (char mensaje []);


char getCaracter (char mensaje []);


void getString(char mensaje [],char vec[]);


void getNombres (char mensaje [], char vec[]);


void stringToUpper (char vec []);


int esNumerico(char vec[]);


int esSoloLetras(char str[]);

void validarString (char validar [], int tam, char solicita[]);


char son (void);

int initEmployees(Employee list[], int len);

int addEmployee(Employee list [], int len, int id, char name[],char lastName[],float salary,int sector);


void altaEmployee (Employee list[], int len);

int idIncremental(Employee list[],int len);


int printEmployees(Employee list [], int len);


int findEmployeeById(Employee list[], int len,int id);


void modificar(Employee list[], int len);


int removeEmployee(Employee list[], int len, int id);

int sortEmployees(Employee list[], int len, int order);


int menuDeOpciones(char mensaje[]);
