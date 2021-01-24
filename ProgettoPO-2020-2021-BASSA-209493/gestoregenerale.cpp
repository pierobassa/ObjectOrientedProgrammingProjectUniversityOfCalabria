#include "gestoregenerale.h"
#include <QDebug>
#include <float.h>


void GestoreGenerale::aggiungiAutore(Autore &a){
    autoriInseriti.push_back(a);
}
bool GestoreGenerale::rimuoviAutore(int id){
    int cont=0;
    for(auto i : autoriInseriti){
        if(i.getId() == id){
            autoriInseriti.removeAt(cont);
            return true;
        }
        else
            cont++;
    }
    return false;
}

void GestoreGenerale::stampaAutori() const{
    for(auto i : autoriInseriti){
        qDebug() << "Id: " << i.getId() << " - " << i.getNome() << " " << i.getCognome() << Qt::endl;
        qDebug() << "Afferenze " << Qt::endl;
        for(auto j : i.getAfferenze()){
            qDebug() << j << Qt::endl;
        }
    }
}

void GestoreGenerale::aggiungiArticolo(Articolo &a){
    articoliInseriti.push_back(a);
}
bool GestoreGenerale::rimuoviArticolo(int id){
    int cont=0;
    for(auto i : articoliInseriti){
        if(i.getId() == id){
            articoliInseriti.removeAt(cont);
            return true;
        }
        else
            cont++;
    }
    return false;
}


void GestoreGenerale::stampaArticoli() const{
    for(auto i : articoliInseriti){
        qDebug() << i.getId() << " - " << "Titolo: " << i.getTitolo() << " | Numero pagine: " << i.getNumeroPagine() << " | Prezzo: " << i.getPrezzo() << Qt::endl;
        /*if(i.getDestinazione())
            qDebug() << "PER CONFERENZA" << Qt::endl;
        else
            qDebug() << "PER RIVISTA" << Qt::endl;*/
        qDebug() << "Autori:" << Qt::endl;
        for(auto j : i.getAutori()){
            qDebug() << "Id: " << j.getId() << " - " << j.getNome() << " " << j.getCognome() << Qt::endl;
            qDebug() << "Afferenze " << Qt::endl;
            for(auto k : j.getAfferenze()){
                qDebug() << k << Qt::endl;
            }
        }
        qDebug() << "Keywords: " << Qt::endl;
        for(auto j : i.getKeywords())
            qDebug() << j << Qt::endl;
        qDebug() << "Articoli correlati: " << Qt::endl;
        for(auto j : i.getArticoliCorrelati())
            qDebug() << j << Qt::endl;
    }
}

void GestoreGenerale::aggiungiConferenza(Conferenza &c){
    conferenzeInserite.push_back(c);
}
bool GestoreGenerale::rimuoviConferenza(int id){
    int cont=0;
    for(auto i : conferenzeInserite){
        if(i.getId() == id){
            conferenzeInserite.removeAt(cont);
            return true;
        }
        else
            cont++;
    }
    return false;
}



void GestoreGenerale::stampaConferenze() const{
    for(auto i : conferenzeInserite){
        qDebug() << "Id: " << i.getId() << "Nome: " << i.getNome() << "(" << i.getAcronimo() << ") | Data:" << i.getData().toString() << " | Luogo:" << i.getLuogo() << " | Partecipanti:" << i.getNumeroPartecipanti() << Qt::endl;
        qDebug() << "Organizzatori: " << Qt::endl;
        for(auto j : i.getOrganizzatori())
            qDebug() << j << Qt::endl;
        qDebug() << "Articoli inerenti: " << Qt::endl;
        for(auto j : i.getArticoli()){
            qDebug() << j.getTitolo() << Qt::endl;
        }
    }
}

void GestoreGenerale::aggiungiRivista(Rivista &r){
    rivisteInserite.push_back(r);
}
bool GestoreGenerale::rimuoviRivista(int id){
    int cont=0;
    for(auto i : rivisteInserite){
        if(i.getId() == id){
            rivisteInserite.removeAt(cont);
            return true;
        }
        else
            cont++;
    }
    return false;
}



