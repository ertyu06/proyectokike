#include <stdio.h>

void TamMatriz (int *estudiantes, int *evaluaciones)
{
    int op, op2;
    do
    {
        printf("ingresa la cantidad de estudiantes (1-40): ");
        scanf("%d",estudiantes);

        if(*estudiantes > 40)
        {
            printf("el maximo de estudiantes es 40\n");
            op=1; 
        }
        else if (*estudiantes < 1)
        {
            printf("el minimo de estudiantes es 1\n");
            op=1; 
        }
        else
        {
            do
            { 
                printf("ingresa la cantidad de evaluaciones (1-5): ");
                scanf("%d",evaluaciones);

                if(*evaluaciones > 5)
                {
                    printf("el maximo de parciales es 5\n");
                    op2=2; 
                }
                else if (*evaluaciones < 1)
                {
                    printf("el minimo de parciales es 1\n");
                    op2=2; 
                }
                else
                {
                    printf("Datos guardados!\n");
                    op=0;
                    op2=0;
                }
            } while (op2 == 2);
        }

    }while (op==1);
}

void Ingresar(int estudiantes,int evaluaciones,int calificaciones[estudiantes][evaluaciones])
{
    int i=0,j=0; 

    for ( i = 0; i < estudiantes; i++) 
    {
        printf("\nIngresa las calificaciones de (0-100)\n");
        for ( j = 0; j < evaluaciones; j++)  
        {
            do
            {
                printf("\nDame la calificacion del estudiante %d: ",i+1);
                printf("\ndel parcial %d: ",j+1);
                scanf("%d",&calificaciones[i][j]);

                if (calificaciones[i][j] < 0 || calificaciones[i][j] > 100)
                {
                    printf("\n  ERROR! La calificacion debe estar entre 0 y 100.\n");
                }

            } while (calificaciones[i][j] < 0 || calificaciones[i][j] > 100);
        }
    }
}

void Imprimir(int estudiantes,int evaluaciones,int calificaciones[estudiantes][evaluaciones])
{
    printf("\n\tImprimiendo las calificaciones\n");
    int i=0,j=0;
    printf("\nLlamando al arreglo de calificaciones\n");
    
    for ( i = 0; i < estudiantes; i++) 
    {
        for ( j = 0; j < evaluaciones; j++) 
        {
            printf ("|%d|", calificaciones[i][j]);
        }
        printf("\n"); 
    }
}

void PromEva(int estudiantes,int evaluaciones,int calificaciones[estudiantes][evaluaciones])
{
    int i=0,j=0;
    int promeva=0; 
    int promcalf[evaluaciones]; 
    
    printf("\n\tPromedio Evaluacion\n");
    
    for ( i = 0; i < evaluaciones; i++) 
    {
        promeva=0; 
        for ( j = 0; j < estudiantes; j++)  
        {
            promeva=promeva+calificaciones[j][i];
        }
        promcalf[i]=promeva/estudiantes;
    }
    
    for (i = 0; i < evaluaciones; i++)
    {
        printf("Promedio del parcial %d es de: %d \n", i + 1, promcalf[i]);
    }
}

void PromEstu(int estudiantes,int evaluaciones,int calificaciones[estudiantes][evaluaciones])
{
    int i=0,j=0;
    int promestu=0; 
    int promcalf[estudiantes]; 
    
    printf("\nPromedio Estudiante\n"); 
    
    for ( i = 0; i < estudiantes; i++) 
    {
        promestu=0; 
        for ( j = 0; j < evaluaciones; j++)  
        {
            promestu=promestu+calificaciones[i][j];
        }
        promcalf[i]=promestu/evaluaciones;
    }

    for (i = 0; i < estudiantes; i++)
    {
        printf("Promedio del estudiante %d es de: %d \n", i + 1, promcalf[i]);
    }
}

void Alertas(int estudiantes, int evaluaciones, int calificaciones[estudiantes][evaluaciones])
{
    printf("\n--- Reporte de Alertas por Riesgo ---\n");
    int i=0, j=0;
    int contador_alertas = 0; 
    int promedio_actual=0;
    int ultima_calificacion=0;

    for (i = 0; i < estudiantes; i++) 
    {
        int promestu = 0; 

        for (j = 0; j < evaluaciones; j++)
        {
            promestu = promestu + calificaciones[i][j];
        }
        promedio_actual = promestu / evaluaciones;
        ultima_calificacion = calificaciones[i][evaluaciones - 1];

        if ( (promedio_actual < 70) || (ultima_calificacion < 70) ) 
        {
            printf("ALERTA: El Estudiante %d esta en riesgo. (Promedio: %d, Ultima Calificacion: %d)\n", i + 1, promedio_actual, ultima_calificacion);
            contador_alertas++; 
        }
    }

    if (contador_alertas == 0)
    {
        printf("Buenas noticias! Ningun estudiante se encuentra en riesgo.\n");
    }
    printf("--- Fin del Reporte ---\n\n");
}

// Nueva funcion: histograma textual de promedios por rangos
void Histograma(int estudiantes,int evaluaciones,int calificaciones[estudiantes][evaluaciones])
{
    int i,j,prom,cont0=0,cont60=0,cont70=0,cont80=0,cont90=0;

    for(i=0;i<estudiantes;i++)
    {
        int suma=0;
        for(j=0;j<evaluaciones;j++)
        {
            suma+=calificaciones[i][j];
        }
        prom=suma/evaluaciones;

        if(prom<60) cont0++;
        else if(prom<70) cont60++;
        else if(prom<80) cont70++;
        else if(prom<90) cont80++;
        else if(prom<=100) cont90++;
    }

    printf("\n--- Histograma de Promedios ---\n");
    printf("0-59   : ");
    for(i=0;i<cont0;i++) printf("*");
    printf("\n60-69  : ");
    for(i=0;i<cont60;i++) printf("*");
    printf("\n70-79  : ");
    for(i=0;i<cont70;i++) printf("*");
    printf("\n80-89  : ");
    for(i=0;i<cont80;i++) printf("*");
    printf("\n90-100 : ");
    for(i=0;i<cont90;i++) printf("*");
    printf("\n------------------------------\n");
}

// Nueva funcion: histograma textual de todas las calificaciones por rangos
void HistogramaDeTodas(int estudiantes, int evaluaciones, int calificaciones[estudiantes][evaluaciones])
{
    
    int i, j, cont0=0, cont60=0, cont70=0, cont80=0, cont90=0;

    
    for(i = 0; i < estudiantes; i++)
    {
        
        for(j = 0; j < evaluaciones; j++)
        {
            if(calificaciones[i][j] < 60) cont0++;
            else if(calificaciones[i][j] < 70) cont60++;
            else if(calificaciones[i][j] < 80) cont70++;
            else if(calificaciones[i][j] < 90) cont80++;
            else cont90++;
        }    
    }

    printf("\n--- Histograma de TODAS las Calificaciones ---\n");
    printf("0-59   : ");
    for(i=0;i<cont0;i++) printf("*");
    printf("\n60-69  : ");
    for(i=0;i<cont60;i++) printf("*");
    printf("\n70-79  : ");
    for(i=0;i<cont70;i++) printf("*");
    printf("\n80-89  : ");
    for(i=0;i<cont80;i++) printf("*");
    printf("\n90-100 : ");
    for(i=0;i<cont90;i++) printf("*");
    printf("\n--------------------------------------------\n");
}