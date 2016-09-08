#include "spielplan.h"

QList<QList<QPair<int, int> > > Spielplan::getOrganizedMatchDaysFromTeamList(QList<int> teamList, bool secondRound)
{
    QList<QList<QPair<int,int>>> resultList;

    //Nur gerade Anzahl Teilnehmer erlaubt
    int intTeams = teamList.size();
    if ((intTeams % 2) != 0) { return resultList; }

    // --- Spielpaarungen bestimmen ---------------------------------------
    int n = intTeams - 1;
    QPair<int,int> paarung;

    for (int i = 1; i <= intTeams - 1; i++) {

        QList<QPair<int,int>> initListSpieltag;
        resultList.insert(i, initListSpieltag);

        int h = intTeams;
        int a = i;

        // heimspiel? auswärtsspiel?
        if ((i % 2) != 0) { int temp = a; a = h; h = temp; }

        paarung.first = teamList.at(h-1);
        paarung.second = teamList.at(a-1);

        QList<QPair<int,int>> l = resultList.at(i-1);
        l.append(paarung);
        resultList.replace(i-1, l);

        for (int k = 1; k <= ((intTeams / 2) - 1); k++) {

            if ((i-k) < 0) {
               a = n + (i-k);
            }
            else {
               a = (i-k) % n;
               a = (a == 0) ? n : a; // 0 -> n-1
            }

            h = (i+k) % n;
            h = (h == 0) ? n : h;    // 0 -> n-1

            // heimspiel? auswärtsspiel?
            if ((k % 2) == 0) { int temp = a; a = h; h = temp; }

            paarung.first = teamList.at(h-1);
            paarung.second = teamList.at(a-1);

            QList<QPair<int,int>> l = resultList.at(i-1);
            l.append(paarung);
            resultList.replace(i-1, l);

        }
    }

    // --- mit Rückrunde? -------------------------------------------------------
    if (secondRound) {

        int cntSpieltage = resultList.size();
        for (int i=0; i < cntSpieltage; i++) {

            QList<QPair<int,int>> spieltagList = resultList.at(i);

            int cntSpiele = spieltagList.size();
            for (int j=0; j < cntSpiele; j++) {
                QPair<int,int> paarung = spieltagList.at(j);
                int temp = paarung.first;
                paarung.first = paarung.second;
                paarung.second = temp;
                spieltagList.replace(j, paarung);
            }
            resultList.append(spieltagList);

        }

    }

    return resultList;
}
