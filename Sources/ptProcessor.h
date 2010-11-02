////////////////////////////////////////////////////////////////////////////////
//
// photivo
//
// Copyright (C) 2008 Jos De Laender <jos.de_laender@telenet.be>
// Copyright (C) 2009,2010 Michael Munzert <mail@mm-log.com>
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

#ifndef DLPROCESSOR_H
#define DLPROCESSOR_H

#include <QString>
#include <QTime>

#include <exiv2/image.hpp>
#include <exiv2/exif.hpp>

#include "ptDcRaw.h"
#include "ptImage.h"

class ptProcessor {

public:

// Cached image versions at different points.
ptImage*  m_Image_AfterDcRaw;
ptImage*  m_Image_AfterLensfun;
ptImage*  m_Image_AfterRGB;
ptImage*  m_Image_AfterLabCC;
ptImage*  m_Image_AfterLabSN;
ptImage*  m_Image_AfterLabEyeCandy;
ptImage*  m_Image_AfterEyeCandy;

// Reporting back
void (*m_ReportProgress)(const QString Message);
void (*m_UpdateGUI)();

// Constructor
ptProcessor(void (*ReportProgress)(const QString Message),void (*UpdateGUI)()=NULL);
// Destructor
~ptProcessor();

// The associated DcRaw.
DcRaw* m_DcRaw;

// The real processing.
void Run(short Phase,
         short SubPhase      = -1,
         short WithIdentify  = 1,
         short ProcessorMode = ptProcessorMode_Preview);

// Exif Related
Exiv2::ExifData m_ExifData;
unsigned char*  m_ExifBuffer;
unsigned int    m_ExifBufferLength;
void            ReadExifBuffer();

// Reporting
void ReportProgress(const QString Message);

// AutoExposure Value in EV.
double m_AutoExposureValue;
// CalculateAutoExposure
// There should be GuiSettings->m_WhiteFraction % pixels above 90%
double CalculateAutoExposure(ptImage *Image);

};

#endif

///////////////////////////////////////////////////////////////////////////////
