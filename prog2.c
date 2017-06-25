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
    mpz_t x,y,g,t,r1,r2,aux;
    mpz_inits(x,y,g,t,r1,r2,aux, NULL); // Se inician las variables.
    mpz_set_str(x, argv[1], 10); // ingresa a la variable a el primer numero
    mpz_set_str(y, argv[2], 10);//  ingresa a la variable b el segundo numero
    mpz_set_ui(g,1); // g = 1
    mpz_set_ui(aux,0); // aux = 0


    if(mpz_sgn(x) > 0 && mpz_sgn(y) > 0 && mpz_cmp(x,y) >= 0)// mientras x > 0 y y > 0 y x >= y
    {
        while(mpz_even_p(x) != 0 && mpz_even_p(y) !=0 ) //  mientras x e y son pares
        {
    	   mpz_fdiv_q_ui(x, x, 2);  //  x = x/2
            mpz_fdiv_q_ui(y, y, 2); //  y = y/2
            mpz_mul_ui(g, g, 2); // g = g/2
        }
        while(mpz_cmp(x,aux) != 0){ // mientras x != aux
            while(mpz_even_p(x) != 0){ // mientras x es par
                mpz_fdiv_q_ui(x, x, 2); // x = x/2
            }
            while(mpz_even_p(y) != 0){ //  mientras y es par
                mpz_fdiv_q_ui(y, y, 2); // y = y/2
            }
            mpz_sub(t,x,y); // t = x - y
            mpz_abs(t,t); // t = | t |
            mpz_fdiv_q_ui(t,t,2); //  t = t/2

            if(mpz_cmp(x,y) >= 0){ // si x >= y 
                mpz_set(x,t);
            }
            else{
                mpz_set(y,t); // y = t
            }
        }
        mpz_mul(aux,g,y); // aux = g * y
    
        mpz_set_str(x, argv[1], 10); 
        mpz_set_str(y, argv[2], 10);

        printf("\n Algoritmo numero 2: ");
        printf("\n Algoritmo Binario para el calculo de gcd(a,b): ");
        printf("\n Numeros ingresados: \n");
        printf("\n x: ");
        gmp_printf("%Zd\n",x);
        printf("\n y: ");
        gmp_printf("%Zd\n",y);

        printf("\n El gcd(a,b) es: ");
        gmp_printf("%Zd\n",aux); 
        mpz_clears(x,y,g,t,r1,r2,aux, NULL); //  se limpian las variables
        gettimeofday(&t_fin, NULL); // se inicia el reloj con la variable t_fin para realizar una diferencia y obtener el tiempo de ejecucion.
        printf("\n Tiempo final en la ejecucion de las operaciones: ");
        secs = timeval_diff(&t_fin, &t_ini); // llama a la funcion diferencia para sacar el valor del tiempo final de la operacion anterior.
        printf("%.16g milliseconds\n", secs * 1000.0); // muestra el resultado expresado en mili
        printf("\n Presione ENTER para continuar... ");
    }
    else
    {
        printf("\n Los numeros ingresados no cumplen con la regla requerida: ");
        printf("\n x > 0, y > 0, x >= y "); 
        printf("\n Presione ENTER para continuar... ");  
    }
    getchar();
    system("clear");

    return 0;
}