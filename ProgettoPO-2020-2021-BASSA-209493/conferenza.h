#ifndef CONFERENZA_H
#define CONFERENZA_H

#include <QMainWindow>
#include <QDate>

#include "articolo.h"

class Conferenza
{
private:
    int id;
    QString nome;
    QDate data;
    QString acronimo;
    QString luogo;
    QList<QString> organizzatori;
    int numeroPartecipanti;
    QList<Articolo> articoli;

public:
    Conferenza(int id, QString n, QDate d, QString acr, QString lg, QList<QString> org, int num, QList<Articolo> a){
        this->id = id;
        nome = n;
        data = d;
        acronimo = acr;
        luogo = lg;
        organizzatori = org;
        numeroPartecipanti = num;
        articoli = a;
    }
    int getId() const{
        return id;
    }
    QString getNome() const{
        return nome;
    }
    QDate getData() const{
        return data;
    }
    QString getAcronimo() const{
        return acronimo;
    }
    QString getLuogo() const{
        return luogo;
    }
    QList<QString> getOrganizzatori() const{
        return organizzatori;
    }
    int getNumeroPartecipanti() const{
        return numeroPartecipanti;
    }
    QList<Articolo> getArticoli() const{
        return articoli;
    }

    void setNome(QString n){
        nome = n;
    }
    void setData(QDate d){
        data = d;
    }
    void setAcronimo(QString a){
        acronimo = a;
    }
    void setLuogo( QString l){
        luogo = l;
    }
    void setNumeroPartecipanti(int np){
        numeroPartecipanti = np;
    }

    void aggiungiArticolo(Articolo a){
        articoli.push_back(a);
    }
};

#endif // CONFERENZA_H
