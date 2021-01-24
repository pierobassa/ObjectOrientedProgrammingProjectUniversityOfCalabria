#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QPixmap>

#include "gestoregenerale.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentWidget(ui->home);

    ui->bottoneFine->setToolTip("Clicca se hai finito di selezionare gli autori dell'articolo.");
    ui->bottoneFineSelezioneCorrelati->setToolTip("Clicca se hai finito di selezionare gli articoli correlati per l'articolo che stai aggiungendo.");

}

MainWindow::~MainWindow()
{
    delete ui;
}

//GESTOREGENERALE
GestoreGenerale gestore;
int idAutori=0, idArticoli=0, idConferenze=0, idRiviste=0;

void MainWindow::on_bottoneHome_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->home);
}
void MainWindow::on_bottoneInserimento_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->paginaInserimento);
}
void MainWindow::on_bottoneInserisciAutore_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->paginaInsAutore);
}
void MainWindow::on_bottoneInserisciArticolo_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->paginaInsArticolo);
}
void MainWindow::on_bottoneInserisciConferenza_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->paginaInsConferenza);
}
void MainWindow::on_bottoneInserisciRivista_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->paginaInsRivista);
}

//INIZIALIZZAZIONE VELOCE AUTORI, ARTICOLI, CONFERENZE, RIVISTE:
void MainWindow::on_bottoneInserAutomatico_clicked()
{
    ui->bottoneInserAutomatico->setVisible(false);
    ui->label_54->clear();
    QMessageBox mess(QMessageBox::Information, "Perfetto!", "Inserimento automatico effettuato!", QMessageBox::Ok, this);
    mess.exec();

    QList<QString> afferenzeAutore;

    //INSERISCO DEGLI AUTORI
    afferenzeAutore.push_back("Uni Calabria");
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

    //ARTICOLI
    QList<Autore> autoriArticolo;
    QList<QString> keywords;
    QList<QString> correlati;
    QDate dataAssociato;


    autoriArticolo.push_back(a4);
    autoriArticolo.push_back(a1);
    keywords.push_back("Intelligenza Artificiale");
    correlati.push_back("Ecco il cashback di Poste Italiane");
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
    dataAssociato.setDate(2021, 1, 1);
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
    dataAssociato.setDate(2020, 10, 12);
    art4.setDataAssociato(dataAssociato);
    gestore.aggiungiArticolo(art4);
    idArticoli++;
    correlati.clear(); keywords.clear(); autoriArticolo.clear();

    autoriArticolo.push_back(a2);
    keywords.push_back("Conto corrente cointesato");
    keywords.push_back("Cashback Poste Italiane");
    keywords.push_back("Aprire un conto Poste Italiane");
    correlati.push_back("Ecco il cashback di Poste Italiane");
    Articolo art5(idArticoli, "Come funziona il conto cointesato", 3, autoriArticolo, keywords, 13.70, correlati);
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


    //TEST PER METODOF1
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

    //CONFERENZE
    QList<QString> organizzatori;
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
    data.setDate(2021, 1, 1);
    Conferenza c2(idConferenze, "Rivoluzione Poste Italiane", data, "RPT", "Milano", organizzatori, 700, articoli);
    gestore.aggiungiConferenza(c2);
    idConferenze++;
    organizzatori.clear(); articoli.clear();

    organizzatori.push_back("Marco De Vries");
    articoli.push_back(art4);
    articoli.push_back(art9);
    data.setDate(2020, 10, 12);
    Conferenza c3(idConferenze, "Samsung October Event", data, "SOE", "Seoul", organizzatori, 1500, articoli);
    gestore.aggiungiConferenza(c3);
    idConferenze++;
    organizzatori.clear(); articoli.clear();

    organizzatori.push_back("Charles Verstappen");
    articoli.push_back(art3);
    data.setDate(2020, 12, 1);
    Conferenza c4(idConferenze, "Apple Christmas event", data, "APPLECE2020", "San Francisco", organizzatori, 1000, articoli);
    gestore.aggiungiConferenza(c4);
    idConferenze++;
    organizzatori.clear(); articoli.clear();


    //TEST METODOF5
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
    keywords.push_back("K1");
    keywords.push_back("K3");
    keywords.push_back("K5");
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

    //RIVISTE

    articoli.push_back(art5);
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
    articoli.push_back(art10);
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

}

//AUTORE
QList<QString> afferenzeInserite;
void MainWindow::on_bottoneInserisciAfferenze_clicked()
{
    if(ui->campoAfferenza->text().isEmpty()){
        QMessageBox mess(QMessageBox::Critical, "ERRORE!", "Devi inserire un'afferenza nel campo di inserimento!", QMessageBox::Ok, this);
        mess.exec();
        return;
    }
    afferenzeInserite.push_back(ui->campoAfferenza->text());
    ui->afferenzeInserite->addItem(ui->campoAfferenza->text());
    ui->campoAfferenza->clear();
}
void MainWindow::on_bottoneInserAutore_clicked()
{
    if(afferenzeInserite.size()==0 || ui->campoNome->text().isEmpty() || ui->campoCognome->text().isEmpty()){
        QMessageBox mess(QMessageBox::Critical, "ERRORE!", "Devi inserire almeno un'afferenza e tutti i campi devono essere compilati!", QMessageBox::Ok, this);
        mess.exec();
        return;
    }

    Autore a(idAutori, ui->campoNome->text(), ui->campoCognome->text(), afferenzeInserite);
    for(auto i : gestore.getAutoriInseriti()){
        if(a == i){
            QMessageBox mess(QMessageBox::Information, "Attenzione!", "Hai già inserito questo autore!", QMessageBox::Ok, this);
            mess.exec();
            return;
        }
    }
    gestore.aggiungiAutore(a);
    idAutori++;

    afferenzeInserite.clear();
    ui->afferenzeInserite->clear();
    ui->campoNome->clear();
    ui->campoCognome->clear();
    ui->campoAfferenza->clear();

}
void MainWindow::on_pulsanteVisualizzaAutori_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->paginaVisualizzaAutori);
    ui->visualizzaAutori->clear();

    QList<Autore> autori = gestore.getAutoriInseriti();
    for(auto i : autori){
        ui->visualizzaAutori->addItem("ID: " + QString::number(i.getId()) + " | " + i.getNome() + " " + i.getCognome());
    }
}
void MainWindow::on_bottoneVisualizzaAfferenzeAutore_clicked()
{
    if(ui->visualizzaAutori->selectedItems().size()==0){
        QMessageBox mess(QMessageBox::Critical, "ERRORE!", "Devi selezionare l'autore per il quale visualizzare le affereze!", QMessageBox::Ok, this);
        mess.exec();
        return;
    }

    ui->visualizzaAfferenzeAutore->clear();

    QString autore = ui->visualizzaAutori->currentItem()->text();
    for(auto i : gestore.getAutoriInseriti()){
        QString aut = "ID: " + QString::number(i.getId()) + " | " + i.getNome() + " " + i.getCognome();
        if(aut == autore){
            for(auto j : i.getAfferenze()){
                ui->visualizzaAfferenzeAutore->addItem(j);
            }
            return;
        }
    }
}
void MainWindow::on_bottoneVisAutori_clicked()
{
    on_pulsanteVisualizzaAutori_clicked();
}
void MainWindow::on_bottoneResetAutore_clicked()
{
    afferenzeInserite.clear();
    ui->afferenzeInserite->clear();
    ui->campoNome->clear();
    ui->campoCognome->clear();
    ui->campoAfferenza->clear();
}

