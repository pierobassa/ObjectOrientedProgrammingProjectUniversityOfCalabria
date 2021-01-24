#ifndef GESTOREGENERALE_H
#define GESTOREGENERALE_H

#include <QMainWindow>
#include "articolo.h"
#include "autore.h"
#include "conferenza.h"
#include "rivista.h"

#include <list>


class GestoreGenerale
{
private:
    QList<Autore> autoriInseriti;
    QList<Articolo> articoliInseriti;
    QList<Conferenza> conferenzeInserite;
    QList<Rivista> rivisteInserite;


public:
    GestoreGenerale(){}

    void aggiungiAutore(Autore &a);
    bool rimuoviAutore(int id);
    void stampaAutori() const;
    QList<Autore> getAutoriInseriti() const{
        return autoriInseriti;
    }

    void aggiungiArticolo(Articolo &a);
    bool rimuoviArticolo(int id);
    void stampaArticoli() const;
    QList<Articolo> getArticoliInseriti() const{
        return articoliInseriti;
    }


    void aggiungiConferenza(Conferenza &c);
    bool rimuoviConferenza(int id);
    void stampaConferenze() const;
    QList<Conferenza> getConferenzeInserite() const{
        return conferenzeInserite;
    }
    void aggiungiArticoloConferenza(int pos, Articolo a){
        conferenzeInserite[pos].aggiungiArticolo(a);
    }


    void aggiungiRivista(Rivista &r);
    bool rimuoviRivista(int id);
    void stampaRiviste() const;
    QList<Rivista> getRivisteInserite() const{
        return rivisteInserite;
    }
    void aggiungiArticoloRivista(int pos, Articolo a){
        rivisteInserite[pos].aggiungiArticolo(a);
    }

    //SEZIONE C
    QList<QString> metodoC6();
    QList<Articolo> metodoC1(int id);
    double metodoC3(int id);

    //SEZIONE D
    list<Articolo> metodoD2(int id);
    list<Articolo> metodoD5(QString keyword);

    //SEZIONE E
    list<Rivista> metodoE6();

    //SEZIONE F
    vector<Articolo> metodoF1(int id);
    list<Conferenza> metodoF5(int id);

};

#endif // GESTOREGENERALE_H
