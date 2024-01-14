#include "station_locations.h"

StationLocations::StationLocations(){};

Json::Value StationLocations::obtainJsonStations() {
    const int OK_RESPONSE = 200;

    // 0 = green line, 1 = subway
    const std::string MBTA_URL =
        "https://api-v3.mbta.com/stops?filter[route_type]=0,1";

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

std::list<Station>
StationLocations::getListStations(Json::Value& jsonStations) {

    std::list<Station> listStations;

    for (int i = 0; i < jsonStations.size(); i++) {
        Station station(jsonStations[i]["attributes"]["name"].asString(),
                        jsonStations[i]["attributes"]["description"].asString(),
                        jsonStations[i]["attributes"]["latitude"].asString(),
                        jsonStations[i]["attributes"]["longitude"].asString());

        listStations.push_front(station);
    };

    return listStations;
};

std::list<Station> StationLocations::returnJsonStations() {
    Json::Value stationsJson = obtainJsonStations();
    return getListStations(stationsJson);
};
