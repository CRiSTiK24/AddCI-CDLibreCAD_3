#ifndef MouseReleaseEvent_H
#define MouseReleaseEvent_H

#include <QPointF>
#include "cad/geometry/geocoordinate.h"
#include "cad/vo/entitydistance.h"

/**
  * Event that get's dispatched each time the mouse is moved.
  */
class LcPainter;
class MouseReleaseEvent  {
    public:
        MouseReleaseEvent() {
        }
        MouseReleaseEvent(const lc::geo::Coordinate& mousePosition, QList<lc::EntityDistance> entities) : _mousePosition(mousePosition), _entities(entities) {
        }

        lc::geo::Coordinate  mousePosition() const {
            return _mousePosition;
        }

        QList<lc::EntityDistance> entities() const {
            return _entities;
        }

    private:
        lc::geo::Coordinate _mousePosition;
        QList<lc::EntityDistance> _entities;
};
Q_DECLARE_METATYPE(MouseReleaseEvent)

#endif // MouseReleaseEvent_H