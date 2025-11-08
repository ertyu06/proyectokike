#include <stdio.h>
#include "libreriaproyecto.h" 
/*Integrantes:
Cesar Enrique Gonzalez Gomez
Carlos Enrique Hernández Saldaña
Jesus Damian Ortiz Vargas
Mario Alberto Espinosa Zamora
*/ 
int main()
{
    // Variables para guardar el tamano de la matriz
    int estudiantes=0,evaluaciones=0;
    
    // Variables para controlar las opciones del menu
    int op=0,op2=0,op3=0;

    // Bandera para saber si ya se ingresaron calificaciones
    int datos_ingresados = 0;

    // 1. Pide al usuario el tamano de la clase (estudiantes y evaluaciones)
    TamMatriz(&estudiantes,&evaluaciones);

    // 2. Declara la matriz de calificaciones con el tamano que dio el usuario
    int calificaciones[estudiantes][evaluaciones];

    // 3. Inicia el ciclo del menu principal
    do
    {  
    printf("\n\t\tBienvenido al registro de Tutor Academico \n1.Ingresar Calificaciones \n2.[Calcular promedio] \n3.Alertas Alumnos \n4.[Histogramas] \n5.Salir\n :");
        scanf("%d",&op);
        
        switch(op)
        {
            case 1:
                Ingresar(estudiantes,evaluaciones,calificaciones);
                datos_ingresados = 1; // Marca que ya se metieron datos
                break;

            case 2:
                if (datos_ingresados == 0)
                {
                    printf("\nPrimero debes ingresar las calificaciones antes de calcular promedios.\n");
                    break;
                }

                printf("\n\t\tSelecciona que promedio quieres calcular \n1.Promedio por estudiante \n2.Promedio por evaluacion \n3.Salir\n");
                scanf("%d",&op2);

                switch (op2)
                {
                    case 1 : 
                        Imprimir(estudiantes,evaluaciones,calificaciones); 
                        PromEstu(estudiantes,evaluaciones,calificaciones); 
                        break;
                    case 2: 
                        Imprimir(estudiantes,evaluaciones,calificaciones);
                        PromEva(estudiantes,evaluaciones,calificaciones);
                        break;
                    case 3:
                        printf("\nSaliendo del submenu... Volviendo al menu principal.\n");
                        break;
                    default:
                        printf("\nValor no valido, por favor ingrese un numero entre las opciones.\n");
                        break;
                }
                break;

            case 3:
                if (datos_ingresados == 0)
                {
                    printf("\nPrimero debes ingresar las calificaciones antes de generar alertas.\n");
                    break;
                }
                Alertas(estudiantes, evaluaciones, calificaciones);
                break;

            case 4:
                if (datos_ingresados == 0)
                {
                    printf("\nPrimero debes ingresar las calificaciones antes de calcular promedios.\n");
                    break;
                }

                printf("\n\t\tSelecciona que Histograma quieres ver \n1.Histograma por promedio de estudiante \n2.Histograma de todas las calificaciones \n3.Salir\n");
                scanf("%d",&op3);

                switch (op3)
                {
                    case 1 : 
                    Histograma(estudiantes,evaluaciones,calificaciones);
                        break;
                    case 2: 
                    HistogramaDeTodas(estudiantes,evaluaciones,calificaciones);
                        break;
                    case 3:
                        printf("\nSaliendo del submenu... Volviendo al menu principal.\n");
                        break;
                    default:
                        printf("\nValor no valido, por favor ingrese un numero entre las opciones.\n");
                        break;
                }
                break;

            case 5:
                op=6; 
                printf("Cerrando programa ..... \n");
                break;

            default:
                printf("\nValor no valido, por favor ingrese un numero entre las opciones.\n");
                break;
        }
    } while (op!=6);

    return 0;
}
