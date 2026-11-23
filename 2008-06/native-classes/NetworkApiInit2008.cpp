// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native Network::API::init 0049ecf0 (inactive; the exe calls it nativeSetVersion from CRobloxApp::InitInstance).
// Evidence: assigns the std::string at 00970b88 (Network::API::version, see ScriptContextVersion.cpp) with
// basic_string::assign(const char*), then touches the class descriptors of Instance, Player, Players and NetworkSettings
// (0049eb30/0049eba0/00491360/0049a8a0/0049ec10/0049ec80, each a Described<>::classDescriptor local-static accessor)
// and finally the NetworkSettings singleton (0049e890: GlobalSettings lock, sing at 009706d0, create + setParent).
// INFERRED: call order and the duplicated Instance descriptor calls follow the disassembly; no original source.
#include "Network/API.h"
#include "Network/NetworkSettings.h"
#include "Network/Player.h"
#include "Network/Players.h"
#include "v8tree/Instance.h"

namespace RBX
{
	namespace Network
	{
		void API::init(const char* v)
		{
			version = v;
			Instance::classDescriptor();
			Instance::classDescriptor();
			Player::classDescriptor();
			Players::classDescriptor();
			Instance::classDescriptor();
			NetworkSettings::classDescriptor();
			NetworkSettings::singleton();
		}
	}
}
