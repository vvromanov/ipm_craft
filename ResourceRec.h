#pragma once

#include <cstdint>

class Resource;

class ResourceRec {
    uint32_t count;
    const Resource& resource;
public:
    ResourceRec(uint32_t count, const Resource &resource);

    const Resource &getResource() const;
    uint32_t getCount(double k) const;
};
