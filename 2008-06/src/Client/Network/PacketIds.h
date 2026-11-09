#include <MessageIdentifiers.h>

namespace RBX
{
	namespace Network
	{
		enum
		{
			ID_SET_GLOBALS = ID_USER_PACKET_ENUM,
			ID_REQUEST_CHARACTER,
			ID_DATA,
			ID_REQUEST_MARKER,
			ID_PHYSICS,
			ID_CHAT_ALL = 0x51,
			ID_REPORT_ABUSE = 0x52
		};
	}
}
