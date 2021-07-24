#include "stella.h"

float Stella::get_temperatura() const{
    return temperatura;
}

const QString &Stella::get_colore() const{
    return colore;
}

Stella::~Stella(){}

Stella::Stella(float d,float f, float t) : Corpo_celeste(d, f, true){
    temperatura= t;
    if(temperatura<=1700) colore= "rossa";
    else if(temperatura<=3000) colore= "arancione";
    else if(temperatura<=6000) colore= "gialla";
    else colore= "bianca";
}

Stella::Stella(Stella &s) : Corpo_celeste(s){
    temperatura= s.get_temperatura();
    colore= s.get_colore();
}

Stella &Stella::operator=(const Stella &s){
    temperatura= s.get_temperatura();
    colore= s.get_colore();
    return *this;
}
