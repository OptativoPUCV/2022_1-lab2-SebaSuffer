#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef struct{
    int year;
    char title[30];
    char director[30];
}Pelicula;

/*
Mostrar todos los productos (): La aplicación muestra por pantalla 
todos los productos existentes (y su respectiva información).
*/
void mostrarTodoslosProductos(Stock * almacen){
    system("cls");
    Pair * aux = firstMap(almacen->nombre);
    printf("=============Productos Disponibles=============\n\n");
    while (aux != NULL){
        printf("Producto: %s\n", (((Producto *)(Pair *)aux->value)->nombre));
        printf(" -Stock Disponible: %zd\n", (((Producto *)(Pair *)aux->value)->stock));
        printf(" -Valor: %zd\n", (((Producto *)(Pair *)aux->value)->valor));
        printf(" -Tipo: %s\n", (((Producto *)(Pair *)aux->value)->tipo));
        printf(" -Marca: %s\n", (((Producto *)(Pair *)aux->value)->marca));
        printf("\n");

        aux = nextMap(almacen->nombre);
    }
    printf("\n");
    printf("================FIN DE LA LECTURA================");

    getch();
}

/*
Mostrar carritos de compra: Se muestran los nombres de los carritos 
de compra creados y la cantidad de productos que tiene cada uno de ellos. 
*/
void mostrarCarritosDeCompra(Carritos* carritosDeCompra){
    system("cls");
    size_t i=1;
    Pair * aux = firstMap(carritosDeCompra->arrCarritos);
    printf("=============[Carritos de Compra]=============\n\n");
    while (aux != NULL){
        printf("%u.- %s\n", i, ((Carrito*)aux->value)->nombre);
        printf(" -Cantidad Disponible = %zd\n", ((Carrito*)aux->value)->cantProductos);
        printf("\n");
        aux = nextMap(carritosDeCompra->arrCarritos);
        i++;
    }

    printf("==============[FIN DE LA LECTURA]==============");

    getch();
}



int main( int argc, char *argv[] ){

    List* movies= createList();
    Pelicula* p= (Pelicula*) malloc (sizeof(Pelicula));
    p->year=2004;
    strcpy(p->title,"2046");
    strcpy(p->director,"Wong Kar Wai");
    pushBack(movies,p);

    p= (Pelicula*) malloc (sizeof(Pelicula));
    p->year=2016;
    strcpy(p->title,"Arrival");
    strcpy(p->director,"Denis Villeneuve ");
    pushBack(movies,p);


    Pelicula* aux = firstList(movies);
    while(aux!=NULL){
        printf("%s (%d)\n",aux->title,aux->year);
        aux=nextList(movies);
    }

    

    return 0;
}
