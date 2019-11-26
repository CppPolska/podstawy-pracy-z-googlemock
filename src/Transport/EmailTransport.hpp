#pragma once

#include "AbstractTransport.hpp"

class EmailTransport : public AbstractTransport {

public:

    bool send(std::string to, std::string content) override;

    bool isReceiverValid(std::string to) override;

};


