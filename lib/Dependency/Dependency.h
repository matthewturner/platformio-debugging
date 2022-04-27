#ifndef Dependency_h
#define Dependency_h

#include <Arduino.h>

class Dependency
{
public:
    bool method();
    uint64_t time();
};

#endif