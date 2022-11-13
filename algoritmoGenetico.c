#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

/*Errores dudas consultas misaelcudek@gmail.com*/
/*https://github.com/misaelcudekmaceiras*/

struct cromosoma
{
    unsigned char gen0:1;
    unsigned char gen1:1;
    unsigned char gen2:1;
    unsigned char gen3:1;

    unsigned char gen4:1;
    unsigned char gen5:1;
    unsigned char gen6:1;
    unsigned char gen7:1;
};//cada gen es un bit dentro de la struct cromosoma

  struct Individuo
{

  char nombre[10];//quiza poner un hash ?
  struct cromosoma c1;
 };
 // La estructura Individuo contiene un  nombre que podria ser un hash 13/11/2022 no implementado
 // La estructura cromosoma contiene 8 bit individualizados con campos de bit que son los genes binarios.
  

#define poblacioINI 10
#define numIteraciones 10

#define minAlgoRand 0
#define maxAlgoRand 100

void generarIndividuo(struct Individuo * i1);
void generarPoblacion(struct Individuo * i1);
void imprimirIndividuo(struct Individuo pob[]);
void imprimirPoblacion(struct Individuo pob[]);
void selecionarIndividuos(struct Individuo pob[]);
void cruzarIndividuos(struct Individuo pob[]);
void mutarIndividuos(struct Individuo pob[]);


int main (void)
{
srandom(time(NULL));//establezco semilla de random //en windows usar srand
  
unsigned int vueltas=numIteraciones;


struct Individuo poblacion[poblacioINI];

generarPoblacion(poblacion);
imprimirPoblacion(poblacion);

do
{
  selecionarIndividuos(poblacion);
  cruzarIndividuos(poblacion);
  mutarIndividuos(poblacion);

  vueltas--;
}while(vueltas>0);//Se iteran numIteraciones veces



return 0;
}

/*Funciones*/


void generarPoblacion(struct Individuo pob[])
{

  for(int i=0;i<poblacioINI;i++)
  {
    generarIndividuo(&(pob[i]));
  }
}




void generarIndividuo(struct Individuo * i1)
{
  //en windows usar rand()
  i1->c1.gen0=((int)(((float)(random())/(float)(RAND_MAX))*(float)(maxAlgoRand-minAlgoRand)))%2;//Tiro random entre minAlgoRand y maxAlgoRand luego %2 0 par 1 impar
  i1->c1.gen1=((int)(((float)(random())/(float)(RAND_MAX))*(float)(maxAlgoRand-minAlgoRand)))%2;//Tiro random entre minAlgoRand y maxAlgoRand luego %2 0 par 1 impar
  i1->c1.gen2=((int)(((float)(random())/(float)(RAND_MAX))*(float)(maxAlgoRand-minAlgoRand)))%2;//Tiro random entre minAlgoRand y maxAlgoRand luego %2 0 par 1 impar
  i1->c1.gen3=((int)(((float)(random())/(float)(RAND_MAX))*(float)(maxAlgoRand-minAlgoRand)))%2;//Tiro random entre minAlgoRand y maxAlgoRand luego %2 0 par 1 impar
  i1->c1.gen4=((int)(((float)(random())/(float)(RAND_MAX))*(float)(maxAlgoRand-minAlgoRand)))%2;//Tiro random entre minAlgoRand y maxAlgoRand luego %2 0 par 1 impar
  i1->c1.gen5=((int)(((float)(random())/(float)(RAND_MAX))*(float)(maxAlgoRand-minAlgoRand)))%2;//Tiro random entre minAlgoRand y maxAlgoRand luego %2 0 par 1 impar
  i1->c1.gen6=((int)(((float)(random())/(float)(RAND_MAX))*(float)(maxAlgoRand-minAlgoRand)))%2;//Tiro random entre minAlgoRand y maxAlgoRand luego %2 0 par 1 impar
  i1->c1.gen7=((int)(((float)(random())/(float)(RAND_MAX))*(float)(maxAlgoRand-minAlgoRand)))%2;//Tiro random entre minAlgoRand y maxAlgoRand luego %2 0 par 1 impar
      //cargo genes aleatoriamente en la pobacion
  //sintaxis fea ver de convertir a array usando macros
}

void imprimirIndividuo(struct Individuo * i1)
{
  if(i1!=NULL)
  {
  printf("%s\t",i1->c1.gen0 ? "SI":"NO" );
  printf("%s\t",i1->c1.gen1 ? "SI":"NO" );
  printf("%s\t",i1->c1.gen2 ? "SI":"NO" );
  printf("%s\t",i1->c1.gen3 ? "SI":"NO" );
  printf("%s\t",i1->c1.gen4 ? "SI":"NO" );
  printf("%s\t",i1->c1.gen5 ? "SI":"NO" );
  printf("%s\t",i1->c1.gen6 ? "SI":"NO" );
  printf("%s\t",i1->c1.gen7 ? "SI":"NO" );
  printf("\n");
  }
}


void imprimirPoblacion(struct Individuo pob[])
{
printf("gen0\tgen1\tgen2\tgen3\tgen4\tgen5\tgen6\tgen7\n");
  for(int i=0;i<poblacioINI;i++)
  {
  imprimirIndividuo(&(pob[i]));
  }
}

void selecionarIndividuos(struct Individuo pob[])
{
  for(int i=0;i<poblacioINI;i++)
  {
    //ACA PONER ALGORITMO DE SELECION
  }

}
void cruzarIndividuos(struct Individuo pob[])
{
    //ACA PONER ALGORITMO DE CRUZAMIENTO
}


void mutarIndividuos(struct Individuo pob[])
{
  //ACA PONER ALGORITMO DE MUTACION
}


