#include "newsSeeker.h"

int main()
{
    NewsSeeker ns;
    ns.agregar("hola1");
    ns.agregar("hola2");
    ns.agregar("adios");
    ns.agregar("hola3");
    ns.agregar("hola4");
    ns.agregar("hola5");
    ns.reordenar(2, -1);
    ns.eliminar(2);
    ns.buscar("hola");
    return 0;
}