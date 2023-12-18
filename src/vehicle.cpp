#include "vehicle.h"

Vehicle::Vehicle(std::string vehicleID, std::string latitude,
                 std::string longitude)
    : vehicleID(vehicleID), latitude(latitude), longitude(longitude){};

std::string Vehicle::getVehicleID() { return vehicleID; }
