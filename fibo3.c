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
	mpz_t x,w,y,z,aux1,aux2,xp,wp,yp,zp,n,naux;
	mpz_inits(x,w,y,z,aux1,aux2,xp,wp,yp,zp,n,naux,NULL);
	mpz_set_str(n, argv[1], 10);


	mpz_set_ui(x,1);
	mpz_set_ui(w,1);
	mpz_set_ui(y,1);
	mpz_set_ui(z,0);
	mpz_set_ui(naux,1);
	
	if( mpz_cmp_ui(n,0) == 0 ){
		gettimeofday(&t_ini, NULL); // Se inicia el reloj antes del ciclo for.
		printf("\n El N ingresado es: %d",0 );
		printf("\n El n-esimo numero (0) de la secuencia Fibonacci es: %d ", 0);
		printf("\n El numero siguiente del n-esimo termino ingresado es %d: ", 1);
		gettimeofday(&t_fin, NULL); // se inicia el reloj con la variable t_fin para realizar una diferencia y obtener el tiempo de ejecucion.
    	secs = timeval_diff(&t_fin, &t_ini); // llama a la funcion diferencia para sacar el valor del tiempo final de la operacion anterior.
    	printf(" \n Tiempo final en la ejecucion de la operacion: ");
    	printf("%.16g milliseconds\n", secs * 1000.0); // muestra el resultado expresado en mili
    	printf("\n Presione ENTER para continuar... ");
    	mpz_clears(x,w,y,z,aux1,aux2,xp,wp,yp,zp,n,naux, NULL);
    	getchar();
    	system("clear");
	}
	else if( mpz_cmp_ui(n,1) == 0 ){
		gettimeofday(&t_ini, NULL); // Se inicia el reloj antes del ciclo for.
		printf("\n El N ingresado es: %d",1 );
		printf("\n El n-esimo numero (1) de la secuencia Fibonacci es: %d", 1);
		printf("\n El numero anterior del n-esimo termino ingresado es: %d", 0);
		printf("\n El numero siguiente del n-esimo termino ingresado es: %d", 1);
		gettimeofday(&t_fin, NULL); // se inicia el reloj con la variable t_fin para realizar una diferencia y obtener el tiempo de ejecucion.
    	secs = timeval_diff(&t_fin, &t_ini); // llama a la funcion diferencia para sacar el valor del tiempo final de la operacion anterior.
    	printf(" \n Tiempo final en la ejecucion de la operacion: ");
    	printf("%.16g milliseconds\n", secs * 1000.0); // muestra el resultado expresado en mili
    	printf("\n Presione ENTER para continuar... ");
    	mpz_clears(x,w,y,z,aux1,aux2,xp,wp,yp,zp,n,naux, NULL);
    	getchar();
    	system("clear");
	}
	else{
		//------------------------------------------------------------------------
		gettimeofday(&t_ini, NULL); // Se inicia el reloj antes del ciclo for.
		while(mpz_cmp(naux,n) < 0){


			mpz_mul_ui(aux1,x,1);
			mpz_mul_ui(aux2,w,1);
			mpz_add(xp,aux1,aux2);

			mpz_mul_ui(aux1,x,1);
			mpz_mul_ui(aux2,w,0);
			mpz_add(wp,aux1,aux2);

			mpz_mul_ui(aux1,y,1);
			mpz_mul_ui(aux2,z,1);
			mpz_add(yp,aux1,aux2);

			mpz_mul_ui(aux1,y,1);
			mpz_mul_ui(aux2,z,0);
			mpz_add(zp,aux1,aux2);

			mpz_set(x,xp);
			mpz_set(w,wp);
			mpz_set(y,yp);
			mpz_set(z,zp);

			mpz_add_ui(naux,naux,1);

		}
		gettimeofday(&t_fin, NULL); // se inicia el reloj con la variable t_fin para realizar una diferencia y obtener el tiempo de ejecucion.
		//------------------------------------------------------------------------
		printf("\n El N ingresado es: ");
		gmp_printf("%Zd",n);
		printf("\n El n-esimo numero de la secuencia Fibonacci es: ");
		gmp_printf("%Zd",w);
		printf("\n El numero anterior del n-esimo termino ingresado es: ");
		gmp_printf("%Zd",z);
		printf("\n El numero siguiente del n-esimo termino ingresado es: ");
		gmp_printf("%Zd",x);
    	secs = timeval_diff(&t_fin, &t_ini); // llama a la funcion diferencia para sacar el valor del tiempo final de la operacion anterior.
    	printf(" \n Tiempo final en la ejecucion de la operacion: ");
    	printf("%.16g milliseconds\n", secs * 1000.0); // muestra el resultado expresado en mili
    	printf("\n Presione ENTER para continuar... ");
    	mpz_clears(x,w,y,z,aux1,aux2,xp,wp,yp,zp,n,naux, NULL);
    	getchar();
    	system("clear");
	}



}