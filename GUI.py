from tkinter import Canvas, Tk


class Station:


    def __init__(self, xcoor, ycoor, color):
        self.size = 8
        self.xcoor_left = xcoor - self.size
        self.ycoor_bottom = ycoor - self.size
        self.xcoor_right = xcoor + self.size
        self.ycoor_top = ycoor + self.size
        self.color = color


class TrainCanvas(Canvas):

    def __init__(self, master):
        super().__init__(master, width=900, height=900, bg="white")
        self.pack()
        self.stations = []  # keeps track of Ball objects
        self.trains = []  # keeps track of Ball objects representation on the Canvas

    def add_stations(self, list_stations):
        print("yes")
        for i in range(len(list_stations)):
            station = Station(list_stations[i][0], list_stations[i][1], list_stations[i][2])
            self.stations.append(
                self.create_oval(station.xcoor_left, station.ycoor_bottom, station.xcoor_right, station.ycoor_top,
                                 outline=station.color, width="3"))


if __name__ == '__main__':
    shop_window = Tk()
    shop_window.geometry("900x900")
    c = TrainCanvas(shop_window)

    c.add_stations([[50, 50, "red"], [200, 200, "green"], [800, 800, "blue"]])
    shop_window.mainloop()
