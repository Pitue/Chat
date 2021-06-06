#ifndef __CHAT_CHAT_H__
#define __CHAT_CHAT_H__

#define SERVER_PORT 30000

#ifdef _WIN32
#define _WIN32_WINNT 0x0A00
#endif

#include <array>
#include <string>

#include <cstring>
#include <cstdint>

#include <asio.hpp>
#include <cnl.h>

enum class MessageType: uint_fast8_t {
	PING = 0,
	TEXT
};

typedef cnl::Message<MessageType> Message;

#endif