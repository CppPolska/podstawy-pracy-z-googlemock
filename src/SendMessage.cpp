#include "SendMessage.hpp"


SendMessage::SendMessage(std::shared_ptr<AbstractTransport> transport): transport(transport) {

}

void SendMessage::addTo(std::string to) {
    toList.push_back(to);
}

void SendMessage::send(Message message) {
    if (toList.empty()) {
        return;
    }

    for (auto &to: toList) {
        transport->send(message.getMessage(), to);
    }
}

void SendMessage::sendToValidReceivers(Message message) {
    if (toList.empty()) {
        return;
    }

    for (auto &to: toList) {
        if (transport->isReceiverValid(to)) {
            transport->send(message.getMessage(), to);
        }
    }
}
