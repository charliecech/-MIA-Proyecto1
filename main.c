#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include "disk.h"
#include "estructurasdisk.h"
#include "split.h"
#define MAX_DISCO 20
//#define MAX_NOMBRE 50
#define MAX_RUTA 50
#define MAX_NAME_SZ 1105
// Variables globales
char nombre_disco[MAX_DISCO];
char rutaDisco[MAX_RUTA];
//char* nombre_disco;
//char* rutaDisco;
int main()
{
    /*remove("hola");
    system("nano hola");
    /*char cadena[]="Home/Carlos";
        int i;
        char **retorno=split(cadena, '/');
        for(i=0;retorno[i]!=NULL;i++)
        {
            printf("%s\n", retorno[i]);
            free(retorno[i]);
        }
        free(retorno);*/
    //nombre_disco = (char*)malloc(MAX_DISCO);
    //rutaDisco = (char*)malloc((MAX_RUTA));
    /*SB super1;
    printf("%d \n", sizeof(super1));
    J jour;
    printf("%d \n", sizeof(jour));
    I inodos;
    printf("%d \n", sizeof(inodos));
    BA ba;
    printf("%d \n", sizeof(ba));
    BC bc;
    printf("%d \n", sizeof(BC));
    BI bi;
    printf("%d \n", sizeof(bi));
    BM bm;
    printf("%d \n", sizeof(bm));*/
    //char nombre_alumno[MAX_NOMBRE];
    //char carne[MAX_NOMBRE];
    setlocale(LC_ALL, "spanish");
    MenuPrincipal();
    return 0;
}

