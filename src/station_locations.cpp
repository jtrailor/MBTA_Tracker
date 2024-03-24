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

    return root;
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

void StationLocations::getMinMaxStationLatLongs() {
    std::list<Station> listStations = returnJsonStations();

    double minLat, minLong, maxLat, maxLong, currentLat, currentLong;
    std::string minLatStation, minLongStation, maxLatStation, maxLongStation,
        stationName;

    minLat = INFINITY;
    maxLat = -INFINITY;
    minLong = INFINITY;
    maxLong = -INFINITY;

    for (const Station& station : listStations) {
        currentLat = station.getLatitude();
        currentLong = station.getLongitude();
        stationName = station.getDescription();

        if (currentLat > maxLat) {
            maxLat = currentLat;
            maxLatStation = stationName;
        }
        if (currentLat < minLat) {
            minLat = currentLat;
            minLatStation = stationName;
        }
        if (currentLong > maxLong) {
            maxLong = currentLong;
            maxLongStation = stationName;
        }
        if (currentLong < minLong) {
            minLong = currentLong;
            minLongStation = stationName;
        }
    }
    std::cout << "Max Lat: " << maxLat << " Station: " << maxLatStation
              << std::endl;
    std::cout << "Min Lat: " << minLat << " Station: " << minLatStation
              << std::endl;
    std::cout << "Max Long: " << maxLong << " Station: " << maxLongStation
              << std::endl;
    std::cout << "Min Long: " << minLong << " Station: " << minLongStation
              << std::endl;
};
