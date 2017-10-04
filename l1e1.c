#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>
#include <inttypes.h>
#include <string.h>

int64_t timing(struct timespec *j, struct timespec *k);	//Conversion de tiempo a Ms(milisegundos)

int main(int argc, char *argv[]){
	
	int a =atoi(argv[1]);   //variable que convierte el char ingresado al ejecutar el programa (n), en entero
	int b =atoi(argv[2]);	//variable que convierte el char ingresado al ejecutar el programa (r), en entero
	mpz_t n;                //variable n en GMP
	mpz_t r;                //variable r en GMP
	mpz_t nr;               //resta n y r
    mpz_t mult;             //guarda el valor de factorial de r por factorial de (n-r)
    mpz_t i;                //variable index
	mpz_t res;       		//resultado de la combinatoria
	mpz_t aux_n;            //factorial de n
	mpz_t aux_r;            //factorial de r
	mpz_t aux_nr;           //factorial de (n-r)
	mpz_init(n);            //Iniciar var. en GMP
	mpz_init(r);
	mpz_init(nr);
	mpz_init(mult);
	mpz_init(res);
	mpz_init(aux_n);
	mpz_init(aux_r);
	mpz_init(aux_nr);
	mpz_init(i);	
	
	
	struct timespec inicio, fin;	//Variables de tiempo
	uint64_t result;				//Variable de tiempo en ms (usando la funcion int64_t)		
	mpz_set_ui(n,a);                // asignar a n el valor ingresado anteriormente	(en la ejecucion del programa)
	mpz_set_ui(r,b);                // asignar a r el valor ingresado anteriormente (en la ejecucion del programa)	
	clock_gettime(CLOCK_MONOTONIC, &inicio); //Calcula el tiempo de inicio del programa	
	if (mpz_cmp(n,r) == 0){                      //para n=r 		
		printf("\nEl resultado es 1 (el valor de n y r es igual)\n");
		return 0;
	} 
	if (mpz_cmp(n,r) < 0){                       //para r mayor a n, se omite el caso		
		printf("\n**Error** r es mayor a n **Error**\n");
		return 0;
	}	
	mpz_sub(nr,n,r);              // nr=(n-r)
	mpz_set_ui(aux_n,1);		  // Asigna valores 1 a auxiliares
	mpz_set_ui(aux_r,1);
	mpz_set_ui(aux_nr,1);
	mpz_add_ui(n,n,1);
	mpz_add_ui(r,r,1);
	mpz_add_ui(nr,nr,1);
	for (mpz_set_ui(i,1); mpz_cmp(n,i) != 0; mpz_add_ui(i,i,1)){  
		mpz_mul(aux_n,aux_n,i);                                       //calculo de n factorial
	}
	for (mpz_set_ui(i,1); mpz_cmp(r,i) != 0; mpz_add_ui(i,i,1)){
		mpz_mul(aux_r,aux_r,i);                                       //calculo de r factorial
	}
	for (mpz_set_ui(i,1); mpz_cmp(nr,i) !=  0; mpz_add_ui(i,i,1)){
		mpz_mul(aux_nr,aux_nr,i);                                     //calculo de n-r factorial
	}
	mpz_mul(mult,aux_r,aux_nr);                                       //multiplica r factorial por (n-r) factorial
	mpz_div(res,aux_n,mult);                                          //division de n por mult	
	printf("El numero de combinaciones C(n,r) es de ");
	gmp_printf("%Zd",res);                                            //muestra el resultado	
	clock_gettime(CLOCK_MONOTONIC, &fin); 						      //tiempo de termino de la operacion
	result= timing(&inicio,&fin);	
	printf("\nEl Tiempo de ejecucion es de %lf milisegundos\n",((double)result/1000000.0));	
	mpz_clear(n);
	mpz_clear(r);
	mpz_clear(mult);
	mpz_clear(nr);
	mpz_clear(res);
	mpz_clear(aux_n);
	mpz_clear(aux_r);
	mpz_clear(aux_nr);
	mpz_clear(i);	
	return 0;	
}
int64_t timing(struct timespec *j, struct timespec *k){
	return(k->tv_sec - j->tv_sec)*1000000000 + k->tv_nsec - j->tv_nsec;
}

