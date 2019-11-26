#include <gtest/gtest.h>

#include "Transport/SlackTransport.hpp"

TEST(SlackTransport, test_send_message_to_valid_identifier) {
    std::string email = "my-receiver";

    SlackTransport transport;
    EXPECT_TRUE(transport.send(email, "message"));
}

TEST(SlackTransport, test_send_message_to_an_email) {
    std::string email = "my@example.com";

    SlackTransport transport;
    EXPECT_FALSE(transport.send(email, "message"));
}