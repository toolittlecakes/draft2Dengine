
#include "level1.h"
#include "../objects/dog.h"
#include "../objects/komet.h"

void Level1::init() {
    objects.emplace_back(std::make_unique<Player>(*this));
    objects.emplace_back(std::make_unique<Komet>(*this, Vec2{100, 200}));
//
//
////    objects.emplace_back(std::make_unique<Dog>(50.f, 600.f, Image(dir_name + "dog.png")));
////    objects.emplace_back(std::make_unique<Dog>(500.f, 300.f, Image(dir_name + "dog.png")));
////    objects.emplace_back(std::make_unique<Dog>(2000.f, 100.f, Image(dir_name + "dog.png")));
//
//
//    objects.emplace_back(std::make_unique<Komet>(100.f, 200.f, Image(dir_name + "komet.png")));
//
//    objects.emplace_back(std::make_unique<Komet>(700.f, 560.f, Image(dir_name + "komet.png")));
//
//    objects.emplace_back(std::make_unique<Komet>(900.f, 20.f, Image(dir_name + "komet.png")));
//
//    for (int i = 0 ; i < 100; i++ ) {
//        objects.emplace_back(std::make_unique<Komet>(rand() % 900 + 50.f, rand()%600 + 50, Image(dir_name + "molecule.png")));
//    }


}

bool Level1::is_finished() const {
    return false;

}

