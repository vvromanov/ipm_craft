#include <cmath>
#include <iostream>
#include "ResourceRec.h"
#include "Resource.h"

ResourceRec::ResourceRec(uint32_t count, const Resource &resource) : count(count), resource(resource) {}

const Resource &ResourceRec::getResource() const {
    return resource;
}

uint32_t ResourceRec::getCount(double k) const {
    uint32_t fixed_count = (floor(count/k)+0.001);
    if (fixed_count==0) {
        fixed_count=1;
    }
    //std::cout <<resource.getName() << " " << count << " -> " << fixed_count << std::endl;
    return fixed_count;
}
