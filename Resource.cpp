//
// Created by Vladimir Romanov on 01/05/2024.
//

#include "Resource.h"

std::vector<const Resource*> Resource::allResources;

Resource::Resource(const std::string &name, double price) : name(name), price(price), resources({}) {
    allResources.push_back(this);
}

Resource::Resource(const std::string &name, double price, const Resources &resources) : name(name), price(price), resources(resources) {
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
