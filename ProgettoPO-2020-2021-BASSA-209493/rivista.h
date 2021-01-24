#ifndef RIVISTA_H
#define RIVISTA_H

#include <QMainWindow>

#include "articolo.h"
#include <QDate>

class Rivista
{
private:
    int id;
    QString nome;
    QString acronimo;
    QString editore;
    int volume;
    QDate data;
    QList<Articolo> articoli;

public:
    Rivista(int id, QString n, QString acr, QString e, int v, QDate d, QList<Articolo> art){
        this->id = id;
        nome = n;
        acronimo = acr;
        editore = e;
        volume = v;
        data = d;
        articoli = art;
    }
    int getId() const{
        return id;
    }
    QString getNome() const{
        return nome;
    }
    QString getAcronimo() const{
        return acronimo;
    }
    QString getEditore() const{
        return editore;
    }
    int getVolume() const{
        return volume;
    }
    QDate getData() const{
        return data;
    }
    QList<Articolo> getArticoli() const{
        return articoli;
    }

    void setNome(QString n){ nome = n; }
    void setAcronimo(QString acr){ acronimo = acr;}
    void setEditore(QString e){ editore = e;}
    void setArticoli(QList<Articolo> art){ articoli = art;}
    void aggiungiArticolo(Articolo a){
        articoli.push_back(a);
    }

};

#endif // RIVISTA_H
