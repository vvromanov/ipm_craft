#pragma once
#include <vector>
#include <map>
#include "ResourceRec.h"

class Resources: public std::vector<ResourceRec> {
public:
    Resources(const std::initializer_list<value_type> &l);
    void Dump(uint32_t count=1, uint32_t offset=0, double k=1) const;
    void DumpResources(std::map<const Resource *, uint32_t>& have, uint32_t count=1, double k=1) const;
    void DumpResources(uint32_t count=1, double k=1) const;
    void DumpRecipe(double k) const;
private:
    void CollectResources(std::map<const Resource *, uint32_t>& have, std::map<const Resource*, uint32_t>& list, uint32_t count=1, double k=1) const;
};