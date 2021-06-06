#include "../Chat.h"
#include "Server.h"

#include <cnl.h>

#include <string_view>

constexpr unsigned int TICK_TIME = 5000;

int main(int argc, char** argv) {
	try {
		Server server;
		server.Start(asio::ip::tcp::endpoint(asio::ip::tcp::v4(), 30000));

		while (true) {
			server.HandleMessages();
			server.PingAll();
			std::this_thread::sleep_for(std::chrono::milliseconds(TICK_TIME));
		}
	}
	catch (std::exception& ex) {
		std::cerr << ex.what() << std::endl;
		return 1;
	}
	return 0;
}
