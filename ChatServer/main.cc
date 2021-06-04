#include <cnl.h>
#include "Server.h"
#include "../Chat.h"

int main(int argc, char** argv) {
	try {
		Server server;
		server.Start(asio::ip::tcp::endpoint(asio::ip::tcp::v4(), 30000));

		while (true) {
			server.HandleMessages();
			//server.Update();
			std::this_thread::sleep_for(std::chrono::seconds(5));
		}
	}
	catch (std::exception& ex) {
		std::cerr << ex.what() << std::endl;
		return 1;
	}
	return 0;
}