//ARTICOLO
void MainWindow::on_radioPrendiConferenze_clicked()
{
    ui->visualizzatoreConferenzeORiviste->clear();
    ui->conferenzaOrivistaSelezionata->clear();
    for(auto i : gestore.getConferenzeInserite()){
        QString conferenza = i.getNome() + " (" +i.getAcronimo() + ") | Data: " + i.getData().toString(Qt::DateFormat::ISODate) + " | Luogo: " + i.getLuogo();
        ui->visualizzatoreConferenzeORiviste->addItem(conferenza);
    }
}
void MainWindow::on_bottoneVaiAselezionaDestinazione_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->paginaSelezioneConferenzaOrivista);
    ui->visualizzatoreConferenzeORiviste->clear();
    on_radioPrendiConferenze_clicked();
    ui->radioPrendiConferenze->setChecked(true);

}
void MainWindow::on_radioPrendiRiviste_clicked()
{
    ui->visualizzatoreConferenzeORiviste->clear();
    ui->conferenzaOrivistaSelezionata->clear();
    for(auto i : gestore.getRivisteInserite()){
        ui->visualizzatoreConferenzeORiviste->addItem(i.getNome() + " (" +i.getAcronimo() + ") | Volume: " + QString::number(i.getVolume()) + " | Editore: " + i.getEditore() + " | " + i.getData().toString(Qt::DateFormat::ISODate));
    }
}
void MainWindow::on_bottVaiAinsConferenza_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->paginaInsConferenza);
}
void MainWindow::on_bottVaiAinsRivista_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->paginaInsRivista);
}
void MainWindow::on_bottSeleziona_clicked()
{
    if(ui->visualizzatoreConferenzeORiviste->selectedItems().size()==0){
        QMessageBox mess(QMessageBox::Critical, "ERRORE!", "Devi selezionare una conferenza o rivista!", QMessageBox::Ok, this);
        mess.exec();
        return;
    }

    if(ui->conferenzaOrivistaSelezionata->count()==1){
        QMessageBox mess(QMessageBox::Critical, "ERRORE!", "Hai già selezionato la conferenza o rivista dell'articolo!", QMessageBox::Ok, this);
        mess.exec();
        return;
    }

    QString selezionato = ui->visualizzatoreConferenzeORiviste->currentItem()->text();
    ui->conferenzaOrivistaSelezionata->addItem(selezionato);

    QListWidgetItem *selezione = ui->visualizzatoreConferenzeORiviste->currentItem();
    ui->visualizzatoreConferenzeORiviste->removeItemWidget(selezione);
    delete selezione;
}
void MainWindow::on_bottRimuovi_clicked()
{
    if(ui->conferenzaOrivistaSelezionata->selectedItems().size()==0){
        QMessageBox mess(QMessageBox::Critical, "ERRORE!", "Devi selezionare la conferenza o rivista da togliere!", QMessageBox::Ok, this);
        mess.exec();
        return;
    }

    QString selezionato = ui->conferenzaOrivistaSelezionata->currentItem()->text();
    ui->visualizzatoreConferenzeORiviste->addItem(selezionato);

    QListWidgetItem *selezione = ui->conferenzaOrivistaSelezionata->currentItem();
    ui->conferenzaOrivistaSelezionata->removeItemWidget(selezione);
    delete selezione;
}
void MainWindow::on_bottoneVaiAdAggiungiAutore_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->paginaInsAutore);
}
void MainWindow::on_bottoneVaiApaginaSelezionaAutori_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->paginaSelezionaAutori);
    ui->tuttiGliAutori->clear();
    QList<Autore> autori = gestore.getAutoriInseriti();
    for(auto i : autori){
        ui->tuttiGliAutori->addItem("ID: " + QString::number(i.getId()) + " | " + i.getNome() + " " + i.getCognome());
    }
}
void MainWindow::on_bottoneIndietro_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->paginaInsAutore);
    ui->visualizzaAutori->clear();
}
void MainWindow::on_bottonePrendiTutti_clicked()
{
    if(ui->tuttiGliAutori->count()==0)
        return;

    for(int i=0; i<ui->tuttiGliAutori->count(); ++i){
        ui->autoriSelezionati->addItem(ui->tuttiGliAutori->item(i)->text());
    }
    ui->tuttiGliAutori->clear();
}
void MainWindow::on_bottoneRimuoviTutti_clicked()
{
    if(ui->autoriSelezionati->count()==0)
        return;

    for(int i=0; i<ui->autoriSelezionati->count(); ++i){
        ui->tuttiGliAutori->addItem(ui->autoriSelezionati->item(i)->text());
    }
    ui->autoriSelezionati->clear();

}
void MainWindow::on_bottonePrendiSelezionato_clicked()
{
    if(ui->tuttiGliAutori->selectedItems().size()==0){
        QMessageBox mess(QMessageBox::Critical, "ERRORE!", "Devi selezionare un autore dalla lista!", QMessageBox::Ok, this);
        mess.exec();
        return;
    }

    QString selezionato = ui->tuttiGliAutori->currentItem()->text();
    ui->autoriSelezionati->addItem(selezionato);

    QListWidgetItem *selezione = ui->tuttiGliAutori->currentItem();
    ui->tuttiGliAutori->removeItemWidget(selezione);
    delete selezione;
}
void MainWindow::on_bottoneRimuoviSelezionato_clicked()
{
    if(ui->autoriSelezionati->selectedItems().size()==0){
        QMessageBox mess(QMessageBox::Critical, "ERRORE!", "Devi selezionare l'autore da togliere dai selezionati!", QMessageBox::Ok, this);
        mess.exec();
        return;
    }

    QString selezionato = ui->autoriSelezionati->currentItem()->text();
    ui->tuttiGliAutori->addItem(selezionato);

    QListWidgetItem *selezione = ui->autoriSelezionati->currentItem();
    ui->autoriSelezionati->removeItemWidget(selezione);
    delete selezione;
}
void MainWindow::on_bottoneFineConferenzaORivista_clicked()
{
    if(ui->conferenzaOrivistaSelezionata->count()==0){
        QMessageBox mess(QMessageBox::Critical, "ERRORE!", "Devi selezionare la conferenza o rivista alla quale assegnare l'articolo!", QMessageBox::Ok, this);
        mess.exec();
        return;
    }
    ui->campoListDestinazioneScelta->clear();
    ui->campoListDestinazioneScelta->addItem(ui->conferenzaOrivistaSelezionata->item(0)->text());
    ui->conferenzaOrivistaSelezionata->clear();
    ui->stackedWidget->setCurrentWidget(ui->paginaInsArticolo);
}
void MainWindow::on_bottoneFine_clicked()
{
    if(ui->autoriSelezionati->count() == 0){
        QMessageBox mess(QMessageBox::Critical, "ERRORE!", "Devi selezionare almeno un autore dell'articolo che stai aggiungendo!", QMessageBox::Ok, this);
        mess.exec();
        return;
    }

    ui->autoriSelezionatiDentroInsArticolo->clear();

    for(int i=0; i<ui->autoriSelezionati->count(); ++i){
        ui->autoriSelezionatiDentroInsArticolo->addItem(ui->autoriSelezionati->item(i)->text());
    }


    ui->tuttiGliAutori->clear();
    ui->autoriSelezionati->clear();

    ui->stackedWidget->setCurrentWidget(ui->paginaInsArticolo);
}
void MainWindow::on_bottoneVaiArticoliCorrelati_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->paginaSelezionaArticoliCorrelati);
    ui->tuttiGliArticoli->clear();
    QList<Articolo> articoli = gestore.getArticoliInseriti();
    for(auto i : articoli){
        ui->tuttiGliArticoli->addItem("ID: " + QString::number(i.getId()) + " | " + i.getTitolo());
    }
}
void MainWindow::on_bottonePrendiTuttiArticoli_clicked()
{
    if(ui->tuttiGliArticoli->count()==0)
        return;

    for(int i=0; i<ui->tuttiGliArticoli->count(); ++i){
        ui->articoliSelezionati->addItem(ui->tuttiGliArticoli->item(i)->text());
    }
    ui->tuttiGliArticoli->clear();
}
void MainWindow::on_bottoneRimuoviTuttiArticoli_clicked()
{
    if(ui->articoliSelezionati->count()==0)
        return;

    for(int i=0; i<ui->articoliSelezionati->count(); ++i){
        ui->tuttiGliArticoli->addItem(ui->articoliSelezionati->item(i)->text());
    }
    ui->articoliSelezionati->clear();

}
void MainWindow::on_bottonePrendiSelezionatoArticolo_clicked()
{
    if(ui->tuttiGliArticoli->selectedItems().size()==0){
        QMessageBox mess(QMessageBox::Critical, "ERRORE!", "Devi selezionare un articolo dalla lista!", QMessageBox::Ok, this);
        mess.exec();
        return;
    }

    QString selezionato = ui->tuttiGliArticoli->currentItem()->text();
    ui->articoliSelezionati->addItem(selezionato);

    QListWidgetItem *selezione = ui->tuttiGliArticoli->currentItem();
    ui->tuttiGliArticoli->removeItemWidget(selezione);
    delete selezione;
}
void MainWindow::on_bottoneRimuoviSelezionatoArticolo_clicked()
{
    if(ui->articoliSelezionati->selectedItems().size()==0){
        QMessageBox mess(QMessageBox::Critical, "ERRORE!", "Devi selezionare l'articolo da togliere dai selezionati!", QMessageBox::Ok, this);
        mess.exec();
        return;
    }

    QString selezionato = ui->articoliSelezionati->currentItem()->text();
    ui->tuttiGliArticoli->addItem(selezionato);

    QListWidgetItem *selezione = ui->articoliSelezionati->currentItem();
    ui->articoliSelezionati->removeItemWidget(selezione);
    delete selezione;
}
void MainWindow::on_bottoneFineSelezioneCorrelati_clicked()
{

    ui->articoliCorrelatiSelezionatiDentroIns->clear();

    for(int i=0; i<ui->articoliSelezionati->count(); ++i){
        ui->articoliCorrelatiSelezionatiDentroIns->addItem(ui->articoliSelezionati->item(i)->text());
    }

    ui->tuttiGliArticoli->clear();
    ui->articoliSelezionati->clear();

    ui->stackedWidget->setCurrentWidget(ui->paginaInsArticolo);
}
QList<QString> keywords;
void MainWindow::on_bottoneAggiungiKeyword_clicked()
{
    if(ui->campoKeyword->text().isEmpty()){
        QMessageBox mess(QMessageBox::Critical, "ERRORE!", "Devi inserire una keyword nel campo di inserimento!", QMessageBox::Ok, this);
        mess.exec();
        return;
    }
    QString keywordInserito = ui->campoKeyword->text();
    for(int i=0; i<ui->keywordInseriti->count(); ++i){
        if(ui->keywordInseriti->item(i)->text() == keywordInserito){
            QMessageBox mess(QMessageBox::Critical, "ERRORE!", "Hai già inserito quella keyword!", QMessageBox::Ok, this);
            mess.exec();
            return;
        }
    }
    keywords.push_back(ui->campoKeyword->text());
    ui->keywordInseriti->addItem(ui->campoKeyword->text());
    ui->campoKeyword->clear();
}
void MainWindow::on_bottoneResetArticolo_clicked()
{
    keywords.clear();

    ui->campoTitolo->clear();
    ui->campoListDestinazioneScelta->clear();
    ui->keywordInseriti->clear();
    ui->autoriSelezionatiDentroInsArticolo->clear();
    ui->articoliCorrelatiSelezionatiDentroIns->clear();
    ui->campoKeyword->clear();
}
void MainWindow::on_bottoneAggiungiArticolo_clicked()
{
    if(keywords.size()==0 || ui->autoriSelezionatiDentroInsArticolo->count()==0 || ui->spinBoxNumeroPagine->value() == 0 || ui->campoListDestinazioneScelta->count()==0 || ui->campoTitolo->text().isEmpty()){
        QMessageBox mess(QMessageBox::Critical, "ERRORE!", "Non tutti i campi sono stati inseriti. (Ricorda che deve esserci almeno un autore, una keyword e almeno una pagina!", QMessageBox::Ok, this);
        mess.exec();
        return;
    }


    QList<Autore> autoriArticolo;
    QList<QString> correlati;

    for(int i=0; i<ui->autoriSelezionatiDentroInsArticolo->count(); ++i){
        QString autore = ui->autoriSelezionatiDentroInsArticolo->item(i)->text();
        for(auto j : gestore.getAutoriInseriti()){
            QString aut = "ID: " + QString::number(j.getId()) + " | " + j.getNome() + " " + j.getCognome();
            if(autore == aut){
                autoriArticolo.push_back(j);
                break;
            }
        }
    }

    for(int i=0; i<ui->articoliCorrelatiSelezionatiDentroIns->count(); ++i){
        QString articolo = ui->articoliCorrelatiSelezionatiDentroIns->item(i)->text();
        for(auto j : gestore.getArticoliInseriti()){
            QString art = "ID: " + QString::number(j.getId()) + " | " + j.getTitolo();
            if(articolo == art){
                QString titolo = j.getTitolo();
                correlati.push_back(titolo);
                break;
            }
        }
    }

    QString titolo = ui->campoTitolo->text();
    int numPagine = ui->spinBoxNumeroPagine->value();
    double prezzo = ui->spinBoxPrezzo->value();


    bool conferenza;
    if(ui->radioPrendiConferenze->isChecked()){
        conferenza = true;
    }
    else
        conferenza = false;

    Articolo art(idArticoli, titolo, numPagine, autoriArticolo, keywords, prezzo, correlati);
    idArticoli++;

    QString assegnato;
    if(conferenza){
        int pos = 0;
        assegnato = ui->campoListDestinazioneScelta->item(0)->text();
        for(auto i : gestore.getConferenzeInserite()){
            QString conf = i.getNome() + " (" +i.getAcronimo() + ") | Data: " + i.getData().toString(Qt::DateFormat::ISODate) + " | Luogo: " + i.getLuogo();
            if(assegnato == conf){
                gestore.aggiungiArticoloConferenza(pos, art);
                art.setDataAssociato(gestore.getConferenzeInserite()[pos].getData());
                break;
            }
            pos++;
        }
    }
    else{
        int pos = 0;
        assegnato = ui->campoListDestinazioneScelta->item(0)->text();
        for(auto i : gestore.getRivisteInserite()){
            QString rivista = i.getNome() + " (" +i.getAcronimo() + ") | Volume: " + QString::number(i.getVolume()) + " | Editore: " + i.getEditore() + " | " + i.getData().toString(Qt::DateFormat::ISODate);
            if(assegnato == rivista){
                gestore.aggiungiArticoloRivista(pos, art);
                art.setDataAssociato(gestore.getRivisteInserite()[pos].getData());
                break;

            }
            else
                pos++;
        }
    }

    gestore.aggiungiArticolo(art);

    correlati.clear(); keywords.clear(); autoriArticolo.clear();

    ui->campoTitolo->clear();
    ui->spinBoxNumeroPagine->setValue(0);
    ui->spinBoxPrezzo->setValue(0.00);
    ui->keywordInseriti->clear();
    ui->autoriSelezionatiDentroInsArticolo->clear();
    ui->articoliCorrelatiSelezionatiDentroIns->clear();
    ui->campoListDestinazioneScelta->clear();
}
void MainWindow::on_bottoneVaiAinsArticolo_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->paginaInsArticolo);
}
void MainWindow::on_bottoneVisualizzaArticoli_clicked()
{
    ui->tuttiGliArticoliInseriti->clear();
    ui->stackedWidget->setCurrentWidget(ui->paginaVisualizzaArticoli);
    for(auto i : gestore.getArticoliInseriti()){
        ui->tuttiGliArticoliInseriti->addItem("ID: " + QString::number(i.getId()) + " | " + i.getTitolo());
    }
}
void MainWindow::on_bottoneVisArticoli_clicked()
{
    on_bottoneVisualizzaArticoli_clicked();
}
void MainWindow::on_bottoneVisualizzaAutoriArticolo_clicked()
{
    if(ui->tuttiGliArticoliInseriti->selectedItems().size()==0){
        QMessageBox mess(QMessageBox::Critical, "ERRORE!", "Seleziona l'articolo per la quale ricevere le informazioni richieste!", QMessageBox::Ok, this);
        mess.exec();
        return;
    }

    ui->visualizzatoreArticolo->clear();

    QString selezionato = ui->tuttiGliArticoliInseriti->currentItem()->text();
    for(auto i : gestore.getArticoliInseriti()){
        QString articolo = "ID: " + QString::number(i.getId()) + " | " + i.getTitolo();
        if(selezionato == articolo){
            for(auto j : i.getAutori()){
                ui->visualizzatoreArticolo->addItem("ID: " + QString::number(j.getId()) + " | " + j.getNome() + " " + j.getCognome());
            }
            return;
        }
    }
}
void MainWindow::on_bottoneVisualizzaKeywordArticolo_clicked()
{
    if(ui->tuttiGliArticoliInseriti->selectedItems().size()==0){
        QMessageBox mess(QMessageBox::Critical, "ERRORE!", "Seleziona l'articolo per la quale ricevere le informazioni richieste!", QMessageBox::Ok, this);
        mess.exec();
        return;
    }

    ui->visualizzatoreArticolo->clear();
    QString selezionato = ui->tuttiGliArticoliInseriti->currentItem()->text();
    for(auto i : gestore.getArticoliInseriti()){
        QString articolo = "ID: " + QString::number(i.getId()) + " | " + i.getTitolo();
        if(selezionato == articolo){
            for(auto j : i.getKeywords()){
                ui->visualizzatoreArticolo->addItem(j);
            }
            return;
        }
    }
}
void MainWindow::on_bottoneVisualizzaArtCorrArticolo_clicked()
{
    if(ui->tuttiGliArticoliInseriti->selectedItems().size()==0){
        QMessageBox mess(QMessageBox::Critical, "ERRORE!", "Seleziona l'articolo per la quale ricevere le informazioni richieste!", QMessageBox::Ok, this);
        mess.exec();
        return;
    }

    ui->visualizzatoreArticolo->clear();
    QString selezionato = ui->tuttiGliArticoliInseriti->currentItem()->text();
    for(auto i : gestore.getArticoliInseriti()){
        QString articolo = "ID: " + QString::number(i.getId()) + " | " + i.getTitolo();
        if(selezionato == articolo){
            for(auto j : i.getArticoliCorrelati()){
                ui->visualizzatoreArticolo->addItem(j);
            }
            return;
        }
    }
}

