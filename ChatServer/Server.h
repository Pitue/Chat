#ifndef __CHAT_SERVER_H__
#define  __CHAT_SERVER_H__

#include <memory>
#include <cnl.h>
#include "../Chat.h"

class Server : public cnl::BasicServer<MessageType> {
	bool OnClientConnect(Connection client) override {
		return true;
	}
	void OnClientDisconnect(Connection client) override {
	}
	void OnMessage(Connection client, Message& message) override {
		std::cout << "Handling message!\n";
		if (message.header_.type_ == MessageType::TEXT) {
			size_t l = message.Read<size_t>();
			unsigned char* str = new unsigned char[l];
			str = message.ReadString(l);
			std::cout << *client << ": " << str << std::endl;
		}
		else if (message.header_.type_ == MessageType::PING) {}
		else {
			throw std::runtime_error("Unknown message type!");
		}
	}

public:
	void PingAll() {
		static Message m(MessageType::PING);
		MessageAll(m);
		ClearDeadConnections();
	}
};

#endif