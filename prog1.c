#include <gmp.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <sys/time.h>

double timeval_diff(struct timeval *a, struct timeval *b) // Esta funcion recibe los tiempos tomados por referencia y los resta para obtener el tiempo de ejecucion de una parte del codigo, en este caso el ciclo for y la formula de induccion.
{
  return
    (double)(a->tv_sec + (double)a->tv_usec/1000000) - 
    (double)(b->tv_sec + (double)b->tv_usec/1000000);
}

int main(int argc, char *argv[])
{
    struct timeval t_ini, t_fin; // Variables definidas con caracteristas de estructura de tiempo.
    double secs , mili_seg1, mili_seg2; // variables enteras para guardar los milisegundos de ejecucion y realizar su comparacio
    gettimeofday(&t_ini, NULL); // Se inicia el reloj antes del ciclo for.
    mpz_t a, b, r; 
    mpz_inits(r, a, b, NULL); // inicia las variables
    mpz_set_str(a, argv[1],0); // ingresa a la variable a el primer numero
    mpz_set_str(b, argv[2],0);// ingresa a la variable b el segundo numero
    mpz_set_ui(r,0); // r = 0

    if(mpz_sgn(a) > 0 && mpz_sgn(b) > 0 && mpz_cmp(a,b) >= 0)// mientras a > 0 y b > 0 y a >= b
    {
        while(mpz_cmp_ui(b,0) != 0) // mientras b diferente de 0
        {
    	   mpz_mod(r,a,b); // r = a(mod)b
    	   mpz_set(a,b); //  a = b
    	   mpz_set(b,r); //  b = r
        }

        mpz_set_str(r, argv[1], 10); // vuelven a guardarse los valores originales en las variables
        mpz_set_str(b, argv[2], 10); // 

        printf("\n Algoritmo numero 1: ");
        printf("\n Algoritmo Euclideano para el calculo de gcd(a,b): ");
        printf("\n Numeros ingresados: \n");
        printf("\n a: ");
        gmp_printf("%Zd\n",r);
        printf("\n b: ");
        gmp_printf("%Zd\n",b);

        printf("\n El gcd(a,b) es: ");
        gmp_printf("%Zd\n",a); 
        mpz_clears(r, a, b, NULL); //  se limpian las varibles.
        gettimeofday(&t_fin, NULL); // se inicia el reloj con la variable t_fin para realizar una diferencia y obtener el tiempo de ejecucion.
        printf("\n Tiempo final en la ejecucion de las operaciones: ");
        secs = timeval_diff(&t_fin, &t_ini); // llama a la funcion diferencia para sacar el valor del tiempo final de la operacion anterior.
        printf("%.16g milliseconds\n", secs * 1000.0); // muestra el resultado expresado en milisegundos.
        printf("\n Presione ENTER para continuar... ");
    }
    else
    {
        printf("\n Los numeros ingresados no cumplen con la regla requerida: ");
        printf("\n a > 0, b > 0, a >= b "); 
        printf("\n Presione ENTER para continuar... ");  
    }

    getchar();
    system("clear");

    return 0;
}