//CONFERENZA
void MainWindow::on_bottoneVisualizzaConferenze_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->paginaVisualizzaConferenze);
    ui->tutteLeConferenze->clear();
    ui->visualizzatoreConferenza->clear();

    for(auto i : gestore.getConferenzeInserite()){
        QString conferenza = i.getNome() + " (" +i.getAcronimo() + ") | Data: " + i.getData().toString(Qt::DateFormat::ISODate) + " | Luogo: " + i.getLuogo();
        ui->tutteLeConferenze->addItem(conferenza);
    }
}
void MainWindow::on_bottoneIndietroConf_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->paginaInsConferenza);
    ui->tutteLeConferenze->clear();
    ui->visualizzatoreConferenza->clear();
}
void MainWindow::on_bottoneVisualizzaOrganizzatori_clicked()
{
    if(ui->tutteLeConferenze->selectedItems().size()==0){
        QMessageBox mess(QMessageBox::Critical, "ERRORE!", "Devi selezionare la conferenza per la quale visualizzare gli organizzatori!", QMessageBox::Ok, this);
        mess.exec();
        return;
    }

    ui->visualizzatoreConferenza->clear();

    QString selezionato = ui->tutteLeConferenze->currentItem()->text();
    for(auto i : gestore.getConferenzeInserite()){
        QString conferenza = i.getNome() + " (" +i.getAcronimo() + ") | Data: " + i.getData().toString(Qt::DateFormat::ISODate) + " | Luogo: " + i.getLuogo();
        if(conferenza == selezionato){
            for(auto j : i.getOrganizzatori()){
                ui->visualizzatoreConferenza->addItem(j);
            }
            return;
        }
    }
}
void MainWindow::on_bottoneVisualizzaArticoliConf_clicked()
{
    if(ui->tutteLeConferenze->selectedItems().size()==0){
        QMessageBox mess(QMessageBox::Critical, "ERRORE!", "Devi selezionare la conferenza per la quale visualizzare gli articoli!", QMessageBox::Ok, this);
        mess.exec();
        return;
    }

    ui->visualizzatoreConferenza->clear();
    QString selezionato = ui->tutteLeConferenze->currentItem()->text();
    for(auto i : gestore.getConferenzeInserite()){
        QString conferenza = i.getNome() + " (" +i.getAcronimo() + ") | Data: " + i.getData().toString(Qt::DateFormat::ISODate) + " | Luogo: " + i.getLuogo();
        if(conferenza == selezionato){
            for(auto j : i.getArticoli()){
                ui->visualizzatoreConferenza->addItem("ID: " + QString::number(j.getId()) + " | " + j.getTitolo());
            }
            return;
        }
    }
}
void MainWindow::on_bottoneAggiungiOrganizzatore_clicked()
{
    if(ui->campoOrganizzatore->text().isEmpty()){
        QMessageBox mess(QMessageBox::Critical, "ERRORE!", "Devi inserire l'organizzatore nell'apposito campo!", QMessageBox::Ok, this);
        mess.exec();
        return;
    }

    ui->organizzatoriInseriti->addItem(ui->campoOrganizzatore->text());
    ui->campoOrganizzatore->clear();
}
void MainWindow::on_bottoneVisConferenze_clicked()
{
    on_bottoneVisualizzaConferenze_clicked();
}
void MainWindow::on_bottoneAggiungiConferenza_clicked()
{
    if(ui->campoNomeConferenza->text().isEmpty() || ui->campoAcronimo->text().isEmpty() || ui->campoLuogo->text().isEmpty() || ui->spinBoxNumeroPartecipanti->value()==0 || ui->organizzatoriInseriti->count()==0){
        QMessageBox mess(QMessageBox::Critical, "ERRORE!", "Tutti i campi sono obbligatori. Ci deve essere almeno un partecipante e almeno un organizzatore!", QMessageBox::Ok, this);
        mess.exec();
        return;
    }

    QList<QString> organizzatori;
    QList<Articolo> articoli;
    QDate data;

    QString nome = ui->campoNomeConferenza->text();
    QString acronimo = ui->campoAcronimo->text();
    QString luogo = ui->campoLuogo->text();
    int numeroPartecipanti = ui->spinBoxNumeroPartecipanti->value();
    data = ui->calendarWidgetConferenza->selectedDate();

    //QString conferenza = nome + " (" + acronimo + ") | Data: " + data.toString(Qt::DateFormat::ISODate) + " | Luogo: " + luogo;
    QString conferenza = nome + " (" + acronimo + ") | Data: " + data.toString(Qt::DateFormat::ISODate);
    for(auto i : gestore.getConferenzeInserite()){
        QString conf = i.getNome() + " (" +i.getAcronimo() + ") | Data: " + i.getData().toString(Qt::DateFormat::ISODate);
        if(conf == conferenza){
            QMessageBox mess(QMessageBox::Critical, "ERRORE!", "Hai già inserito una conferenza con stesso nome, acronimo e data!", QMessageBox::Ok, this);
            mess.exec();
            return;
        }
    }

    for(int i=0; i<ui->organizzatoriInseriti->count(); ++i){
        organizzatori.push_back(ui->organizzatoriInseriti->item(i)->text());
    }


    Conferenza nuovaConferenza(idConferenze, nome, data, acronimo, luogo, organizzatori, numeroPartecipanti, articoli);
    idConferenze++;
    gestore.aggiungiConferenza(nuovaConferenza);
    organizzatori.clear(); articoli.clear();

    ui->calendarWidgetConferenza->setCurrentPage(QDate::currentDate().year(), QDate::currentDate().month());
    ui->campoNomeConferenza->clear(); ui->campoAcronimo->clear(); ui->campoLuogo->clear();
    ui->spinBoxNumeroPartecipanti->setValue(0);
    ui->organizzatoriInseriti->clear();
    ui->campoOrganizzatore->clear();
}

