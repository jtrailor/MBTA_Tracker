import requests


class VehicleLocations:

    def obtain_json_vehicles(self):
        mbta_url = "https://api-v3.mbta.com/vehicles?filter[route]=" \
                   "Red," \
                   "Blue," \
                   "Orange," \
                   "Green-B," \
                   "Green-C," \
                   "Green-D," \
                   "Green-E"

        response = requests.get(mbta_url)

        if response.status_code == 200:
            return response.json()['data']

    def process_vehicle_json(self, vehicle_json):
        vehicle_list = []

        for i in range(len(vehicle_json)):
            vehicle_list.append([vehicle_json[i]['relationships']['route']['data']['id'],
                                 vehicle_json[i]['attributes']['latitude'],
                                 vehicle_json[i]['attributes']['longitude']])

        return vehicle_list

    def return_vehicle_locations(self):
        vehicle_json = self.obtain_json_vehicles()
        return self.process_vehicle_json(vehicle_json)


if __name__ == '__main__':
    VehicleLocations().return_vehicle_locations()
