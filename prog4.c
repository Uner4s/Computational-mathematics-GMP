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
    
	mpz_t a,b,x,y,v,u,g,A,B,C,D; 
    mpz_inits(a,b,x,y,v,u,g,A,B,C,D, NULL);

    mpz_set_ui(g,1);// g = 1
    mpz_set_ui(u,1);// u = 1
    mpz_set_str(x, argv[1],0);// ingresa a la variable a el primer numero
    mpz_set_str(y, argv[2],0);//  ingresa a la variable b el segundo numero


    if(mpz_sgn(x) > 0 && mpz_sgn(y) > 0 && mpz_cmp(x,y) >= 0)// mientras x > 0 y y > 0 y x >= y
    {
        while (mpz_even_p(x) != 0 && mpz_even_p(y) != 0){// mientras x e y son pares.
            mpz_fdiv_q_ui(x,x,2);// x = x/2
            mpz_fdiv_q_ui(y,y,2);// y = y/2
            mpz_mul_ui(g,g,2);// g = 2*g
        }

   		    mpz_set(u,x);// u = x
    	    mpz_set(v,y);// v = y
    	    mpz_set_ui(A,1);// A = 1
    	    mpz_set_ui(B,0);// B = 0
    	    mpz_set_ui(C,0);// C = 0
    	    mpz_set_ui(D,1);// D = 1

        while(mpz_cmp_ui(u,0) != 0){// mientras u != 0
    	    while( mpz_even_p(u) != 0 ){ // mientras u sea par
    		    mpz_fdiv_q_ui(u,u,2);// u = u/2
    		    if(mpz_even_p(A) != 0 && mpz_even_p(B) != 0){// si A y B son pares
    			    mpz_fdiv_q_ui(A,A,2);// A = A/2
    			    mpz_fdiv_q_ui(B,B,2);// B = B/2
    		    }
    		    else{
    			    mpz_add(A,A,y);// A = A + y
    			    mpz_fdiv_q_ui(A,A,2);// A = A/2
    			    mpz_sub(B,B,x);// B = B - X
    			    mpz_fdiv_q_ui(B,B,2);// B = B / 2
    		    }
    	    }

    	    while(mpz_even_p(v) != 0){// Mientras v es par
    		    mpz_fdiv_q_ui(v,v,2);// v = v/2
    		    if(mpz_even_p(C) != 0 && mpz_even_p(D) != 0){// Si C y D son pares
    			    mpz_fdiv_q_ui(C,C,2);// C = C/2
    			    mpz_fdiv_q_ui(D,D,2);// D = D/2
    		    }
    		    else{
    			    mpz_add(C,C,y);//C = C+y
    			    mpz_fdiv_q_ui(C,C,2);//C = C/2
    			    mpz_sub(D,D,x);// D = D+x
    			    mpz_fdiv_q_ui(D,D,2);//D = D/2
    		    }
    	    }

    	    if(mpz_cmp(u,v) >= 0){// si u >= v
    		    mpz_sub(u,u,v);// u = u-v
    		    mpz_sub(A,A,C);// A = A-C
    		    mpz_sub(B,B,D);// B = B - D
    	    }
    	    else{
    		    mpz_sub(v,v,u);// v = v - u
    		    mpz_sub(C,C,A);// C = C - A
    		    mpz_sub(D,D,B);  // D = D - B 	
    	    }

    	    if(mpz_cmp_ui(u,0) == 0){// Si u == 0
    		    mpz_set(a,C);// a = C
    		    mpz_set(b,D);// b = D

    	    }
	    }

	    mpz_mul(A,g,v);// A = g * v
        mpz_set_str(x, argv[1],0);// ingresa a la variable a el primer numero
        mpz_set_str(y, argv[2],0);//  ingresa a la variable b el segundo numero

        mpz_mod(a,a,y);// a = a mod y
        mpz_mod(b,b,x);// b = b mod x

        printf("\n Algoritmo numero 4: ");
        printf("\n Algoritmo Euclideano Extendido Binario para el calculo de gcd(x,y) y enteros a y b que satisfacen ax + by = v: ");
        printf("\n Numeros ingresados: \n");
        printf("\n x: ");
        gmp_printf("%Zd\n",x);
        printf("\n y: ");
        gmp_printf("%Zd\n",y);

        printf("\n El gcd(a,b) = u es: ");
        gmp_printf("%Zd\n",A);

        printf("\n Los enteros a y b que satisfacen ax + by = d: ");
        printf("\n a: ");
        gmp_printf("%Zd\n",a);
        printf("\n b: ");
        gmp_printf("%Zd\n",b);


        mpz_clears(a,b,x,y,v,u,g,A,B,C,D, NULL);
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