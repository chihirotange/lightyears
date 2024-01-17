#pragma once
#include <stdio.h>
#include <memory>
#include <unordered_map>
template<typename T>
using unique = std::unique_ptr<T>;

template<typename T>
using shared = std::shared_ptr<T>;

template<typename T>
using weak = std::weak_ptr<T>;

template<typename T>
using List = std::vector<T>;

template<typename key, typename value, typename hash = std::hash<key>>
using Map = std::map<key, value, hash>;

namespace AiEngine
{
    #define LOG(M, ...) printf(M "\n", __VA_ARGS__)
}