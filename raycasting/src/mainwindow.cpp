#include "headers/mainwindow.h"
#include "ui_mainwindow.h"
#include "headers/glwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QAction *open = new QAction("&Abrir",this);
      QAction *save = new QAction("&Salvar",this);
      QAction *quit = new QAction("&Fechar",this);

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

      GLWidget *glw = new GLWidget(this);
      setCentralWidget(glw);

    objetos;
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

  QString filename = QFileDialog::getOpenFileName(this,"Abrir arquivo OBJ",fileInfo.absolutePath(),"Arquivo OBJ (*.obj)");

  if (!filename.isEmpty()){
    //parser(filename.toStdString(), objetos);
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
