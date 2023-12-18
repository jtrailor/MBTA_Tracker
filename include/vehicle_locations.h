#include <iostream>
#include <string.h>

#include <cpr/cpr.h>
#include <json/json.h>

#include "vehicle.h"

#ifndef VEHICLE_LOCATIONS_H
#define VEHICLE_LOCATIONS_H

class VehicleLocations {
  public:
    VehicleLocations();

    std::list<Vehicle> returnJsonVehicles();

  private:
    Json::Value obtainJsonVehicles();

    std::list<Vehicle> getListVehicles(Json::Value& jsonVehicles);
};

#endif