void MainWindow::on_bottoneResetConferenza_clicked()
{
    ui->campoNomeConferenza->clear();
    ui->campoAcronimo->clear();
    ui->organizzatoriInseriti->clear();
    ui->campoLuogo->clear();
    ui->spinBoxNumeroPartecipanti->setValue(0);
    ui->campoOrganizzatore->clear();
    ui->calendarWidgetConferenza->setCurrentPage(QDate::currentDate().year(), QDate::currentDate().month());
}

//RIVISTA
void MainWindow::on_bottoneVisualizzaRiviste_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->paginaVisualizzaRiviste);
    ui->tutteLeRiviste->clear();

    for(auto i : gestore.getRivisteInserite()){
        ui->tutteLeRiviste->addItem(i.getNome() + " (" +i.getAcronimo() + ") | Volume: " + QString::number(i.getVolume()) + " | Editore: " + i.getEditore() + " | " + i.getData().toString(Qt::DateFormat::ISODate));
    }
}
void MainWindow::on_bottoneIndietroRivista_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->paginaInsRivista);
    ui->tutteLeRiviste->clear();
    ui->visualizzatoreArticoliRivista->clear();
}
void MainWindow::on_bottoneVisualizzaArticoliRivista_clicked()
{
    if(ui->tutteLeRiviste->selectedItems().size()==0){
        QMessageBox mess(QMessageBox::Critical, "ERRORE!", "Devi selezionare la rivista per la quale visualizzare gli articoli inerenti!", QMessageBox::Ok, this);
        mess.exec();
        return;
    }

    ui->visualizzatoreArticoliRivista->clear();

    QString selezionato = ui->tutteLeRiviste->currentItem()->text();
    for(auto i : gestore.getRivisteInserite()){
        QString rivista = i.getNome() + " (" +i.getAcronimo() + ") | Volume: " + QString::number(i.getVolume()) + " | Editore: " + i.getEditore() + " | " + i.getData().toString(Qt::DateFormat::ISODate);
        if(selezionato == rivista){
            for(auto j : i.getArticoli()){
                ui->visualizzatoreArticoliRivista->addItem("ID: " + QString::number(j.getId()) + " | " + j.getTitolo());
            }
            return;
        }
    }

}
void MainWindow::on_bottoneVisRiviste_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->paginaVisualizzaRiviste);
    ui->tutteLeRiviste->clear();

    for(auto i : gestore.getRivisteInserite()){
        ui->tutteLeRiviste->addItem(i.getNome() + " (" +i.getAcronimo() + ") | Volume: " + QString::number(i.getVolume()) + " | Editore: " + i.getEditore() + " | " + i.getData().toString(Qt::DateFormat::ISODate));
    }
}
void MainWindow::on_bottoneAggiungiRivista_clicked()
{
    if(ui->campoNomeRivista->text().isEmpty() || ui->campoAcronimoRivista->text().isEmpty() || ui->campoEditore->text().isEmpty() || ui->spinBoxVolume->value()==0){
        QMessageBox mess(QMessageBox::Critical, "ERRORE!", "Tutti i campi sono obbligatori e il volume deve essere maggiore di 0!", QMessageBox::Ok, this);
        mess.exec();
        return;
    }

    QList<Articolo> articoli;
    QString nome = ui->campoNomeRivista->text();
    QString acronimo = ui->campoAcronimoRivista->text();
    QString editore = ui->campoEditore->text();
    int volume = ui->spinBoxVolume->value();
    QDate data = ui->calendarWidgetRivista->selectedDate();

    //QString rivista = nome + " (" + acronimo + ") | Volume: " + QString::number(volume) + " | Editore: " + editore  + " | " + data.toString(Qt::DateFormat::ISODate);
    QString rivista = nome + " (" + acronimo + ")" + " | " + data.toString(Qt::DateFormat::ISODate);
    for(auto i : gestore.getRivisteInserite()){
        //QString riv = i.getNome() + " (" +i.getAcronimo() + ") | Volume: " + QString::number(i.getVolume()) + " | Editore: " + i.getEditore() + " | " + i.getData().toString(Qt::DateFormat::ISODate);
        QString riv = i.getNome() + " (" + i.getAcronimo() + ")" + " | " + i.getData().toString(Qt::DateFormat::ISODate);
        if(rivista == riv){
            QMessageBox mess(QMessageBox::Critical, "ERRORE!", "Hai già inserito una rivista con stesso nome, acronimo e data!", QMessageBox::Ok, this);
            mess.exec();
            return;
        }
    }

    Rivista nuovaRivista(idRiviste, nome, acronimo, editore, volume, data, articoli);
    idRiviste++;
    gestore.aggiungiRivista(nuovaRivista);


    ui->calendarWidgetRivista->setCurrentPage(QDate::currentDate().year(), QDate::currentDate().month());
    ui->campoNomeRivista->clear();
    ui->campoEditore->clear();
    ui->campoAcronimoRivista->clear();
    ui->spinBoxVolume->setValue(0);
    articoli.clear();
}

