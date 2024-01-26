#include <stdio.h>

int main() {
    int dia, mes, anio, suma_digitos, digito;
    char respuesta;

    do {
        printf("Ingrese su día de nacimiento (1-31): ");
        scanf("%d", &dia);
        printf("Ingrese su mes de nacimiento (1-12): ");
        scanf("%d", &mes);
        printf("Ingrese su año de nacimiento (1000-2024): ");
        scanf("%d", &anio);

        if ((mes == 2) && ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0))) {
            if (dia > 29) {
                printf("Fecha ingresada no válida. Por favor, ingrese una fecha válida.\n");
                continue; 
            }
          
        } else if (mes == 2 && dia > 28) {
            printf("Fecha ingresada no válida. Por favor, ingrese una fecha válida.\n");
            continue; 
            
            
        } 
        else if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && (dia > 30)) {
            printf("Fecha ingresada no válida. Por favor, ingrese una fecha válida.\n");
            continue;
        }
        else if (!((dia >= 1 && dia <= 31) && (mes >= 1 && mes <= 12) && (anio >= 1000 && anio <= 2024))) {
            printf("Fecha ingresada no válida. Por favor, ingrese una fecha válida.\n");
            continue; 
        }

        suma_digitos = 0;

        while (anio > 0) {
            digito = anio % 10;
            suma_digitos += digito;
            anio = (anio - digito) / 10;
        }

        while (mes > 0) {
            digito = mes % 10;
            suma_digitos += digito;
            mes = (mes - digito) / 10;
        }

        while (dia > 0) {
            digito = dia % 10;
            suma_digitos += digito;
            dia = (dia - digito) / 10;
        }

        while (suma_digitos > 9) {
            digito = suma_digitos % 10;
            suma_digitos = (suma_digitos - digito) / 10 + digito;
        }

        printf("Su número de la suerte es: %d\n", suma_digitos);

        printf("¿Desea calcular otro número de la suerte? (s/n): ");
        scanf(" %c", &respuesta);

    } while (respuesta == 's' || respuesta == 'S');

    return 0;
}
