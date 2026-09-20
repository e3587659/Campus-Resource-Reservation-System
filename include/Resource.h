
#define RESOURCE_H

#include <string>

class Resource {
private:
    std::string resourceId;
    std::string resourceName;
    std::string category;
    bool available;

public:
    Resource();
    Resource(std::string id, std::string name, std::string cat, bool avail);

    std::string getId() const;
    std::string getName() const;
    std::string getCategory() const;
    bool isAvailable() const;

    void setId(std::string id);
    void setName(std::string name);
    void setCategory(std::string cat);
    void setAvailable(bool avail);

    void display() const;
};

#endif
