#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
    Programa que mediante instruccion RDTSC genera nums pseudoaletorios 
    mediante los ticks que lleva el CPU internamente

    Este programa necesita ser compilado con cualquier compilador que no sea el visual studio compiler
*/

static inline uint64_t rdtsc() { // Instruccion RDTSC (Cuenta los ticks del CPU en ASM)
    unsigned int lo, hi; // Variables Low y High que guardaremos los valores del registro EAX y EDX
    __asm__ volatile ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((uint64_t)hi << 32) | lo; // Retornamos los 2 valores juntos como 1 de 64 bits
    /*
     *
     * a = 0xA = 1010
     * al desplazarlos en 8 se queda como 1010 0000 0000
     * 0xff 0 1111 1111 
     * 1010 0000 0000 + 1111 1111 = 1010 1111 1111
     * 
     */
}


int main() {

    srand((uint32_t)rdtsc()); // Llamamos a srand y convertimos el valor de la instruccion RDTSC a 32 bits

    size_t size_pass = rand() %56 + 8; // Definimos tamaño maximo y minimo de nuestra contraseña siendo %56 el resultado de 64 - 8 y 8 el valor minimo

    uint8_t* Mem = (uint8_t*) malloc(size_pass + 1); // Reservamos memoria
    memset(Mem, 0, size_pass + 1); // La ponemos a 0


    for (int i = 0; i < size_pass; i++) {
        size_t time_now = (size_t)rdtsc(); // Guardamos los ticks generados en la variable time_now
        // printf("%zu\n", time_now); Imprime los ticks
        srand(time_now); // Generamos num random con los ticks


        int num_random = rand() % 94 + 32; // Generamos el caracter random desde el 32 en tabla ascii hasta el 126
        // printf("%d %c\n", num_random,num_random); imprime num aleatoria con chars
        Mem[i] = num_random; // Memoria = Num random
    }   
    printf("Password: %s\n", Mem);
    free(Mem); // Liberamos memoria
    Mem = NULL; // Ponemos memoria = null para evitar punteros colgantes
    return 0;
}
