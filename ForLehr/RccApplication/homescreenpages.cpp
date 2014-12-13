#include <QDomDocument>
#include <QtGui>

#include "HomeScreenPages.h"

NewsPage::NewsPage(QWidget *parent) :
    QWidget (parent),
    ui(new Ui::NewsPage)
{


    ui->setupUi(this);
    //this->setFixedSize(1024,768);

    //Mouse Tracking
    this->setMouseTracking(true);
    //ui->centralWidget->setMouseTracking(true);

    QPixmap pixmap(":Images/ArticleImage1.jpg");
    QPixmap pixmap2(":Images/ArticleImage3.jpg");


    QIcon ButtonIcon(pixmap);
    QIcon ButtonIcon2(pixmap2);
    ui->article1_Picture_2->setIcon(ButtonIcon);
    ui->article1_Picture_2->setIconSize(pixmap.rect().size());
    ui->article1_Picture_3->setIcon(ButtonIcon2);
    ui->article1_Picture_3->setIconSize(pixmap2.rect().size());

    /*
    QDomDocument xml;
    QFile xmlFile(":/newsArticles.xml");
    xml.setContent(&xmlFile);
    scene = new QGraphicsScene(this);
    //ui->graphicsView->setScene(scene);
    //QGraphicsRectItem *frame = scene->addRect(100,100,100,100);
    //frame->setPen(Qt::NoPen);
    //qDebug() << zeroDash.isNull();
    //qDebug() << zeroDash.firstChildElement().text();

    //of element "image" get the attribute "path"'s value
    QDomElement root = xml.firstChildElement();
    QDomNodeList articlePath = root.elementsByTagName("Articles").at(0).childNodes();//.at(0).firstChildElement().text();
    QDomNodeList imagePath = root.elementsByTagName("Images").at(0).childNodes();
    QDomNodeList artLinks = root.elementsByTagName("Links").at(0).childNodes();
    QPixmap *pix = new QPixmap[imagePath.size()];
    QFile *files = new QFile[articlePath.size()];
    QLabel *labels = new QLabel[articlePath.size()];
    QTextStream tempFile;
    //int width;
    //int height;
    //int a=100, b=0, c=-100;
    //QGraphicsPixmapItem *test;

    //qDebug() << root.text();
    //QString tempString;
    for(int i = 0; i<articlePath.size(); i++){
        pix[i].load(imagePath.at(i).toElement().text());
        files[i].setFileName(articlePath.at(i).toElement().text());

        labels[i].setPixmap(pix[i]);
        files[i].open(QIODevice::ReadOnly | QIODevice::Text);
        tempFile.setDevice(&files[i]);
        labels[i].setText(tempFile.readAll());
        //qDebug() << imagePath.at(i).toElement().text();
        //qDebug() << articlePath.at(i).toElement().text();
        //qDebug() << articlePath.size();
        //qDebug() << (tempFile.readAll());
        //width = pix[i].width();
        //height = pix[i].height();
        if(i==1)
            scene->setSceneRect((0-width/2),a,0,0);
        else if(i==2)
            frame->mapRectToParent((0-width/2),a,0,0);
        else if(i==3)
            scene->setSceneRect((0-width/2),c,0,0);

        test = scene->addPixmap(pix[i]);
        if(i==1)
            test->translate(0-width/2,a);
        else if(i==2)
            test->translate(0-width/2,b);
        else if(i==3)
            test->translate(0-width/2,c);
        files[i].close();

    }
    //contentsWidget = new QListWidget;
    ui->listWidget->setViewMode(QListView::IconMode);
    ui->listWidget->setIconSize(QSize(100, 100));
    ui->listWidget->setMovement(QListView::Static);
    //ui->listWidget->setMaximumWidth(145);
    ui->listWidget->setSpacing(12);

    QListWidgetItem *Art1 = new QListWidgetItem(ui->listWidget);
    Art1->setIcon(QIcon(imagePath.at(0).toElement().text()));
    Art1->setText(tr("Article 1"));
    Art1->setTextAlignment(Qt::AlignHCenter);
    Art1->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    Art1->setData( 5, QVariant( artLinks.at(0).toElement().text() ));

    QListWidgetItem *Art2 = new QListWidgetItem(ui->listWidget);
    Art2->setIcon(QIcon(imagePath.at(1).toElement().text()));
    Art2->setText(tr("Article 2"));
    Art2->setTextAlignment(Qt::AlignHCenter);
    Art2->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    Art2->setData( 5, QVariant( artLinks.at(1).toElement().text() ));

    QListWidgetItem *Art3 = new QListWidgetItem(ui->listWidget);
    Art3->setIcon(QIcon(imagePath.at(2).toElement().text()));
    Art3->setText(tr("Article 3"));
    Art3->setTextAlignment(Qt::AlignHCenter);
    Art3->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    Art3->setData( 5, QVariant( artLinks.at(2).toElement().text() ));

    connect( ui->listWidget, SIGNAL( itemClicked(QListWidgetItem*) ), this, SLOT( itemClicked( QListWidgetItem* ) ) );


    QGroupBox *configGroup = new QGroupBox(tr("Server configuration"));

    QLabel *serverLabel = new QLabel(tr("Server:"));
    QComboBox *serverCombo = new QComboBox;
    serverCombo->addItem(tr("Qt (Australia)"));
    serverCombo->addItem(tr("Qt (Germany)"));
    serverCombo->addItem(tr("Qt (Norway)"));
    serverCombo->addItem(tr("Qt (People's Republic of China)"));
    serverCombo->addItem(tr("Qt (USA)"));

    QHBoxLayout *serverLayout = new QHBoxLayout;
    serverLayout->addWidget(serverLabel);
    serverLayout->addWidget(serverCombo);

    QVBoxLayout *configLayout = new QVBoxLayout;
    configLayout->addLayout(serverLayout);
    configGroup->setLayout(configLayout);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(configGroup);
    mainLayout->addStretch(1);
    setLayout(mainLayout);
    */
    //scene = new QGraphicsScene(this);
    //ui->gaben->setScene(scene);

    //QPixmap qtsucks(":/Naamloos-1.png");
    //scene->addPixmap(qtsucks);




    /*
    QGraphicsWidget *textEdit = scene.addWidget(new QTextEdit);
    QGraphicsWidget *pushButton = scene.addWidget(new QPushButton);

    QGraphicsGridLayout *layout = new QGraphicsGridLayout;
    layout->addItem(textEdit, 0, 0);
    layout->addItem(pushButton, 0, 1);

    QGraphicsWidget *form = new QGraphicsWidget;
    form->setLayout(layout);
    scene.addItem(form);

    xmlFile.close();
*/
}

