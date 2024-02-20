#include "station.h"

Station::Station(std::string stationName, std::string description,
                 std::string latitude, std::string longitude)
    : stationName(stationName), description(description), latitude(latitude),
      longitude(longitude){};

double Station::getLatitude() const { return std::stod(latitude); }

double Station::getLongitude() const { return std::stod(longitude); }

std::string Station::getDescription() const { return description; }

std::string Station::getLineColor() {
    std::string DELIMITER = " - ";

    int lengthDelimiter = DELIMITER.size();

    int firstDelimiter = description.find(DELIMITER);
    int secondDelimiter =
        description.find(DELIMITER, firstDelimiter + lengthDelimiter);

    int firstIndex = firstDelimiter + lengthDelimiter;
    int length = secondDelimiter - firstDelimiter - lengthDelimiter;

    return checkValidLine(description.substr(firstIndex, length));
}

std::string Station::checkValidLine(const std::string& lineColor) {
    std::unordered_set<std::string> LINE_COLOR_SET = {
        "Orange Line", "Blue Line",  "Red Line",
        "Silver Line", "Green Line", "Mattapan Trolley"};

    std::string UNKNOWN_LINE = "Unknown Line";

    if (LINE_COLOR_SET.find(lineColor) != LINE_COLOR_SET.end()) {
        return lineColor;
    } else {
        return UNKNOWN_LINE;
    }
}