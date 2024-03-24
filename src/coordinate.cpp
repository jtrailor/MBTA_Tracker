#include "coordinate.h"

Coordinate::Coordinate(double latitude, double longitude)
    : normalizedLatitude(normalize(latitude, MIN_LAT, MAX_LAT)),
      normalizedLongitude(normalize(longitude, MIN_LONG, MAX_LONG)) {}

const double Coordinate::getNormalizedLatitude() const {
    return normalizedLatitude;
};

const double Coordinate::getNormalizedLongitude() const {
    return normalizedLongitude;
};

double Coordinate::normalize(double value, double min, double max) {
    return (value - min) / (max - min) * 100.0;
}
