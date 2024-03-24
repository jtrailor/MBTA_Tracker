#include "station_locations.h"
#include "train_locations.h"
#include "visualization.h"
#include <iostream>

int main() {
    StationLocations sl;

    // sl.getMinMaxStationLatLongs();

    std::list<Station> locations = sl.returnJsonStations();

    for (Station station : locations) {
        station.print();
    }

    runProgram();
}