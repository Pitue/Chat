#include "../Chat.h"
#include "Client.h"
#include <cnl.h>

#define HOST "127.0.0.1"

int main(int argc, char** argv) {
	try {
		Client client;
		client.Connect(HOST, SERVER_PORT);

		Message msg(MessageType::PING),
			txt(MessageType::TEXT);
		const std::string str = "Hello World!";
		txt.WriteString(str);
		txt.Write(str.size());

		while (1) {	
			if (!client.IsConnected()) return 1;
			std::this_thread::sleep_for(std::chrono::seconds(5));
			client.Send(txt);
		}
	}
	catch (std::exception& ex) {
		std::cerr << ex.what() << std::endl;
		return 1;
	}
}
