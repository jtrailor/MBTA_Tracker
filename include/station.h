#include <iostream>
#include <string.h>
#include <unordered_set>

#include "constants.h"
#include "coordinate.h"

#ifndef STATION_H
#define STATION_H

class Station {
  public:
    Station(std::string stationName, std::string description,
            std::string latitude, std::string longitude);

    double getLatitude() const;

    double getLongitude() const;

    std::string getDescription() const;

    LineColor getLineColor() const;

    LineColor extractLineColor();

    void print() const;

  private:
    LineColor checkValidLine(const std::string& lineColor) const;

    LineColor convertStringLineColor(const std::string& lineColor) const;

    std::string stationName;
    std::string description;
    std::string latitude;
    std::string longitude;

    LineColor lineColor;

    Coordinate normalizedCoordinate;
};

#endif
