
#ifndef DRAFT_COMPONENT_CONTAINER_H
#define DRAFT_COMPONENT_CONTAINER_H

#include <array>
#include <tuple>
#include <memory>
#include "component.h"
#include "all_components/transform.h"
#include "all_components/script.h"
#include "all_components/draw.h"


class ComponentContainer final {
public:


    template <typename T>
    constexpr int get_index() {
        constexpr int i = std::tuple_size<ComponentsList>::value - 1;
        return get_index_impl<T, std::tuple_element_t<i, ComponentsList>, i>::value;
    }



    template<typename T>
    void add_component(std::shared_ptr<T> component) {
        map[get_index<T>()] = component;
    }



    template<typename T>
    std::shared_ptr<T> get_component() {
        return std::dynamic_pointer_cast<T> (map[get_index<T>()]);
    }

    void update_all(Object &object) {
        for(const auto &component : map) {
            component->update(object);
        }
    }

private:
    typedef std::tuple<

        Transform,
        Draw,
        Script


    > ComponentsList;


    std::array<std::shared_ptr<Component>, std::tuple_size<ComponentsList>::value> map{};
    template <typename T, typename U, int i >
    struct get_index_impl;

    template <typename T, int i>
    struct get_index_impl<T, T, i> {
        static const int value = i;
    };

    template <typename T, typename U, int i >
    struct get_index_impl {
        static const int value = get_index_impl<T, std::tuple_element_t <i - 1, ComponentsList>, i - 1>::value;
    };
};

#endif //DRAFT_COMPONENT_CONTAINER_H
