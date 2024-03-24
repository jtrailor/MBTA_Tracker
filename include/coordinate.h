#include "constants.h"

#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate {
  public:
    Coordinate(double latitude, double longitude);

    const double getNormalizedLatitude() const;

    const double getNormalizedLongitude() const;

  private:
    double normalize(double value, double min, double max);

    const double normalizedLatitude;
    const double normalizedLongitude;
};

#endif