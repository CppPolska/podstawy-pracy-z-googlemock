#include "Message.hpp"

Message::Message(std::string message): message(std::move(message)) {

}

std::string Message::getMessage() const {
    return message;
}

bool Message::isHtml() const {
    auto startHtmlTagPos = message.find("<html>");
    if (startHtmlTagPos != std::string::npos) {
        auto endHtmlTagPos = message.find("</html>");
        return endHtmlTagPos != std::string::npos && endHtmlTagPos > startHtmlTagPos;
    }
    return false;
}
