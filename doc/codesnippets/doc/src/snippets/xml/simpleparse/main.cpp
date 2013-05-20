/****************************************************************************
**
** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the documentation of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <qfile.h>
#include <qxml.h>
#include "handler.h"

#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    QFile *file = new QFile(argv[1]);

//! [0]
    xmlReader = QXmlSimpleReader()
    source = QXmlInputSource(filename)
//! [0]

//! [1]
    handler = Handler()
    xmlReader.setContentHandler(handler)
    xmlReader.setErrorHandler(handler)
//! [1]

//! [2]
    ok = xmlReader.parse(source)

    if not ok:
        print "Parsing failed."
//! [2]
    else {
        QStringList names = handler->names();
        QList<int> indentations = handler->indentations();

        int items = names.count();

        for (int i = 0; i < items; ++i) {
            for (int j = 0; j < indentations[i]; ++j)
                std::cout << " ";
            std::cout << names[i].toLocal8Bit().constData() << std::endl;
        }
    }

    return 0;
}
