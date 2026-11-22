#pragma once
#include <string>

namespace RBX
{
	namespace Network
	{
		class API
		{
		public:
			static std::string version;

			static void init(const char* version);
		};
	}
}
// 2008-06 native header port of rbxgs Network/include/Network/API.h (2007 text). Kept only because every dependent exact native unit
// compiles to an identical object with it in native-headers (proof: work/donorfree-route/header_port_proof.json).