void GestoreGenerale::stampaRiviste() const{
    for(auto i : rivisteInserite){
        qDebug() << "Id: " << i.getId() << "Nome: " << i.getNome() << "(" << i.getAcronimo() << ") | Editore:" << i.getEditore() << "Volume: " << i.getVolume() << Qt::endl;
        qDebug() << "Articoli:" << Qt::endl;
        for(auto j : i.getArticoli()){
            qDebug() << j.getId() << " - " << "Titolo: " << j.getTitolo() << " | Numero pagine: " << j.getNumeroPagine() << " | Prezzo: " << j.getPrezzo() << Qt::endl;
        }
    }
}

QList<QString> getKeywords(QList<Articolo> articoliInseriti){
    QList<QString> keywords;

    for(auto i : articoliInseriti){
        for(auto j : i.getKeywords()){
            if(keywords.indexOf(j) == -1){
                keywords.push_back(j);
            }
        }
    }

    return keywords;
}

QList<QString> GestoreGenerale::metodoC6(){
    QList<QString> keywords = getKeywords(articoliInseriti);

    double prezzo=0, max=DBL_MIN;
    QList<QString> keywordAlti;

    for(auto i : keywords){
        for(auto j : articoliInseriti){
            for(auto k : j.getKeywords()){
                if(k == i){
                    prezzo += j.getPrezzo();
                    break;
                }
            }
        }
        if(prezzo>max){
            keywordAlti.clear();
            keywordAlti.push_back(i);
            max = prezzo;
        }
        else if(prezzo == max){
            keywordAlti.push_back(i);
        }
        prezzo = 0;
    }

    return keywordAlti;
}

QList<Articolo> GestoreGenerale::metodoC1(int id){
    QList<Articolo> articoliPrezzoBasso;
    double min=DBL_MAX, prezzo;

    for(auto i : articoliInseriti){
        for(auto j : i.getAutori()){
            if(j.getId() == id){
                prezzo = i.getPrezzo();
                if(prezzo<min){
                    articoliPrezzoBasso.clear();
                    articoliPrezzoBasso.push_back(i);
                    min = prezzo;
                    break;
                }
                else if(prezzo == min){
                    articoliPrezzoBasso.push_back(i);
                    break;
                }
            }
        }
    }

    return articoliPrezzoBasso;
}

double GestoreGenerale::metodoC3(int id){
    double sommaPrezzi=0;
    int numeroArticoli=0;

    for(auto i : articoliInseriti){
        for(auto j : i.getAutori()){
            if(j.getId() == id){
                sommaPrezzi+=i.getPrezzo();
                numeroArticoli++;
                break;
            }
        }
    }

    if(sommaPrezzi == 0)
        return -1;

    sommaPrezzi = (double) sommaPrezzi/numeroArticoli;

    return sommaPrezzi;
}

bool compare(Articolo a1, Articolo a2){
    return a1.getPrezzo() < a2.getPrezzo();
}

//SEZIONE D
list<Articolo> GestoreGenerale::metodoD2(int id){
    list<Articolo> articoliInseritiAutore;

    for(auto i : articoliInseriti){
        for(auto j : i.getAutori()){
            if(j.getId() == id){
                articoliInseritiAutore.push_back(i);
                break;
            }
        }
    }

    articoliInseritiAutore.sort(compare);

    return articoliInseritiAutore;
}

bool compareMetodoD5(Articolo a1, Articolo a2){
    if(a1.getDataAssociato()>a2.getDataAssociato())
        return true;
    if(a2.getDataAssociato()>a1.getDataAssociato())
        return false;
    if(a1.getPrezzo()<a2.getPrezzo())
        return true;
    if(a2.getPrezzo()<a1.getPrezzo())
        return false;

    QString cognomePrimo1, cognomePrimo2;
    cognomePrimo1 = a1.getAutori()[0].getCognome();
    cognomePrimo2 = a2.getAutori()[0].getCognome();
    return cognomePrimo1 < cognomePrimo2;
}

