//
// Created by Vladimir Romanov on 01/05/2024.
//

#include <iostream>
#include "Resource.h"

std::vector<const Resource *> Resource::allResources;

Resource::Resource(const std::string &name, double recept_price, double price) : name(name), price(price),
                                                                                 recept_price(recept_price),
                                                                                 resources({}) {
    allResources.push_back(this);
}

Resource::Resource(const std::string &name, double recept_price, double price, const Resources &resources) : name(name),
                                                                                                             price(price),
                                                                                                             recept_price(
                                                                                                                     recept_price),
                                                                                                             resources(
                                                                                                                     resources) {
    allResources.push_back(this);
}

const std::string &Resource::getName() const {
    return name;
}

double Resource::getPrice() const {
    return price;
}

const Resources &Resource::getResources() const {
    return resources;
}

const char *rt2str(ResourceType rt) {
    switch (rt) {
        case rtOre:
            return "Ore";
        case rtAlloy:
            return "Alloy";
        case rtItem:
            return "Item";
        case rtProject:
            return "Project";
        default:
            return "???";
    }
}

void Resource::DumpAll() {
    for (const auto r: allResources) {
        std::cout << r->name << "," << rt2str(r->getType()) << "," << r->getPlanet() << "," << r->getPrice()
                  << std::endl;
    }
}

int Resource::getPlanet() const {
    int planet = 0;
    for (const auto r: resources) {
        int resourcePlanet = r.getResource().getPlanet();
        if (resourcePlanet > planet) {
            planet = resourcePlanet;
        }
    }
    return planet;
}
