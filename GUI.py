import sys
from PyQt6.QtWidgets import QApplication, QMainWindow, QPushButton


class MBTATracker(QMainWindow):

    def __init__(self):
        super(MBTATracker, self).__init__()
        self.setWindowTitle("MBTA Tracker")
        self.setFixedWidth(900)
        self.setFixedHeight(900)


app = QApplication(sys.argv)

window = MBTATracker()
window.show()

app.exec()
