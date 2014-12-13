#include "battlearea.h"
#include "ui_battlearea.h"

#include <QtGui>


BattleArea::BattleArea(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BattleArea)
{
    ui->setupUi(this);
    //QGraphicsView::viewportUpdateMode(QGraphicsView::FullViewportUpdate);
    /*
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    scene->setSceneRect(-500,-500,500,500);
    QPen myPen = QPen(Qt::red);
    QLineF TopLine(scene->sceneRect().topLeft(), scene->sceneRect().topRight());
    QLineF LeftLine(scene->sceneRect().topLeft(), scene->sceneRect().bottomLeft());
    QLineF RightLine(scene->sceneRect().topRight(), scene->sceneRect().bottomRight());
    QLineF BottomLine(scene->sceneRect().bottomLeft(), scene->sceneRect().bottomRight());

    scene->addLine(TopLine,myPen);
    scene->addLine(LeftLine,myPen);
    scene->addLine(RightLine,myPen);
    scene->addLine(BottomLine,myPen);

    int ItemCount = 30;

    for(int i=0; i<ItemCount; i++){
        MyItem *item = new MyItem();
        scene->addItem(item);
    }


    timer2 = new QTimer(this);
    connect(timer2, SIGNAL(timeout()), scene, SLOT(advance()));
    timer2->start(200);

    iSprites = new QPixmap[100];
    offsetPoints = new QPoint[100];
    offsetPointsDash = new QPoint[100];
    offsetPointsRun = new QPoint[100];
    offsetPointsMSmash = new QPoint[100];
    offsetPointsSSmash = new QPoint[100];
    offsetPointsWSmash = new QPoint[100];
    Run = new QPixmap[100];
    SSmash = new QPixmap[100];
    MSmash = new QPixmap[100];
    WSmash = new QPixmap[100];
    Dash = new QPixmap[100];
    */



    x=500;
    y=250;
    i=0;
    tracker=0;
    this->setFixedSize(1000,500);
    timer = new QTimer;
    timer->setInterval(50);

    getFilePaths();

    connect( timer, SIGNAL( timeout() ), this, SLOT( nextFrame() ) );
    player1 = Right;
    currentDirectionP1 =  player1;
    control = run;

    QPixmap bkgnd(":/Skullgirls---LittleInnsmouth.jpg");
    bkgnd = bkgnd.scaled( 1000, 500, Qt::KeepAspectRatioByExpanding);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

}

BattleArea::~BattleArea()
{
    delete ui;

}
void BattleArea::paintEvent(QPaintEvent *event)
{
    //qDebug() << "paintEvent";
    //qDebug() << i;
    //QPainter paint();
    paint.begin(this);
    paint.setRenderHint(QPainter::Antialiasing);
    paint.translate(x,y);
    paint.scale(1.2,1.2);
    QPixmap tempPix;
    QPoint tempPoint;

    if(control == run){

        tempPix = Run[i];
        tempPoint = offsetPointsRun[i];

    }else if(control == dash){

        tempPix = Dash[i];
        tempPoint = offsetPointsDash[i];

    }else if(control == W_Smash){

        tempPix = WSmash[i];
        tempPoint = offsetPointsWSmash[i];

    }else if(control == S_Smash){

        tempPix = SSmash[i];
        tempPoint = offsetPointsSSmash[i];

    }

    //qDebug() << "X: " << tempPoint.x();
    //qDebug() << "Y: " << tempPoint.y();
    if(currentDirectionP1 != player1){
        flipped = tempPix.toImage().mirrored(true,false);
        paint.drawPixmap(tempPoint,QPixmap::fromImage(flipped));
    }else{
        paint.drawPixmap(tempPoint, tempPix);
    }
    /*
    QGraphicsPixmapItem *pix = scene->addPixmap(tempPix);
    pix->setPos(tempPoint);
    scene->advance();
    */

    paint.end();
}

