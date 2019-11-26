#include <gtest/gtest.h>

#include <Message.hpp>

TEST(Message, test_get_message_content) {
    std::string message = "message content";
    EXPECT_EQ(message, Message(message).getMessage());
}

TEST(Message, test_message_is_html) {
    std::string message = "<html>message</html>";
    EXPECT_TRUE(Message(message).isHtml());
}

TEST(Message, test_message_is_not_html_when_no_start_html_tag_found) {
    std::string message = "message</html>";
    EXPECT_FALSE(Message(message).isHtml());
}

TEST(Message, test_message_is_not_html_when_no_end_html_tag_found) {
    std::string message = "<html>message";
    EXPECT_FALSE(Message(message).isHtml());
}

TEST(Message, test_message_is_not_html_end_tag_is_before_start) {
    std::string message = "</html>message<html>";
    EXPECT_FALSE(Message(message).isHtml());
}