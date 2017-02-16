/* Universidade Federal da Paraíba
   Bacharelado em Engenharia de Computação

   Aluno - Matheus Amorim de Almeida Santiago
   Matrícula - 11500715

   Fun With Sequences
   You are given a sorted sequence of N integers S= S1, S2, ..., Sn and a sorted sequence of M integers Q= Q1, Q2, ..., Qm.
   Please print in the ascending order all such Si that doesn't belong to Q.

   Input - In the first line you are given one integer 2<= n <=100, and in the following line N integers: -100<= Si <= 100, Si<= Si+1.
   In the third line you are given one integer 2<=m<=100, and in the following line M integers: -100 <= Qi <=100, Qi <= Qi+1.

   Output - The sequence of requested integers separated by spaces.
*/

#include <stdio.h>

#define MAX 100

int main(void){

	int S = 0, Q = 0;
	int i = 0, m = 0;
	int listaS[MAX];
	int listaQ[MAX];
	int output[MAX];

/*Lista S*/
	scanf("%d", &S);
	listaS[S];


	for(i = 0; i < S; i++){
		scanf("%d", &listaS[i]);
	}

/*Lista Q*/
	scanf("%d", &Q);
	listaQ[Q];

	for(i = 0; i < Q; i++){
		scanf("%d", &listaQ[i]);
	}

	for(i = 0; i < S; i++){

		for(m = 0; m < Q; m++){
			if(listaS[i] == listaQ[m]){
				break;
			}
		}
		if (m == Q){
            printf("%d ", listaS[i]);
		}
	}

	printf("\n");

	return 0;
}

