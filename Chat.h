#ifndef __CHAT_CHAT_H__
#define __CHAT_CHAT_H__

#define SERVER_PORT 30000

#include <cstdint>

enum class MessageType: uint_fast8_t {
	PING = 0,
	TEXT
};

#define message_string const char[256]

#endif