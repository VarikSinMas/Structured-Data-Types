/*FUNDAMENTOS DE PROGRAMACIÓN AA5 (Antoni Fernández Almécija*/

#include <stdio.h>
#include <string.h>

#define MAX_CENTROS_TRABAJO 40
#define MAX_TRABAJADORES 30
#define MAX_CHAR 20

typedef struct
{
    char DNI[10];
    char Nombre[MAX_CHAR];
    char Apellido1[MAX_CHAR];
    char Apellido2[MAX_CHAR];
    int telefono;
    float sueldo;
} Trabajador;

typedef struct
{
    char Denominacion[MAX_CHAR];
    Trabajador trabajadores[MAX_TRABAJADORES];
    int numero_trabajadores_guardados;
} CentroTrabajo;

typedef struct
{
    CentroTrabajo centros_trabajo[MAX_CENTROS_TRABAJO];
    int numero_centros_trabajo_guard;
} Empresa;

void inicializar_empresa(Empresa *e);
int menu();
void introducir_centro_trabajo(Empresa *e);
void listar_centro_trabajo(Empresa e);
void listar_empleados_centro_trabajo(Empresa e);
void borrar_centro_trabajo(Empresa *e);
void anadir_trabajadores_centro_trabajo(Empresa *e);

int main()
{
    Empresa e;
    int o;

    inicializar_empresa(&e);
    o = menu();

    while (o >= 1 && o <= 5)
    {
        if (o == 1)
        {
            introducir_centro_trabajo(&e);
        }
        else if (o == 2)
        {
            listar_centro_trabajo(e);
        }
        else if (o == 3)
        {
            listar_empleados_centro_trabajo(e);
        }
        else if (o == 4)
        {
            borrar_centro_trabajo(&e);
        }
else if (o == 5)
        {
            anadir_trabajadores_centro_trabajo(&e);
        }
        o = menu();
    }

    return 0;
}

void inicializar_empresa(Empresa *e)
{
    e->numero_centros_trabajo_guard = 0;
}

int menu()
{
    int op;
    printf("****************************************************************\n");
    printf("Teclea el numero de la opcion escogida o cualquier otro numero para salir:\n");
    printf("1. Introducir centro de trabajo y trabajadores de este\n");
    printf("2. Listar centros de trabajo introducidos.\n");
    printf("3. Listar trabajadores de un centro de trabajo determinado.\n");
    printf("4. Borrar centro de trabajo y trabajadores.\n");
    printf("5. Anadir trabajadores al centro de trabajo existente. \n");
        printf("******************************************************************\n");
    scanf("%d", &op);
    return op;
}

void introducir_centro_trabajo(Empresa *e)
{
    if (e->numero_centros_trabajo_guard < MAX_CENTROS_TRABAJO)
    {
        CentroTrabajo c;
        int p;

        printf("Teclea el nombre del centro de trabajo: ");
        scanf("%s", c.Denominacion);
        c.numero_trabajadores_guardados = 0;

        printf("Vas a introducir un nuevo trabajador? Teclea 1 si es que si, o 0 si es que no: ");
        scanf("%d", &p);

        while (p == 1)
        {
            Trabajador t;

            printf("Teclea el DNI del trabajador: ");
            scanf("%s", t.DNI);
            printf("Teclea el nombre del trabajador: ");
            scanf("%s", t.Nombre);
            printf("Teclea el primer apellido del trabajador: ");
            scanf("%s", t.Apellido1);
            printf("Teclea el segundo apellido del trabajador: ");
            scanf("%s", t.Apellido2);
            printf("Teclea el telefono del trabajador: ");
            scanf("%d", &t.telefono);
            printf("Teclea el sueldo del trabajador: ");
            scanf("%f", &t.sueldo);

            c.trabajadores[c.numero_trabajadores_guardados] = t;
            c.numero_trabajadores_guardados++;

            printf("Vas a introducir un nuevo trabajador? Teclea 1 si es que si, o 0 si es que no: ");
            scanf("%d", &p);
        }

        e->centros_trabajo[e->numero_centros_trabajo_guard] = c;
        e->numero_centros_trabajo_guard++;
    }
}

void listar_centro_trabajo(Empresa e)
{
    for (int i = 0; i < e.numero_centros_trabajo_guard; i++)
    {
        printf("Denominacion: %s\n", e.centros_trabajo[i].Denominacion);
        printf("numero de trabajadores: %d\n", e.centros_trabajo[i].numero_trabajadores_guardados);
    }
}

