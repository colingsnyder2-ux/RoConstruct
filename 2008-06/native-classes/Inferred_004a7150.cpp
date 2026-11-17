// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 004a7150: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "reflection/property.h"
#include "v8tree/Instance.h"
#include "Network/IdSerializer.h"
#include "util/Name.h"

namespace RBX {
namespace Network {

void StringReceiver::deserializeString(Reflection::Property& property, RakNet::BitStream& bitStream)
{
	std::string value;
	receive(bitStream, value);

	if (property.getInstance())
	{
		Instance* instance = static_cast<Instance*>(property.getInstance());
		const Reflection::PropertyDescriptor& desc = property.getDescriptor();
		desc.setStringValue(instance, value);
	}
}

}
}
