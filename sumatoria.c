#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>


double timeval_diff(struct timeval *a, struct timeval *b) // Esta funcion recibe los tiempos tomados por referencia y los resta para obtener el tiempo de ejecucion de una parte del codigo, en este caso el ciclo for y la formula de induccion.
{
  return
    (double)(a->tv_sec + (double)a->tv_usec/1000000) -
    (double)(b->tv_sec + (double)b->tv_usec/1000000);
}


int main(int argc, char *argv[])
{ // Funcion que muestra los primeros n numeros de una sumatoria al cubo con funcion iterativa normal sin induccion.

	system("clear"); // Limpia la pantalla de la terminal.
  	struct timeval t_ini, t_fin; // Variables definidas con caracteristas de estructura de tiempo.
  	double secs , mili_seg1, mili_seg2; // variables enteras para guardar los milisegundos de ejecucion y realizar su comparacion.

 	unsigned long long resultado=0; //definicion de variable para obtener el resultado del algoritmo sin induccion.
 	unsigned long long i=0; // definida para la multiplicacion de numeros grandes dentro del ciclo for.
 	int inicial; // Variable que toma el valor ingresado por el usuario para ser utilizado como parametro de ejecucion del for.


	unsigned long long Valor_final; // Variable que toma el resultado final de la formula de induccion matematica.
 	unsigned long long inicial_2; // definida para la multiplicacion de numeros grandes dentro de la formula de induccion matematica.
 	
       inicial = atoi(argv[1]); // Funcion que transforma una cadena char a un numero entero asignandolo.
	inicial_2 = inicial; // Funcion que transforma una cadena char a un numero entero asignandolo.

	
 	if(inicial <= 0 || isdigit(inicial) != 0 || inicial > 80000) // If que mantiene los numeros ingreados por el usuario dentro de un paramtro.
 	{
 		printf("No existen los parametros suficientes para realizar esta operacion.");
 	}
 	else
 	{
		gettimeofday(&t_ini, NULL); // Se inicia el reloj antes del ciclo for.
		//-----------------------------------------------------------------------------------------------------------------
 		for (i=1; i <= inicial; i++)
	 	{
	 		resultado=resultado+(i*i*i); // Va sumando uno por uno los valores al cubo de 0 hasta n del numero ingresado por el usuario.
  	 	}
  		//-----------------------------------------------------------------------------------------------------------------
		gettimeofday(&t_fin, NULL); // se inicia el reloj con la variable t_fin para realizar una diferencia y obtener el tiempo de ejecucion.
		
		printf("\n Numero ingresado: %d ", inicial); // Muestra por pantalla el numero ingresado por el usuario.
		printf("\n");
 		printf("\n El valor de la sumatoria con la primera estrategia es: %llu", resultado); //despliega resultado, el comando %llu es para mostrar numeros grandes
		printf(" \n Tiempo final en la ejecucion de las operaciones: ");
		secs = timeval_diff(&t_fin, &t_ini); // llama a la funcion diferencia para sacar el valor del tiempo final de la operacion anterior.
  		printf("%.16g milliseconds\n", secs * 1000.0); // muestra el resultado expresado en milisegundos.
		mili_seg1 = secs; // Variable que guarda el valor del  tiempo de la primera operacion.

		gettimeofday(&t_ini, NULL); // Se inicia el reloj antes de la formula.
		//-----------------------------------------------------------------------------------------------------------------
		Valor_final = ((((inicial_2*(inicial_2 + 1)))/2)*(((inicial_2*(inicial_2 + 1)))/2)); // Se expresa la formula de induccion matematica de forma explicita.
		//-----------------------------------------------------------------------------------------------------------------
		gettimeofday(&t_fin, NULL);// se inicia el reloj con la variable t_fin para realizar una diferencia y obtener el tiempo de ejecucion.

		
 		printf("\n El valor de la sumatoria con la estrategia de induccion matematica es: %llu", Valor_final); //despliega resultado, el comando %llu es para mostrar numeros grandes resultado
		printf(" \n Tiempo final en la ejecucion de la operacion: ");
		secs = timeval_diff(&t_fin, &t_ini);// llama a la funcion diferencia para sacar el valor del tiempo final de la operacion anterior.
  		printf("%.16g milliseconds\n", secs * 1000.0); // muestra el resultado expresado en milisegundos.
		mili_seg2 = secs; // Variable que guarda el valor del  tiempo de la segunda operacion.

		secs = (mili_seg1 - mili_seg2); // toma el valor de la resta entre ambos tiempos de ejecucion de los algoritmos para saber cual es la diferencia en milisegundos.
		printf("\n");
		printf("\n Diferencia de tiempo entre ambos algoritmos: "); // muestra el valor en milisegundos al comparar ambos algoritmos.
		printf("%.16g milliseconds\n", secs * 1000.0);// muestra el resultado expresado en milisegundos.

	}
	printf("\n Presione Enter para continuar...");
	getchar();
	system("clear");
	
 	return 0;
} 

