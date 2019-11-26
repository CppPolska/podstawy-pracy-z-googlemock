#include "EmailTransport.hpp"

bool EmailTransport::send(std::string to, std::string content) {
    return isReceiverValid(to);

}

bool EmailTransport::isReceiverValid(std::string to) {
    bool atFound = false;
    bool dotFound = false;

    for (auto c: to) {
        if (!atFound) {
            if (c == '@') {
                atFound = true;
            }
        } else if (!dotFound) {
            if (c == '.') {
                dotFound = true;
            }
        }
    }

    return atFound && dotFound;
}
