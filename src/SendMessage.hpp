#pragma once

#include <memory>
#include <vector>
#include "Transport/AbstractTransport.hpp"
#include "Message.hpp"

class SendMessage {

public:

    explicit SendMessage(std::shared_ptr<AbstractTransport> transport);

    void addTo(std::string to);

    void send(Message message);
    void sendToValidReceivers(Message message);

private:

    std::shared_ptr<AbstractTransport> transport;
    std::vector<std::string> toList;

};
