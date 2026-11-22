// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// 2008-06 native RBX::Network::IdSerializer::trySerializeId (inactive), declared in Network/IdSerializer.h. The body
// belongs to the Network/Streaming.cpp unit (AppUnit49C_2008IdSerializerTemplates.cpp holds its neighbours); it has
// its own file here because that unit was not assigned to this batch. Flags copied from that unit.
#include "Network/IdSerializer.h"
#include "util/Name.h"
#include <BitStream.h>

namespace RBX
{
	namespace Network
	{
		// 004a8cc0 (donor tools/rbxgs/Client/Network/Streaming.cpp IdSerializer::trySerializeId). Evidence: thiscall,
		// ret 8; a NULL instance sends Name::getNullName() 00554270 (+4 name string) through scopeNames (+0x130)
		// StringSender::send 004a7e20 and returns true; otherwise GuidItem<Instance>::registerGuid 0049bba0 on the
		// instance, the Guid::Data copied inline from +8 / +0xc, StringSender::trySend 004a7ba0 with scope->name (+4),
		// false when it fails, else WriteBits 004a5600 (&id.index, 24, true) and true.
		bool IdSerializer::trySerializeId(RakNet::BitStream& stream, const Instance* instance)
		{
			if (instance)
			{
				// INFERRED: the 2008 getGuid() registers first (util/GuidItem.h proposal); registerGuid is non-const.
				const_cast<Instance*>(instance)->registerGuid();
				Guid::Data id;
				instance->getGuid().extract(id);

				if (!scopeNames.trySend(stream, id.scope->name))
					return false;

				stream.WriteBits((unsigned char*)&id.index, 24);
				return true;
			}
			else
			{
				scopeNames.send(stream, Name::getNullName().name);
				return true;
			}
		}
	}
}
