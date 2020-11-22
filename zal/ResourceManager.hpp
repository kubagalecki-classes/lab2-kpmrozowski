#pragma once

#include "Resource.hpp"
#include <iostream>
using namespace std;

class ResourceManager
{
    // Twoja implementacja tutaj
    int we;
    Resource* res;

public:
    ResourceManager() {
        cout << "default constructor\n";
        this->res = new Resource{};
    }
    ResourceManager(ResourceManager&obj) {
        cout << "copy constructor";
        this->res = new Resource{*obj.getResource()};
    }
    ResourceManager(ResourceManager&& obj) {
        cout << "move constructor";
        this->res = obj.getResource();
        obj.res   = (std::nullptr_t) nullptr;
    }
    ResourceManager& operator=(ResourceManager&obj) {
        cout << "copy assignment operator";
        this->res = new Resource{*obj.getResource()};
        return *this;
    }
    ResourceManager& operator=(ResourceManager&&obj) {
        cout << "move assignment operator";
        this->res = obj.res;
        return *this;
    }
    ~ResourceManager() {
        cout << "denstructor";
        delete res;
    }
    double get() {
        return res->get();
    }
    Resource* getResource() {
        return res;
    }
};
