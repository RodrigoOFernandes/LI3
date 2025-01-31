#include "../include/gestores/gestor.h"
#include "../include/interativo/menu.h"



int main()
{
    Gestor* g = GestorInit();
    
    menu_interativo(g);

    GestorDestroy(g);

    return 0;
}