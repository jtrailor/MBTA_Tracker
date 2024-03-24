#include <iostream>
#include <string.h>
#include <unordered_set>

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

    std::string getLineColor();

    void print() const;

  private:
    std::string checkValidLine(const std::string& lineColor);

    std::string stationName;
    std::string description;
    std::string latitude;
    std::string longitude;

    Coordinate normalizedCoordinate;
};

#endif
