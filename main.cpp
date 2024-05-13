#include <iostream>
#include "Resource.h"
#include "Ore.h"
#include "Alloy.h"
#include "Item.h"
#include "Project.h"

#define K_(x) (x*1.e3)
#define M_(x) (x*1.e6)
#define B_(x) (x*1.e9)
#define T_(x) (x*1.e12)
#define T1(minutes) (minutes*60)
#define T2(hours, minutes) ((hours*60+minutes)*60)

int main() {
    Ore Copper("Copper", 1000);
    Ore Iron("Iron", 2);
    Ore Lead("Lead", 4);
    Ore Silica("Silica", 8);
    Ore Aluminum("Aluminum", 17);
    Ore Silver("Silver", 36);
    Ore Gold("Gold", 75);
    Ore Diamond("Diamond", 160);

    Ore Platinum("Platinum", 340);
    Ore Titanium("Titanium", 730);
    Ore Iridium("Iridium", 1600);
    Ore Paladium("Paladium", 3500);
    Ore Osmium("Osmium", 7800);
    Ore Rhodium("Rhodium", 17500);
    Ore Inerton("Inerton", 40000);
    Ore Quadium("Quadium", 92000);
    Ore Scrith("Scrith", 215000);
    Ore Uru("Uru", 510000);
    Ore Vibranium("Vibranium", 1250000);
    Ore Aether("Aether", M_(3.2));
    Ore Viterium("Viterium", M_(9));

    Alloy CopperBar("CopperBar", 1450, 20, Resources{
            {1000, Copper}
    });

    Alloy IronBar("IronBar", 3000, 30, Resources{
            {1000, Iron}
    });

    Alloy LeadBar("LeadBar", 61000, 40, Resources{
            {1000, Lead}
    });

    Alloy SiliconBar("SiliconBar", 12500, 60, Resources{
            {1000, Silica}
    });

    Alloy AluminumBar("AluminumBar", 27600, 80, Resources{
            {1000, Aluminum}
    });

    Alloy SilverBar("SilverBar", 60000, 120, Resources{
            {1000, Silver}
    });

    Alloy GoldBar("GoldBar", 120000, 180, Resources{
            {1000, Gold}
    });

    Alloy BronzeBar("BronzeBar", 234000, 240, Resources{
            {2,  SilverBar},
            {10, CopperBar}
    });

    Alloy SteelBar("SteelBar", 340000, 8 * 60, Resources{
            {15, LeadBar},
            {30, IronBar}
    });

    Alloy PlatinumBar("PlatinumBar", 780000, 10 * 60, Resources{
            {2,    GoldBar},
            {1000, Platinum}
    });

    Alloy TitaniumBar("TitaniumBar", 1630000, 12 * 60, Resources{
            {2,    BronzeBar},
            {1000, Titanium}
    });

    Alloy IridiumBar("IridiumBar", 3110000, 14 * 60, Resources{
            {2,    SteelBar},
            {1000, Iridium}
    });

    Alloy PaladiumBar("PaladiumBar", 7000000, 16 * 60, Resources{
            {2,    PlatinumBar},
            {1000, Paladium}
    });

    Alloy OsmiumBar("OsmiumBar", 14500000, 18 * 60, Resources{
            {2,    TitaniumBar},
            {1000, Titanium}
    });

    Alloy RhodiumBar("RhodiumBar", 31000000, 20 * 60, Resources{
            {2,    IridiumBar},
            {1000, Rhodium}
    });

    Alloy InertonAlloy("InertonAlloy", 68 * 1000000, 24 * 60, Resources{
            {2,    PaladiumBar},
            {1000, Inerton}
    });

    Alloy QuadiumAlloy("QuadiumAlloy", 152 * 1000000, 26 * 60, Resources{
            {2,    OsmiumBar},
            {1000, Quadium}
    });
    Alloy ScrithAlloy("ScrithAlloy", 352 * 1000000, 32 * 60, Resources{
            {2,    RhodiumBar},
            {1000, Scrith}
    });

    Alloy UruAlloy("UruAlloy", 832 * 1000000, 36 * 60, Resources{
            {2,    InertonAlloy},
            {1000, Uru}
    });

    Alloy VibraniumAlloy("VibraniumAlloy", 2050 * 1000000, 42 * 60, Resources{
            {2,    QuadiumAlloy},
            {1000, Vibranium}
    });

    Alloy AetherAlloy("AetherAlloy", 5120 * 1000000L, 44 * 60, Resources{
            {2,    QuadiumAlloy},
            {1000, Aether}
    });

    /* ######################################################################################################################### */

    Item CopperWire("CopperWire", K_(10), T1(1), Resources{
            {5, CopperBar},
    });

    Item IronNails("IronNails", K_(20), T1(2), Resources{
            {5, IronBar},
    });

    Item Battery("Battery", K_(70), T1(4), Resources{
            {2,  CopperWire},
            {10, CopperBar},
    });

    Item Hammer("Hammer", K_(135), T1(8), Resources{
            {2, IronNails},
            {5, LeadBar},
    });

    Item Glass("Glass", K_(220), T1(12), Resources{
            {10, SiliconBar},
    });

    Item Circuit("Circuit", K_(620), T1(20), Resources{
            {5,  SiliconBar},
            {5,  AluminumBar},
            {10, CopperWire},
    });

    Item Lens("Lens", M_(1.1), T1(40), Resources{
            {1, Glass},
            {5, SilverBar},
    });

    Item Laser("Laser", M_(3.2), T2(1,0), Resources{
            {5,  GoldBar},
            {1,  Lens},
            {10, IronBar},
    });

    Item BasicComputer("Basic Computer", M_(7.6), T2(1,20), Resources{
            {5, Circuit},
            {5, SilverBar},
    });

    Item SolarPanel("Solar Panel", M_(12.5), T2(1,40), Resources{
            {5,  Circuit},
            {10, Glass},
    });

    Item LaserTorch("Laser Torch", M_(31), T2(2,0), Resources{
            {5, BronzeBar},
            {2, Laser},
            {5, Lens},
    });

    Item AdvancedBattery("Advanced Battery", M_(35), T2(2,30), Resources{
            {20, SteelBar},
            {30, Battery},
    });

    Item ThermalScanner("Thermal Scanner", M_(71.5), T2(3,0), Resources{
            {5, PlatinumBar},
            {2, Laser},
            {5, Glass},
    });

    Item AdvancedComputer("Advanced Computer", M_(180), T2(3,30), Resources{
            {5, TitaniumBar},
            {5, BasicComputer},
    });

    Item NavigationModule("Navigation Module", B_(1), T2(3,45), Resources{
            {2, LaserTorch},
            {1, ThermalScanner},
    });

    Item PlasmaTorch("Plasma Torch", B_(1.15), T2(4,10), Resources{
            {15, IridiumBar},
            {5,  LaserTorch},
    });

    Item RadioTower("RadioTower", B_(1.45), T2(4,20), Resources{
            {75,  PlatinumBar},
            {150, AluminumBar},
            {50,  TitaniumBar},
    });

    Item Telescope("Telescope", B_(2.7), T2(4,40), Resources{
            {20, Lens},
            {1,  AdvancedComputer},
    });

    Item SatelliteDish("Satellite Dish", B_(3.4), T2(5,0), Resources{
            {150, SteelBar},
            {30,  PlatinumBar},
    });

    Item Motor("Motor", B_(7), T2(5,20), Resources{
            {500, BronzeBar},
            {200, Hammer},
    });

    Item Accumulator("Accumulator", B_(12), T2(5,40), Resources{
            {20, OsmiumBar},
            {3, AdvancedBattery},
    });

    Item NuclearCapsule("Nuclear Capsule", B_(26), T2(5,50), Resources{
            {5, RhodiumBar},
            {1, PlasmaTorch},
    });

    Item WindTurbine("Wind Turbine", B_(140), T2(6,0), Resources{
            {120, AluminumBar},
            {1, Motor},
    });

    Item SpaceProbe("Space Probe", B_(180), T2(6,10), Resources{
            {1, SatelliteDish},
            {25, SolarPanel},
            {1, Telescope},
    });

    Item NuclearReactor("Nuclear Reactor", T_(1), T2(6,20), Resources{
            {30, IridiumBar},
            {1, NuclearCapsule},
    });

    Item Collider("Collider", T_(2), T2(6,25), Resources{
            {500, InertonAlloy},
            {100, QuadiumAlloy},
    });

    Item GravityChamber("Gravity Chamber", T_(15), T2(6,45), Resources{
            {60, AdvancedComputer},
            {1, NuclearReactor},
    });

    /* ######################################################################################################################### */

    Project Telescope11("Telescope 11", Resources{
            {3,  AdvancedComputer},
            {10, OsmiumBar},
    });

    Project Telescope15("Telescope 15", Resources{
            {5,  Motor},
            {10, ScrithAlloy},
    });

    Project Telescope16("Telescope 16", Resources{
            {3,  Accumulator},
            {10, UruAlloy},
    });

    Project Telescope17("Telescope 17", Resources{
            {3,  NuclearCapsule},
            {10, VibraniumAlloy},
    });

    Project Telescope18("Telescope 18", Resources{
            {4,  WindTurbine},
            {10, AetherAlloy},
    });

    Project Telescope19("Telescope 19", Resources{
            {4,  NuclearReactor},
            {10, VibraniumAlloy},
    });

    Project Telescope20("Telescope 20", Resources{
            {5,  Collider},
            {10, XyniumAlloy},
    });

    Project SuperiorCrafting("Superior Crafting", Resources{
            {2,  ThermalScanner},
            {10, AdvancedBattery},
            {20, LaserTorch},
    });

    Project Leader("Leader", Resources{
            {60, RhodiumBar},
            {5,  NavigationModule},
    });


    Project AsteroidAutoMiner("Asteroid Auto Miner", Resources{
            {20,  AdvancedComputer},
            {100, SolarPanel},
    });

    Project AsteroidScanner("Asteroid Scanner", Resources{
            {30,  ThermalScanner},
            {5, NavigationModule},
    });

    Project AdvancedAsteroidMiner("Advanced Asteroid Miner", Resources{
            {1,  SpaceProbe},
            {50, PlasmaTorch},
    });

    Project DebrisScanner("Debris Scanner", Resources{
            {1,  Collider},
            {8, GravityChamber},
    });

    Project AdvancedLeader("Advanced Leader", Resources{
            {10,  Motor},
            {10, Telescope},
            {200, ScrithAlloy},
    });

    std::map<const Resource *, uint32_t> have;
    have[&SpaceProbe] = 1;
    //have[&Glass] = 153;
    //have[&CopperWire]=67;
//    have[&Battery]=9;
//    have[&AdvancedBattery]=1;
    have[&Lens] = 3;
//    have[&Laser] = 1;
    have[&LaserTorch] = 12;
//    have[&PlasmaTorch] = 1;
//    have[&Accumulator] = 1;
    Resources todo{
        { 1, AsteroidScanner},
        //{1,Telescope18}
//        { 1, AdvancedLeader},
//        {1,DebrisScanner}
    };

    todo.Dump();
    std::cout<<"========================================="<<std::endl;
    todo.DumpResources();
    std::cout<<"========================================="<<std::endl;
    todo.DumpResources(have);

    return 0;
}
