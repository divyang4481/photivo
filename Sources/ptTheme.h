////////////////////////////////////////////////////////////////////////////////
//
// photivo
//
// Copyright (C) 2010 Michael Munzert <mail@mm-log.com>
//
// This file is part of photivo.
//
// photivo is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 3
// as published by the Free Software Foundation.
//
// photivo is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with photivo.  If not, see <http://www.gnu.org/licenses/>.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef DLTHEME_H
#define DLTHEME_H

#include <QtCore>
#include <QtGui>

////////////////////////////////////////////////////////////////////////////////
//
// ptTheme
//
////////////////////////////////////////////////////////////////////////////////

class ptTheme {

public :

// Constructor
ptTheme(QApplication* Application);

// Destructor
~ptTheme();

// Variables
QStyle*     ptThemeStyle;
QStyle*     ptStyle;
QPalette    ptPalette;
QPalette    ptMenuPalette;
QString     ptStyleSheet;

QPalette    ptSystemPalette;
QStyle*     ptSystemStyle;

QPixmap*    ptIconCircleGreen;
QPixmap*    ptIconCircleRed;
QPixmap*    ptIconCrossRed;
QPixmap*    ptIconReset;
QPixmap*    ptIconDisk;

// Methods
void Reset();
void Normal(short Color);
void MidGrey(short Color);
void DarkGrey(short Color);
void VeryDark(short Color);
void CSS();
void JustTools();
void SetHighLightColor(short Color);

private slots:

signals:

protected:

private:


QColor      ptHighLight;
QColor      ptBackGround;
QColor      ptGradient;
QColor      ptText;
QColor      ptDark;
QColor      ptBright;
QColor      ptVeryBright;

};

#endif

////////////////////////////////////////////////////////////////////////////////

