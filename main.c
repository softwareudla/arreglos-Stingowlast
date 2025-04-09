#include <stdio.h>

int main()
{

    int i, j;
    float calificaciones[5][3];
    float promedio_estudiantes[5];
    float promedio_asignatura[3];
    float maxestudiantes[5], minestudiantes[5];
    float maxasignatura[3], minasignatura[3];
    int aprobados[3] = {0}, reprobados[3];

    for ( i = 0; i < 5; i++)
    {
        for ( j = 0; i < 3; j++)
        {
            do
            {
                printf("Ingrese la calificación del estudiante %d en asignatura %d :", i+1, j+1);
                scanf("%f", &calificaciones[i][j]);
            } while (calificaciones[i][j] < 0 || calificaciones[i][j] > 10);
            
        }
        
    }
    


    return 0;
}
