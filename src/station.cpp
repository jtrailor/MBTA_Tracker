#include "station.h"

Station::Station(std::string stationName, std::string description,
                 std::string latitude, std::string longitude)
    : stationName(stationName), description(description), latitude(latitude),
      longitude(longitude), lineColor(extractLineColor()),
      normalizedCoordinate(getLatitude(), getLongitude()){};

double Station::getLatitude() const { return std::stod(latitude); }

double Station::getLongitude() const { return std::stod(longitude); }

std::string Station::getDescription() const { return description; }

LineColor Station::getLineColor() const { return lineColor; }

LineColor Station::extractLineColor() {
    std::string DELIMITER = " - ";

    int lengthDelimiter = DELIMITER.size();

    int firstDelimiter = description.find(DELIMITER);
    int secondDelimiter =
        description.find(DELIMITER, firstDelimiter + lengthDelimiter);

    int firstIndex = firstDelimiter + lengthDelimiter;
    int length = secondDelimiter - firstDelimiter - lengthDelimiter;

    return checkValidLine(description.substr(firstIndex, length));
}

LineColor Station::checkValidLine(const std::string& lineColor) const {
    std::unordered_set<std::string> LINE_COLOR_SET = {
        "Orange Line", "Blue Line",  "Red Line",
        "Silver Line", "Green Line", "Mattapan Trolley"};

    if (LINE_COLOR_SET.find(lineColor) != LINE_COLOR_SET.end()) {
        return convertStringLineColor(lineColor);
    } else {
        return LineColor::unknown;
    }
}

LineColor Station::convertStringLineColor(const std::string& lineColor) const {
    LineColor color;

    if (lineColor == "Orange") {
        color = LineColor::orange;
    } else if (lineColor == "Green") {
        color = LineColor::green;
    } else if (lineColor == "Blue") {
        color = LineColor::blue;
    } else if (lineColor == "Silver") {
        color = LineColor::silver;
    } else {
        color = LineColor::red;
    }

    return color;
}

void Station::print() const {
    std::cout << "Station name: " << stationName << std::endl;
    std::cout << "Description: " << description << std::endl;
    std::cout << "Latitude: " << latitude << std::endl;
    std::cout << "Longitude: " << longitude << std::endl;
    std::cout << "Normalized Latitude: "
              << std::to_string(normalizedCoordinate.getNormalizedLatitude())
              << std::endl;
    std::cout << "Normalized Longitude: "
              << std::to_string(normalizedCoordinate.getNormalizedLongitude())
              << std::endl;
}