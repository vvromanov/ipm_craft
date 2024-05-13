#include <cmath>
#include "ResourceRec.h"

ResourceRec::ResourceRec(uint32_t count, const Resource &resource) : count(count), resource(resource) {}

const Resource &ResourceRec::getResource() const {
    return resource;
}

uint32_t ResourceRec::getCount(double k) const {
    return ceil(count*k);
}
