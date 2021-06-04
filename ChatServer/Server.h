#ifndef __CHAT_SERVER_H__
#define  __CHAT_SERVER_H__

#include <memory>
#include <cnl.h>
#include "../Chat.h"

class Server : public cnl::BasicServer<MessageType> {
	bool OnClientConnect(std::shared_ptr<Connection> client) override {
		return true;
	}
	void OnClientDisconnect(std::shared_ptr<Connection> client) override {
		Message m(MessageType::TEXT);
		m.Write("Hallo!");
	}
	void OnMessage(std::shared_ptr<Connection> client, Message& message) override {
		switch (message.header_.type_) {
		case MessageType::PING:

			break;

		default:

			break;
		}
	}
};

#endif