#include <QApplication>
#include <iostream>
#include "controller.h"
#include "sistema_stellare.h"
#include "deep_ptr.h"
#include "corpo_celeste.h"
#include "stella.h"
#include "pianeta.h"
#include "satellite.h"
#include <QVector>
#include <QDebug>

void temp(QVector<Sistema_stellare<Deep_ptr<Corpo_celeste>>>& sistemi){
    Sistema_stellare<Deep_ptr<Corpo_celeste>> sis(new Stella("s2",1000,100));
    sistemi.push_back(sis);
}

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    Controller c;
    c.setController();
    c.get_gui()->show();
    return a.exec();
    return 0;
}
