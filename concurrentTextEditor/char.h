#ifndef CHAR_H
#define CHAR_H

#include <QUuid>
#include "Identifier.h"
#include "Enums.h"

#include <QtMath>

class Char
{
public:

    //Costruttore
    Char(QChar value, int counter, QUuid siteID, QList<Identifier> identifiers, Format format = Format::plain){

        _value  = value;
        _format = format;
        _counter = counter;
        _siteID = siteID;
        _position = identifiers;
    }

    Char(){}

    QChar _value;
    Format _format;
    int _counter;
    QUuid _siteID;
    QList<Identifier> _position;

    int compareTo(Char otherChar) {

        Identifier id1, id2;
        int comp;
        QList<Identifier> pos1 = _position;
        QList<Identifier> pos2= otherChar._position;

        for (int i = 0; i < std::min(pos1.length(), pos2.length()); i++) {
          id1 = pos1[i];
          id2 = pos2[i];
          comp = id1.compareTo(id2);

          if (comp != 0) {
            return comp;
          }
        }

        if (pos1.length() < pos2.length()) {
          return -1;
        } else if (pos1.length() > pos2.length()) {
          return 1;
        } else {
          return 0;
        }
      }
};

#endif // CHAR_H