void listar_empleados_centro_trabajo(Empresa e)
{
    if (e.numero_centros_trabajo_guard == 0)
    {
        printf("No hay centros de trabajo guardados.\n");
    }
    else
    {
        printf("Indica por su numero de los siguientes centros de trabajo de cual quieres listar sus empleados:\n");
        for (int i = 0; i < e.numero_centros_trabajo_guard; i++)
        {
            printf("%d. %s\n", i + 1, e.centros_trabajo[i].Denominacion);
        }

        int c;
        scanf("%d", &c);

        while (c < 1 || c > e.numero_centros_trabajo_guard)
        {
            printf("Numero incorrecto. Indica por su numero uno de entre los siguientes centros de trabajo de cual quieres listar sus empleados:\n");
            for (int i = 0; i < e.numero_centros_trabajo_guard; i++)
            {
                printf("%d. %s\n", i + 1, e.centros_trabajo[i].Denominacion);
            }
            scanf("%d", &c);
        }

        printf("Sus empleados son:\n");
        for (int i = 0; i < e.centros_trabajo[c - 1].numero_trabajadores_guardados; i++)
        {
            Trabajador t = e.centros_trabajo[c - 1].trabajadores[i];
            printf("DNI: %s\n", t.DNI);
            printf("Nombre: %s\n", t.Nombre);
            printf("Apellido1: %s\n", t.Apellido1);
            printf("Apellido2: %s\n", t.Apellido2);
            printf("Telefono: %d\n", t.telefono);
            printf("Sueldo: %.2f\n", t.sueldo);
        }
    }
}

void borrar_centro_trabajo(Empresa *e)
{
    int numero;

    printf("Indica por su numero de los siguientes centros de trabajo cual quieres borrar junto con sus trabajadores:\n");
    for (int i = 0; i < e->numero_centros_trabajo_guard; i++)
    {
        printf("%d. %s\n", i + 1, e->centros_trabajo[i].Denominacion);
    }
    scanf("%d", &numero);

    if (numero > 0 && numero <= e->numero_centros_trabajo_guard)
    {
        for (int i = numero - 1; i < e->numero_centros_trabajo_guard - 1; i++)
        {
            e->centros_trabajo[i] = e->centros_trabajo[i + 1];
        }
        e->numero_centros_trabajo_guard--;
        printf("Centro de trabajo y trabajadores eliminados con exito.\n");
    }
    else
    {
        printf("numero de centro de trabajo invalido.\n");
    }
}

void anadir_trabajadores_centro_trabajo(Empresa *e)
{
    if (e->numero_centros_trabajo_guard == 0)
    {
        printf("No hay centros de trabajo guardados.\n");
    }
    else
    {
        printf("Indica por su numero uno de los siguientes centros de trabajo al que quieres anadir empleados:\n");
        for (int i = 0; i < e->numero_centros_trabajo_guard; i++)
        {
            printf("%d. %s\n", i + 1, e->centros_trabajo[i].Denominacion);
        }

        int c;
        scanf("%d", &c);

        while (c < 1 || c > e->numero_centros_trabajo_guard)
        {
            printf("Numero incorrecto. Indica por su numero uno de los siguientes centros de trabajo al que quieres anadir empleados:\n");
            for (int i = 0; i < e->numero_centros_trabajo_guard; i++)
            {
                printf("%d. %s\n", i + 1, e->centros_trabajo[i].Denominacion);
            }
            scanf("%d", &c);
        }

        CentroTrabajo *centro = &(e->centros_trabajo[c - 1]);
        int p = 1;

        while (p == 1 && centro->numero_trabajadores_guardados < MAX_TRABAJADORES)
        {
            Trabajador t;

            printf("Teclea el DNI del trabajador: ");
            scanf("%s", t.DNI);
            printf("Teclea el nombre del trabajador: ");
            scanf("%s", t.Nombre);
            printf("Teclea el primer apellido del trabajador: ");
            scanf("%s", t.Apellido1);
            printf("Teclea el segundo apellido del trabajador: ");
            scanf("%s", t.Apellido2);
            printf("Teclea el telefono del trabajador: ");
            scanf("%d", &t.telefono);
            printf("Teclea el sueldo del trabajador: ");
            scanf("%f", &t.sueldo);

            centro->trabajadores[centro->numero_trabajadores_guardados] = t;
            centro->numero_trabajadores_guardados++;

            printf("¿Quieres anadir otro trabajador? Teclea 1 si es que si, o 0 si es que no: ");
            scanf("%d", &p);
        }

        if (centro->numero_trabajadores_guardados == MAX_TRABAJADORES)
        {
            printf("No se pueden anadir mas trabajadores. Se ha alcanzado el limite.\n");
        }
    }
}
