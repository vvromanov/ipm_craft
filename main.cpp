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
#define q_(x) (x*1.e15)
#define Q_(x) (x*1.e18)

#define T1(minutes) (minutes*60)
#define T2(hours, minutes) ((hours*60+minutes)*60)


int main() {
    Ore Copper("Copper", 1000, 1);
    Ore Iron("Iron", 2, 2);
    Ore Lead("Lead", 4, 4);
    Ore Silica("Silica", 8, 7);
    Ore Aluminum("Aluminum", 17, 9);
    Ore Silver("Silver", 36, 12);
    Ore Gold("Gold", 75, 14);
    Ore Diamond("Diamond", 160, 17);

    Ore Platinum("Platinum", 340, 19);
    Ore Titanium("Titanium", 730, 22);
    Ore Iridium("Iridium", 1600, 25);
    Ore Paladium("Paladium", 3500, 28);
    Ore Osmium("Osmium", 7800, 31);
    Ore Rhodium("Rhodium", 17500, 34);
    Ore Inerton("Inerton", 40000, 37);
    Ore Quadium("Quadium", 92000, 40);
    Ore Scrith("Scrith", 215000, 43);
    Ore Uru("Uru", 510000, 46);
    Ore Vibranium("Vibranium", 1250000, 49);
    Ore Aether("Aether", M_(3.2), 52);
    Ore Viterium("Viterium", M_(9), 55);
    Ore Xynium("Xynium", M_(28), 58);
    Ore Quolium("Quolium", M_(90), 61);
    Ore Literium("Literium", M_(300), 64);
    Ore Wraith("Wraith", B_(1.1), 67);

    /* ######################################################################################################################### */

    Alloy CopperBar("Copper Bar", 0, K_(1.45), 20, Resources{
            {1000, Copper}
    });

    Alloy IronBar("Iron Bar", K_(3), K_(3), 30, Resources{
            {1000, Iron}
    });

    Alloy LeadBar("Lead Bar", K_(9), K_(6.1), 40, Resources{
            {1000, Lead}
    });

    Alloy SiliconBar("Silicon Bar", K_(25), K_(12.5), 60, Resources{
            {1000, Silica}
    });

    Alloy AluminumBar("Aluminum Bar", K_(75), K_(27.6), 80, Resources{
            {1000, Aluminum}
    });

    Alloy SilverBar("Silver Bar", K_(225), K_(60), T1(2), Resources{
            {1000, Silver}
    });

    Alloy GoldBar("GoldBar", K_(500), K_(120), T1(3), Resources{
            {1000, Gold}
    });

    Alloy BronzeBar("Bronze Bar", M_(1), K_(234), T1(4), Resources{
            {2,  SilverBar},
            {10, CopperBar}
    });

    Alloy SteelBar("Steel Bar", M_(2), K_(340), T1(8), Resources{
            {15, LeadBar},
            {30, IronBar}
    });

    Alloy PlatinumBar("Platinum Bar", M_(4), K_(780), T1(10), Resources{
            {2,    GoldBar},
            {1000, Platinum}
    });

    Alloy TitaniumBar("Titanium Bar", M_(8), M_(1.63), T1(12), Resources{
            {2,    BronzeBar},
            {1000, Titanium}
    });

    Alloy IridiumBar("Iridium Bar", M_(15), M_(3.11), T1(14), Resources{
            {2,    SteelBar},
            {1000, Iridium}
    });

    Alloy PaladiumBar("Paladium Bar", M_(30), M_(7), T1(16), Resources{
            {2,    PlatinumBar},
            {1000, Paladium}
    });

    Alloy OsmiumBar("Osmium Bar", M_(60), M_(14.5), T1(18), Resources{
            {2,    TitaniumBar},
            {1000, Titanium}
    });

    Alloy RhodiumBar("Rhodium Bar", M_(120), M_(31), T1(20), Resources{
            {2,    IridiumBar},
            {1000, Rhodium}
    });

    Alloy InertonAlloy("Inerton Alloy", M_(250), M_(68), T1(24), Resources{
            {2,    PaladiumBar},
            {1000, Inerton}
    });

    Alloy QuadiumAlloy("Quadium Alloy", M_(500), M_(152), T1(26), Resources{
            {2,    OsmiumBar},
            {1000, Quadium}
    });
    Alloy ScrithAlloy("Scrith Alloy", B_(1), M_(352), T1(32), Resources{
            {2,    RhodiumBar},
            {1000, Scrith}
    });

    Alloy UruAlloy("Uru Alloy", B_(2), M_(832), T1(36), Resources{
            {2,    InertonAlloy},
            {1000, Uru}
    });

    Alloy VibraniumAlloy("Vibranium Alloy", B_(4), B_(2.05), T1(42), Resources{
            {2,    QuadiumAlloy},
            {1000, Vibranium}
    });

    Alloy AetherAlloy("Aether Alloy", B_(8), B_(5.12), T1(44), Resources{
            {2,    QuadiumAlloy},
            {1000, Aether}
    });

    Alloy ViteriumAlloy("Viterium Alloy", B_(16), B_(15.5), T1(48), Resources{
            {2,    UruAlloy},
            {1000, Viterium}
    });

    Alloy XyniumAlloy("Xynium Alloy", B_(84), B_(48), T1(55), Resources{
            {5,    VibraniumAlloy},
            {1500, Xynium}
    });

    Alloy QuoliumAlloy("Quolium Alloy", B_(275), B_(160), T2(1, 2), Resources{
            {5,    VibraniumAlloy},
            {1500, Quolium}
    });

    Alloy LiteriumAlloy("Literium Alloy", T_(1), B_(600), T2(1, 9), Resources{
            {5,    ViteriumAlloy},
            {1500, Literium}
    });

    Alloy WraithAlloy("Wraith Alloy", T_(4.2), T_(2.4), T2(1, 16), Resources{
            {5,    XyniumAlloy},
            {1500, Wraith}
    });

    /* ######################################################################################################################### */

    Item CopperWire("Copper Wire", 0, K_(10), T1(1), Resources{
            {5, CopperBar},
    });

    Item IronNails("Iron Nails", K_(20), K_(20), T1(2), Resources{
            {5, IronBar},
    });

    Item Battery("Battery", K_(50), K_(70), T1(4), Resources{
            {2,  CopperWire},
            {10, CopperBar},
    });

    Item Hammer("Hammer", K_(100), K_(135), T1(8), Resources{
            {2, IronNails},
            {5, LeadBar},
    });

    Item Glass("Glass", K_(200), K_(220), T1(12), Resources{
            {10, SiliconBar},
    });

    Item Circuit("Circuit", K_(400), K_(620), T1(20), Resources{
            {5,  SiliconBar},
            {5,  AluminumBar},
            {10, CopperWire},
    });

    Item Lens("Lens", M_(1), M_(1.1), T1(40), Resources{
            {1, Glass},
            {5, SilverBar},
    });

    Item Laser("Laser", M_(2), M_(3.2), T2(1, 0), Resources{
            {5,  GoldBar},
            {1,  Lens},
            {10, IronBar},
    });

    Item BasicComputer("Basic Computer", M_(5), M_(7.6), T2(1, 20), Resources{
            {5, Circuit},
            {5, SilverBar},
    });

    Item SolarPanel("Solar Panel", M_(10), M_(12.5), T2(1, 40), Resources{
            {5,  Circuit},
            {10, Glass},
    });

    Item LaserTorch("Laser Torch", M_(20), M_(31), T2(2, 0), Resources{
            {5, BronzeBar},
            {2, Laser},
            {5, Lens},
    });

    Item AdvancedBattery("Advanced Battery", M_(30), M_(35), T2(2, 30), Resources{
            {20, SteelBar},
            {30, Battery},
    });

    Item ThermalScanner("Thermal Scanner", M_(50), M_(71.5), T2(3, 0), Resources{
            {5, PlatinumBar},
            {2, Laser},
            {5, Glass},
    });

    Item AdvancedComputer("Advanced Computer", M_(120), M_(180), T2(3, 30), Resources{
            {5, TitaniumBar},
            {5, BasicComputer},
    });

    Item NavigationModule("Navigation Module", M_(250), B_(1), T2(3, 45), Resources{
            {2, LaserTorch},
            {1, ThermalScanner},
    });

    Item PlasmaTorch("Plasma Torch", M_(550), B_(1.15), T2(4, 10), Resources{
            {15, IridiumBar},
            {5,  LaserTorch},
    });

    Item RadioTower("Radio Tower", B_(1.5), B_(1.45), T2(4, 20), Resources{
            {75,  PlatinumBar},
            {150, AluminumBar},
            {50,  TitaniumBar},
    });

    Item Telescope("Telescope", B_(5), B_(2.7), T2(4, 40), Resources{
            {20, Lens},
            {1,  AdvancedComputer},
    });

    Item SatelliteDish("Satellite Dish", B_(17.5), B_(3.4), T2(5, 0), Resources{
            {150, SteelBar},
            {30,  PlatinumBar},
    });

    Item Motor("Motor", B_(60), B_(7), T2(5, 20), Resources{
            {500, BronzeBar},
            {200, Hammer},
    });

    Item Accumulator("Accumulator", B_(100), B_(12), T2(5, 40), Resources{
            {20, OsmiumBar},
            {3,  AdvancedBattery},
    });

    Item NuclearCapsule("Nuclear Capsule", B_(200), B_(26), T2(5, 50), Resources{
            {5, RhodiumBar},
            {1, PlasmaTorch},
    });

    Item WindTurbine("Wind Turbine", B_(500), B_(140), T2(6, 0), Resources{
            {120, AluminumBar},
            {1,   Motor},
    });

    Item SpaceProbe("Space Probe", T_(1), B_(180), T2(6, 10), Resources{
            {1,  SatelliteDish},
            {25, SolarPanel},
            {1,  Telescope},
    });

    Item NuclearReactor("Nuclear Reactor", T_(2), T_(1), T2(6, 20), Resources{
            {30, IridiumBar},
            {1,  NuclearCapsule},
    });

    Item Collider("Collider", T_(3), T_(2), T2(6, 25), Resources{
            {500, InertonAlloy},
            {100, QuadiumAlloy},
    });

    Item GravityChamber("Gravity Chamber", T_(6), T_(15), T2(6, 45), Resources{
            {60, AdvancedComputer},
            {1,  NuclearReactor},
    });

    Item Robot("Robot", T_(15), T_(50), T2(7, 12), Resources{
            {300, ScrithAlloy},
            {90,  Accumulator},
    });

    Item FusionCapsule("Fusion Capsule", T_(75), T_(240), T2(7, 30), Resources{
            {200, UruAlloy},
            {100, VibraniumAlloy},
            {100, NuclearCapsule},
    });

    Item Teleporter("Teleporter", T_(500), q_(1.8), T2(8, 02), Resources{
            {250, NavigationModule},
            {1,   GravityChamber},
    });

    Item FusionReactor("Fusion Reactor", q_(2.5), q_(40), T2(8, 36), Resources{
            {40, Collider},
            {50, NuclearCapsule},
            {1,  FusionCapsule},
    });

    Item SubspaceRelay("Subspace Relay", q_(15), Q_(1), T2(8, 58), Resources{
            {70,  SpaceProbe},
            {100, SatelliteDish},
            {3,   Teleporter},
    });
    Item AdvancedRobot("Advanced Robot", q_(142), Q_(29.5), T2(17, 22), Resources{
            {200, Robot},
            {5,   FusionReactor},
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
            {12, ViteriumAlloy},
    });

    Project Telescope20("Telescope 20", Resources{
            {5,  Collider},
            {15, XyniumAlloy},
    });

    Project Telescope21("Telescope 21", Resources{
            {5,  GravityChamber},
            {20, QuoliumAlloy},
    });

    Project Telescope22("Telescope 22", Resources{
            {6,  Robot},
            {24, LiteriumAlloy},
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

    Project SeniorLeader("SeniorLeader", Resources{
            {10, Robot},
    });

    Project AsteroidAutoMiner("Asteroid Auto Miner", Resources{
            {20,  AdvancedComputer},
            {100, SolarPanel},
    });

    Project AsteroidScanner("Asteroid Scanner", Resources{
            {30, ThermalScanner},
            {5,  NavigationModule},
    });

    Project AdvancedAsteroidScanner("Advanced Asteroid Scanner", Resources{
            {150, Telescope},
    });

    Project AdvancedAsteroidHarvester("Advanced Asteroid Harvester", Resources{
            {1,  SpaceProbe},
            {50, PlasmaTorch},
    });

    Project SuperiorAsteroidHarvester("Superior Asteroid Harvester", Resources{
            {10,  NuclearReactor},
            {300, ScrithAlloy},
            {600, InertonAlloy},
    });

    Project DebrisScanner("Debris Scanner", Resources{
            {1, Collider},
            {8, GravityChamber},
    });

    Project AdvancedLeader("Advanced Leader", Resources{
            {10,  Motor},
            {10,  Telescope},
            {200, ScrithAlloy},
    });

    Project FurnaceOverdrive3("Furnace Overdrive 3", Resources{
            {300, AetherAlloy},
            {100, PlasmaTorch},
            {2,   FusionCapsule},
    });

    std::map<const Resource *, uint32_t> have;
//    have[&CopperWire]=M_(4.43);
//    have[&IronNails] = M_(1.24);
    have[&Battery] = K_(56);
//    have[&Hammer] = K_(331.58);
//    have[&Glass] = K_(811);
    have[&Circuit] = K_(4.56);
    //have[&Lens] = 76;
//    have[&Laser] = K_(27.98);
    have[&BasicComputer] = K_(30);
    have[&SolarPanel] = K_(1);
    have[&LaserTorch] = K_(2.11);
    have[&AdvancedBattery] = K_(30);
    //have[&ThermalScanner]=34;
    have[&AdvancedComputer] = 11;
    have[&NavigationModule] = 25;
    have[&PlasmaTorch] = 37;
//    have[&RadioTower]=4;
//    have[&Telescope]=330;
//    have[&SatelliteDish]=562;
//    have[&Motor]=855;
    have[&Accumulator] = 10;
    have[&NuclearCapsule] = 11;
//    have[&WindTurbine]=37;
//    have[&SpaceProbe]=22;
//    have[&NuclearReactor]=6;
//    have[&Collider]=0;
//    have[&GravityChamber]=1;
    have[&Robot] = 1;
//    have[&FusionCapsule]=1;
//    have[&SpaceProbe]=1;
//    have[&Teleporter]=1;
    have[&FusionReactor] = 1;

    Resources todo{
            {1, AdvancedRobot},
//        {2, Teleporter}
//        {1, SeniorLeader},
            //{1, FurnaceOverdrive3}
    };

    todo.Dump();
    std::cout << "=========================================" << std::endl;
    todo.DumpResources();
    std::cout << "=========================================" << std::endl;
    todo.DumpResources(have);
    Resource::DumpAll();
    return 0;
}
