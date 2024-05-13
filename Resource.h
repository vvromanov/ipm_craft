#pragma once

#include <string>
#include <vector>
#include "ResourceList.h"

typedef enum {
    rtOre,
    rtAlloy,
    rtItem,
    rtProject
} ResourceType;

class Resource {
    std::string name;
    double price;
    static std::vector<const Resource*> allResources;
    Resources resources;
public:
    Resource(const std::string &name, double price);
    Resource(const std::string &name, double price, const Resources &resources);

    const std::string &getName() const;
    double getPrice() const;
    virtual ResourceType getType() const=0;
    virtual double GetK() const=0;
    virtual uint32_t getTimeToProduce(bool scaled=true) const=0;
    const Resources &getResources() const;
};
