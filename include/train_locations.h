#include <iostream>
#include <string.h>

#include <cpr/cpr.h>
#include <json/json.h>

#include "train.h"

#ifndef TRAIN_LOCATIONS_H
#define TRAIN_LOCATIONS_H

class TrainLocations {
  public:
    TrainLocations();

    std::list<Train> returnJsonTrains();

  private:
    Json::Value obtainJsonTrains();

    std::list<Train> getListTrains(Json::Value& jsonTrains);
};

#endif