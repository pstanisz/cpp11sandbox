#pragma once

#include <stdio.h>
#include <iostream>
#include <memory>
#include <mutex>
#include <thread>

using namespace std;

class Interface
{
public:
    virtual void interfaceFun() = 0;
};

class ThreadSafeSingleton : public Interface
{
    ThreadSafeSingleton();
    ThreadSafeSingleton(const ThreadSafeSingleton &)=delete;
    ThreadSafeSingleton& operator=(const ThreadSafeSingleton &)=delete;

public:
    static ThreadSafeSingleton &getInstance();
    virtual ~ThreadSafeSingleton();
    void interfaceFun();
};
