#include "train_locations.h"

TrainLocations::TrainLocations(){};

Json::Value TrainLocations::obtainJsonTrains() {
    const int OK_RESPONSE = 200;

    // 0 = green line, 1 = subway
    const std::string MBTA_URL =
        "https://api-v3.mbta.com/vehicles?filter[route]="
        "Red,"
        "Blue,"
        "Orange,"
        "Green-B,"
        "Green-C,"
        "Green-D,"
        "Green-E";

    cpr::Response r = cpr::Get(cpr::Url{MBTA_URL});

    Json::Reader reader;
    Json::Value root;

    if (r.status_code == OK_RESPONSE) {
        bool parseSuccessful = reader.parse(r.text, root);

        if (parseSuccessful) {
            return root["data"];
        }
    }
};

std::list<Train> TrainLocations::getListTrains(Json::Value& jsonTrains) {

    std::list<Train> listTrains;

    for (int i = 0; i < jsonTrains.size(); i++) {
        Train train(
            jsonTrains[i]["relationships"]["route"]["data"]["id"].asString(),
            jsonTrains[i]["attributes"]["latitude"].asString(),
            jsonTrains[i]["attributes"]["longitude"].asString());

        listTrains.push_front(train);
    };

    return listTrains;
};

std::list<Train> TrainLocations::returnJsonTrains() {
    Json::Value trainsJson = obtainJsonTrains();
    return getListTrains(trainsJson);
};
