#pragma once

#include <string>

class Message {

public:

    explicit Message(std::string message);

    std::string getMessage() const;
    bool isHtml() const;

private:

    std::string message;

};