//SEZIONE B
void MainWindow::on_bottoneVaiASezioneB_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->paginaSezioneB);
}
void MainWindow::on_bottVaiAVisArticoliRelativiAdAutore_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->paginaSezBVisualizzaArticoliAutore);
    ui->tuttiGliAutoriSEZB->clear();

    for(auto i : gestore.getAutoriInseriti()){
         ui->tuttiGliAutoriSEZB->addItem("ID: " + QString::number(i.getId()) + " | " + i.getNome() + " " + i.getCognome());
    }
}
void MainWindow::on_bottVisArticoliAutore_clicked()
{
   if(ui->tuttiGliAutoriSEZB->selectedItems().size()==0){
       QMessageBox mess(QMessageBox::Critical, "ERRORE!", "Devi selezionare un autore dalla lista!", QMessageBox::Ok, this);
       mess.exec();
       return;
   }

   ui->articoliAutoreSelezionato->clear();

   int pos = ui->tuttiGliAutoriSEZB->currentRow();
   int IDautoreSelezionato = gestore.getAutoriInseriti()[pos].getId();
   for(auto i : gestore.getArticoliInseriti()){
       for(auto j : i.getAutori()){
           if(j.getId() == IDautoreSelezionato){
               ui->articoliAutoreSelezionato->addItem("ID: " + QString::number(i.getId()) + " | " + i.getTitolo());
               break;
           }
       }
   }

   if(ui->articoliAutoreSelezionato->count()==0){
       QMessageBox mess(QMessageBox::Warning, "Attenzione!", "Non ci sono articoli per l'autore selezionato!", QMessageBox::Ok, this);
       mess.exec();
       return;
   }
}
void MainWindow::on_botVisConferenze_clicked()
{
    on_bottoneVisualizzaConferenze_clicked();
}
void MainWindow::on_bottVisRiviste_clicked()
{
    on_bottoneVisRiviste_clicked();
}

