#include <iostream>
#include "ResourceList.h"
#include "Resource.h"
#include "rx_dump.h"
#include "MiningSettings.h"

Resources::Resources(const std::initializer_list<ResourceRec> &l) : vector(l) {}

static void DumpTime(double time_d);

void Resources::Dump(uint32_t count, uint32_t offset, double k) const {
    for (const auto &r: *this) {
        if (r.getResource().getType() != rtOre) {
            std::cout << GetIndentStr(offset) << count * r.getCount(k) << " x " << r.getResource().getName() << " ";
            DumpTime(r.getResource().getTimeToProduce(true));
            std::cout << std::endl;
            r.getResource().getResources().Dump(r.getCount(k) * count, offset + 4, r.getResource().GetK());
        }
    }
}

void Resources::CollectResources(std::map<const Resource *, uint32_t> &have, std::map<const Resource *, uint32_t> &list,
                                 uint32_t count, double k) const {
    for (const auto &r: *this) {
        uint32_t produce_resource = count * r.getCount(k);
        uint32_t have_resource = have[&r.getResource()];
        if (have_resource != 0) {
            if (produce_resource <= have_resource) {
                have[&r.getResource()] -= produce_resource;
                produce_resource = 0;
            } else {
                produce_resource -= have_resource;
                have[&r.getResource()] = 0;
            }
        }
        if (produce_resource != 0) {
            if (list.contains(&r.getResource())) {
                list[&r.getResource()] = list[&r.getResource()] + produce_resource;
            } else {
                list[&r.getResource()] = produce_resource;
            }
            r.getResource().getResources().CollectResources(have, list, produce_resource, r.getResource().GetK());
        }
    }
}

static void DumpTime(double time_d) {
    uint32_t time_ms = (time_d * 1000) + 0.001;
    uint32_t time = time_ms / 1000;
    uint32_t seconds = time % 60;
    time /= 60;
    uint32_t minutes = time % 60;
    uint32_t hours = time / 60;
    if (hours != 0) {
        std::cout << hours << ':';
    }
    if (hours != 0 || minutes != 0) {
        if (minutes < 10) {
            std::cout << '0';
        }
        std::cout << minutes << ':';
    }
    if (seconds < 10 && (hours != 0 || minutes != 0)) {
        std::cout << '0';
    }
    std::cout << seconds;
    if (time_ms < 3) {
        std::cout << '.' << time_ms % 1009;
    }
}

void Resources::DumpResources(std::map<const Resource *, uint32_t> &have, uint32_t count, double k) const {
    std::map<const Resource *, uint32_t> list;
    CollectResources(have, list, count, k);
    uint32_t all_time = 0;
    for (auto i: list) {
        if (i.first->getType() == rtItem) {
            double time = i.first->getTimeToProduce();
            double total_time = time * i.second;
            std::cout << i.first->getName() << ": " << i.second << " ";
            DumpTime(time);
            std::cout << " ";
            DumpTime(total_time / IPM_CRAFT_COUNT);
            std::cout << std::endl;
            if (i.first->getType() == rtItem) {
                all_time += total_time;
            }
        }
    }
    std::cout << "Total time: ";
    DumpTime(all_time / IPM_CRAFT_COUNT);
    std::cout << std::endl;
}

void Resources::DumpResources(uint32_t count, double k) const {
    std::map<const Resource *, uint32_t> have;
    DumpResources(have, count, k);
}

void Resources::DumpRecipe(double k) const {

}