list<Articolo> GestoreGenerale::metodoD5(QString keyword){
    list<Articolo> articoliRelativiKeyword;

    for(auto i : articoliInseriti){
        for(auto j : i.getKeywords()){
            if(j == keyword){
                articoliRelativiKeyword.push_back(i);
                break;
            }
        }
    }

    articoliRelativiKeyword.sort(compareMetodoD5);

    return articoliRelativiKeyword;
}



//SEZIONE E

bool sottoinsiemeProprio(const list<QString>keywordsR1, const list<QString>keywordsR2){
    /*
    Dati due insiemi A e B non vuoti, diremo che A è un sottoinsieme proprio di B
    se tutti gli elementi dell'insieme A appartengono anche all'insieme B e almeno
    un elemento dell'insieme B non appartiene all'insieme A. @https://www.okpedia.it/sottoinsieme_proprio
    */

    if(keywordsR1.size()>=keywordsR2.size()){
        return false;
    }
    if(keywordsR1.size()==0){
        return false;
    }

    for(auto i : keywordsR1){
        if(find(keywordsR2.begin(), keywordsR2.end(), i) == keywordsR2.end())
            return false;
    }
    return true;
}

list<Rivista> GestoreGenerale::metodoE6(){
    list<QString> keywordsR1, keywordsR2;

    list<Rivista> rivisteSpecialistiche;

    for(auto i : rivisteInserite){
        for(auto j : i.getArticoli()){
            for(auto k : j.getKeywords())
                keywordsR1.push_back(k);
        }
        //dentro keywordsR1 ho tutte le keywords degli articoli di R1
        keywordsR1.sort();
        keywordsR1.unique(); //tolgo le keywords che compaiono più volte fra gli articoli della rivista R1;

        for(auto j=rivisteInserite.begin(); j!=rivisteInserite.end(); ++j){
            if(j->getId() != i.getId()){ //non prendo le keywords della stessa rivista R1
                for(auto k : j->getArticoli()){
                    for(auto l : k.getKeywords())
                        keywordsR2.push_back(l);
                }
                //ora dentro keywordsR2 ho tutte le keywords degli articoli della rivista R2 (diverso da R1)
                keywordsR2.sort();
                keywordsR2.unique(); //tolgo le keywords che compaiono più volte fra gli articoli di R2
                if(sottoinsiemeProprio(keywordsR1, keywordsR2)){ //vedo se keywordsR1 è un sottoinsieme proprio di keywordsR2
                    rivisteSpecialistiche.push_back(i); //se si aggiungo R1 alla lista rivisteSpecialistiche
                    break; //i è una rivistaSpecialistica allora vado alla rivista successiva
                }
                //altrimenti svuoto keywordsR2. R2 diventerà la successiva rivista in rivisteInserite e così via
                keywordsR2.clear();
            }
        }
        keywordsR1.clear();
        keywordsR2.clear();
    }

    return rivisteSpecialistiche;
}

//SEZIONE F


bool giaInserito(vector<Articolo> influenzatiDaA, Articolo B){
    for(auto k : influenzatiDaA){
        if(k.getId() == B.getId())
            return true;
    }

    return false;
}


