#include <cnl.h>
#include "Client.h"
#include "../Chat.h"

#define HOST "127.0.0.1"

int main(int argc, char** argv) {
	try {
		Client client;
		client.Connect(HOST, SERVER_PORT);

		cnl::Message<MessageType> msg(MessageType::PING);

		while (1) {
			client.Send(msg);
			if (!client.IsConnected()) return 1;
			std::this_thread::sleep_for(std::chrono::seconds(5));
		}
	}
	catch (std::exception& ex) {
		std::cerr << ex.what() << std::endl;
		return 1;
	}
}
