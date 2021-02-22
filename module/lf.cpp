﻿#include "lf.h"

LF::LF(Ui::MainWindow *ui, Util *addr, QWidget *parent): QObject(parent)
{
    this->parent = parent;
    util = addr;
    this->ui = ui;

}

void LF::read()
{
    if(Util::getClientType() == Util::CLIENTTYPE_OFFICIAL)
        util->execCMD("lf read");
    else if(Util::getClientType() == Util::CLIENTTYPE_ICEMAN)
        util->execCMD("lf read -v");
    Util::gotoRawTab();
    util->execCMD("data plot");
}

void LF::sniff()
{
    if(Util::getClientType() == Util::CLIENTTYPE_OFFICIAL)
        util->execCMD("lf snoop");
    else if(Util::getClientType() == Util::CLIENTTYPE_ICEMAN)
        util->execCMD("lf sniff -v");
    Util::gotoRawTab();
    util->execCMD("data plot");
}

void LF::search()
{
    if(Util::getClientType() == Util::CLIENTTYPE_OFFICIAL)
        util->execCMD("lf search u");
    else if(Util::getClientType() == Util::CLIENTTYPE_ICEMAN)
        util->execCMD("lf search -u");
    Util::gotoRawTab();
}

void LF::tune()
{
    if(Util::getClientType() == Util::CLIENTTYPE_OFFICIAL)
        util->execCMD("hw tune l");
    else if(Util::getClientType() == Util::CLIENTTYPE_ICEMAN)
        util->execCMD("lf tune"); // TODO: if freq is set, append it as a parameter
    Util::gotoRawTab();
}