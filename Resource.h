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

const char *rt2str(ResourceType rt);

class Resource {
    std::string name;
    double price;
    double recept_price;
    static std::vector<const Resource *> allResources;
    Resources resources;
public:
    Resource(const std::string &name, double recept_price, double price);

    Resource(const std::string &name, double recept_price, double price, const Resources &resources);

    const std::string &getName() const;

    double getPrice() const;

    virtual ResourceType getType() const = 0;

    virtual int getPlanet() const;

    virtual double GetK() const = 0;

    virtual double getTimeToProduce(bool scaled = true) const = 0;

    const Resources &getResources() const;

    static void DumpAll();
};