void NewsPage::on_article1_Picture_2_clicked(){

    QString link ="http://www.rcc.edu/about/campusnews/Pages/Taube-to-be-Featured-Speaker-at-Xipe-Projects-.aspx";
    QDesktopServices::openUrl(QUrl(link));

}
void NewsPage::on_article1_Picture_3_clicked(){

    QString link ="http://www.rcc.edu/about/campusnews/Pages/Journalism-Students-Win-Eight-Awards-at-Southern-California-Competition.aspx";
    QDesktopServices::openUrl(QUrl(link));
}
void NewsPage::itemClicked( QListWidgetItem* item ){
    QDesktopServices::openUrl( item->data( 5 ).toString() );
}


Forums::Forums(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Forums)
{
    ui->setupUi(this);

    this->setFixedSize(1024,768);

    contentsWidget = new QListWidget;
    contentsWidget->setViewMode(QListView::IconMode);
    contentsWidget->setIconSize(QSize(100, 100));
    contentsWidget->setMovement(QListView::Static);
    contentsWidget->setMaximumWidth(145);
    contentsWidget->setMinimumWidth(145);
    contentsWidget->setSpacing(12);

    a = new QStackedWidget;
    a->addWidget(new SubForum("A"));//A
    a->addWidget(new SubForum("B"));//B
    a->addWidget(new SubForum("C"));//C
    a->addWidget(new SubForum("D"));//D
    a->addWidget(new SubForum("E"));//E
    a->addWidget(new SubForum("F"));//F
    a->addWidget(new SubForum("G"));//G
    a->addWidget(new SubForum("H"));//H
    a->addWidget(new SubForum("I"));//I
    a->addWidget(new SubForum("J"));//J
    a->addWidget(new SubForum("K"));//K
    a->addWidget(new SubForum("L"));//L
    a->addWidget(new SubForum("M"));//M
    a->addWidget(new SubForum("N"));//N
    a->addWidget(new SubForum("O"));//O
    a->addWidget(new SubForum("P"));//P
    a->addWidget(new SubForum("Q"));//Q
    a->addWidget(new SubForum("R"));//R
    a->addWidget(new SubForum("S"));//S
    a->addWidget(new SubForum("T"));//T
    a->addWidget(new SubForum("U"));//U
    a->addWidget(new SubForum("V"));//V
    a->addWidget(new SubForum("W"));//W
    a->addWidget(new SubForum("X"));//X
    a->addWidget(new SubForum("Y"));//Y
    a->addWidget(new SubForum("Z"));//Z
    a->setFixedWidth(1024);
    a->setFixedHeight(768);



    createIcons();
    contentsWidget->setCurrentRow(0);

    QHBoxLayout *horizontalLayout = new QHBoxLayout;
    horizontalLayout->addWidget(contentsWidget);
    horizontalLayout->addWidget(a, 1);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(horizontalLayout);
    mainLayout->addStretch(1);
    mainLayout->addSpacing(12);
    setLayout(mainLayout);

}

