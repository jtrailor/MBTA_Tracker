#include "vehicle_locations.h"

VehicleLocations::VehicleLocations(){};

Json::Value VehicleLocations::obtainJsonVehicles() {
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

std::list<Vehicle>
VehicleLocations::getListVehicles(Json::Value& jsonVehicles) {

    std::list<Vehicle> listVehicles;

    for (int i = 0; i < jsonVehicles.size(); i++) {
        Vehicle vehicle(
            jsonVehicles[i]['relationships']['route']['data']['id'].asString(),
            jsonVehicles[i]["attributes"]["latitude"].asString(),
            jsonVehicles[i]["attributes"]["longitude"].asString());

        listVehicles.push_front(vehicle);
    };

    return listVehicles;
};

std::list<Vehicle> VehicleLocations::returnJsonVehicles() {
    Json::Value vehiclesJson = obtainJsonVehicles();
    return getListVehicles(vehiclesJson);
};
