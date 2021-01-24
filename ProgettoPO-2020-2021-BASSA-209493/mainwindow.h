#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_bottoneHome_clicked();

    void on_bottoneInserimento_clicked();

    void on_bottoneInserisciAutore_clicked();

    void on_bottoneInserisciArticolo_clicked();

    void on_bottoneInserisciConferenza_clicked();

    void on_bottoneInserisciRivista_clicked();

    void on_bottoneInserisciAfferenze_clicked();

    void on_bottoneInserAutore_clicked();

    void on_pulsanteVisualizzaAutori_clicked();

    void on_bottoneVaiApaginaSelezionaAutori_clicked();

    void on_bottoneVaiAdAggiungiAutore_clicked();

    void on_bottoneIndietro_clicked();

    void on_bottonePrendiTutti_clicked();

    void on_bottoneRimuoviTutti_clicked();

    void on_bottonePrendiSelezionato_clicked();

    void on_bottoneRimuoviSelezionato_clicked();

    void on_bottoneFine_clicked();

    void on_bottoneVaiArticoliCorrelati_clicked();

    void on_bottoneInserAutomatico_clicked();

    void on_bottonePrendiTuttiArticoli_clicked();

    void on_bottoneRimuoviTuttiArticoli_clicked();

    void on_bottonePrendiSelezionatoArticolo_clicked();

    void on_bottoneRimuoviSelezionatoArticolo_clicked();

    void on_bottoneFineSelezioneCorrelati_clicked();

    void on_bottoneAggiungiKeyword_clicked();

    void on_bottoneAggiungiArticolo_clicked();

    void on_bottoneVisualizzaAfferenzeAutore_clicked();

    //void on_bottoneSelezionaArticoli_clicked();

    //void on_bottPrendiTutti_clicked();

    //void on_bottRimuoviTutti_clicked();

    //void on_bottPrendiSelezionato_clicked();

    //void on_bottRimuoviSelezionato_clicked();

    //void on_bottoneFineSelezArtConferenza_clicked();

    void on_bottoneVisualizzaConferenze_clicked();

    void on_bottoneIndietroConf_clicked();

    void on_bottoneVisualizzaOrganizzatori_clicked();

    void on_bottoneVisualizzaArticoliConf_clicked();

    void on_bottoneAggiungiOrganizzatore_clicked();

    void on_bottoneAggiungiConferenza_clicked();

    void on_bottoneVisualizzaRiviste_clicked();

    void on_bottoneIndietroRivista_clicked();

    void on_bottoneVisualizzaArticoliRivista_clicked();

    //void on_bottoneSelezionaArticoliRivista_clicked();

    void on_bottoneVaiAselezionaDestinazione_clicked();

    void on_radioPrendiConferenze_clicked();

    void on_radioPrendiRiviste_clicked();

    void on_bottVaiAinsConferenza_clicked();

    void on_bottVaiAinsRivista_clicked();

    void on_bottSeleziona_clicked();

    void on_bottRimuovi_clicked();

    void on_bottoneFineConferenzaORivista_clicked();

    void on_bottoneVisualizzaArticoli_clicked();

    void on_bottoneResetArticolo_clicked();

    void on_bottoneVisAutori_clicked();

    void on_bottoneVisConferenze_clicked();

    void on_bottoneVisRiviste_clicked();

    void on_bottoneVaiAinsArticolo_clicked();

    void on_bottoneVisArticoli_clicked();

    void on_bottoneVisualizzaAutoriArticolo_clicked();

    void on_bottoneVisualizzaKeywordArticolo_clicked();

    void on_bottoneVisualizzaArtCorrArticolo_clicked();

    void on_bottVaiAVisArticoliRelativiAdAutore_clicked();

    void on_bottoneVaiASezioneB_clicked();

    void on_bottVisArticoliAutore_clicked();

    void on_botVisConferenze_clicked();

    void on_bottVisRiviste_clicked();

    void on_bottoneAggiungiRivista_clicked();

    void on_bottoneVaiASezioneC_clicked();

    void on_bottVaiAkeywordAlto_clicked();

    void on_bottVaiAselezionaAutore_clicked();

    void on_bottVaiAselezionaAutore_2_clicked();

    void on_bottMetodoC1_clicked();

    void on_bottMetodoC3_clicked();

    void on_bottoneVaiASezioneD_clicked();

    void on_bottVaiAMetodoD2_clicked();

    void on_bottVaiAMetodoD5_clicked();

    void on_bottMetodoD2_clicked();

    void on_bottMetodoD5_clicked();

    void on_bottoneVaiASezioneE_clicked();

    void on_bottVaiAmetodoF1_clicked();

    void on_bottoneVaiASezioneF_clicked();

    void on_bottPrendiInfluenzati_clicked();

    void on_bottVaiAmetodoF5_clicked();

    void on_bottPrendiSimiliMetodoF5_clicked();

    void on_bottoneVaiAInsDaFileDiTesto_clicked();

    void on_bottVisAutori_clicked();

    void on_bottVisConferenze_clicked();

    void on_bottonVisRiviste_clicked();

    void on_bottVisArticoli_clicked();

    void on_bottPrendiFile_clicked();

    void on_bottImportFile_clicked();

    void on_bottoneResetAutore_clicked();

    void on_bottoneResetConferenza_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
