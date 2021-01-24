#include "mainwindow.h"

#include <QApplication>
#include "autore.h"
#include "gestoregenerale.h"
#include <QDebug>

#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
        //VI LASCIO I TEST CHE AVEVO FATTO SU CONSOLE SE MAI DOVESSE SERVIRE :)
    //TEST AUTORE
    /*GestoreGenerale gestore;
    int idArticoli=0, idConferenze=0, idRiviste=0, idAutori=0;


    QList<QString> afferenzeAutore;
    */
    //INSERISCO DEGLI AUTORI
    /*afferenzeAutore.push_back("Uni Calabria");
    afferenzeAutore.push_back("Uni Torino");
    Autore a1(idAutori, "Mario", "Gratteri", afferenzeAutore);
    gestore.aggiungiAutore(a1);
    afferenzeAutore.clear();
    idAutori++;

    afferenzeAutore.push_back("Uni Pisa");
    afferenzeAutore.push_back("Uni Bologna");
    Autore a2(idAutori, "Luigi", "Bassa", afferenzeAutore);
    gestore.aggiungiAutore(a2);
    afferenzeAutore.clear();
    idAutori++;

    afferenzeAutore.push_back("Uni Milano");
    afferenzeAutore.push_back("Uni Calabria");
    Autore a3(idAutori, "Luca", "De Luca", afferenzeAutore);
    gestore.aggiungiAutore(a3);
    afferenzeAutore.clear();
    idAutori++;

    afferenzeAutore.push_back("Uni Torino");
    Autore a4(idAutori, "Francesco", "Simonetti", afferenzeAutore);
    gestore.aggiungiAutore(a4);
    afferenzeAutore.clear();
    idAutori++;

    afferenzeAutore.push_back("Uni Bologna");
    afferenzeAutore.push_back("Uni Livorno");
    afferenzeAutore.push_back("Uni Calabria");
    Autore a5(idAutori, "Giovanni", "De Vries", afferenzeAutore);
    gestore.aggiungiAutore(a5);
    afferenzeAutore.clear();
    idAutori++;

    afferenzeAutore.push_back("Uni Torino");
    Autore a6(idAutori, "Simone", "Leclerc", afferenzeAutore);
    gestore.aggiungiAutore(a6);
    afferenzeAutore.clear();
    idAutori++;

    afferenzeAutore.push_back("Uni Calabria");
    Autore a7(idAutori, "Vincenzo", "Vettel", afferenzeAutore);
    gestore.aggiungiAutore(a7);
    afferenzeAutore.clear();
    idAutori++;
*/
    /*
    gestore.stampaAutori();
    gestore.rimuoviAutore(3);
    gestore.stampaAutori();
    */

    //TEST ARTICOLO
    /*int id;
    QString titolo;
    int numeroPagine;
    QList<Autore> autori;
    QList<QString> keywords;
    double prezzo;
    QList<QString> articoliCorrelati;  */

    //ARTICOLI
    /*QList<Autore> autoriArticolo;
    QList<QString> keywords;
    QList<QString> correlati;
    QDate dataAssociato;

    autoriArticolo.push_back(a4);
    autoriArticolo.push_back(a1);
    keywords.push_back("Intelligenza Artificiale");
    keywords.push_back("Serie Galaxy S21");
    correlati.push_back("Come funziona il conto cointestato");
    Articolo art1(idArticoli, "AI - Rivoluzione 2050", 12, autoriArticolo, keywords, 12.90, correlati);
    dataAssociato.setDate(2020, 3, 17);
    art1.setDataAssociato(dataAssociato);
    gestore.aggiungiArticolo(art1);
    idArticoli++;
    correlati.clear(); keywords.clear(); autoriArticolo.clear();

    autoriArticolo.push_back(a2);
    autoriArticolo.push_back(a5);
    keywords.push_back("Cashback Poste Italiane");
    Articolo art2(idArticoli, "Ecco il cashback di Poste Italiane", 7, autoriArticolo, keywords, 11.30, correlati);
    dataAssociato.setDate(2020, 1, 1);
    art2.setDataAssociato(dataAssociato);
    gestore.aggiungiArticolo(art2);
    idArticoli++;
    correlati.clear(); keywords.clear(); autoriArticolo.clear();

    autoriArticolo.push_back(a7);
    keywords.push_back("Airpods Max sorpresa per natale");
    keywords.push_back("Intelligenza Artificiale");
    correlati.push_back("AI - Rivoluzione 2050");
    correlati.push_back("Nuova Serie Samsung Galaxy S21");
    Articolo art3(idArticoli, "Airpods MAX sorpresa Apple", 3, autoriArticolo, keywords, 15.80, correlati);
    dataAssociato.setDate(2020, 12, 1);
    art3.setDataAssociato(dataAssociato);
    gestore.aggiungiArticolo(art3);
    idArticoli++;
    correlati.clear(); keywords.clear(); autoriArticolo.clear();

    autoriArticolo.push_back(a1);
    autoriArticolo.push_back(a4);
    keywords.push_back("Serie Galaxy S21");
    keywords.push_back("Intelligenza Artificiale");
    correlati.push_back("Airpods MAX sorpresa Apple");
    Articolo art4(idArticoli, "Nuova Serie Samsung Galaxy S21", 6, autoriArticolo, keywords, 0.80, correlati);
    dataAssociato.setDate(2021, 10, 12);
    art4.setDataAssociato(dataAssociato);
    gestore.aggiungiArticolo(art4);
    idArticoli++;
    correlati.clear(); keywords.clear(); autoriArticolo.clear();

    autoriArticolo.push_back(a2);
    keywords.push_back("Conto corrente cointesato");
    keywords.push_back("Cashback Poste Italiane");
    keywords.push_back("Aprire un conto Poste Italiane");
    correlati.push_back("Ecco il cashback di Poste Italiane");
    correlati.push_back("Cashback fino a 150 euro!");
    Articolo art5(idArticoli, "Come funziona il conto cointestato", 3, autoriArticolo, keywords, 13.70, correlati);
    dataAssociato.setDate(2020, 11, 3);
    art5.setDataAssociato(dataAssociato);
    gestore.aggiungiArticolo(art5);
    idArticoli++;
    correlati.clear(); keywords.clear(); autoriArticolo.clear();

    autoriArticolo.push_back(a1);
    keywords.push_back("Prove Libere F1 Abu Dhabi");
    keywords.push_back("Verstappen tempo più veloce!");
    correlati.push_back("Dimesso il CEO della Ferrari");
    Articolo art6(idArticoli, "Risultati delle FP1 ultimo GP 2020 F1", 2, autoriArticolo, keywords, 3.80, correlati);
    dataAssociato.setDate(2021, 1, 3);
    art6.setDataAssociato(dataAssociato);
    gestore.aggiungiArticolo(art6);
    idArticoli++;
    correlati.clear(); keywords.clear(); autoriArticolo.clear();

    autoriArticolo.push_back(a1);
    keywords.push_back("Prove Libere F1 Abu Dhabi");
    keywords.push_back("Verstappen tempo più veloce!");
    keywords.push_back("ULTIMA ORA! CEO Camilleri si dimette!");
    Articolo art7(idArticoli, "Problemi in casa Ferrari, Camilleri si dimette!", 1, autoriArticolo, keywords, 0.80, correlati);
    dataAssociato.setDate(2021, 1, 12);
    art7.setDataAssociato(dataAssociato);
    gestore.aggiungiArticolo(art7);
    idArticoli++;
    correlati.clear(); keywords.clear(); autoriArticolo.clear();

    autoriArticolo.push_back(a1);
    keywords.push_back("Intelligenza Artificiale");
    Articolo art8(idArticoli, "Robot Umano Nuova generazione", 1, autoriArticolo, keywords, 12.90, correlati);
    dataAssociato.setDate(2020, 3, 17);
    art8.setDataAssociato(dataAssociato);
    gestore.aggiungiArticolo(art8);
    idArticoli++;
    correlati.clear(); keywords.clear(); autoriArticolo.clear();

    autoriArticolo.push_back(a5);
    autoriArticolo.push_back(a3);
    keywords.push_back("Cashback Poste Italiane");
    correlati.push_back("Ecco il cashback di Poste Italiane");
    Articolo art9(idArticoli, "Cashback fino a 150 euro!", 2, autoriArticolo, keywords, 1.70, correlati);
    dataAssociato.setDate(2020, 11, 3);
    art5.setDataAssociato(dataAssociato);
    gestore.aggiungiArticolo(art9);
    idArticoli++;
    correlati.clear(); keywords.clear(); autoriArticolo.clear();

    autoriArticolo.push_back(a2);
    keywords.push_back("Finito il campionato F1 2021");
    correlati.push_back("Risultati delle FP1 ultimo GP 2020 F1");
    Articolo art10(idArticoli, "Terminato il calendario F1 2021, test a Febbraio.", 3, autoriArticolo, keywords, 3.20, correlati);
    dataAssociato.setDate(2021, 1, 12);
    art10.setDataAssociato(dataAssociato);
    gestore.aggiungiArticolo(art10);
    idArticoli++;
    correlati.clear(); keywords.clear(); autoriArticolo.clear();

*/
    //TEST APPROFONDITO PER METODOF1
    /*
    autoriArticolo.push_back(a4);
    autoriArticolo.push_back(a1);
    keywords.push_back("Intelligenza Artificiale");
    keywords.push_back("Serie Galaxy S21");
    correlati.push_back("Come funziona il conto cointestato");
    correlati.push_back("Ecco il cashback di Poste Italiane");
    Articolo art1(idArticoli, "AI - Rivoluzione 2050", 12, autoriArticolo, keywords, 12.90, correlati);
    dataAssociato.setDate(2020, 12, 17);
    art1.setDataAssociato(dataAssociato);
    gestore.aggiungiArticolo(art1);
    idArticoli++;
    correlati.clear(); keywords.clear(); autoriArticolo.clear();

    autoriArticolo.push_back(a2);
    autoriArticolo.push_back(a5);
    keywords.push_back("Cashback Poste Italiane");
    Articolo art2(idArticoli, "Ecco il cashback di Poste Italiane", 7, autoriArticolo, keywords, 11.30, correlati);
    dataAssociato.setDate(2020, 1, 1);
    art2.setDataAssociato(dataAssociato);
    gestore.aggiungiArticolo(art2);
    idArticoli++;
    correlati.clear(); keywords.clear(); autoriArticolo.clear();

    autoriArticolo.push_back(a7);
    keywords.push_back("Airpods Max sorpresa per natale");
    keywords.push_back("Intelligenza Artificiale");
    correlati.push_back("AI - Rivoluzione 2050");
    correlati.push_back("Nuova Serie Samsung Galaxy S21");
    Articolo art3(idArticoli, "Airpods MAX sorpresa Apple", 3, autoriArticolo, keywords, 15.80, correlati);
    dataAssociato.setDate(2021, 12, 1);
    art3.setDataAssociato(dataAssociato);
    gestore.aggiungiArticolo(art3);
    idArticoli++;
    correlati.clear(); keywords.clear(); autoriArticolo.clear();

    autoriArticolo.push_back(a1);
    autoriArticolo.push_back(a4);
    keywords.push_back("Serie Galaxy S21");
    keywords.push_back("Intelligenza Artificiale");
    correlati.push_back("Airpods MAX sorpresa Apple");
    Articolo art4(idArticoli, "Nuova Serie Samsung Galaxy S21", 6, autoriArticolo, keywords, 0.80, correlati);
    dataAssociato.setDate(2022, 10, 12);
    art4.setDataAssociato(dataAssociato);
    gestore.aggiungiArticolo(art4);
    idArticoli++;
    correlati.clear(); keywords.clear(); autoriArticolo.clear();

    autoriArticolo.push_back(a2);
    keywords.push_back("Conto corrente cointesato");
    keywords.push_back("Cashback Poste Italiane");
    keywords.push_back("Aprire un conto Poste Italiane");
    correlati.push_back("Ecco il cashback di Poste Italiane");
    correlati.push_back("Cashback fino a 150 euro!");
    Articolo art5(idArticoli, "Come funziona il conto cointestato", 3, autoriArticolo, keywords, 13.70, correlati);
    dataAssociato.setDate(2020, 11, 3);
    art5.setDataAssociato(dataAssociato);
    gestore.aggiungiArticolo(art5);
    idArticoli++;
    correlati.clear(); keywords.clear(); autoriArticolo.clear();

    autoriArticolo.push_back(a1);
    keywords.push_back("Prove Libere F1 Abu Dhabi");
    keywords.push_back("Verstappen tempo più veloce!");
    correlati.push_back("Dimesso il CEO della Ferrari");
    correlati.push_back("Come funziona il conto cointestato");
    Articolo art6(idArticoli, "Risultati delle FP1 ultimo GP 2020 F1", 2, autoriArticolo, keywords, 3.80, correlati);
    dataAssociato.setDate(2021, 1, 3);
    art6.setDataAssociato(dataAssociato);
    gestore.aggiungiArticolo(art6);
    idArticoli++;
    correlati.clear(); keywords.clear(); autoriArticolo.clear();

    autoriArticolo.push_back(a1);
    keywords.push_back("Prove Libere F1 Abu Dhabi");
    keywords.push_back("Verstappen tempo più veloce!");
    keywords.push_back("ULTIMA ORA! CEO Camilleri si dimette!");
    Articolo art7(idArticoli, "Problemi in casa Ferrari, Camilleri si dimette!", 1, autoriArticolo, keywords, 0.80, correlati);
    dataAssociato.setDate(2021, 1, 12);
    art7.setDataAssociato(dataAssociato);
    gestore.aggiungiArticolo(art7);
    idArticoli++;
    correlati.clear(); keywords.clear(); autoriArticolo.clear();

    autoriArticolo.push_back(a1);
    keywords.push_back("Intelligenza Artificiale");
    Articolo art8(idArticoli, "Robot Umano Nuova generazione", 1, autoriArticolo, keywords, 12.90, correlati);
    dataAssociato.setDate(2020, 3, 17);
    art8.setDataAssociato(dataAssociato);
    gestore.aggiungiArticolo(art8);
    idArticoli++;
    correlati.clear(); keywords.clear(); autoriArticolo.clear();

    autoriArticolo.push_back(a5);
    autoriArticolo.push_back(a3);
    keywords.push_back("Cashback Poste Italiane");
    correlati.push_back("Ecco il cashback di Poste Italiane");
    Articolo art9(idArticoli, "Cashback fino a 150 euro!", 2, autoriArticolo, keywords, 1.70, correlati);
    dataAssociato.setDate(2020, 11, 3);
    art9.setDataAssociato(dataAssociato);
    gestore.aggiungiArticolo(art9);
    idArticoli++;
    correlati.clear(); keywords.clear(); autoriArticolo.clear();

    autoriArticolo.push_back(a2);
    keywords.push_back("Finito il campionato F1 2021");
    correlati.push_back("Risultati delle FP1 ultimo GP 2020 F1");
    correlati.push_back("Come funziona il conto cointestato");
    Articolo art10(idArticoli, "Terminato il calendario F1 2021, test a Febbraio.", 3, autoriArticolo, keywords, 3.20, correlati);
    dataAssociato.setDate(2021, 1, 12);
    art10.setDataAssociato(dataAssociato);
    gestore.aggiungiArticolo(art10);
    idArticoli++;
    correlati.clear(); keywords.clear(); autoriArticolo.clear();
    */
    //gestore.stampaArticoli();
     /*
    gestore.rimuoviArticolo(3);
    gestore.stampaArticoli();
    */

    //TEST CONFERENZA
    /*
    int id;
    QString nome;
    QDate data;
    QString acronimo;
    QString luogo;
    QList<QString> organizzatori;
    int numeroPartecipanti;
    QList<Articolo> articoli;
    */
   /* QList<QString> organizzatori;
    QList<Articolo> articoli;
    QDate data;


    organizzatori.push_back("Francesco Montuoro");
    organizzatori.push_back("Luca De Montezemolo");
    articoli.push_back(art1);
    articoli.push_back(art8);
    data.setDate(2020, 3, 17);
    Conferenza c1(idConferenze, "Intelligenza Artificiale Summit 2020", data, "AI", "Monza", organizzatori, 200, articoli);
    gestore.aggiungiConferenza(c1);
    idConferenze++;
    organizzatori.clear(); articoli.clear();

    organizzatori.push_back("Lucia Mirarchi");
    articoli.push_back(art2);
    data.setDate(2020, 1, 1);
    Conferenza c2(idConferenze, "Rivoluzione Poste Italiane", data, "RPT", "Milano", organizzatori, 700, articoli);
    gestore.aggiungiConferenza(c2);
    idConferenze++;
    organizzatori.clear(); articoli.clear();

    organizzatori.push_back("Marco De Vries");
    articoli.push_back(art4);
    data.setDate(2021, 10, 12);
    Conferenza c3(idConferenze, "Samsung October Event", data, "SOE", "Seoul", organizzatori, 1500, articoli);
    gestore.aggiungiConferenza(c3);
    idConferenze++;
    organizzatori.clear(); articoli.clear();

    organizzatori.push_back("Charles Verstappen");
    articoli.push_back(art3);
    data.setDate(2020, 12, 1);
    Conferenza c4(idConferenze, "Apple Christmas event ", data, "APPLECE2020", "San Francisco", organizzatori, 1000, articoli);
    gestore.aggiungiConferenza(c4);
    idConferenze++;
    organizzatori.clear(); articoli.clear();

*/
    //TEST APPROFONDITI METODOF5
    /*
    autoriArticolo.push_back(a4);
    autoriArticolo.push_back(a1);
    keywords.push_back("K1");
    keywords.push_back("K2");
    correlati.push_back("Come funziona il conto cointestato");
    Articolo art1(idArticoli, "AI - Rivoluzione 2050", 12, autoriArticolo, keywords, 12.90, correlati);
    dataAssociato.setDate(2020, 3, 17);
    art1.setDataAssociato(dataAssociato);
    gestore.aggiungiArticolo(art1);
    idArticoli++;
    correlati.clear(); keywords.clear(); autoriArticolo.clear();

    autoriArticolo.push_back(a2);
    autoriArticolo.push_back(a5);
    keywords.push_back("K6");
    Articolo art2(idArticoli, "Ecco il cashback di Poste Italiane", 7, autoriArticolo, keywords, 11.30, correlati);
    dataAssociato.setDate(2020, 1, 1);
    art2.setDataAssociato(dataAssociato);
    gestore.aggiungiArticolo(art2);
    idArticoli++;
    correlati.clear(); keywords.clear(); autoriArticolo.clear();

    autoriArticolo.push_back(a7);
    keywords.push_back("K1");
    correlati.push_back("AI - Rivoluzione 2050");
    correlati.push_back("Nuova Serie Samsung Galaxy S21");
    Articolo art3(idArticoli, "Airpods MAX sorpresa Apple", 3, autoriArticolo, keywords, 15.80, correlati);
    dataAssociato.setDate(2020, 12, 1);
    art3.setDataAssociato(dataAssociato);
    gestore.aggiungiArticolo(art3);
    idArticoli++;
    correlati.clear(); keywords.clear(); autoriArticolo.clear();

    autoriArticolo.push_back(a1);
    autoriArticolo.push_back(a4);
    keywords.push_back("K1");
    keywords.push_back("K3");
    keywords.push_back("K4");
    keywords.push_back("Intelligenza Artificiale");
    correlati.push_back("Airpods MAX sorpresa Apple");
    Articolo art4(idArticoli, "Nuova Serie Samsung Galaxy S21", 6, autoriArticolo, keywords, 0.80, correlati);
    dataAssociato.setDate(2021, 10, 12);
    art4.setDataAssociato(dataAssociato);
    gestore.aggiungiArticolo(art4);
    idArticoli++;
    correlati.clear(); keywords.clear(); autoriArticolo.clear();

    autoriArticolo.push_back(a1);
    keywords.push_back("K3");
    keywords.push_back("K5");
    keywords.push_back("K6");
    Articolo art8(idArticoli, "Robot Umano Nuova generazione", 1, autoriArticolo, keywords, 12.90, correlati);
    dataAssociato.setDate(2020, 3, 17);
    art8.setDataAssociato(dataAssociato);
    gestore.aggiungiArticolo(art8);
    idArticoli++;
    correlati.clear(); keywords.clear(); autoriArticolo.clear();

    autoriArticolo.push_back(a1);
    keywords.push_back("K1");
    keywords.push_back("K3");
    keywords.push_back("K5");
    Articolo art5(idArticoli, "Robot Umano Nuova generazione", 1, autoriArticolo, keywords, 12.90, correlati);
    dataAssociato.setDate(2020, 12, 1);
    art5.setDataAssociato(dataAssociato);
    gestore.aggiungiArticolo(art5);
    idArticoli++;
    correlati.clear(); keywords.clear(); autoriArticolo.clear();
    */

    /*
    organizzatori.push_back("Francesco Montuoro");
    organizzatori.push_back("Luca De Montezemolo");
    articoli.push_back(art1);
    articoli.push_back(art8);
    data.setDate(2020, 3, 17);
    Conferenza c1(idConferenze, "C1", data, "AI", "Monza", organizzatori, 200, articoli);
    gestore.aggiungiConferenza(c1);
    idConferenze++;
    organizzatori.clear(); articoli.clear();

    organizzatori.push_back("Lucia Mirarchi");
    articoli.push_back(art2);
    data.setDate(2020, 1, 1);
    Conferenza c2(idConferenze, "C2", data, "RPT", "Milano", organizzatori, 700, articoli);
    gestore.aggiungiConferenza(c2);
    idConferenze++;
    organizzatori.clear(); articoli.clear();

    organizzatori.push_back("Marco De Vries");
    articoli.push_back(art1);
    data.setDate(2021, 10, 12);
    Conferenza c3(idConferenze, "C3", data, "SOE", "Seoul", organizzatori, 1500, articoli);
    gestore.aggiungiConferenza(c3);
    idConferenze++;
    organizzatori.clear(); articoli.clear();

    organizzatori.push_back("Charles Verstappen");
    articoli.push_back(art3);
    articoli.push_back(art5);
    articoli.push_back(art2);
    data.setDate(2020, 12, 1);
    Conferenza c4(idConferenze, "C4", data, "APPLECE2020", "San Francisco", organizzatori, 1000, articoli);
    gestore.aggiungiConferenza(c4);
    idConferenze++;
    organizzatori.clear(); articoli.clear();
    */
    //gestore.stampaConferenze();

    /*
    int id;
    QString nome;
    QString acronimo;
    QString editore;
    int volume;
    QList<Articolo> articoli;
    */

    //RIVISTE
    /*articoli.push_back(art5);
    data.setDate(2020, 11, 3);
    Rivista r1(idRiviste, "Conto Italiano", "CI", "Laura Maggi", 1, data, articoli);
    gestore.aggiungiRivista(r1);
    idRiviste++;
    articoli.clear();

    articoli.push_back(art6);
    data.setDate(2021, 1, 3);
    Rivista r2(idRiviste, "F1 Magazine", "F1M", "Luca Prezemolo", 4, data, articoli);
    gestore.aggiungiRivista(r2);
    idRiviste++;
    articoli.clear();

    articoli.push_back(art7);
    data.setDate(2021, 1, 12);
    Rivista r3(idRiviste, "Motorsport News", "MN", "Lucia Marchi", 7, data, articoli);
    gestore.aggiungiRivista(r3);
    idRiviste++;
    articoli.clear();

    articoli.push_back(art9);
    data.setDate(2020, 11, 3);
    Rivista r4(idRiviste, "Piano Economico 2021 Italia", "PE2021", "Lucia Mirarchi", 2, data, articoli);
    gestore.aggiungiRivista(r4);
    idRiviste++;
    articoli.clear();
    //gestore.stampaRiviste();

*/
    //SEZIONE C
    /*
    QList<QString> keywordAlti = gestore.metodoC6();
    for(auto i : keywordAlti)
        qDebug() << i << Qt::endl;


    QList<Articolo> articoliPrezzoBasso = gestore.metodoC1(0);
    if(articoliPrezzoBasso.size()==0){
        qDebug() << "Non ci sono articoli per l'autore selezionato!" << Qt::endl;
    }
    for(auto i : articoliPrezzoBasso){
        qDebug() << i.getTitolo() << " | Prezzo: " << i.getPrezzo() << Qt::endl;
    }

    double mediaPrezzi = gestore.metodoC3(5);
    if(mediaPrezzi == -1)
        qDebug() << "Non ci sono articoli per l'autore indicato!" << Qt::endl;
    else
        qDebug() << mediaPrezzi << Qt::endl;
    */

    //SEZIONE D
    /*
    list<Articolo> articoliAutoreOrdinatiPrezzoCrescente = gestore.metodoD2(4);

    if(articoliAutoreOrdinatiPrezzoCrescente.size()==0){
        qDebug() << "Non ci sono articoli per l'autore selezionato!" << Qt::endl;
    }
    else{
        for(auto i : articoliAutoreOrdinatiPrezzoCrescente)
            qDebug() << i.getTitolo() << " | Prezzo: " << i.getPrezzo() << Qt::endl;
    }

    list<Articolo> articoliRelativiKeyword = gestore.metodoD5("Intelligenza Artificiale");

    for(auto i : articoliRelativiKeyword)
        qDebug() << i.getTitolo() << " | " << i.getDataAssociato() << " | " << i.getPrezzo() << " | Cognome: " << i.getAutori()[0].getCognome() << Qt::endl;
    */
    //SEZIONE E
    /*
    list<Rivista> rivisteSpecialistiche = gestore.metodoE6();
    if(rivisteSpecialistiche.size()==0)
        qDebug() << "Non ci sono riviste specialistiche!" << Qt::endl;
    for(auto i : rivisteSpecialistiche){
        qDebug() << i.getNome() << Qt::endl;
        for(auto j : i.getArticoli()){
            for(auto k : j.getKeywords())
                qDebug() << k << Qt::endl;
        }
    }
    */

    //SEZIONE F
    /*
    vector<Articolo> articoliInfluenzati = gestore.metodoF1(4);
    if(articoliInfluenzati.size() == 0){
        qDebug() << "Non ci sono articoli influenzati dall'articolo selezionato" << Qt::endl;
    }
    else{
        for(auto i : articoliInfluenzati)
            qDebug() << i.getTitolo() << Qt::endl;
    }
    */

    /*
    list<Conferenza> conferenzeSimili = gestore.metodoF5(0);
    if(conferenzeSimili.size()==0){
        qDebug() << "Non ci sono conferenze simili a quella specificata!" << Qt::endl;
    }
    else{
        for(auto i : conferenzeSimili)
            qDebug() << i.getNome() << Qt::endl;
    }
    */ //HO LASCIATO I VARI TEST CHE HO FATTO PER I METODI

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();


}
