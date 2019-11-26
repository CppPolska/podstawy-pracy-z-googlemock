#pragma once

#include "AbstractTransport.hpp"

class SlackTransport : public AbstractTransport {

public:

    bool send(std::string to, std::string content) override;
    bool isReceiverValid(std::string to) override;
};


