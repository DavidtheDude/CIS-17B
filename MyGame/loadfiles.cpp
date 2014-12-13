#include "loadfiles.h"

LoadFiles::LoadFiles()
{
    iSprites = new QPixmap[100];
    offsetPoints = new QPoint[100];
}

LoadFiles::~LoadFiles()
{
    delete [] iSprites;
    delete [] offsetPoints;
}

void LoadFiles::load(QString File)
{
    //qDebug() << File;

    QDomDocument domVar;
    QFile domVarFile(File);

    domVarFile.open(QIODevice::ReadOnly |  QIODevice::Text);
    domVar.setContent(&domVarFile);

    //of element "image" get the attribute "path"'s value
    QDomElement root = domVar.firstChildElement();
    QString imagePath = root.elementsByTagName("image").at(0).firstChildElement().text();



    //initializing pixmap with the sprite sheet
    QPixmap spriteSheet(imagePath);

    //get the number of modules or "frames" used  MAY NOT NEED 'CAUSE SIZE FUNCTIONS OP
    //DON'T NEED AFTER ALL OH WELL WASTED TIME
    //int nModules = domVar.elementById("modules").attributeNode("nModules").value().toInt();

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
    //make a pixmap pointer that is size nrow.length

    //make a copy of the sprite sheet that is the size of the qrect frames
    size=nRow.length();
    for(unsigned int i=0; i<nRow.length(); i++){
        iSprites[i]=spriteSheet.copy(frames[i]);
    }

    //get the offsets
    QDomNodeList offset = domVar.elementsByTagName("itemAnim").at(0).childNodes();
    //qDebug() << offset.isEmpty();

    int offsets[offset.size()][4];

    QString tempString2;
    QStringList tempList2;

    for(unsigned int i=0; i<nRow.length(); i++){
        //filling temp vars with the string of values then using a list to traverse it
        tempString2=offset.at(i).toElement().text();
        tempList2=tempString2.split(" ", QString::SkipEmptyParts);
        //converting it to an int for use of dimensions
        for(int l=0; l<4; l++){
            offsets[i][l]= tempList2.at(l).toInt();
            //qDebug() << "Offsets" << l+1 << offsets[i][l] << " ";
        }
    }


    for(unsigned int i=0; i<offset.length(); i++){
        offsetPoints[i].setX(offsets[i][1]);
        offsetPoints[i].setY(offsets[i][2]);
    }

    if(File.contains("dash")){
        //qDebug() << File;
        zeroSprites.writeDash(iSprites);
        zeroSprites.writePointsDash(offsetPoints);
    }
    else if(File.contains("run")){
        //qDebug() << File;
        zeroSprites.writeRun(iSprites);
        zeroSprites.writePointsRun(offsetPoints);
    }
    else if(File.contains("sSclice")){
        //qDebug() << File;
        zeroSprites.writeSSmash(iSprites);
        zeroSprites.writePointsSSmash(offsetPoints);
    }
    else if(File.contains("mSlice")){
        //qDebug() << File;
        zeroSprites.writeMSmash(iSprites);
        zeroSprites.writePointsMSmash(offsetPoints);
    }
    else if(File.contains("slice")){
        //qDebug() << File;
        zeroSprites.writeWSmash(iSprites);
        zeroSprites.writePointsWSmash(offsetPoints);
    }

    domVarFile.close();
    //this->close();
}

void LoadFiles::getFilePaths()
{
    QDomDocument domVar;
    QFile fileVar(":/Zero/files.xml");
    domVar.setContent(&fileVar);
    QDomElement root = domVar.firstChildElement();
    QDomNodeList imagePaths = root.elementsByTagName("path");//.at(0).firstChildElement().text();
    //qDebug() << imagePaths.at(0).isNull();
    //qDebug() << imagePaths.at(1).firstChildElement().toElement().text();

    for( int z = 0; z<imagePaths.size(); z++){
        load(imagePaths.at(z).toElement().text());
    }

}

