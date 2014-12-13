/****************************************************************************
**
** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef HomeScreenPages_H
#define HomeScreenPages_H

#include <QWidget>
#include <QImage>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QGroupBox>
#include <QTextEdit>
#include <QComboBox>
#include <QGridLayout>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QDomDocument>
#include <QDomElement>
#include <QListWidget>
#include <QtGui>
#include <QDialog>


#include "ui_NewsPage.h"
#include "ui_about.h"
#include "ui_Appointments.h"
#include "ui_busSchedule.h"
#include "ui_clubs.h"
#include "ui_Forums.h"
#include "ui_schedule.h"
#include "ui_schoolInfo.h"
#include "ui_Map.h"
#include "globals.h"
#include "subforum.h"



class NewsPage : public QWidget
{

    Q_OBJECT
public:
    NewsPage(QWidget *parent = 0);
private slots:
    void on_article1_Picture_2_clicked();



    void on_article1_Picture_3_clicked();

private:
    Ui::NewsPage *ui;
    QGraphicsScene *scene;
    //QListWidget *contentsWidget;
    QDomNodeList artLinks;
private slots:
    void itemClicked( QListWidgetItem* );
};


class Forums : public QWidget
{

    Q_OBJECT
public:
    Forums(QWidget *parent = 0);
    void createIcons();

public slots:
    void changePage(QListWidgetItem *current, QListWidgetItem *previous);

private:
    Ui::Forums *ui;
    QListWidget *contentsWidget;
    QStackedWidget *a;

};


class  Schedule : public QWidget
{

    Q_OBJECT
public:
    Schedule(QWidget *parent = 0);
private slots:
    void on_leftButton_clicked();
    void on_rightButton_clicked();
    void on_saveButton_clicked();

private:
    Ui::schedule *ui;
    void moveCurrentItem(QListWidget *source,QListWidget *target);

};

class Clubs : public QWidget
{
    Q_OBJECT
public:
    Clubs(QWidget *parent = 0);
private:
    Ui::Clubs *ui;

};

/*
class  SchoolInfo : public QWidget
{

    Q_OBJECT
public:
    SchoolInfo(QWidget *parent = 0);
private:
    Ui::schoolInfo *ui;

};
*/


class  Appointments : public QWidget
{

    Q_OBJECT
public:
    Appointments(QWidget *parent = 0);
private:
    Ui::appointments *ui;

};


class  BusSchedule : public QWidget
{

    Q_OBJECT
public:
    BusSchedule(QWidget *parent = 0);
private:
    Ui::BusSchedule *ui;

};


class  About : public QWidget
{
    Q_OBJECT
public:
    About(QWidget *parent = 0);
private:
    Ui::About *ui;
};

class  Map : public QWidget
{
    Q_OBJECT
public:
    Map(QWidget *parent = 0);
private:
    Ui::Map *ui;
};




#endif
