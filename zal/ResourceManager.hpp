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
        this->res = obj.res;
    }
    ResourceManager& operator=(const ResourceManager&obj) {
        cout << "copy assignment operator";
        this->res = new Resource{*obj.cgetResource()};
        return *this;
    }
    ResourceManager& operator=(const ResourceManager&&obj) {
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
    Resource* cgetResource() const {
        return res;
    }
};