void Forums::createIcons()
{

    QListWidgetItem *A = new QListWidgetItem(contentsWidget);
    A->setIcon(QIcon(":/Images/A.png"));
    A->setText(tr("A"));
    A->setTextAlignment(Qt::AlignHCenter);
    A->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *B = new QListWidgetItem(contentsWidget);
    B->setIcon(QIcon(":/Images/B.png"));
    B->setText(tr("B"));
    B->setTextAlignment(Qt::AlignHCenter);
    B->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *C = new QListWidgetItem(contentsWidget);
    C->setIcon(QIcon(":/Images/C.png"));
    C->setText(tr("C"));
    C->setTextAlignment(Qt::AlignHCenter);
    C->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *D = new QListWidgetItem(contentsWidget);
    D->setIcon(QIcon(":/Images/D.png"));
    D->setText(tr("D"));
    D->setTextAlignment(Qt::AlignHCenter);
    D->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *E = new QListWidgetItem(contentsWidget);
    E->setIcon(QIcon(":/Images/E.png"));
    E->setText(tr("E"));
    E->setTextAlignment(Qt::AlignHCenter);
    E->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *F = new QListWidgetItem(contentsWidget);
    F->setIcon(QIcon(":/Images/F.png"));
    F->setText(tr("F"));
    F->setTextAlignment(Qt::AlignHCenter);
    F->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *G = new QListWidgetItem(contentsWidget);
    G->setIcon(QIcon(":/Images/G.png"));
    G->setText(tr("G"));
    G->setTextAlignment(Qt::AlignHCenter);
    G->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *H = new QListWidgetItem(contentsWidget);
    H->setIcon(QIcon(":/Images/H.png"));
    H->setText(tr("H"));
    H->setTextAlignment(Qt::AlignHCenter);
    H->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *I = new QListWidgetItem(contentsWidget);
    I->setIcon(QIcon(":/Images/I.png"));
    I->setText(tr("I"));
    I->setTextAlignment(Qt::AlignHCenter);
    I->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *J = new QListWidgetItem(contentsWidget);
    J->setIcon(QIcon(":/Images/J.png"));
    J->setText(tr("J"));
    J->setTextAlignment(Qt::AlignHCenter);
    J->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *K = new QListWidgetItem(contentsWidget);
    K->setIcon(QIcon(":/Images/K.png"));
    K->setText(tr("K"));
    K->setTextAlignment(Qt::AlignHCenter);
    K->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *L = new QListWidgetItem(contentsWidget);
    L->setIcon(QIcon(":/Images/L.png"));
    L->setText(tr("L"));
    L->setTextAlignment(Qt::AlignHCenter);
    L->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *M = new QListWidgetItem(contentsWidget);
    M->setIcon(QIcon(":/Images/M.png"));
    M->setText(tr("M"));
    M->setTextAlignment(Qt::AlignHCenter);
    M->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *N = new QListWidgetItem(contentsWidget);
    N->setIcon(QIcon(":/Images/N.png"));
    N->setText(tr("N"));
    N->setTextAlignment(Qt::AlignHCenter);
    N->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *O = new QListWidgetItem(contentsWidget);
    O->setIcon(QIcon(":/Images/OA.png"));
    O->setText(tr("O"));
    O->setTextAlignment(Qt::AlignHCenter);
    O->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *P = new QListWidgetItem(contentsWidget);
    P->setIcon(QIcon(":/Images/P.png"));
    P->setText(tr("P"));
    P->setTextAlignment(Qt::AlignHCenter);
    P->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *Q = new QListWidgetItem(contentsWidget);
    Q->setIcon(QIcon(":/Images/Q.png"));
    Q->setText(tr("Q"));
    Q->setTextAlignment(Qt::AlignHCenter);
    Q->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *R = new QListWidgetItem(contentsWidget);
    R->setIcon(QIcon(":/Images/R.png"));
    R->setText(tr("R"));
    R->setTextAlignment(Qt::AlignHCenter);
    R->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *S = new QListWidgetItem(contentsWidget);
    S->setIcon(QIcon(":/Images/S.png"));
    S->setText(tr("S"));
    S->setTextAlignment(Qt::AlignHCenter);
    S->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *T = new QListWidgetItem(contentsWidget);
    T->setIcon(QIcon(":/Images/T.png"));
    T->setText(tr("T"));
    T->setTextAlignment(Qt::AlignHCenter);
    T->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *U = new QListWidgetItem(contentsWidget);
    U->setIcon(QIcon(":/Images/U.png"));
    U->setText(tr("U"));
    U->setTextAlignment(Qt::AlignHCenter);
    U->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *V = new QListWidgetItem(contentsWidget);
    V->setIcon(QIcon(":/Images/V.png"));
    V->setText(tr("V"));
    V->setTextAlignment(Qt::AlignHCenter);
    V->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *W = new QListWidgetItem(contentsWidget);
    W->setIcon(QIcon(":/Images/W.png"));
    W->setText(tr("W"));
    W->setTextAlignment(Qt::AlignHCenter);
    W->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *X = new QListWidgetItem(contentsWidget);
    X->setIcon(QIcon(":/Images/X.png"));
    X->setText(tr("X"));
    X->setTextAlignment(Qt::AlignHCenter);
    X->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *Y = new QListWidgetItem(contentsWidget);
    Y->setIcon(QIcon(":/Images/Y.png"));
    Y->setText(tr("Y"));
    Y->setTextAlignment(Qt::AlignHCenter);
    Y->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *Z = new QListWidgetItem(contentsWidget);
    Z->setIcon(QIcon(":/Images/Z.png"));
    Z->setText(tr("Z"));
    Z->setTextAlignment(Qt::AlignHCenter);
    Z->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    connect(contentsWidget,
            SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),
            this, SLOT(changePage(QListWidgetItem*,QListWidgetItem*)));

}

