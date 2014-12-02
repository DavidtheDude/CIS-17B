#include "battlearea.h"
#include "ui_battlearea.h"



BattleArea::BattleArea(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BattleArea)
{
    ui->setupUi(this);
    this->resize(800,600);
    timer->setInterval(50);
    connect( timer, SIGNAL( timeout() ), this, SLOT( nextFrame() ) );
}

BattleArea::~BattleArea()
{
    delete ui;

}

void BattleArea::Load()
{

    QDomDocument zeroDash;
    QFile zeroDashFile(":/Zero/run.xml");
    //zeroDashFile.open(QIODevice::ReadOnly |  QIODevice::Text);
    /*
    if(!zeroDashFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file";
    }else{
        if(!zeroDash.setContent(&zeroDashFile)){
            qDebug() << "Failed to load document";
        }
    }
    */
    zeroDash.setContent(&zeroDashFile);
    //qDebug() << zeroDash.isNull();
    //qDebug() << zeroDash.firstChildElement().text();

    //of element "image" get the attribute "path"'s value
    QDomElement root = zeroDash.firstChildElement();
    QString imagePath = root.elementsByTagName("image").at(0).firstChildElement().text();



    //initializing pixmap with the sprite sheet
    QPixmap spriteSheet(imagePath);
    //qDebug() << imagePath;
    //qDebug() << root.text();
    //if(root==imagePath)
      //  qDebug() << "true";
    //get the number of modules or "frames" used  MAY NOT NEED 'CAUSE SIZE FUNCTIONS OP
    //DON'T NEED AFTER ALL OH WELL WASTED TIME
    //int nModules = zeroDash.elementById("modules").attributeNode("nModules").value().toInt();

    //nodelist
    QDomNodeList nRow = root.elementsByTagName("modules").at(0).childNodes();//.at(0).childNodes();
    //# of childe nodes
    int nodes = nRow.length();

    //2d aray always nRow rows and 6 columns for each row for the dimensions of a given individual sprite
    int dimensions[nRow.length()][6];
    //qDebug() << "nodes: " <<nodes<<endl;

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
            //qDebug() << "Dimensions" << l+1 << dimensions[i][l] << " ";
            //qDebug() << nRow.at(nRow.length()-1).childNodes().at();
        }
    }


    QRect *frames =  new QRect[nRow.length()];
    //setting up a QRects for the crop
    //I Learned I can just start from the the third number
    int start=2;
    for(int i=0; i<nRow.length(); i++){
        frames[i].setRect(dimensions[i][start],dimensions[i][start+1],dimensions[i][start+2],dimensions[i][start+3]);
    }
    //qDebug() << frames[1];
    //make a pixmap pointer that is size nrow.length

    //make a copy of the sprite sheet that is the size of the qrect frames
    size=nRow.length();
    for(int i=0; i<nRow.length(); i++){
        iSprites[i]=spriteSheet.copy(frames[i]);
    }

    //get the offsets
    QDomNodeList offset = zeroDash.elementsByTagName("itemAnim").at(0).childNodes();
    //qDebug() << offset.isEmpty();

    int offsets[offset.size()][4];

    QString tempString2;
    QStringList tempList2;

    for(int i=0; i<nRow.length(); i++){
        //filling temp vars with the string of values then using a list to traverse it
        tempString2=offset.at(i).toElement().text();
        tempList2=tempString2.split(" ", QString::SkipEmptyParts);
        //converting it to an int for use of dimensions
        for(int l=0; l<4; l++){
            offsets[i][l]= tempList2.at(l).toInt();
            //qDebug() << "Offsets" << l+1 << offsets[i][l] << " ";
        }
    }


    for(int i=0; i<offset.length(); i++){
        offsetPoints[i].setX(offsets[i][1]);
        offsetPoints[i].setY(offsets[i][2]);
    }
    //QPainter paint(this);
    //paint = paint.drawPixmap(iSprites->rect(),iSprites[0]);
    //QPaintEvent *event;
    //paintEvent(event,iSprites);
    //QPainter paint(this);
    //paint.drawPixmap(iSprites->rect(),iSprites[0]);

    zeroDashFile.close();
    //instantiateTimer();
    //delete [] frames;
    //delete [] offsetPoints;

    this->close();
}

void BattleArea::instantiateTimer()
{

}

void BattleArea::runAnimation()
{
    timer->start();
}

void BattleArea::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);
    paint.setRenderHint(QPainter::Antialiasing);
    paint.translate(x,y);
    paint.scale(1.2,1.2);
    paint.drawPixmap(offsetPoints[i],iSprites[i],iSprites[i].rect());
    //paint.drawPixmap(offsetPoints[i+1],iSprites[i+1]),iSprites[i+1].rect();
    //paint.drawPixmap(offsetPoints[i+2],iSprites[i+2],iSprites[i+2].rect());
    //i++;

}

void BattleArea::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "I'm getting called still" << i <<endl;
    if(!event->isAutoRepeat()){
        switch( event->key() ){
            case Qt::Key_Right:{
                //instantiateTimer();
                timer->start();
                break;
            }
            case Qt::Key_Left:{
                ///instantiateTimer();
                timer->start();
                break;
            }
            case Qt::Key_Up:{
                //instantiateTimer();
                timer->start();
                break;
            }
            case Qt::Key_Down:{
                //instantiateTimer();
                timer->start();
                break;
            }

        }
    }
}
void BattleArea::keyReleaseEvent(QKeyEvent *event){

    qDebug() << "Release" <<endl;
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

        }
    }
}

void BattleArea::nextFrame()
{
    qDebug() << size;
    qDebug() << i;
    if(i<size){
        i++;
        repaint();
    }
    if(i>=size){
        timer->stop();
        i=0;
        repaint();
    }
}
void BattleArea::startAnimation()
{
    m_anim->setStartValue(QPointF(0, 0));
    m_anim->setEndValue(QPointF(100, 100));
    m_anim->setDuration(2000);
    m_anim->setLoopCount(-1); // forever
    m_anim->start();
}


