#ifndef RACK_H
#define RACK_H

#include <QDomElement>
#include <QDomDocument>
#include <QGraphicsView>

class Rack
{
public:
    enum Type {Straight = 0, Quincunx};

    Rack();
    Rack(
      const int& row,
      const int& col,
      const Type& type);
    Rack(const Rack& a);

    Rack& operator=(const Rack& a);

    inline void setRow(const int& row){_row=row;}
    inline void setCol(const int& col){_col=col;}
    inline void setType(const Type& type){_type=type;}

    inline const int& row()const{return _row;}
    inline const int& col()const{return _col;}
    inline const Type& type()const{return _type;}

    inline int& row(){return _row;}
    inline int& col(){return _col;}
    inline Type& type(){return _type;}

    QDomElement  toDomElement(QDomDocument& document) const;
    Rack fromDomElement(const QDomElement &elementRequirement);

    void draw(QGraphicsScene* scene);

private:
    int _row;
    int _col;
    Type _type;

};

#endif
