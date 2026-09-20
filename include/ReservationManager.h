#ifndef RESERVATION_MANAGER_H
#define RESERVATION_MANAGER_H

#include <vector>
#include <string>
#include "Resource.h"

class ReservationManager {
private:
    std::vector<Resource> resources;

public:
    ReservationManager();
    
    void loadResources(const std::string& filename);
    
    void displayAllResources() const;
    
    const std::vector<Resource>& getResources() const;
};

#endif
