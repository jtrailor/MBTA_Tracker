#include <iostream>
#include <string.h>

#include <cpr/cpr.h>
#include <json/json.h>

#include "station.h"

#ifndef STATION_LOCATIONS_H
#define STATION_LOCATIONS_H

class StationLocations {
  public:
    StationLocations();

    std::list<Station> returnJsonStations();

  private:
    Json::Value obtainJsonStations();

    std::list<Station> getListStations(Json::Value& jsonStations);
};

#endif