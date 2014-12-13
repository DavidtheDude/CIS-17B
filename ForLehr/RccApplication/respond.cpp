#include "respond.h"
#include "ui_respond.h"

#include <QComboBox>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>

Respond::Respond(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Respond)
{
    ui->setupUi(this);
    /*
    QLabel *title = new QLabel("Title ");
    QLabel *urlLabel = new QLabel("Url");
    QLabel *choose = new QLabel("Choose a sub-forum");
    QPushButton *submit = new QPushButton("Submit");
    QGroupBox *forums = new QGroupBox();



    QComboBox *threadType = new QComboBox;
    QLineEdit *titleInput = new QLineEdit;
    QLineEdit *urlInput = new QLineEdit;
    QTextEdit *text = new QTextEdit;
    QLineEdit *sub = new QLineEdit;


    QGridLayout *forumButton = new QGridLayout;

    threadType->addItem("Link");
    threadType->addItem("Text");


    forumButton->addWidget(threadType);
    forumButton->addWidget(title);
    forumButton->addWidget(titleInput);
    forumButton->addWidget(urlLabel);
    forumButton->addWidget(urlInput);
    forumButton->addWidget(text);
    forumButton->addWidget(choose);
    forumButton->addWidget(sub);
    forumButton->addWidget(submit);

    forums->setLayout(forumButton);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(forums);
    mainLayout->addSpacing(12);

    mainLayout->addStretch(1);
    setLayout(mainLayout);
    */
}

Respond::~Respond()
{
    delete ui;
}


void Respond::on_pushButton_clicked()
{
    this->close();
}
