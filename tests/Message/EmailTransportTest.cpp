#include <gtest/gtest.h>

#include "Transport/EmailTransport.hpp"

TEST(EmailTransport, test_send_message_to_valid_email) {
    std::string email = "my@example.com";

    EmailTransport transport;
    EXPECT_TRUE(transport.send(email, "message"));
}

TEST(EmailTransport, test_send_message_to_receiver_without_at) {
    std::string email = "example.com";

    EmailTransport transport;
    EXPECT_FALSE(transport.send(email, "message"));
}

TEST(EmailTransport, test_send_message_to_receiver_without_dot) {
    std::string email = "example@com";

    EmailTransport transport;
    EXPECT_FALSE(transport.send(email, "message"));
}