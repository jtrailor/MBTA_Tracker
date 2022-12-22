import requests


class StationLocations:

    def obtain_json_stations(self):
        mbta_url = "https://api-v3.mbta.com/stops?filter[route_type]=" \
                   "0," \
                   "1"

        response = requests.get(mbta_url)

        if response.status_code == 200:
            return response.json()['data']

    #Todo: Use the description to get the color
    def process_station_json(self, station_json):
        station_list = []

        for i in range(len(station_json)):
            station_list.append([station_json[i]['attributes']['name'],
                                 station_json[i]['attributes']['description']])

        return station_list

    def return_station_locations(self):
        station_json = self.obtain_json_stations()
        return self.process_station_json(station_json)


if __name__ == '__main__':
    print(StationLocations().return_station_locations())
