#include <iostream>
#include <string.h>
#include <unordered_set>

#ifndef VEHICLE_H
#define VEHICLE_H

class Vehicle {
  public:
    Vehicle(std::string vehicleID, std::string latitude, std::string longitude);

    std::string getVehicleID();

  private:
    std::string vehicleID;
    std::string latitude;
    std::string longitude;
};

#endif
