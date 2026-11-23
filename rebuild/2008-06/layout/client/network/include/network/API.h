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
