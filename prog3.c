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
    mpz_t a,b,x,y,x1,y1,x2,y2,q,d,r; 
    mpz_inits(a,b,x,y,x1,y1,x2,y2,q,d,r, NULL);
    mpz_set_str(a, argv[1],0); // ingresa a la variable a el primer numero
    mpz_set_str(b, argv[2],0); //  ingresa a la variable b el segundo numero

    if(mpz_sgn(a) > 0 && mpz_sgn(b) > 0 && mpz_cmp(a,b) >= 0)// mientras a > 0 y b > 0 y a >= b
    {
        if(mpz_cmp_ui(b,0) == 0){
    	   mpz_set(d,a); // d = a
    	   mpz_set_ui(x,1); // x = 1 
    	   mpz_set_ui(y,0);//  y = 0
        }

        mpz_set_ui(x2,1); // x2 = 1
        mpz_set_ui(x1,0); // x1 = 0 
        mpz_set_ui(y2,0);//  y2 = 0
        mpz_set_ui(y1,1);//  y1 = 1

        while(mpz_cmp_ui(b,0) > 0){

    	   mpz_fdiv_q(q,a,b);// q = a/b 
    	   mpz_mul(r,q,b);// r = q*b
    	   mpz_sub(r,a,r);// r = a*r
    	   mpz_mul(x,q,x1);// x = q*x1
    	   mpz_sub(x,x2,x);// x = x2-x
    	   mpz_mul(y,q,y1);// y = q*y1
    	   mpz_sub(y,y2,y);// y = y2-y

    	   mpz_set(a,b);// a=b
    	   mpz_set(b,r);// b = r
    	   mpz_set(x2,x1);// x2 = x1
    	   mpz_set(x1,x);//  x1 = x
    	   mpz_set(y2,y1);// y2 = y1
    	   mpz_set(y1,y);// y1 = y

        }

        mpz_set(d,a);// d = a
        mpz_set(x,x2);//  x = x2
        mpz_set(y,y2);//  y = y2

        mpz_set_str(a, argv[1], 10); 
        mpz_set_str(b, argv[2], 10);
    
        mpz_mod(x,x,b);// x = x mod b
        mpz_mod(y,y,a);// y = y mod a

        printf("\n Algoritmo numero 3: ");
        printf("\n Algoritmo Euclideano Extendido para el calculo de gcd(a,b) y enteros x e y que satisfacen ax + by = d: ");
        printf("\n Numeros ingresados: \n");
        printf("\n a: ");
        gmp_printf("%Zd\n",a);
        printf("\n b: ");
        gmp_printf("%Zd\n",b);


        printf("\n El gcd(a,b) = d es: ");
        gmp_printf("%Zd\n",d);

        printf("\n Los enteros x e y que satisfacen ax + by = d: ");
        printf("\n x: ");
        gmp_printf("%Zd\n",x);
        printf("\n y: ");
        gmp_printf("%Zd\n",y);

        gettimeofday(&t_fin, NULL); // se inicia el reloj con la variable t_fin para realizar una diferencia y obtener el tiempo de ejecucion.
        printf("\n Tiempo final en la ejecucion de las operaciones: ");
        secs = timeval_diff(&t_fin, &t_ini); // llama a la funcion diferencia para sacar el valor del tiempo final de la operacion anterior.
        printf("%.16g milliseconds\n", secs * 1000.0); // muestra el resultado expresado en mili
        mpz_clears(a,b,x,y,x1,y1,x2,y2,q,d,r, NULL);

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