void Forums::changePage(QListWidgetItem *current, QListWidgetItem *previous)
{
    if (!current)
        current = previous;

    a->setCurrentIndex(contentsWidget->row(current));
}


Schedule::Schedule(QWidget *parent)
    : QWidget(parent),
      ui(new Ui::schedule)
{
    ui->setupUi(this);
    this->setFixedSize(1024,768);
    //Read in Class file
//    QFile classFile("class.txt");
//    classFile.open(QIODevice::ReadOnly);
//    QTextStream textStream(&classFile);
//    QString line;
//    while(!textStream.atEnd())
//    {
//        line=textStream.readLine();
//        ui->classList->addItem(line);
//    }
//    classFile.close();
    //Add Classes Manually
    ui->classList->addItem("MAT-1A");
    ui->classList->addItem("MAT-1B");
    ui->classList->addItem("MAT-1C");
    ui->classList->addItem("ENG-1A");
    ui->classList->addItem("ENG-1B");
    ui->classList->addItem("PHY-4A");
    ui->classList->addItem("PHY-4B");
    ui->classList->addItem("PHY-4C");
    ui->classList->addItem("PHY-4D");
    ui->classList->addItem("CSC-5");
    ui->classList->addItem("CSC-17A");
    ui->classList->addItem("CSC-17B");
    ui->classList->addItem("CSC-17C");
    ui->classList->addItem("BIO-1");
    ui->classList->addItem("ECO-4");

    //Label for student
    ui->studentLabel->setText(Globals::getSessionEmail());
    //Read if Student File is there
    QString name1 = Globals::getSessionEmail();
    QString name2 = ".txt";
    QFile myFile(name1+name2);
    myFile.open(QIODevice::ReadOnly);
    QTextStream stream(&myFile);
    QString line;
    while(!stream.atEnd())
    {
        line=stream.readLine();
        ui->studentList->addItem(line);
    }
    myFile.close();

    /*
    ui->setupUi(this);
    QGroupBox *packagesGroup = new QGroupBox(tr("Look for packages"));

    QLabel *nameLabel = new QLabel(tr("Name:"));
    QLineEdit *nameEdit = new QLineEdit;

    QLabel *dateLabel = new QLabel(tr("Released after:"));
    QDateTimeEdit *dateEdit = new QDateTimeEdit(QDate::currentDate());

    QCheckBox *releasesCheckBox = new QCheckBox(tr("Releases"));
    QCheckBox *upgradesCheckBox = new QCheckBox(tr("Upgrades"));

    QSpinBox *hitsSpinBox = new QSpinBox;
    hitsSpinBox->setPrefix(tr("Return up to "));
    hitsSpinBox->setSuffix(tr(" results"));
    hitsSpinBox->setSpecialValueText(tr("Return only the first result"));
    hitsSpinBox->setMinimum(1);
    hitsSpinBox->setMaximum(100);
    hitsSpinBox->setSingleStep(10);

    QPushButton *startQueryButton = new QPushButton(tr("Start query"));

    QGridLayout *packagesLayout = new QGridLayout;
    packagesLayout->addWidget(nameLabel, 0, 0);
    packagesLayout->addWidget(nameEdit, 0, 1);
    packagesLayout->addWidget(dateLabel, 1, 0);
    packagesLayout->addWidget(dateEdit, 1, 1);
    packagesLayout->addWidget(releasesCheckBox, 2, 0);
    packagesLayout->addWidget(upgradesCheckBox, 3, 0);
    packagesLayout->addWidget(hitsSpinBox, 4, 0, 1, 2);
    packagesGroup->setLayout(packagesLayout);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(packagesGroup);
    mainLayout->addSpacing(12);
    mainLayout->addWidget(startQueryButton);
    mainLayout->addStretch(1);
    setLayout(mainLayout);
    */
}

