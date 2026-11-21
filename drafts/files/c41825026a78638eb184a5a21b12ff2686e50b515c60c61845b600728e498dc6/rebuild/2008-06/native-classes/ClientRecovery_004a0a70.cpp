// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// 2008-06 native RBX::Network::Client::connect 004a0a70 (inactive). The Client unit is NetworkClientServer2008Client.cpp;
// this body is kept in its own unit. Declaration in native-headers/Network/Client2008.h. Shape after the donor
// tools/rbxgs Client/Network/Client.cpp Client::connect and the server-verified mined analog src/2008-06/004a0a70.cpp;
// callees read from the target: operator!=(string, const char*) "localhost" 0082316c, find_first_of("192.168", 0, 7)
// 00823164, Security::Context::current 00493760 / requirePermission 00489810 (" connect to an extranet game" 00823144),
// SocketDescriptor(unsigned short, const char*) 004a97e0, rakPeer slot 1 Startup / slot 9 Connect with API::version
// 00970b8c, runtime_error 00409d50, StandardOut::print "Connecting to %s:%d" 008230f4, updateNetworkSimulator 004ae950.
#include "Network/Client2008.h"
#include "Network/API.h"
#include "security/SecurityContext.h"
#include "util/standardout.h"
#include <stdexcept>

namespace RBX
{
	namespace Network
	{
		// 004a0a70
		void Client::connect(std::string server, int serverPort, int clientPort, int threadSleepTime)
		{
			if (server != "localhost" && server.find_first_of("192.168", 0, 7) != 0)
			{
				// INFERRED: the 2008 Security::Permissions value 4 (pushed as the permission argument of
				// requirePermission 00489810); the available SecurityContext.h only names None and Administrator.
				Security::Context::current().requirePermission((Security::Permissions)4, " connect to an extranet game");
			}

			SocketDescriptor socketDescriptor(clientPort, "");
			if (!rakPeer->Startup(1, threadSleepTime, &socketDescriptor, 1))
				throw std::runtime_error("Failed to start network client");

			if (!rakPeer->Connect(server.c_str(), serverPort, API::version.c_str(), (int)API::version.size(), 0))
				throw std::runtime_error("Failed to connect to server");

			StandardOut::singleton()->print(MESSAGE_INFO, "Connecting to %s:%d", server.c_str(), serverPort);

			updateNetworkSimulator();
		}
	}
}