void BattleArea::keyPressEvent(QKeyEvent *event)
{
    ////qDebug() << "I'm getting called still" << i <<endl;
    if(!event->isAutoRepeat()){
        //qDebug() << "Not";
        switch( event->key() ){
            case Qt::Key_Right:{
                control = run;
                timer->start();
                x+=7;
                player1=Right;
                break;
            }
            case Qt::Key_Left:{
                control = run;
                timer->start();
                x-=7;
                player1=Left;
                break;
            }
            case Qt::Key_Z:{
                control = dash;
                //qDebug() << "keypress" <<control;
                i=0;
                timer->start();
                if(player1 == Right)
                    x+=30;
                else
                    x-=30;
                break;
            }
            case Qt::Key_X:{
                i=0;
                control = W_Smash;
                timer->start();
                break;
            }
            case Qt::Key_C:{
                i=0;
                control = S_Smash;
                timer->start();
                break;
            }
        }
    }
    if(event->isAutoRepeat()){
        //qDebug() << "Auto";
        switch( event->key() ){
            case Qt::Key_Right:{
                control = run;
                //timer->start();
                x+=7;
                break;
            }
            case Qt::Key_Left:{
                control = run;
                //timer->start();
                x-=7;
                break;
            }
            case Qt::Key_Z:{
                control = dash;
                //timer->start();
                if(player1 == Right)
                    x+=30;
                else
                    x-=30;
                break;
            }

        }
    }
}

void BattleArea::keyReleaseEvent(QKeyEvent *event){
    //qDebug() << "Release" <<endl;
    if(!event->isAutoRepeat()){
        switch( event->key() ){
            case Qt::Key_Right:{
                timer->stop();
                i=0;
                repaint();
                break;
            }
            case Qt::Key_Left:{
                timer->stop();
                i=0;
                repaint();
                break;
            }
            case Qt::Key_Up:{
                timer->stop();
                i=0;
                repaint();
                break;
            }
            case Qt::Key_Down:{
                timer->stop();
                i=0;
                repaint();
                break;
            }
            case Qt::Key_Z:{
                control = run;
                timer->stop();
                i=0;
                repaint();
                break;
            }
            case Qt::Key_X:{
                control = run;
                timer->stop();
                i=0;
                repaint();
                break;
            }
            case Qt::Key_C:{
                control = run;
                timer->stop();
                i=0;
                repaint();
                break;
            }

        }
    }
}

void BattleArea::getFilePaths()
{
    QDomDocument domVar;
    QFile fileVar(":/Zero/files.xml");
    domVar.setContent(&fileVar);
    QDomElement root = domVar.firstChildElement();
    QDomNodeList imagePaths = root.elementsByTagName("path");//.at(0).firstChildElement().text();
    ////qDebug() << imagePaths.at(0).isNull();
    ////qDebug() << imagePaths.at(2).firstChildElement().toElement().text();

    //qDebug() << imagePaths.size();
    for( int z = 0; z<imagePaths.size(); z++){//imagePaths.size(); z++){
        load(imagePaths.at(z).toElement().text());
    }
}

