/*============================================================================*/
/* IF61C - TRABALHO 2                                                         */
/*----------------------------------------------------------------------------*/
/* Autor: Vinícius Pinheiro
/*============================================================================*/

#include <stdlib.h>
#include <math.h>

#include "trabalho2.h"

/**
 * Adiciona uma espécie de "estalo" no áudio. O intervalo passado define quanstos estalos irão aparecer.
 * Quanto menor o número do intervalo, mais evidente fica.
 *
 * @double* dados: vetor de dados.
 * @unsigned long n_amostras: número de amostras no vetor.
 * @unsigned short intervalo: o número de amostras entre dois pontos de ruído é intervalo-1.
 *
 * Valor de Retorno: nenhum.
 **/
 void ruidoPeriodico (double* dados, unsigned long n_amostras, unsigned short intervalo)
 {
    int i, valor = 1;
    for (i = 0; i < n_amostras; i += intervalo)
    {
        dados[i] = valor;
        if (!(valor))
            valor = 1;
        else
            valor = 0;
    }
 }

 /**
 * Utiliza a mediana entre 3 valores, para eliminar o ruido. A mediana seria o valor mais próximo da função,
 * considerando que os ruídos estão nos extremos do intervalo. Cria um vetor aulixiar, para que os novos
 * valores da mediana não influeciem nos anteriores.
 *
 * @double* dados: vetor de dados.
 * @unsigned long n_amostras: número de amostras no vetor.
 *
 * Valor de Retorno: nenhum.
 **/
 void removeRuido (double* dados, unsigned long n_amostras)
 {
     double *vetorAuxiliar = dados;
     int i;
     /* O primeiro e o último valor permanecem iguais: */
     for (i = 1; i < (n_amostras - 1); i++)
     {
         /* Encontra o valor do meio (supondo A, B e C): */
        if (vetorAuxiliar[i-1] > vetorAuxiliar[i])
        {
            if (vetorAuxiliar[i] > vetorAuxiliar[i+1])
                dados[i] = vetorAuxiliar[i]; // O do meio é o B
            else if (vetorAuxiliar[i-1] > vetorAuxiliar[i + 1])
                dados[i] = vetorAuxiliar[i+1]; // O do meio é o C
            else
                dados[i] = vetorAuxiliar[i-1]; // O do meio é o A
        }
        else if (vetorAuxiliar[i] > vetorAuxiliar[i+1])
        {
            if (vetorAuxiliar[i-1] > vetorAuxiliar[i+1])
                dados[i] = vetorAuxiliar[i-1]; // O do meio é o A
            else
                 dados[i] = vetorAuxiliar[i+1]; // O do meio é o C
        }
        else
            dados[i] = vetorAuxiliar[i]; // O do meio é o B
     }
 }

/**
 * Utiliza a mediana entre 3 valores, para eliminar o ruido. A mediana seria o valor mais próximo da função,
 * considerando que os ruídos estão nos extremos do intervalo. Cria um vetor aulixiar, para que os novos
 * valores da mediana não influeciem nos anteriores.
 *
 * @double* dados: vetor de dados.
 * @unsigned long n_amostras: número de amostras no vetor.
 *
 * Valor de Retorno: nenhum.
 **/
 void inverteSinal (double* dados, unsigned long n_amostras)
 {
     double *vetorAuxiliar = dados;
     int i, j = 0;
     for (i = (n_amostras - 1); i > 0; i--)
     {
         dados[j] = vetorAuxiliar[i];
         j++;
     }
 }
