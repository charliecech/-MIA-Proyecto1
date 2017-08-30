#ifndef ESTRUCTURASDISK_H
#define ESTRUCTURASDISK_H
#include <stdio.h>

typedef struct superbloque{
  int numero_inodos;
  int numero_bloques;
  int tam_bloques;
  int numero_magico;
  int bloques_free;
  int inodos_free;
  char mount_time[128];
  int bitmap_inodos;
  int inodos;
  int bitmap_bloques;
  int bloques;
  //int bitmap_bloquesind;
  int bloquesind;
  int free_inodo;
  int free_bloque;
  //int free_bloqueind;
  int journal;
  int free_journal;
}SB;

typedef struct journaling{
    char fecha[128];
    char descripsion[140];
}J;

typedef struct inodos{
    int id;
    char fecha[128];
    int tam;
    int tipo_dato;
    int bloque_dir1;
    int bloque_dir2;
    int bloque_dir3;
    int bloque_dir4;
    int bloque_ind1;
    int bloque_ind2;
    int user;
    int permiso;
}I;

typedef struct bloquesArchivos{
    char padre[25];
    char nombre[25];
    char informacion[24];
    char extra[2];
}BA;

typedef struct bloquesCarpetas{
    char padre[25];
    char nombre[25];
    /*int hijo1;
    int hijo2;
    int hijo3;
    int hijo4;
    int hijo5;
    int hijo6;*/
    int hijo[6];
}BC;

typedef struct bloquesIndirectos{
    int nivel;
    int apuntador1;
    int apuntador2;
    int apuntador3;
    int apuntador4;
    int apuntador5;
    int apuntador6;
    int extra[12];
}BI;

#endif // ESTRUCTURASDISK_H