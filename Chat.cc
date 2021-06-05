#include "Chat.h"

message_string ToMessageString(const std::string& str) {
	message_string t;
	if (str.size() > t.size()) {
		throw std::runtime_error("Given string is too long to be converted to message_string\n");
	}

	std::memcpy(t.data(), str.data(), str.size());
	return t;
}