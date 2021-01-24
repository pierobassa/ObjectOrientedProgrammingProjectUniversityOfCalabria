#ifndef ARTICOLO_H
#define ARTICOLO_H

#include <QMainWindow>

#include "autore.h"
#include <QDate>


class Articolo
{
private:
    int id;
    QString titolo;
    int numeroPagine;
    QList<Autore> autori;
    QList<QString> keywords;
    double prezzo;
    QList<QString> articoliCorrelati;
    QDate dataAssociato;

public:
    Articolo(){}
    Articolo(int identificativo, QString t, int np, QList<Autore> _autori, QList<QString> _keywords, double p, QList<QString> artCorrelati){
        id = identificativo;
        titolo = t;
        numeroPagine = np;
        autori = _autori;
        keywords = _keywords;
        prezzo = p;
        articoliCorrelati = artCorrelati;
    }

    int getId() const{
        return id;
    }
    QString getTitolo() const{
        return titolo;
    }
    int getNumeroPagine() const{
        return numeroPagine;
    }
    QList<Autore> getAutori() const{
        return autori;
    }
    QList<QString> getKeywords() const{
        return keywords;
    }
    double getPrezzo() const{
        return prezzo;
    }
    QList<QString> getArticoliCorrelati() const{
        return articoliCorrelati;
    }

    QDate getDataAssociato() const{
        return dataAssociato;
    }

    void setTitolo(QString t){
        titolo = t;
    }

    void setNumeroPagine(int np){
        numeroPagine = np;
    }
    void setPrezzo(double p){
        prezzo = p;
    }

    void setKeywords(QList<QString> _keywords){
        keywords = _keywords;
    }

    void setArticoliCorrelati(QList<QString> artCorr){
        articoliCorrelati = artCorr;
    }
    void setDataAssociato(QDate data){
        dataAssociato = data;
    }
};

#endif // ARTICOLO_H
