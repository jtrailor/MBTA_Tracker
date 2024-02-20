#include <iostream>
#include <string.h>
#include <unordered_set>

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

  private:
    std::string checkValidLine(const std::string& lineColor);

    std::string stationName;
    std::string description;
    std::string latitude;
    std::string longitude;
};

#endif
