#include <iostream>
#include <string.h>
#include <unordered_set>

#ifndef TRAIN_H
#define TRAIN_H

class Train {
  public:
    Train(std::string trainID, std::string latitude, std::string longitude);

    std::string getTrainID();
    std::string getLatitude();
    std::string getLongitude();

  private:
    std::string trainID;
    std::string latitude;
    std::string longitude;
};

#endif
