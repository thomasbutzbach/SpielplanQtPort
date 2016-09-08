#ifndef SPIELPLAN_H
#define SPIELPLAN_H

#include <QList>
#include <QPair>

/*
    * Spielplan generieren
    *
    * Spielplan generieren nach dem "Kantenfärbungs Algorithums".
    * Quelle: http://www-i1.informatik.rwth-aachen.de/~algorithmus/algo36.php
    *
    * Based on spielplan script by
    * Andy Theiler <andy@x3m.ch>
    * Licensed under BSD license
    * https://github.com/deezaster/spielplan
    * Ported and modified for Qt 5.7 by Thomas Butzbach <github@piganis.de>
    *
    * ------------------------------------------------------------------------
    * Support/Info/Download: https://github.com/thomasbutzbach/SpielplanQtPort
    * ------------------------------------------------------------------------
    *
    *  @version    1.0 for Qt 5.6
    *  @author     Thomas Butzbach <github@piganis.de>
    *  @copyright  Copyright (c) 2016, Thomas Butzbach, (www.piganis.de)
    *  @license    http://www.opensource.org/licenses/bsd-license.php  BSD License
    *
 */

class Spielplan
{    

public:
    Spielplan() = delete;
    static QList<QList<QPair<int, int> > > getOrganizedMatchDaysFromTeamList(QList<int> teamList, bool secondRound = false);
};

#endif // SPIELPLAN_H