//Add Class
void Schedule::on_leftButton_clicked()
{
    moveCurrentItem(ui->classList,ui->studentList);
}

//Remove Class
void Schedule::on_rightButton_clicked()
{
    // moveCurrentItem(ui->studentList,ui->classList);
    delete ui->studentList->currentItem();
}

void Schedule::on_saveButton_clicked()
{
    QString line;
    //Write to file
    QString name1 = Globals::getSessionEmail();
    QString name2 = ".txt";
    QFile myFile(name1+name2);
    myFile.open(QFile::WriteOnly|QFile::Text);
    QTextStream out(&myFile);
    //Count the numbers of classes listed
    int index = ui->studentList->count();
    //Write into file
    for(int i=0;i<index;i++)
    {
        line = ui->studentList->item(i)->text();
        out<<line<<endl;
    }
    myFile.close();
}

void Schedule::moveCurrentItem(QListWidget *source, QListWidget *target)
{
    if (source->currentItem())
    {
        QListWidgetItem *newItem = source->currentItem()->clone();
        target->addItem(newItem);
        target->setCurrentItem(newItem);
        delete source->currentItem();
    }
}
/*
Clubs::Clubs(QWidget *parent)
    : QWidget(parent),
      ui(new Ui::Clubs)
{
    ui->setupUi(this);
    this->setFixedSize(1024,768);
}
*/
/*
SchoolInfo::SchoolInfo(QWidget *parent)
    : QWidget(parent),
      ui(new Ui::schoolInfo)
{
    ui->setupUi(this);
    this->setFixedSize(1024,768);
}
*/
/*
Map::Map(QWidget *parent)
    : QWidget(parent),
      ui(new Ui::Map)
{
    ui->setupUi(this);
    this->setFixedSize(1024,768);


}


Appointments::Appointments(QWidget *parent)
    : QWidget(parent),
      ui(new Ui::appointments)
{
    ui->setupUi(this);
    this->setFixedSize(1024,768);
}


BusSchedule::BusSchedule(QWidget *parent)
    : QWidget(parent),
      ui(new Ui::BusSchedule)
{
    ui->setupUi(this);
    this->setFixedSize(1024,768);
}


About::About(QWidget *parent)
    : QWidget(parent),
      ui(new Ui::About)
{
    ui->setupUi(this);
    this->setFixedSize(1024,768);
}
*/

