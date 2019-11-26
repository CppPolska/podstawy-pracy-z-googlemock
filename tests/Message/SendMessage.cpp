#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "SendMessage.hpp"
#include "Transport/AbstractTransport.hpp"

using ::testing::Return;

class MockTransport : public AbstractTransport {

public:

    MOCK_METHOD2(send, bool(std::string to, std::string content));
    MOCK_METHOD1(isReceiverValid, bool(std::string to));

};

TEST(SendMessage, test_sender_doesnt_send_message) {
    auto mockTransport = std::make_shared<MockTransport>();

    SendMessage sendMessage(mockTransport);
    Message message("message content");

    EXPECT_CALL(*mockTransport, send("asd", "asd"))
            .Times(0);

    sendMessage.send(message);
}

TEST(SendMessage, test_sender_really_sends_message) {
    auto mockTransport = std::make_shared<MockTransport>();

    SendMessage sendMessage(mockTransport);
    sendMessage.addTo("my@email.to");
    Message message("message content");

    EXPECT_CALL(*mockTransport, send("message content", "my@email.to"))
            .Times(1)
            .WillOnce(Return(true));

    sendMessage.send(message);
}

TEST(SendMessage, test_sender_sends_message_multiple_times) {
    auto mockTransport = std::make_shared<MockTransport>();

    SendMessage sendMessage(mockTransport);
    sendMessage.addTo("first@email.to");
    sendMessage.addTo("second@email.to");
    Message message("message content");

    EXPECT_CALL(*mockTransport, send("message content", "first@email.to"))
            .Times(1)
            .WillOnce(Return(true));

    EXPECT_CALL(*mockTransport, send("message content", "second@email.to"))
            .Times(1)
            .WillOnce(Return(true));

    sendMessage.send(message);
}

TEST(SendMessage, test_sender_returns_false_on_invalid_email) {
    auto mockTransport = std::make_shared<MockTransport>();

    SendMessage sendMessage(mockTransport);
    sendMessage.addTo("im-not-an-email");
    Message message("message content");

    EXPECT_CALL(*mockTransport, send("message content", "im-not-an-email"))
            .Times(1)
            .WillOnce(Return(false));

    sendMessage.send(message);
}

TEST(SendMessage, test_sender_sends_only_to_valid_receivers) {
    auto mockTransport = std::make_shared<MockTransport>();

    std::string invalidIdentifier = "im-not-valid-identifier";
    std::string validIdentifier = "im-valid-identifier";
    std::string messageContent = "message content";

    SendMessage sendMessage(mockTransport);
    sendMessage.addTo(invalidIdentifier);
    sendMessage.addTo(validIdentifier);

    Message message(messageContent);

    EXPECT_CALL(*mockTransport, isReceiverValid(invalidIdentifier))
            .Times(1)
            .WillOnce(Return(false));

    EXPECT_CALL(*mockTransport, send(messageContent, invalidIdentifier))
            .Times(0);

    EXPECT_CALL(*mockTransport, isReceiverValid(validIdentifier))
            .Times(1)
            .WillOnce(Return(true));

    EXPECT_CALL(*mockTransport, send(messageContent, validIdentifier))
            .Times(1)
            .WillOnce(Return(true));

    sendMessage.sendToValidReceivers(message);
}