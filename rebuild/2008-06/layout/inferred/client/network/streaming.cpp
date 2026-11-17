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