//SEZIONE C
void MainWindow::on_bottoneVaiASezioneC_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->paginaSezioneC);
}
void MainWindow::on_bottVaiAkeywordAlto_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->paginaKeywordAlto);

    QList<QString> keywordAlti = gestore.metodoC6();
    if(keywordAlti.size()==0){
        QMessageBox mess(QMessageBox::Warning, "Attenzione!", "Non hai inserito articoli!", QMessageBox::Ok, this);
        mess.exec();
        return;
    }

    ui->risultatoKeywordAlto->clear();

    for(auto i : keywordAlti){
        ui->risultatoKeywordAlto->addItem(i);
    }
}
void MainWindow::on_bottVaiAselezionaAutore_clicked()
{
    ui->visualizzatoreSezioneC->clear();
    ui->tuttiAutoriSezioneC->clear();

    ui->stackedWidget->setCurrentWidget(ui->paginaSelezionaAutore);

    if(gestore.getAutoriInseriti().size()==0){
        QMessageBox mess(QMessageBox::Warning, "Attenzione!", "Non hai inserito Autori!", QMessageBox::Ok, this);
        mess.exec();
        return;
    }

    for(auto i : gestore.getAutoriInseriti()){
        ui->tuttiAutoriSezioneC->addItem("ID: " + QString::number(i.getId()) + " | " + i.getNome() + " " + i.getCognome());
    }
}
void MainWindow::on_bottVaiAselezionaAutore_2_clicked()
{
    on_bottVaiAselezionaAutore_clicked();
}
void MainWindow::on_bottMetodoC1_clicked()
{
    if(ui->tuttiAutoriSezioneC->selectedItems().size()==0){
        QMessageBox mess(QMessageBox::Critical, "ERRORE!", "Devi selezionare a sinistra l'autore per il quale ricevere le informazioni desiderate!", QMessageBox::Ok, this);
        mess.exec();
        return;
    }

    ui->visualizzatoreSezioneC->clear();

    QList<Articolo> articoliPrezzoBasso = gestore.metodoC1(ui->tuttiAutoriSezioneC->currentRow());
    if(articoliPrezzoBasso.size()==0){
        QMessageBox mess(QMessageBox::Warning, "Attenzione!", "Non ci sono articoli per l'autore selezionato!", QMessageBox::Ok, this);
        mess.exec();
        return;
    }
    for(auto i : articoliPrezzoBasso){
        ui->visualizzatoreSezioneC->addItem("ID: " + QString::number(i.getId()) + " | " + i.getTitolo() + " | Prezzo: " + QString::number(i.getPrezzo()));
    }
}
void MainWindow::on_bottMetodoC3_clicked()
{
    if(ui->tuttiAutoriSezioneC->selectedItems().size()==0){
        QMessageBox mess(QMessageBox::Critical, "ERRORE!", "Devi selezionare a sinistra l'autore per il quale ricevere le informazioni desiderate!", QMessageBox::Ok, this);
        mess.exec();
        return;
    }

    ui->visualizzatoreSezioneC->clear();

    double mediaPrezzi = gestore.metodoC3(ui->tuttiAutoriSezioneC->currentRow());
        if(mediaPrezzi == -1){
            QMessageBox mess(QMessageBox::Warning, "Attenzione!", "Non ci sono articoli per l'autore selezionato!", QMessageBox::Ok, this);
            mess.exec();
            return;
        }
        else
            ui->visualizzatoreSezioneC->addItem(QString::number(mediaPrezzi));
}

