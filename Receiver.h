#pragma once
#include <thread>
#include <string>

class Receiver
{
    std::thread t;

    void readMessages() const;

public:
    void Start();
    void Join();
};