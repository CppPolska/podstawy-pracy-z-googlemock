#pragma once

#include <string>

class AbstractTransport {

public:

    virtual bool send(std::string to, std::string content) = 0;
    virtual bool isReceiverValid(std::string receiver) = 0;

    virtual ~AbstractTransport();

};


