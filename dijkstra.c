#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<math.h>
#define IN 20000
#include<time.h>
#include <sys/time.h>

double timeval_diff(struct timeval *a, struct timeval *b) // Esta funcion recibe los tiempos tomados por referencia y los resta para obtener el tiempo de ejecucion de una parte del codigo, en este caso el ciclo for y la formula de induccion.
{
  return
    (double)(a->tv_sec + (double)a->tv_usec/1000000) -
    (double)(b->tv_sec + (double)b->tv_usec/1000000);
}


int main()
{
    struct timeval t_ini, t_fin; // Variables definidas con caracteristas de estructura de tiempo.
    double secs , mili_seg1, mili_seg2; // variables enteras para guardar los milisegundos de ejecucion y realizar su comparacio
	printf("\t Algoritmo de Dijkstra en C\n");
	int N2,N;
	printf("Ingrese la cantidad de nodos del grafo: ");
    scanf("%d",&N);
    N2=N;
	int n,contador=0;
    int cost[N][N],i,j,w,ch,co;
    int source, target,x,y;
    srand((unsigned)time(NULL));
    
    for(i=1;i< N;i++){
    	for(j=1;j< N;j++){
    		cost[i][j] = IN;
		}
	}
	
    for(x=1;x< N;x++)
    {
        for(y=x+1;y< N;y++)
        {
            n=rand()%10+1;
            if(n == 1 || n == 2 || n == 3){
            	n=rand()%20+1;
            	cost [x][y] = cost[y][x] = n;
            }
            else{
            	cost [x][y] = cost[y][x] = 40000;
            }
        }
    }
	int opcion = 0;
	int iteraciones = 0;
	while(opcion!=1){

    	printf("\nIngrese nodo de Inicio:  \n");
    	scanf("\n%d", &source);
    	printf("\nIngrese nodo de llegada:  \n");
    	scanf("\n%d", &target);
        gettimeofday(&t_ini, NULL); // Se inicia el reloj antes del ciclo for.
    	int distancia[N],prev[N],m,selected[N],min,start,d;
    	for(i=0;i<N;i++){
        	selected[i]=0;
		}
    	char path[N];
    	for(i=1;i< N;i++)
    	{
        	distancia[i] = IN;
        	prev[i] = -1;
    	}
    	start = source;
    	selected[start]=1;
    	distancia[start] = 0;
    	while(selected[target] ==0)
    	{
        	min = IN;
        	m = 0;
        	for(i=1;i< N;i++)
        	{
            	d = distancia[start] +cost[start][i];
            	if(d< distancia[i]&&selected[i]==0)
            	{
                	distancia[i] = d;
                	prev[i] = start;
            	}
            	if(min>distancia[i] && selected[i]==0)
            	{
                	min = distancia[i];
                	m = i;
            	}
        	}
        	start = m;
        	selected[start] = 1;
        	iteraciones++;
        	
    	}
    	start = target;
    	j = 0;
        int camino[N],contador2=0;
    	while(start != -1)
    	{
        	camino[contador2]=start;
        	start = prev[start];
            contador2++;
    	}
        contador2--;
        while(contador2>=0){
            printf("--->  %d",camino[contador2]);
            contador2--;
        }
    	co=distancia[target];
        gettimeofday(&t_fin, NULL); // se inicia el reloj con la variable t_fin para realizar una diferencia y obtener el tiempo de ejecucion.
    	printf("\nEl camino mas corto es de peso : %d",co);
    	if(iteraciones == 1){
    		printf("\nEl camino encontrado es un camino directo");
    		printf("\nNumero de Iteraciones : %d",iteraciones);
    	}
    	else{
    		printf("\nNumero de Iteraciones : %d",iteraciones);
    	}
        printf("\n Tiempo final en la ejecucion de las operaciones: ");
        secs = timeval_diff(&t_fin, &t_ini); // llama a la funcion diferencia para sacar el valor del tiempo final de la operacion anterior.
        printf("%.16g milliseconds\n", secs * 1000.0); // muestra el resultado expresado en mili
        printf("\nDesea ingresar otro camino? (Si -> 0) (No -> 1)");
    	scanf("\n%d", &opcion);
        system("clear");
    	
	}
    return 0;
}
