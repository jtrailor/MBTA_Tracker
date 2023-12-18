#include "station_locations.h"
#include <iostream>

int main() {
    StationLocations sl;

    std::list<Station> listStations = sl.returnJsonStations();

    std::list<Station>::iterator it = listStations.begin();

    for (int i = 0; i < listStations.size(); i++) {

        std::cout << "Color: " << it->getLineColor() << std::endl;
        std::cout << "Description : " << it->getDescription() << std::endl;

        advance(it, 1);
    }
}