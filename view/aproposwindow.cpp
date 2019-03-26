#include "aproposwindow.h"
#include "ui_aproposwindow.h"
#include "model/utils.h"
#include <QIcon>
#include <fstream>
#include <QStandardItemModel>
#include <cctype>
#include <QFileDialog>
#include <QtXml/qdom.h>
#include <vector>
#include "model/informaticien.h"
using namespace std;


AProposWindow::AProposWindow (QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AProposWindow)
{
    ui->setupUi(this);
}

AProposWindow::~AProposWindow()
{
    delete ui;
}

void AProposWindow::on_btnRetour_clicked()
{
    close();
}

void AProposWindow::on_btnExporter_clicked()
{
    /*QFileDialog dialog;
    dialog.setAcceptMode(QFileDialog::AcceptSave);
    dialog.selectFile("Exportation Comptes");
    dialog.setWindowIcon(QIcon(":hospital.png"));

    QString fichier = dialog.getSaveFileName(nullptr, "Enregistrer la planification", "Exportation Comptes"
                                             , "Fichier XML (*.xml)");
    if (!fichier.isNull()) {
        QDomDocument doc;
        QDomElement TCompte = doc.createElement("TCompte");
        doc.appendChild(TCompte);
        vector<Informaticien> informaticiens = Utils::loadInformaticien();
        for (unsigned int i = 0; i < informaticiens.size(); i++)
        {
            QDomElement element = doc.createElement("Comptes");
            element.setAttribute("id",informaticiens[i].getIdentifiant());

        }
    }*/
}
