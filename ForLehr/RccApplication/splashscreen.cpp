#include "splashscreen.h"
#include "ui_splashscreen.h"
#include "loginpage.h"
#include <QTime>
#include <QTimer>
#include <QLabel>
#include "csplashscreen.h"

SplashScreen::SplashScreen(QLabel *parent) :
    QLabel(parent),
    ui(new Ui::SplashScreen)
{

    ui->setupUi(this);


    QPixmap image(":/rccTigerEdited.png");
    /*
    QLabel* aWidget = new QLabel(0, Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);
    aWidget->setAttribute(Qt::WA_TranslucentBackground);
    aWidget->setPixmap(image);
    aWidget->show();
    */

    //CSplashScreen* aSplashScreen = new CSplashScreen(image);
    //aSplashScreen->show();

    this->setWindowFlags(0, Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setPixmap(image);

    /*
    QPalette palette;
    palette.setBrush(QPalette::Window, image);
    this->setPalette(palette);

    this->setAutoFillBackground(false);
    */
    LoginPage *w=new LoginPage;
    QTimer::singleShot(5000, this,SLOT(close()));
    QTimer::singleShot(5000, aWidget,SLOT(close()));
    QTimer::singleShot(5000, w,SLOT(show()));
    //delete aSplashScreen;

}

SplashScreen::~SplashScreen()
{
    delete ui;
}

/*
void test_SplashScreen()
{
 class SleeperThread : public QThread
 {
 public:
  static void msleep(unsigned long msecs) {QThread::msleep(msecs);}
 };

 QPixmap aSplashImage(":/splash.png");

 CSplashScreen* aSplashScreen = new CSplashScreen(aSplashImage);
 aSplashScreen->show();

 for (int i = 1; i <= 5; i++)
 {
  aSplashScreen->showMessage(QString("Processing %1...").arg(i), Qt::AlignTop | Qt::AlignLeft, Qt::white);
  SleeperThread::msleep(1000);
 }

 delete aSplashScreen;
}
*/
