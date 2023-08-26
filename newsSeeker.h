#ifndef NEWSSEEKER_H
#define NEWSSEEKER_H

#include "doubleList.h"

class NewsSeeker {
    private:
        DoubleList list;
    
    public:
        NewsSeeker();
        void agregar(int data); //agrega una noticia, usa el metodo insertLast
        void buscar(string keyword); //busca la noticia con el keyword indicado, usa los metodos top5 y searchPosition
        void eliminar(int position); //elimina la noticia en la posicion indicada, usa el metodo deletePosition
        void reordenar(int position, int offset); //reordena la noticia aumentado su prioridad en la cantidad indicada, un offset positivo aumenta la prioridad
                                                  //usa los metodos searchPosition, deletePosition e insertPosition
};

#endif