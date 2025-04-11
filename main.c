#include <stdio.h>
#include <string.h>

//DAVID SOASTI, PAUL CABRERA Y ALEJANDRO HOLGUIN

int main() {
    int estudiantes = 5;
    int asignaturas = 3;
    char materias[3][30];
    float calificaciones[5][3];
    float nota;
    int resultado, len, opcion;
    char check;
    float sumaEstudiante, sumaAsignatura;
    float promedioEstudiante[5];
    float promedioAsignatura[3];
    float max, min;
    int aprobados[3] = {0, 0, 0};
    int calificacionesIngresadas = 0;

    do {
        printf("\n------------- MENÚ -------------\n");
        printf("1. Ingresar calificaciones\n");
        printf("2. Modificar calificación\n");
        printf("3. Tabla de calificaciones y resultados\n");
        printf("4. Salir\n");
        printf("\nSeleccione una opción: ");
        resultado = scanf("%d%c", &opcion, &check);

        if (resultado != 2 || check != '\n') {
            printf("\nEntrada inválida. Solo se permiten números enteros del menú.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (opcion) {
            case 1:
                for (int j = 0; j < asignaturas; j++) {
                    printf("\nIngrese el nombre o ID de la materia %d: ", j + 1);
                    fflush(stdin);
                    fgets(materias[j], 30, stdin);

                    len = strlen(materias[j]) - 1;
                    materias[j][len] = '\0';

                    for (int i = 0; i < estudiantes; i++) {
                        int valido = 0;
                        while (!valido) {
                            printf("Ingrese la calificación del estudiante %d en %s: ", i + 1, materias[j]);
                            resultado = scanf("%f%c", &nota, &check);

                            if (resultado != 2 || check != '\n') {
                                printf("Calificación inválida. No se permiten letras o símbolos\n");
                                while (getchar() != '\n');
                            } else if (nota < 0 || nota > 10) {
                                printf("Calificación fuera de rango: debe estar entre 0 y 10.\n");
                            } else {
                                calificaciones[i][j] = nota;
                                valido = 1;
                            }
                        }
                    }
                }
                calificacionesIngresadas = 1;
                break;

            case 2:
                if (!calificacionesIngresadas) {
                    printf("\nIngrese primero las calificaciones antes de modificarlas.\n");
                    break;
                }

                int estValido = 0, aux;

                while (!estValido) {
                    printf("\nIngrese el número del estudiante a modificar (1-5): ");
                    resultado = scanf("%d%c", &aux, &check);

                    if (resultado != 2 || check != '\n') {
                        printf("Carácter inválido. Debe ser un número entero entre 1 y 5.\n");
                        while (getchar() != '\n');
                    } else if (aux < 1 || aux > 5) {
                        printf("Número inválido. Debe ser un número entre 1 y 5.\n");
                    } else {
                        estValido = 1;
                        aux--;
                    }
                }

                for (int j = 0; j < asignaturas; j++) {
                    int valido = 0;
                    while (!valido) {
                        printf("\nIngrese la nueva calificación de %s para el estudiante %d: ", materias[j], aux + 1);
                        resultado = scanf("%f%c", &nota, &check);

                        if (resultado != 2 || check != '\n') {
                            printf("Calificación inválida. No se permiten letras o símbolos \n");
                            while (getchar() != '\n');
                        } else if (nota < 0 || nota > 10) {
                            printf("Calificación fuera de rango (0-10).\n");
                        } else {
                            calificaciones[aux][j] = nota;
                            valido = 1;
                        }
                    }
                }
                printf("Calificaciones del estudiante %d modificadas correctamente.\n", aux + 1);
                break;

            case 3:
                if (!calificacionesIngresadas) {
                    printf("No hay calificaciones ingresadas aún.\n");
                    break;
                }

                for (int i = 0; i < estudiantes; i++) {
                    sumaEstudiante = 0;
                    for (int j = 0; j < asignaturas; j++) {
                        sumaEstudiante += calificaciones[i][j];
                    }
                    promedioEstudiante[i] = sumaEstudiante / asignaturas;
                }

                for (int j = 0; j < asignaturas; j++) {
                    sumaAsignatura = 0;
                    aprobados[j] = 0;
                    for (int i = 0; i < estudiantes; i++) {
                        sumaAsignatura += calificaciones[i][j];
                        if (calificaciones[i][j] >= 6) aprobados[j]++;
                    }
                    promedioAsignatura[j] = sumaAsignatura / estudiantes;
                }

                printf("\n--------------- Tabla de Calificaciones ---------------\n\n");
                printf("\t\t");
                for (int j = 0; j < asignaturas; j++) {
                    printf("%s\t\t", materias[j]);
                }
                printf("\n-----------------------------------------------------------\n");

                for (int i = 0; i < estudiantes; i++) {
                    printf("ESTUDIANTE %d\t", i + 1);
                    for (int j = 0; j < asignaturas; j++) {
                        printf("%.2f\t\t", calificaciones[i][j]);
                    }
                    printf("\n");
                }

                printf("\n--------------- Resultados Generales ----------------\n");

                for (int i = 0; i < estudiantes; i++) {
                    printf("Promedio del estudiante %d: %.2f\n", i + 1, promedioEstudiante[i]);
                }

                printf("-----------------------------------------------------------\n");

                for (int j = 0; j < asignaturas; j++) {
                    printf("Promedio de la asignatura %s: %.2f\n", materias[j], promedioAsignatura[j]);
                }

                printf("-----------------------------------------------------------\n");

                for (int i = 0; i < estudiantes; i++) {
                    max = calificaciones[i][0];
                    min = calificaciones[i][0];
                    for (int j = 1; j < asignaturas; j++) {
                        if (calificaciones[i][j] > max) max = calificaciones[i][j];
                        if (calificaciones[i][j] < min) min = calificaciones[i][j];
                    }
                    printf("Estudiante %d - Nota más alta: %.2f, Nota más baja: %.2f\n", i + 1, max, min);
                }

                printf("-----------------------------------------------------------\n");

                for (int j = 0; j < asignaturas; j++) {
                    max = calificaciones[0][j];
                    min = calificaciones[0][j];
                    for (int i = 1; i < estudiantes; i++) {
                        if (calificaciones[i][j] > max) max = calificaciones[i][j];
                        if (calificaciones[i][j] < min) min = calificaciones[i][j];
                    }
                    printf("%s - Nota más alta: %.2f, Nota más baja: %.2f\n", materias[j], max, min);
                    printf("Estudiantes que aprobaron %s: %d\n", materias[j], aprobados[j]);
                }

                printf("-----------------------------------------------------------\n");
                break;

            case 4:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }

    } while (opcion != 4);

    return 0;
}