void MenuPrincipal(){
    fflush(stdin);
    int opcion = 0;
    int carne,tamano_disco = 0;
    while (opcion != 17){
        fflush(stdin);
        printf(" ============================================================================= \n");
        printf("                                Menu principal \n");
        printf(" ============================================================================= \n");
        printf("  1. Crear disco \n");
        printf("  2. Montar Disco \n");
        printf("  3. Estado bloques e inodos \n");
        printf("  4. Desmontar disco \n");
        printf("  5. Bitacora \n");
        printf("  6. Visor De Archivos \n");
        printf("  7. Crear Carpeta \n");
        printf("  8. Crear Archivo \n");
        printf("  9. Visor De Carpeta \n");
        printf(" 10. Eliminar Archivo o Carpeta \n");
        printf(" 11. Mover Archivo o Carpeta \n");
        printf(" 12. Modificar Archivo \n");
        printf(" 16. Reporte Directorios \n");
        printf(" 17. Salir \n");
        printf(" -----------------------------------------------------------------------------\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion){
        case 1:
            fflush(stdin);
            // Seccion para crear el disco
            system("clear");
            if (!isEmpty(rutaDisco,"")) {
                printf(" ============================================================================= \n");
                printf("                                 Crear disco \n");
                printf(" ============================================================================= \n");
                printf(" Ingrese el nombre del disco: ");
                scanf("%s", &nombre_disco);
                printf(" Ingrese el tamano del disco (en MB): ");
                fflush(stdin);
                scanf("%d", &tamano_disco);
                printf(" Ingrese al ruta del disco: ");
                fflush(stdin);
                scanf("%s", &rutaDisco);
                /*printf(" Ingrese el nombre del alumno: ");
                // %limite[regex]
                scanf("%s", nombre_alumno);*/
                printf(" Ingrese el registro academico: ");
                fflush(stdin);
                scanf("%d", &carne);
                /*printf(" Ingrese la cantidad de bloques: ");
                scanf("%d", &bloques);*/
                crear_disco(nombre_disco, tamano_disco, carne, rutaDisco);
            }else{
                printf(" Existe un disco montado!");
            }
            break;

        case 2:
            fflush(stdin);
            system("clear");
            if (!isEmpty(rutaDisco,"")) {
                printf(" ============================================================================= \n");
                printf("                                Montar Disco \n");
                printf(" ============================================================================= \n");
                printf(" Ingrese el nombre del disco: ");
                scanf("%s", &nombre_disco);
                printf(" Ingrese al ruta del disco: ");
                fflush(stdin);
                scanf("%s", &rutaDisco);
                if (montar_disco(nombre_disco,rutaDisco)) {
                    printf(" El disco se monto correctamente! \n");
                }else{
                    memset(&rutaDisco,0,sizeof(rutaDisco));
                    memset(&nombre_disco,0,sizeof(nombre_disco));
                    perror(" Error al montar el disco verificar que la ruta este correcta \n");
                }
            }else{
                printf(" Ya existe un disco montado!\n");
            }
            /*printf(" Ingrese la cantidad de bloques: ");
            scanf("%d", &bloques);*/
            //ingresar_bloques(nombre_disco, bloques,rutaDisco);
            break;

        case 3:
            fflush(stdin);
            system("clear");
            if (!isEmpty(rutaDisco,"")) {
                perror(" No existe ningun disco montando!\n");
            }else{
                printf(" ============================================================================= \n");
                printf("                              Estado De Los BitMap \n");
                printf(" ============================================================================= \n\n");
                estado_bloques(nombre_disco,rutaDisco);
                estado_inodos(nombre_disco,rutaDisco);
            }
            break;

        case 4:
            fflush(stdin);
            // Mostrar el disco
            system("clear");
            char op[MAX_RUTA];
            printf(" ============================================================================= \n");
            printf("                               Desmontar disco \n");
            printf(" ============================================================================= \n");
            printf(" Desea desmontar el disco: %s",nombre_disco);
            printf("\n Ingrese \"S\" para confirmar.");
            scanf("%s", &op);
            if (strcmp(op, "S") == 0) {
                memset(&rutaDisco,0,sizeof(rutaDisco));
                memset(&nombre_disco,0,sizeof(nombre_disco));
                printf(" El disco fue desmontado correctamente!\n");
            } else {
                printf(" El disco continuara funcionando en el sistema!\n");
            }
            break;
        case 5:
            fflush(stdin);
            // Mostrar el disco
            system("clear");
            if (!isEmpty(rutaDisco,"")) {
                perror(" No existe ningun disco montando!\n");
            }else{
                printf(" ============================================================================= \n");
                printf("                                Bitacora \n");
                printf(" ============================================================================= \n\n");
                bitacora(nombre_disco,rutaDisco);
            }
            break;
        case 7:
            fflush(stdin);
            system("clear");
            char nombreC[25];
            char path[100];
            memset(&nombreC,0,sizeof(nombreC));
            memset(&path,0,sizeof(path));
            if (isEmpty(rutaDisco,"")) {
                printf(" ============================================================================= \n");
                printf("                              Crear carpeta \n");
                printf(" ============================================================================= \n");
                printf(" Ingrese el nombre de la carpeta: ");
                scanf("%s", &nombreC);
                printf(" Ingrese la ruta donde se creara la carpeta: ");
                fflush(stdin);
                scanf("%s", &path);
                char subbuff[strlen(path)];
                memcpy( subbuff, &path[1], strlen(path)-1);
                subbuff[strlen(path)-1] = '\0';
                        //int i;
                char **retorno=split(subbuff, '/');
                crear_carpeta(nombre_disco,rutaDisco,path,retorno,nombreC);
                free(retorno);
                        /*for(i=0;retorno[i]!=NULL;i++)
                        {
                            printf("%s\n", retorno[i]);
                            free(retorno[i]);
                        }*/
            }else{
                printf(" No existe ningun disco montando!\n");
            }
            /*printf(" Ingrese la cantidad de bloques: ");
            scanf("%d", &bloques);*/
            //ingresar_bloques(nombre_disco, bloques,rutaDisco);
            break;
        case 6:
            fflush(stdin);
            system("clear");
            //char nombreC[25];
            //char path[100];
            //char cont[96];
            memset(&nombreC,0,sizeof(nombreC));
            memset(&path,0,sizeof(path));
            if (isEmpty(rutaDisco,"")) {
                printf(" ============================================================================= \n");
                printf("                              Visor Archivos \n");
                printf(" ============================================================================= \n");
                printf(" Ingrese el nombre del archivo: ");
                scanf("%s", &nombreC);
                printf(" Ingrese la ruta donde se ubica el archivo: ");
                fflush(stdin);
                scanf("%s", &path);
                printf("\n Contenido de %s: \n",nombreC);
                char subbuff[strlen(path)];
                memcpy( subbuff, &path[1], strlen(path)-1);
                subbuff[strlen(path)-1] = '\0';
                        //int i;
                char **retorno=split(subbuff, '/');
                visor_archivo(nombre_disco,rutaDisco,path,retorno,nombreC);
                free(retorno);
                printf(" \n");
                        /*for(i=0;retorno[i]!=NULL;i++)
                        {
                            printf("%s\n", retorno[i]);
                            free(retorno[i]);
                        }*/
            }else{
                printf(" No existe ningun disco montando!\n");
            }
            /*printf(" Ingrese la cantidad de bloques: ");
            scanf("%d", &bloques);*/
            //ingresar_bloques(nombre_disco, bloques,rutaDisco);
            break;
        case 9:
            fflush(stdin);
            system("clear");
            //char nombreC[25];
            //char path[100];
            //char cont[96];
            memset(&nombreC,0,sizeof(nombreC));
            memset(&path,0,sizeof(path));
            if (isEmpty(rutaDisco,"")) {
                printf(" ============================================================================= \n");
                printf("                              Visor Carpeta \n");
                printf(" ============================================================================= \n");
                printf(" Ingrese la ruta donde se ubica la carpeta: ");
                scanf("%s", &path);
                printf("\n Contenido de %s: \n",nombreC);
                char subbuff[strlen(path)];
                memcpy( subbuff, &path[1], strlen(path)-1);
                subbuff[strlen(path)-1] = '\0';
                        //int i;
                char **retorno=split(subbuff, '/');
                visor_carpeta(nombre_disco,rutaDisco,path,retorno);
                free(retorno);
                printf(" \n");
                printf(" \n");
                printf(" \n");
                        /*for(i=0;retorno[i]!=NULL;i++)
                        {
                            printf("%s\n", retorno[i]);
                            free(retorno[i]);
                        }*/
            }else{
                printf(" No existe ningun disco montando!\n");
            }
            /*printf(" Ingrese la cantidad de bloques: ");
            scanf("%d", &bloques);*/
            //ingresar_bloques(nombre_disco, bloques,rutaDisco);
            break;
        case 8:
            fflush(stdin);
            system("clear");
            //char nombreC[25];
            //char path[100];
            char cont[96];
            memset(&nombreC,0,sizeof(nombreC));
            memset(&path,0,sizeof(path));
            memset(&cont,0,sizeof(cont));
            char *name = malloc (MAX_NAME_SZ);
            char* comando=(char*)malloc(150);
            memset(&comando[0], 0, sizeof(comando));
            if (isEmpty(rutaDisco,"")) {
                printf(" ============================================================================= \n");
                printf("                              Crear Archivo \n");
                printf(" ============================================================================= \n");
                printf(" Ingrese el nombre del archivo: ");
                scanf("%s", &nombreC);
                printf(" Ingrese la ruta donde se creara el archivo: ");
                fflush(stdin);
                scanf("%s", &path);
                printf(" Ingrese el contenido del archivo: ");
                fflush(stdin);
                //Leer entrada con gets
                /*fgets (name, MAX_NAME_SZ, stdin);
                fflush(stdin);
                fgets (name, MAX_NAME_SZ, stdin);
                if ((strlen(name)>0) && (name[strlen (name) - 1] == '\n'))
                        name[strlen (name) - 1] = '\0';*/

                //Leer entrada con nano
                FILE *fp = NULL;
                fp = fopen(nombreC,"a");
                fclose(fp);
                fflush(fp);
                //Mostrar archivo con nano
                strcat(comando,"nano ");
                strcat(comando,nombreC);
                system(comando);
                free(comando);
                //Leer buffer
                char *source = NULL;
                fp = fopen(nombreC, "r");
                if (fp != NULL) {
                    /* Go to the end of the file. */
                    if (fseek(fp, 0L, SEEK_END) == 0) {
                        /* Get the size of the file. */
                        long bufsize = ftell(fp);
                        if (bufsize == -1) { /* Error */ }

                        /* Allocate our buffer to that size. */
                        source = malloc(sizeof(char) * (bufsize + 1));

                        /* Go back to the start of the file. */
                        if (fseek(fp, 0L, SEEK_SET) != 0) { /* Error */ }

                        /* Read the entire file into memory. */
                        size_t newLen = fread(source, sizeof(char), bufsize, fp);
                        if ( ferror( fp ) != 0 ) {
                            fputs("Error reading file", stderr);
                        } else {
                            source[newLen++] = '\0'; /* Just to be safe. */
                        }
                    }
                    fclose(fp);
                }
                //printf("%s \n",source);

                //Eliminar archivo
                remove(nombreC);

                //scanf("%s", &cont);
                char subbuff[strlen(path)];
                memcpy( subbuff, &path[1], strlen(path)-1);
                subbuff[strlen(path)-1] = '\0';
                        //int i;
                char **retorno=split(subbuff, '/');
                crear_archivo(nombre_disco,rutaDisco,path,retorno,source,nombreC,1);
                free(retorno);
                free (name);
                free(source);
                        /*for(i=0;retorno[i]!=NULL;i++)
                        {
                            printf("%s\n", retorno[i]);
                            free(retorno[i]);
                        }*/
            }else{
                printf(" No existe ningun disco montando!\n");
            }
            /*printf(" Ingrese la cantidad de bloques: ");
            scanf("%d", &bloques);*/
            //ingresar_bloques(nombre_disco, bloques,rutaDisco);
            break;
        case 10:
            fflush(stdin);
            system("clear");
            //char nombreC[25];
            //char path[100];
            //char cont[96];
            memset(&nombreC,0,sizeof(nombreC));
            memset(&path,0,sizeof(path));
            if (isEmpty(rutaDisco,"")) {
                printf(" ============================================================================= \n");
                printf("                         Eliminar Archivo o Carpeta \n");
                printf(" ============================================================================= \n");
                printf(" Ingrese la ruta donde se va a eliminar: ");
                scanf("%s", &path);
                printf("\n Contenido de %s: \n",nombreC);
                char subbuff[strlen(path)];
                memcpy( subbuff, &path[1], strlen(path)-1);
                subbuff[strlen(path)-1] = '\0';
                        //int i;
                char **retorno=split(subbuff, '/');
                eliminar(nombre_disco,rutaDisco,path,retorno,1);
                free(retorno);
                printf(" \n");
                        /*for(i=0;retorno[i]!=NULL;i++)
                        {
                            printf("%s\n", retorno[i]);
                            free(retorno[i]);
                        }*/
            }else{
                printf(" No existe ningun disco montando!\n");
            }
            /*printf(" Ingrese la cantidad de bloques: ");
            scanf("%d", &bloques);*/
            //ingresar_bloques(nombre_disco, bloques,rutaDisco);
            break;
        case 11:
            fflush(stdin);
            system("clear");
            //char nombreC[25];
            char pathMove[100];
            //char cont[96];
            memset(&nombreC,0,sizeof(nombreC));
            memset(&path,0,sizeof(path));
            memset(&pathMove,0,sizeof(pathMove));
            if (isEmpty(rutaDisco,"")) {
                printf(" ============================================================================= \n");
                printf("                          Mover Archivo o Carpeta \n");
                printf(" ============================================================================= \n");
                printf(" Ingrese la ruta donde se encuentra: ");
                scanf("%s", &path);
                char subbuff[strlen(path)];
                memcpy( subbuff, &path[1], strlen(path)-1);
                subbuff[strlen(path)-1] = '\0';
                        //int i;
                char **retorno=split(subbuff, '/');
                printf(" Ingrese la ruta donde desea mover el contenido: ");
                fflush(stdin);
                scanf("%s", &pathMove);
                char subbuffMove[strlen(pathMove)];
                memcpy( subbuffMove, &pathMove[1], strlen(pathMove)-1);
                subbuffMove[strlen(pathMove)-1] = '\0';
                        //int i;
                char **retornoMove=split(subbuffMove, '/');
                mover(nombre_disco,rutaDisco,path,retorno,pathMove,retornoMove);
                free(retorno);
                free(retornoMove);
                printf(" \n");
                        /*for(i=0;retorno[i]!=NULL;i++)
                        {
                            printf("%s\n", retorno[i]);
                            free(retorno[i]);
                        }*/
            }else{
                printf(" No existe ningun disco montando!\n");
            }
            /*printf(" Ingrese la cantidad de bloques: ");
            scanf("%d", &bloques);*/
            //ingresar_bloques(nombre_disco, bloques,rutaDisco);
            break;
        case 12:
            fflush(stdin);
            system("clear");
            //char nombreC[25];
            //char path[100];
            //char cont[96];
            memset(&nombreC,0,sizeof(nombreC));
            memset(&path,0,sizeof(path));
            if (isEmpty(rutaDisco,"")) {
                printf(" ============================================================================= \n");
                printf("                              Modificar Archivos \n");
                printf(" ============================================================================= \n");
                printf(" Ingrese el nombre del archivo: ");
                scanf("%s", &nombreC);
                printf(" Ingrese la ruta donde se ubica el archivo: ");
                fflush(stdin);
                scanf("%s", &path);
                printf("\n Contenido de %s: \n",nombreC);
                printf(" \n");
                char subbuff[strlen(path)];
                memcpy( subbuff, &path[1], strlen(path)-1);
                subbuff[strlen(path)-1] = '\0';
                        //int i;
                char **retorno=split(subbuff, '/');
                modificar_archivo(nombre_disco,rutaDisco,path,retorno,nombreC);
                visor_archivo(nombre_disco,rutaDisco,path,retorno,nombreC);
                free(retorno);
                printf(" \n");
                printf(" \n");
                        /*for(i=0;retorno[i]!=NULL;i++)
                        {
                            printf("%s\n", retorno[i]);
                            free(retorno[i]);
                        }*/
            }else{
                printf(" No existe ningun disco montando!\n");
            }
            /*printf(" Ingrese la cantidad de bloques: ");
            scanf("%d", &bloques);*/
            //ingresar_bloques(nombre_disco, bloques,rutaDisco);
            break;

        case 16:
            fflush(stdin);
            // Mostrar el disco
            system("clear");
            if (!isEmpty(rutaDisco,"")) {
                perror(" No existe ningun disco montando!\n");
            }else{
                printf(" ============================================================================= \n");
                printf("                              Reporte Directorios \n");
                printf(" ============================================================================= \n\n");
                //reporte1(nombre_disco,rutaDisco);
                char **ret;
                printf("node [shape=record];\n0 [label=\"/\"];\n");
                recorrido_carpeta(nombre_disco,rutaDisco,"/",ret,0);
            }
            break;
        }
    }
}

int isEmpty(char * cadena,char * aviso){
    if(cadena[0]=='\0'){
        //strcat(aviso,"\n");
        printf(aviso);
        return 0;
    }
    return 1;
}