void BattleArea::load(QString File)
{
    ////qDebug() << File;

    QDomDocument domVar;
    QFile domVarFile(File);

    domVarFile.open(QIODevice::ReadOnly |  QIODevice::Text);
    domVar.setContent(&domVarFile);

    //of element "image" get the attribute "path"'s value
    QDomElement root = domVar.firstChildElement();
    QString imagePath = root.elementsByTagName("image").at(0).firstChildElement().text();
    ////qDebug() << root.text();
    ////qDebug() <<"Null?" << domVar.isNull();
    ////qDebug() <<"In there?" << domVar.firstChildElement().toElement().text();



    //initializing pixmap with the sprite sheet
    QPixmap spriteSheet(imagePath);

    //get the number of modules or "frames" used  MAY NOT NEED 'CAUSE SIZE FUNCTIONS OP
    //DON'T NEED AFTER ALL OH WELL WASTED TIME
    //int nModules = domVar.elementById("modules").attributeNode("nModules").value().toInt();

    //nodelist
    QDomNodeList nRow = root.elementsByTagName("modules").at(0).childNodes();//.at(0).childNodes();
    ////qDebug() << nRow.length();
    //# of childe nodes
    int nodes = nRow.length();

    //2d aray always nRow rows and 6 columns for each row for the dimensions of a given individual sprite
    int dimensions[nRow.length()][6];
    ////qDebug() << "nodes: " <<nodes<<endl;

    //temporary vars
    QString tempString;
    QStringList tempList;

    for(int i=0; i<nodes; i++){
        //filling temp vars with the string of values then using a list to traverse it
        tempString = nRow.at(i).toElement().text();
        tempList=tempString.split(" ", QString::SkipEmptyParts);
        //converting it to an int for use of dimensions
        for(int l=0; l<6; l++){
            dimensions[i][l] = tempList.at(l).toInt();
            ////qDebug() << "Dimensions" << l+1 << dimensions[i][l] << " ";
            ////qDebug() << nRow.at(nRow.length()-1).childNodes().at();
        }
    }


    QRect *frames =  new QRect[nRow.length()];
    //setting up a QRects for the crop
    //I Learned I can just start from the the third number
    int start=2;
    for(int i=0; i<nRow.length(); i++){
        frames[i].setRect(dimensions[i][start],dimensions[i][start+1],dimensions[i][start+2],dimensions[i][start+3]);
    }
    //make a pixmap pointer that is size nrow.length

    //make a copy of the sprite sheet that is the size of the qrect frames
    tempSize=nRow.length();
    //qDebug() << nRow.length();
    for(unsigned int i=0; i<nRow.length(); i++){
        iSprites[i]=spriteSheet.copy(frames[i]);
    }


    //get the offsets
    QDomNodeList offset = domVar.elementsByTagName("itemAnim").at(0).childNodes();
    ////qDebug() << offset.isEmpty();


    int offsets[offset.size()][4];

    QString tempString2;
    QStringList tempList2;
    ////qDebug() << "TEST" << File;
    ////qDebug() << nRow.length();
    for(unsigned int i=0; i<offset.length(); i++){
        //filling temp vars with the string of values then using a list to traverse it
        tempString2=offset.at(i).toElement().text();
        ////qDebug() << tempString2;
        tempList2=tempString2.split(" ", QString::SkipEmptyParts);
        ////qDebug() << tempList2;
        ////qDebug() << i;
        //converting it to an int for use of dimensions
        for(int l=0; l<4; l++){
            offsets[i][l]= tempList2.at(l).toInt();
            ////qDebug() << "Offsets" << l+1 << offsets[i][l] << " ";
        }
    }
    ////qDebug() << "LAST?" << File;



    for(unsigned int i=0; i<offset.length(); i++){
        offsetPoints[i].setX(offsets[i][1]);
        offsetPoints[i].setY(offsets[i][2]);
        ////qDebug() << offsetPoints[i];
        ////qDebug() << offsetPoints[i];

    }

    if(File.contains("dash")){
        ////qDebug() << File;
        for(int z = 0; z<tempSize; z++){
            Dash[z] = iSprites[z];
            offsetPointsDash[z] = offsetPoints[z];
            size[1] = tempSize;
            ////qDebug() << offsetPointsDash[z].isNull();
            ////qDebug() << Dash[z].isNull();
            ////qDebug() <<"Dash " << size[1];
        }
    }
    else if(File.contains("run")){
        ////qDebug() << File;
        for(int z = 0; z<tempSize; z++){
            Run[z] = iSprites[z];
            offsetPointsRun[z] = offsetPoints[z];
            size[0] = tempSize;
            ////qDebug()<<"Run" << size[0];
        }
    }
    else if(File.contains("sSlice")){
       //qDebug() << File;
       //qDebug() << "SSmash size: "<< tempSize;
        for(int z = 0; z<tempSize; z++){
            SSmash[z] = iSprites[z];
            offsetPointsSSmash[z] = offsetPoints[z];
            size[2] = tempSize;
            ////qDebug()<< "SSmash " << size[3];
            ////qDebug() << offsetPoints[z];
            ////qDebug() << "HERE";
        }
    }else if(File.contains("slice")){
        ////qDebug() << File;
        ////qDebug() << "WSmash size: "<< tempSize;
        for(int z = 0; z<tempSize; z++){
            WSmash[z] = iSprites[z];
            offsetPointsWSmash[z] = offsetPoints[z];
            size[3] = tempSize;
            ////qDebug() << offsetPoints[z];
            ////qDebug() << "HERE";
            ////qDebug()<< "WSmash " << size[4];

        }
    }


    domVarFile.close();
}

void BattleArea::nextFrame(){
    ////qDebug() <<"NextFrame: "<< control;
    ////qDebug() << "NextFrame";
    int localSize;
    if(control == run){
        localSize=size[0];
    }else if(control == dash){
        localSize=size[1];
    }else if(control == W_Smash){
        localSize = size[3];
    }else if(control == S_Smash){
        localSize = size[2];
    }/*
    //qDebug() <<"localsize "<< localSize;
    //qDebug() <<"i "<< i;
    //qDebug() <<"SSmash: "<<size[3];
    //qDebug() <<"Control: "<< control;
    */
    if( i < localSize ) {
        i++;
        repaint();
    }
    if( i>=localSize && control == run ) {
        i=3;
        repaint();
    }else if( i>=localSize && control == dash ) {
        ////qDebug() << "i>=localSize && control == dash";
        i=1;
        repaint();
    }else if( i >= localSize && ( control != run && control != dash ) ) {
        ////qDebug() << "i >= localSize && ( control != run && control != dash";
        i=0;
        repaint();
    }
}
