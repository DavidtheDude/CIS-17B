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

#include <QtGui>

#include "HomeScreen.h"
#include "HomeScreenPages.h"
#include "globals.h"


HomeScreen::HomeScreen()
{
    //setting up the list of options that the user can click on
    contentsWidget = new QListWidget;
    contentsWidget->setViewMode(QListView::IconMode);
    contentsWidget->setIconSize(QSize(100, 100));
    contentsWidget->setMovement(QListView::Static);
    contentsWidget->setMaximumWidth(145);
    contentsWidget->setSpacing(12);


    HomeScreenPagesWidget = new QStackedWidget;
    HomeScreenPagesWidget->addWidget(new NewsPage);
    HomeScreenPagesWidget->addWidget(new Forums);
    HomeScreenPagesWidget->addWidget(new Schedule);
    //HomeScreenPagesWidget->addWidget(new Map);
    //HomeScreenPagesWidget->addWidget(new SchoolInfo);
    //HomeScreenPagesWidget->addWidget(new Appointments);
    //HomeScreenPagesWidget->addWidget(new BusSchedule);
    //HomeScreenPagesWidget->addWidget(new About);
    HomeScreenPagesWidget->setFixedWidth(1024);
    HomeScreenPagesWidget->setFixedHeight(768);


    //QPushButton *closeButton = new QPushButton(tr("Close"));

    createIcons();
    contentsWidget->setCurrentRow(0);

    //connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));

    QHBoxLayout *horizontalLayout = new QHBoxLayout;
    horizontalLayout->addWidget(contentsWidget);
    horizontalLayout->addWidget(HomeScreenPagesWidget, 1);

    //QHBoxLayout *buttonsLayout = new QHBoxLayout;
    //buttonsLayout->addStretch(1);
    //buttonsLayout->addWidget(closeButton);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(horizontalLayout);
    mainLayout->addStretch(1);
    mainLayout->addSpacing(12);
    //mainLayout->addLayout(buttonsLayout);
    setLayout(mainLayout);

    setWindowTitle(tr("Config Dialog"));




}

void HomeScreen::createIcons()
{
    QListWidgetItem *NewsButton = new QListWidgetItem(contentsWidget);
    NewsButton->setIcon(QIcon(":/Images/News.png"));
    NewsButton->setText(tr("News"));
    NewsButton->setTextAlignment(Qt::AlignHCenter);
    NewsButton->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ForumsButton = new QListWidgetItem(contentsWidget);
    ForumsButton->setIcon(QIcon(":/Images/Forums.png"));
    ForumsButton->setText(tr("Forums"));
    ForumsButton->setTextAlignment(Qt::AlignHCenter);
    ForumsButton->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ScheduleButton = new QListWidgetItem(contentsWidget);
    ScheduleButton->setIcon(QIcon(":/Images/Schedule.png"));
    ScheduleButton->setText(tr("Schedule"));
    ScheduleButton->setTextAlignment(Qt::AlignHCenter);
    ScheduleButton->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    /*
    QListWidgetItem *Map = new QListWidgetItem(contentsWidget);
    Map->setIcon(QIcon(":/Images/About.png"));
    Map->setText(tr("Maps"));
    Map->setTextAlignment(Qt::AlignHCenter);
    Map->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);


    QListWidgetItem *Club = new QListWidgetItem(contentsWidget);
    Club->setIcon(QIcon(":/Images/Clubs.png"));
    Club->setText(tr("Clubs"));
    Club->setTextAlignment(Qt::AlignHCenter);
    Club->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *SchoolInfoButton = new QListWidgetItem(contentsWidget);
    SchoolInfoButton->setIcon(QIcon(":/Images/SchoolInfo.png"));
    SchoolInfoButton->setText(tr("School Information"));
    SchoolInfoButton->setTextAlignment(Qt::AlignHCenter);
    SchoolInfoButton->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);


    QListWidgetItem *AppointmentsButton = new QListWidgetItem(contentsWidget);
    AppointmentsButton->setIcon(QIcon(":/Images/Appointments.png"));
    AppointmentsButton->setText(tr("Appointments"));
    AppointmentsButton->setTextAlignment(Qt::AlignHCenter);
    AppointmentsButton->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *BusSchedule = new QListWidgetItem(contentsWidget);
    BusSchedule->setIcon(QIcon(":/Images/Bus.png"));
    BusSchedule->setText(tr("Bus Schedule"));
    BusSchedule->setTextAlignment(Qt::AlignHCenter);
    BusSchedule->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    */

    QListWidgetItem *AboutButton = new QListWidgetItem(contentsWidget);
    AboutButton->setIcon(QIcon(":/Images/About.png"));
    AboutButton->setText(tr("About"));
    AboutButton->setTextAlignment(Qt::AlignHCenter);
    AboutButton->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);



    connect(contentsWidget,
            SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),
            this, SLOT(changePage(QListWidgetItem*,QListWidgetItem*)));
}

void HomeScreen::changePage(QListWidgetItem *current, QListWidgetItem *previous)
{
    if (!current)
        current = previous;

    HomeScreenPagesWidget->setCurrentIndex(contentsWidget->row(current));
}
