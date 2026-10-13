#include "../include/Resource.h"
#include <iostream>

Resource::Resource() {
    resourceId = "";
    resourceName = "";
    category = "";
    available = true;
}

Resource::Resource(std::string id, std::string name, std::string cat, bool avail) {
    resourceId = id;
    resourceName = name;
    category = cat;
    available = avail;
}

std::string Resource::getId() const {
    return resourceId;
}

std::string Resource::getName() const {
    return resourceName;
}

std::string Resource::getCategory() const {
    return category;
}

bool Resource::isAvailable() const {
    return available;
}

void Resource::setId(std::string id) {
    resourceId = id;
}

void Resource::setName(std::string name) {
    resourceName = name;
}

void Resource::setCategory(std::string cat) {
    category = cat;
}

void Resource::setAvailable(bool avail) {
    available = avail;
}

void Resource::display() const {
    std::cout << "ID: " << resourceId 
              << " | Name: " << resourceName 
              << " | Category: " << category 
              << " | Status: " << (available ? "Available" : "Unavailable")
              << std::endl;
}
