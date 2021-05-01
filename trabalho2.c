/*============================================================================*/
/* IF61C - TRABALHO 2                                                         */
/*----------------------------------------------------------------------------*/
/* Autor: Vin�cius Pinheiro
/*============================================================================*/

#include <stdlib.h>
#include <math.h>

#include "trabalho2.h"

/**
 * Adiciona uma esp�cie de "estalo" no �udio. O intervalo passado define quanstos estalos ir�o aparecer.
 * Quanto menor o n�mero do intervalo, mais evidente fica.
 *
 * @double* dados: vetor de dados.
 * @unsigned long n_amostras: n�mero de amostras no vetor.
 * @unsigned short intervalo: o n�mero de amostras entre dois pontos de ru�do � intervalo-1.
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
 * Utiliza a mediana entre 3 valores, para eliminar o ruido. A mediana seria o valor mais pr�ximo da fun��o,
 * considerando que os ru�dos est�o nos extremos do intervalo. Cria um vetor aulixiar, para que os novos
 * valores da mediana n�o influeciem nos anteriores.
 *
 * @double* dados: vetor de dados.
 * @unsigned long n_amostras: n�mero de amostras no vetor.
 *
 * Valor de Retorno: nenhum.
 **/
 void removeRuido (double* dados, unsigned long n_amostras)
 {
     double *vetorAuxiliar = dados;
     int i;
     /* O primeiro e o �ltimo valor permanecem iguais: */
     for (i = 1; i < (n_amostras - 1); i++)
     {
         /* Encontra o valor do meio (supondo A, B e C): */
        if (vetorAuxiliar[i-1] > vetorAuxiliar[i])
        {
            if (vetorAuxiliar[i] > vetorAuxiliar[i+1])
                dados[i] = vetorAuxiliar[i]; // O do meio � o B
            else if (vetorAuxiliar[i-1] > vetorAuxiliar[i + 1])
                dados[i] = vetorAuxiliar[i+1]; // O do meio � o C
            else
                dados[i] = vetorAuxiliar[i-1]; // O do meio � o A
        }
        else if (vetorAuxiliar[i] > vetorAuxiliar[i+1])
        {
            if (vetorAuxiliar[i-1] > vetorAuxiliar[i+1])
                dados[i] = vetorAuxiliar[i-1]; // O do meio � o A
            else
                 dados[i] = vetorAuxiliar[i+1]; // O do meio � o C
        }
        else
            dados[i] = vetorAuxiliar[i]; // O do meio � o B
     }
 }

/**
 * Utiliza a mediana entre 3 valores, para eliminar o ruido. A mediana seria o valor mais pr�ximo da fun��o,
 * considerando que os ru�dos est�o nos extremos do intervalo. Cria um vetor aulixiar, para que os novos
 * valores da mediana n�o influeciem nos anteriores.
 *
 * @double* dados: vetor de dados.
 * @unsigned long n_amostras: n�mero de amostras no vetor.
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
