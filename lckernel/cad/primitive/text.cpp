#include "text.h"

using namespace lc;

Text::Text(const geo::Coordinate& insertion_point, double height, QString text_value, const std::shared_ptr<const Layer> layer) : CADEntity(layer), geo::Text(insertion_point, height, text_value) {

}

Text::Text(const geo::Coordinate& insertion_point, double height, QString text_value, const std::shared_ptr<const Layer> layer, const QList<std::shared_ptr<const MetaType> >& metaTypes) : CADEntity(layer, metaTypes),  geo::Text(insertion_point, height, text_value) {
}

std::shared_ptr<const lc::CADEntity> Text::move(const geo::Coordinate& offset) const {

}

std::shared_ptr<const lc::CADEntity> Text::copy(const geo::Coordinate& offset) const {

}

std::shared_ptr<const lc::CADEntity> Text::rotate(const geo::Coordinate& rotation_center, const double rotation_angle) const {

}

std::shared_ptr<const lc::CADEntity> Text::scale(const geo::Coordinate& scale_center, const geo::Coordinate& scale_factor) const {

}