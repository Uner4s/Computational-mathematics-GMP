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
	mpz_t j, n,k,i;
	mpz_inits(j,n,i,k,NULL);
	mpz_set_str(n, argv[1], 10);
	mpz_set_ui(j,0);
    mpz_set_ui(i,1);

    gettimeofday(&t_ini, NULL); // Se inicia el reloj antes del ciclo for.
    for(mpz_set_ui(k,1);mpz_cmp(k,n) <= 0; mpz_add_ui(k,k,1)){
        mpz_add(j,j,i);
        mpz_sub(i,j,i);
    }
    gettimeofday(&t_fin, NULL); // se inicia el reloj con la variable t_fin para realizar una diferencia y obtener el tiempo de ejecucion.
    
    printf("\n El N ingresado es: ");
    gmp_printf("%Zd",n);
    printf("\n El n-esimo termino de la serie fibbonacci es: ");
    gmp_printf("%Zd\n",j);
    printf("\n Tiempo final en la ejecucion de las operaciones: ");
    secs = timeval_diff(&t_fin, &t_ini); // llama a la funcion diferencia para sacar el valor del tiempo final de la operacion anterior.
    printf("%.16g milliseconds\n", secs * 1000.0); // muestra el resultado expresado en mili
    printf("\n Presione ENTER para continuar... ");
    getchar();
    mpz_clears(n,j,k,i, NULL);
    system("clear");
}