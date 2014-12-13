#include "loginpage.h"
#include "ui_loginpage.h"
#include <QLabel>
#include <QTimer>
#include <QTime>
#include <QPropertyAnimation>
#include <QDesktopWidget>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QPushButton>
#include <QCryptographicHash>
#include "sha1.h"
#include "io.h"
#include "createaccount.h"
#include "globals.h"

LoginPage::LoginPage(QWidget *parent) :
    QMainWindow(parent, Qt::FramelessWindowHint | Qt::WindowSystemMenuHint),
    ui(new Ui::LoginPage)
{
    ui->setupUi(this);
    QPalette palette;
    palette.setColor(QPalette::Background, Qt::white);
    this->setAutoFillBackground(true);
    this->setPalette(palette);

    checke = 0;
    checkp = 0;
    QColor color(255,102,0,255);
    QBrush background(color);
    scene = new QGraphicsScene(ui->graphicsView);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setBackgroundBrush(background);
    QPushButton close;
    close.setText("X");
    close.setFlat(true);
    //scene->addWidget(close);

}

LoginPage::~LoginPage()
{
    delete ui;
}

void LoginPage::on_Login_clicked() {
    /*******************
    *** Verification ***
    ***    Andrew    ***
    *******************/
    checke = 0;
    checkp = 0;
    if( ( ui->Email->text() != NULL ) && ( ui->Password->text() != NULL ) ) {
        email = ui->Email->text();
        password = ui->Password->text();
        if( !email.contains( QRegExp( "[\\w|.|-]*@\\w*\\.[\\w|.]*" ) ) && false ){
            checkp = 1;
            checke = 0;
            QMessageBox::information(this, tr("Invalid Email"), "Enter a valid email" );
        }
        else{
            checkp = 1;
            checke = 1;
        }
    }
    else if( ui->Password->text() == NULL ) {
        QString msg;
        if( ui->Email->text() == NULL ) {
            msg = "Please write an E-mail and password.";
            checke = 0;
            checkp = 0;
        }
        else{
            msg = "Please enter a password.";
            checkp = 0;
        }
        QMessageBox::information(this, tr("Missing Fields"), msg );
    }
    //If both email and password is filled in do this
    if( checke == 1 && checkp == 1 ) {
        //Hash email and password
        QByteArray emailHash = QCryptographicHash::hash( email.toUtf8(), QCryptographicHash::Sha1 );
        QString ehexstring = emailHash.toHex();
        QByteArray passHash = QCryptographicHash::hash( password.toUtf8(), QCryptographicHash::Sha1 );
        QString phexstring = passHash.toHex();
        //Save email hash to text
        //changing the way the user/pass is writing --michael

        IO io;

        if( io.checkUser( ehexstring, phexstring ) ){
            //the user is signed in
            //set the global session email
            Globals::setGlobals( email, ehexstring );

            this->close();
            splashInit();
        } else {
            QMessageBox::StandardButton reply;
            QString msg = "Email or Password is wrong try agian?";
            reply = QMessageBox::question(this, tr("Failed"), msg, QMessageBox::Yes | QMessageBox::No );
            if (reply == QMessageBox::No) {
                close();
            }
        }
    }
}

/**
 * Shows the splash screen for 5 secs after login
 * @brief LoginPage::splashInit
 */
void LoginPage::splashInit() {

        /*************************
         * Show the Splash Image *
         *         David S.      *
         * **********************/
        QPixmap image( ":/Images/SplashScreen.png" );
        QLabel* aWidget = new QLabel( 0, Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint );
        aWidget->setAttribute( Qt::WA_TranslucentBackground );
        aWidget->setPixmap( image );

        int width = image.width();
        int height = image.height();

        QDesktopWidget wid;
        QRect mainScreenSize = wid.availableGeometry( wid.primaryScreen() );

        aWidget->move( ( mainScreenSize.width() / 2 ) - ( width / 2 ), ( mainScreenSize.height() / 2  - ( height / 2 ) ) );
        aWidget->show();

        HomeScreen *dialog = new HomeScreen;

        /********************************************************************
         * after a set amount of time close splash image and open main menu *
         * *****************************************************************/
        QTimer::singleShot( 1000, aWidget,SLOT( close() ) );
        QTimer::singleShot( 1000, dialog,SLOT( show() ) );
}


void LoginPage::on_CreateAcc_clicked() {
    CreateAccount *create = new CreateAccount;
    create->exec();
}

//Commented out extra work that I had to figure out but didn't quite work
/*
int width = aWidget->frameGeometry().width();
int height = aWidget->frameGeometry().height();

QDesktopWidget wid;

int screenWidth = wid.screen()->width();
int screenHeight = wid.screen()->height();

aWidget->setGeometry((screenWidth/3)-(width/3),(screenHeight/3)-(height/3),width,height);
*/

/*
if(screenWidth%1920==0){
    int x=screenWidth/1920;
    screenWidth/=x;
}
else if(screenWidth%1920==0){
    int x=screenWidth/1920;
    screenWidth/=x;
}
*/
//aWidget->move((screenWidth/2)-(width/2), (screenHeight/2)-(height/2));
//aWidget->move(846,390);
//aWidget->move(846*2,390);


/*
aWidget->setGeometry(
    QStyle::alignedRect(
        Qt::LeftToRight,
        Qt::AlignCenter,
        aWidget->size(),
        qApp->desktop()->availableGeometry()
    ));
*/

/*
QPropertyAnimation *animation = new QPropertyAnimation(aWidget, "geometry");
animation->setDuration(3000);
animation->setStartValue(QRect(846, 390, image.width(), image.height()));
animation->setEndValue(QRect(846, 390, image.width(), image.height()));

animation->start();
*/



void LoginPage::on_X_clicked()
{
    this->close();
}

void LoginPage::on___clicked()
{
    this->setWindowState(Qt::WindowMinimized);
}
