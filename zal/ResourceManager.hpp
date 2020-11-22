#pragma once

#include "./include/Resource.hpp"
#include <iostream>
using namespace std;

class ResourceManager
{
    Resource* res;
public:
    ResourceManager() {
        cout << "default constructor\n";
        this->res = new Resource{};
    }
    ResourceManager(ResourceManager&obj) {
        cout << "copy constructor";
    }
    ResourceManager& operator=(const ResourceManager&) {
        cout << "copy assignment operator";
        return *this;
    }
    ResourceManager(ResourceManager&&) {
        cout << "move constructor";
    }
    ResourceManager& operator=(const ResourceManager&&) {
        cout << "move assignment operator";
        return *this;
    }
    ~ResourceManager() {
        cout << "denstructor";
        delete res;
    }
    double get()
    { return res->get();
    }
};
