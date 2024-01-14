#include "train.h"

Train::Train(std::string trainID, std::string latitude, std::string longitude)
    : trainID(trainID), latitude(latitude), longitude(longitude){};

std::string Train::getTrainID() { return trainID; }
std::string Train::getLatitude() { return latitude; }
std::string Train::getLongitude() { return longitude; }
