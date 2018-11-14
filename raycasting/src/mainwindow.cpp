#include "headers/mainwindow.h"
#include "ui_mainwindow.h"
#include "headers/glwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    GLWidget *glw = new GLWidget(this);
    QAction *open = new QAction("&Abrir",this);
    QAction *save = new QAction("&Salvar",this);
    QAction *quit = new QAction("&Fechar",this);

    QVariant v = qVariantFromValue(glw);
    open->setData(v);

    open->setShortcut(tr("CTRL+O"));
    save->setShortcut(tr("CTRL+S"));
    quit->setShortcut(tr("CTRL+Q"));

    // Menu: Arquivo
    QMenu *file = menuBar()->addMenu("&Arquivo");
    file->addAction(open);
    file->addAction(save);
    file->addSeparator();
    file->addAction(quit);

    connect(open,&QAction::triggered,this,&MainWindow::openObjFile);
    connect(save,&QAction::triggered,this,&MainWindow::saveObjFile);
    connect(quit,&QAction::triggered,this,&QApplication::quit);

    setCentralWidget(glw);


    statusBar()->showMessage("Pronto");

    // ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openObjFile()
{
    QFileInfo fileInfo;

    QAction *act = qobject_cast<QAction *>(sender());
    QVariant v = act->data();
    GLWidget *glw = (GLWidget *) v.value<void *>();

    QString filename = QFileDialog::getOpenFileName(this,"Abrir arquivo OBJ",fileInfo.absolutePath(),"Arquivo OBJ (*.obj)");
    if (!filename.isEmpty()){
        const char *str;
        QByteArray ba;
        ba = filename.toLatin1();
        str = ba.data();
        parser(str, glw->objetos);
        statusBar()->showMessage("Carregando "+filename+" ...");
    }
}

void MainWindow::saveObjFile()
{
    QFileInfo fileInfo;
    QString filename = QFileDialog::getSaveFileName(this,"Salvar arquivo OBJ",fileInfo.absolutePath(),"Arquivo OBJ (*.obj)");

    if (!filename.isEmpty())
        statusBar()->showMessage("Salvando "+filename+" ...");
}
