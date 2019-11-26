#include "SlackTransport.hpp"

bool SlackTransport::send(std::string to, std::string content) {
    return isReceiverValid(to);
}

bool SlackTransport::isReceiverValid(std::string to) {
    for (auto c: to) {
        if (c == '@') {
            return false;
        }
    }
    return true;
}