//SEZIONE D
void MainWindow::on_bottoneVaiASezioneD_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->paginaSezioneD);
}
void MainWindow::on_bottVaiAMetodoD2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->paginaMetodoD2);
    ui->tuttiAutoriSezioneD->clear();
    ui->visualizzatoreMetodoD2->clear();

    for(auto i : gestore.getAutoriInseriti()){
        ui->tuttiAutoriSezioneD->addItem("ID: " + QString::number(i.getId()) + " | " + i.getNome() + " " + i.getCognome());
    }


}
void MainWindow::on_bottVaiAMetodoD5_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->paginaMetodoD5);
    ui->tuttiKeywordSezioneD->clear();
    ui->visualizzatoreMetodoD5->clear();

    QList<QString> tuttiKeyword;
    for(auto i : gestore.getArticoliInseriti()){
        for(auto j : i.getKeywords()){
            if(tuttiKeyword.indexOf(j)==-1){
                tuttiKeyword.push_back(j);
            }
        }
    }
    for(auto i : tuttiKeyword)
        ui->tuttiKeywordSezioneD->addItem(i);
}
void MainWindow::on_bottMetodoD2_clicked()
{
    if(ui->tuttiAutoriSezioneD->selectedItems().size()==0){
        QMessageBox mess(QMessageBox::Critical, "ERRORE!", "Devi selezionare a sinistra l'autore per il quale ricevere le informazioni desiderate!", QMessageBox::Ok, this);
        mess.exec();
        return;
    }

    ui->visualizzatoreMetodoD2->clear();

    list<Articolo> articoliAutoreOrdinatiPrezzoCrescente = gestore.metodoD2(ui->tuttiAutoriSezioneD->currentRow());
    if(articoliAutoreOrdinatiPrezzoCrescente.size()==0){
        QMessageBox mess(QMessageBox::Warning, "Attenzione!", "Non ci sono articoli per l'autore selezionato!", QMessageBox::Ok, this);
        mess.exec();
        return;
    }

    for(auto i : articoliAutoreOrdinatiPrezzoCrescente)
        ui->visualizzatoreMetodoD2->addItem(i.getTitolo() + " | Prezzo: " + QString::number(i.getPrezzo()));

}
void MainWindow::on_bottMetodoD5_clicked()
{
    if(ui->tuttiKeywordSezioneD->selectedItems().size()==0){
        QMessageBox mess(QMessageBox::Critical, "ERRORE!", "Devi selezionare a sinistra la keyword per la quale ricevere le informazioni desiderate!", QMessageBox::Ok, this);
        mess.exec();
        return;
    }
    ui->visualizzatoreMetodoD5->clear();

    list<Articolo> articoliRelativiKeyword = gestore.metodoD5(ui->tuttiKeywordSezioneD->currentItem()->text());

    for(auto i : articoliRelativiKeyword)
        ui->visualizzatoreMetodoD5->addItem(i.getTitolo() + " | " + i.getDataAssociato().toString(Qt::DateFormat::ISODate) + " | " + QString::number(i.getPrezzo()) + " | Cognome: " + i.getAutori()[0].getCognome());
}

//SEZIONE E
void MainWindow::on_bottoneVaiASezioneE_clicked()
{
    ui->rivisteSpecialistiche->clear();

    ui->stackedWidget->setCurrentWidget(ui->paginaSezioneE);

    list<Rivista> rivisteSpecialistiche = gestore.metodoE6();
    if(rivisteSpecialistiche.size()==0){
        QMessageBox mess(QMessageBox::Warning, "Attenzione!", "Non ci sono riviste specialistiche!", QMessageBox::Ok, this);
        mess.exec();
        return;
    }
    for(auto i : rivisteSpecialistiche)
        ui->rivisteSpecialistiche->addItem(i.getNome());
}

//SEZIONE F
void MainWindow::on_bottoneVaiASezioneF_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->paginaSezioneF);
}
void MainWindow::on_bottVaiAmetodoF1_clicked()
{
    ui->tuttiArticoliMetodoF1->clear();
    ui->stackedWidget->setCurrentWidget(ui->paginaMetodoF1);
    for(auto i : gestore.getArticoliInseriti()){
        ui->tuttiArticoliMetodoF1->addItem("ID: " + QString::number(i.getId()) + " | " + i.getTitolo());
    }
}
void MainWindow::on_bottPrendiInfluenzati_clicked()
{
    ui->influenzati->clear();

    if(ui->tuttiArticoliMetodoF1->selectedItems().size()==0){
        QMessageBox mess(QMessageBox::Critical, "ERRORE!", "Devi selezionare a sinistra l'articolo per il quale ricevere gli influenzati", QMessageBox::Ok, this);
        mess.exec();
        return;
    }

    vector<Articolo> articoliInfluenzati = gestore.metodoF1(ui->tuttiArticoliMetodoF1->currentRow());
    if(articoliInfluenzati.size() == 0){
        QMessageBox mess(QMessageBox::Warning, "Attenzione!", "Non ci sono articoli influenzati dall'articolo selezionato!", QMessageBox::Ok, this);
        mess.exec();
        return;
    }

    for(auto i : articoliInfluenzati)
        ui->influenzati->addItem("ID: " + QString::number(i.getId()) + " | " + i.getTitolo());

}
void MainWindow::on_bottVaiAmetodoF5_clicked()
{
    ui->tutteConferenzeMetodoF5->clear();
    ui->stackedWidget->setCurrentWidget(ui->paginaMetodoF5);

    if(gestore.getConferenzeInserite().size()==0){
        QMessageBox mess(QMessageBox::Warning, "Attenzione!", "Non hai inserito Conferenze!", QMessageBox::Ok, this);
        mess.exec();
        return;
    }


    for(auto i : gestore.getConferenzeInserite()){
        ui->tutteConferenzeMetodoF5->addItem(i.getNome() + " (" +i.getAcronimo() + ") | Data: " + i.getData().toString(Qt::DateFormat::ISODate) + " | Luogo: " + i.getLuogo());
    }
}
void MainWindow::on_bottPrendiSimiliMetodoF5_clicked()
{
    ui->conferenzeSimili->clear();

    if(ui->tutteConferenzeMetodoF5->selectedItems().size()==0){
        QMessageBox mess(QMessageBox::Critical, "ERRORE!", "Devi selezionare a sinistra la conferenza per la quale ricevere i simili!", QMessageBox::Ok, this);
        mess.exec();
        return;
    }

    list<Conferenza> conferenzeSimili = gestore.metodoF5(ui->tutteConferenzeMetodoF5->currentRow());
    if(conferenzeSimili.size()==0){
        QMessageBox mess(QMessageBox::Warning, "Attenzione!", "Non ci sono conferenze simili a quella specificata!", QMessageBox::Ok, this);
        mess.exec();
        return;
    }

    for(auto i : conferenzeSimili)
        ui->conferenzeSimili->addItem(i.getNome());
}

//INPUT DA FILE DI TESTO
void MainWindow::on_bottoneVaiAInsDaFileDiTesto_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->paginaImportFileTesto);
    ui->labelNomeFIle->clear();
    ui->comboBoxSceltaTipo->setCurrentIndex(0);
}
void MainWindow::on_bottVisAutori_clicked()
{
    on_pulsanteVisualizzaAutori_clicked();
}
void MainWindow::on_bottVisConferenze_clicked()
{
    on_bottoneVisualizzaConferenze_clicked();
}
void MainWindow::on_bottonVisRiviste_clicked()
{
    on_bottoneVisualizzaRiviste_clicked();
}
void MainWindow::on_bottVisArticoli_clicked()
{
    on_bottoneVisualizzaArticoli_clicked();
}

QStringList listaParole;
void MainWindow::on_bottPrendiFile_clicked()
{
    //Prendo il file scegliendolo mediante una QFileDialog che filtra per .txt
    QFile file(QFileDialog::getOpenFileName(this, tr("Scegli il file .txt per gli autori"), "C:\\", tr("Text files (*.txt)")));

    //Ora dobbiamo aprire il file scelto
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream stream(&file); //punto al file

    QFileInfo fileInfo(file.fileName()); //Prendo il nome del file scelto
    QString filename(fileInfo.fileName()); //Passo ad una QString il nome
    ui->labelNomeFIle->setText(filename);

    QString text = stream.readAll(); //trasferisco l'intero contenuto del file di testo alla stringa text

    listaParole = text.split('\n', Qt::SkipEmptyParts); //Assegno alla QStringList ogni keyword presente nel file di testo, saltando le parti vuote
}


