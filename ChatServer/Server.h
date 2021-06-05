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
	}
	void OnMessage(std::shared_ptr<Connection> client, Message& message) override {
		switch (message.header_.type_) {
		case MessageType::PING:
			break;
		case MessageType::TEXT:
			std::cout << message.Read<message_string>().data() << std::endl;
			break;
		default:
			throw std::runtime_error("Unknown type!\n");
			break;
		}
	}

public:
	void PingAll() {
		static Message m(MessageType::PING);

		bool del = false;
		for (auto& x : connections_) {
			if (!x->IsConnected()) {
				x.reset();
				del = true;
				continue;
			}
			x->Send(m);
			if (!x->IsConnected()) {
				x.reset();
				del = true;
			}
		}
		if (del) connections_.erase(connections_.begin(), std::remove(connections_.begin(), connections_.end(), nullptr));
	}
};

#endif