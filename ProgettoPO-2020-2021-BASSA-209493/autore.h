#ifndef AUTORE_H
#define AUTORE_H

#include <QMainWindow>
#include <iostream>

using namespace std;

class Autore
{
private:
    int id;
    QString nome;
    QString cognome;
    QList<QString> afferenze;


public:
    Autore(){}
    Autore(int id, QString n, QString c, QList<QString> _afferenze){
        this->id = id;
        nome = n;
        cognome = c;
        afferenze = _afferenze;
    }

    bool aggiungiAfferenza(QString aff){
        for(auto i : afferenze){
            if(i == aff){
                return false;
            }
        }

        afferenze.push_back(aff);
        return true;
    }
    bool rimuoviAfferenza(QString aff){
        for(auto i=afferenze.begin(); i!=afferenze.end(); ++i){
            if(*i == aff){
                afferenze.erase(i);
                return true;
            }
        }
        return false;
    }

    int getId() const{
        return id;
    }
    QString getNome() const{
        return nome;
    }
    QString getCognome() const{
        return cognome;
    }
    QList<QString> getAfferenze() const{
        return afferenze;
    }

    void ssetId(int id){
        this->id = id;
    }
    void setNome(QString n){
        nome = n;
    }
    void setCognome(QString c){
        cognome = c;
    }

    /*bool operator==(const Autore &a) const{
        if(afferenze.size() != a.afferenze.size())
            return false;
        if(id == a.id && nome == a.nome && cognome == a.cognome){
            bool flag=false;
            for(int i=0; i<afferenze.size(); i++){
                for(int j=0; j<a.afferenze.size(); j++){
                    if(afferenze[i] == a.afferenze[j]){
                        flag=true;
                        break;
                    }
                }
                if(!flag)
                    return false;
                flag=false;
            }
            return true;
        }
        else
            return false;
    }*/

    bool operator==(const Autore &a) const{
        if(nome == a.nome && cognome == a.cognome && afferenze==a.afferenze)
            return true;
        else
            return false;
    }


};

#endif // AUTORE_H