void MainWindow::on_bottImportFile_clicked()
{
    if(ui->comboBoxSceltaTipo->currentIndex()==0){
        QList<QString> afferenzeAutore;
        QString nome, cognome;
        for(int i=0; i<listaParole.size(); ++i){
            if(listaParole[i]=="NOME"){
                nome = listaParole[i+1];

            }
            if(listaParole[i]=="COGNOME"){
                cognome=listaParole[i+1];
            }
            if(listaParole[i] == "AFFERENZE"){
                for(int j = i+1; j<listaParole.size(); ++j){
                    if(listaParole[j]=="DONE"){
                        Autore a(idAutori, nome, cognome, afferenzeAutore);
                        gestore.aggiungiAutore(a);
                        afferenzeAutore.clear();
                        idAutori++;
                        break;
                    }
                    afferenzeAutore.push_back(listaParole[j]);
                }
            }
        }
        QMessageBox mess(QMessageBox::Information, "Successo!", "Autori inseriti correttamente se hai rispettato il formato richiesto!", QMessageBox::Ok, this);
        mess.exec();

        ui->labelNomeFIle->clear();
    }
    if(ui->comboBoxSceltaTipo->currentIndex()==1){
        QList<QString> organizzatori;
        QList<Articolo> articoli;
        QDate data;

        QString nome, acronimo, luogo;
        int numeroPartecipanti;

        for(int i=0; i<listaParole.size(); ++i){
            if(listaParole[i]=="NOME"){
                nome = listaParole[i+1];
            }
            if(listaParole[i]=="ACRONIMO"){
                acronimo = listaParole[i+1];
            }
            if(listaParole[i] == "DATA"){
                QString date = listaParole[i+1];
                data = QDate::fromString(date, "dd/MM/yyyy");
            }
            if(listaParole[i] == "LUOGO"){
                luogo = listaParole[i+1];
            }
            if(listaParole[i] == "NUMERO_PARTECIPANTI"){
                numeroPartecipanti = listaParole[i+1].toInt();
            }
            if(listaParole[i] == "ORGANIZZATORI"){
                for(int j=i+1; j<listaParole.size(); ++j){
                    if(listaParole[j] == "DONE"){
                        Conferenza c(idConferenze, nome, data, acronimo, luogo, organizzatori, numeroPartecipanti, articoli);
                        gestore.aggiungiConferenza(c);
                        idConferenze++;
                        organizzatori.clear(); articoli.clear();
                        break;
                    }
                    organizzatori.push_back(listaParole[j]);
                }
            }
        }
        QMessageBox mess(QMessageBox::Information, "Successo!", "Conferenze inserite correttamente se hai rispettato il formato richiesto!", QMessageBox::Ok, this);
        mess.exec();

        ui->labelNomeFIle->clear();
    }
    if(ui->comboBoxSceltaTipo->currentIndex()==2){
        QList<Articolo> articoli;
        QString nome, acronimo, editore;
        int volume;
        QDate data;

        for(int i=0; i<listaParole.size(); ++i){
           if(listaParole[i] == "NOME"){
               nome = listaParole[i+1];
           }
           if(listaParole[i] == "ACRONIMO"){
               acronimo = listaParole[i+1];
           }
           if(listaParole[i] == "EDITORE"){
               editore = listaParole[i+1];
           }
           if(listaParole[i] == "VOLUME"){
               volume = listaParole[i+1].toInt();
           }
           if(listaParole[i] == "DATA"){
               QString date = listaParole[i+1];
               data = QDate::fromString(date, "dd/MM/yyyy");
           }
           if(listaParole[i] == "DONE"){
               Rivista nuovaRivista(idRiviste, nome, acronimo, editore, volume, data, articoli);
               idRiviste++;
               gestore.aggiungiRivista(nuovaRivista);
           }
        }
        QMessageBox mess(QMessageBox::Information, "Successo!", "Riviste inserite correttamente se hai rispettato il formato richiesto!", QMessageBox::Ok, this);
        mess.exec();

        ui->labelNomeFIle->clear();
    }
    if(ui->comboBoxSceltaTipo->currentIndex()==3){

        QList<Autore> autoriArticolo;
        QList<QString> correlati;
        QList<QString> keywords;

        QString titolo;
        int numPagine;
        double prezzo;

        //Per conferenza o rivista associata
        QString luogo;
        QString nome;

        bool flagConferenza;

        for(int i=0; i<listaParole.size(); ++i){
            if(listaParole[i] == "TITOLO"){
                titolo = listaParole[i+1];
            }
            if(listaParole[i] == "NUMERO_PAGINE"){
                numPagine = listaParole[i+1].toInt();
            }
            if(listaParole[i] == "PREZZO")
                prezzo = listaParole[i+1].toDouble();

            if(listaParole[i] == "CONFERENZA"){
                flagConferenza=true;
                nome = listaParole[i+1];
            }
            if(listaParole[i] == "RIVISTA"){
                flagConferenza=false;
                nome = listaParole[i+1];
            }
            if(listaParole[i] == "AUTORI"){
                for(int j=i+1; j<listaParole.size(); ++j){
                    if(listaParole[j]=="KEYWORDS"){
                        break;
                    }
                    //QString autore = listaParole[j];
                    int id = listaParole[j].toInt();
                    for(auto k : gestore.getAutoriInseriti()){
                        //QString aut = k.getNome() + " " + k.getCognome(); //HO evitato nome e cognome perché ci possono essere autori con stesso nome e cognome
                        if(id == k.getId()){
                            autoriArticolo.push_back(k);
                            break;
                        }
                    }
                }
            }
            if(listaParole[i] == "KEYWORDS"){
                for(int j=i+1; j<listaParole.size(); ++j){
                    if(listaParole[j] == "CORRELATI"){
                        break;
                    }
                    keywords.push_back(listaParole[j]);
                }
            }
            if(listaParole[i] == "CORRELATI"){
                for(int j=i+1; j<listaParole.size(); ++j){
                    if(listaParole[j] == "DONE"){
                        Articolo art(idArticoli, titolo, numPagine, autoriArticolo, keywords, prezzo, correlati);
                        if(flagConferenza){
                            int pos=0;
                            for(auto i : gestore.getConferenzeInserite()){
                                if(i.getNome() == nome){
                                    gestore.aggiungiArticoloConferenza(pos, art);
                                    art.setDataAssociato(gestore.getConferenzeInserite()[pos].getData());
                                    break;
                                }
                                pos++;
                            }
                        }
                        else{
                            int pos = 0;
                            for(auto i : gestore.getRivisteInserite()){
                                if(i.getNome() == nome){
                                    gestore.aggiungiArticoloRivista(pos, art);
                                    art.setDataAssociato(gestore.getRivisteInserite()[pos].getData());
                                    break;
                                }
                                pos++;
                            }
                        }
                        idArticoli++;
                        gestore.aggiungiArticolo(art);
                        correlati.clear();
                        keywords.clear();
                        autoriArticolo.clear();
                        break;
                    }
                    correlati.push_back(listaParole[j]);
                }
            }
        }
        QMessageBox mess(QMessageBox::Information, "Successo!", "Articoli inseriti correttamente se hai rispettato il formato richiesto!", QMessageBox::Ok, this);
        mess.exec();

        ui->labelNomeFIle->clear();
    }
}