vector<Articolo> GestoreGenerale::metodoF1(int id){
    QString titoloA;
    QDate dataA;

    for(auto i : articoliInseriti){
        if(i.getId() == id){
            titoloA = i.getTitolo();
            dataA = i.getDataAssociato();
            break;
        }
    } //PRENDO TITOLO E DATA DELL'ARTICOLO SELEZIONATO CHE INFLUISCE SUGLI ALTRI
    //NEI CORRELATI HO SCELTO DI INSERIRE IL TITOLO DELL'ARTICOLO CORRELATO

    vector<Articolo> influenzatiDaA; //Andrò ad inserire tutti gli articoli influenzati da A

    for(auto i : articoliInseriti){
        if(i.getId() != id){
            QList<QString> correlati = i.getArticoliCorrelati();
            if(find(correlati.begin(), correlati.end(), titoloA) != correlati.end() && dataA < i.getDataAssociato()){
                influenzatiDaA.push_back(i); //SE TROVO articolo A nei correlati aggiungo B se la data di A è precedente (minore) della data di B
            }
            correlati.clear(); //Svuoto per sicurezza
        }
    }
    //Ora dentro influenzatiDaA ho tutti gli articoli direttamente influenzati da A

    //Cerchiamo le influenze transitive: A->C e C->B allora A influenza B
    QString titoloC;
    QDate dataC;

    for(int i=0; i<(int)influenzatiDaA.size(); i++){//Scorro gli influenzati direttamente da A
        titoloC = influenzatiDaA[i].getTitolo(); //Prendo il Titolo di C
        dataC = influenzatiDaA[i].getDataAssociato(); //Prendo la data di C
        for(int j=0; j<articoliInseriti.size(); j++){ //Scorro tutti gli articoli e cerco gli articoli influenzati da C
            if(influenzatiDaA[i].getId() != articoliInseriti[j].getId()){ //Evito di controllare se C influenza C
                QList<QString> correlati = articoliInseriti[j].getArticoliCorrelati(); //Prendo i correlati di B
                QDate data = articoliInseriti[j].getDataAssociato(); //Prendo la data di B
                if(find(correlati.begin(), correlati.end(), titoloC) != correlati.end() && dataC<data){ //Se trovo C nei correlati di B e la data di C è precedente alla data di B
                    if(!giaInserito(influenzatiDaA, articoliInseriti[j])) //Allora controllo se non ho già inserito B
                        influenzatiDaA.push_back(articoliInseriti[j]); //Se non l'ho già inserito, B diventa influenzato da A transitivamente.
                        //Osservazione: influenzatiDaA avrà un nuovo elemento, pertanto andrà a controllare anche se l'articolo inserito influenzi altri articoli non già inseriti
                }
            }
        }
    }

    return influenzatiDaA;
}

bool keywordSimili(const list<QString> keywordsConferenzaSpecificata, const list<QString> keywordsConferenza){
    list<QString> keywordTotali;
    for(auto i : keywordsConferenzaSpecificata)
        keywordTotali.push_back(i);
    for(auto i : keywordsConferenza)
        keywordTotali.push_back(i);

    keywordTotali.sort();
    keywordTotali.unique(); //Faccio l'unione dei due insiemi (quindi tolgo anche la ridondanza)

    int cont = 0, keywordTot = keywordTotali.size(); //prendo la cardinalità dell'unione
    double percentuale;

    for(auto i : keywordsConferenzaSpecificata){
        if(find(keywordsConferenza.begin(), keywordsConferenza.end(), i) != keywordsConferenza.end()){
            cont++; //conto gli elementi in comune
        }
    }

    percentuale = (double) cont/keywordTot; //Freq. relativa = numero di elementi in comune / numero totale

    if(percentuale>=0.80)
        return true;
    else
        return false;
}

list<Conferenza> GestoreGenerale::metodoF5(int id){

    list<QString> keywordsConferenzaSpecificata, keywordsConferenza;

    list<Conferenza> conferenzeSimili;

    for(auto i : conferenzeInserite){
        if(i.getId() == id){
            for(auto j : i.getArticoli()){
                for(auto k : j.getKeywords())
                    keywordsConferenzaSpecificata.push_back(k);
            }
            keywordsConferenzaSpecificata.sort();
            keywordsConferenzaSpecificata.unique();
            break;
        }
    }

    //Dentro keywordsConferenzaSpecificata ho tutte le keywords (rimossa eventuale ridondanza) della conferenza specificata

    for(auto i : conferenzeInserite){ //Ora vado a vedere quali conferenze sono simili (hanno almeno 80% keywords in comune)
        if(i.getId()!=id){ //controllo quelle diverse da se stessa
            for(auto j : i.getArticoli()){
                for(auto k : j.getKeywords()){
                    keywordsConferenza.push_back(k); //prendo tutte le keywords della conferenza
                }
            }
            keywordsConferenza.sort();
            keywordsConferenza.unique(); //tolgo l'eventuale ridondanza
            if(keywordSimili(keywordsConferenzaSpecificata, keywordsConferenza)){ //controllo se hanno almeno l'80% delle keywords in comune.
                conferenzeSimili.push_back(i);  //Se si, aggiungo la conferenza nella lista essendo una conferenza simile.
            }
            keywordsConferenza.clear();
        }
    }

    return conferenzeSimili;
}








