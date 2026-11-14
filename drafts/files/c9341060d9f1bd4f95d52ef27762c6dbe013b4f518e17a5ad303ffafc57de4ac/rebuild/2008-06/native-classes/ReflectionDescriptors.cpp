// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// 2008-06 native reflection descriptor leaves (inactive).
// Already defined inline in read-only headers, not repeated here:
//   EnumDescriptor::equalValue 00448300, EnumDescriptor::isValue 00448450 (reflection/enumconverter.h)
//   Name::empty 00496350 (util/Name.h)
#include "reflection/property.h"
#include "reflection/type.h"
#include "util/Guid.h"
#include <boost/thread/once.hpp>

namespace RBX
{
	namespace Reflection
	{
		// 0056be00 ?read@PropertyDescriptor@Reflection@RBX@@UBEXPAVDescribedBase@23@PBVXmlElement@@AAVIReferenceBinder@3@@Z
		// mov eax,[ecx]; jmp [eax+0x2c]: forwards to the private readValue slot.
		void PropertyDescriptor::read(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const
		{
			readValue(instance, element, binder);
		}

		// 00594b40 ?addArgument@SignatureDescriptor@Reflection@RBX@@QAEXABVName@3@ABVType@23@ABVValue@23@@Z
		// Builds an Item on the stack (Value copy clones the boost::any content through slot 2), list push_back
		// (_Buynode 00417f00, _Incsize 00682cc0), then destroys the temporary Item.
		void SignatureDescriptor::addArgument(const Name& name, const Type& type, const Value& defaultValue)
		{
			Item item = {&name, &type, defaultValue};
			arguments.push_back(item);
		}
	}
}

// Defined in Guid.cpp (external linkage there): the scope initialiser 005a8260 and its result 00976b64.
extern const RBX::Name* localScope;
void initLocalScope();

namespace RBX
{
	// 005a82e0 ?getLocalScope@Guid@RBX@@SAABVName@2@XZ
	// boost::call_once(initLocalScope 005a8260, flag 00976b6c); return *localScope 00976b64.
	// The registry names the flag as Guid::Guid's local static (?flag@?1???0Guid@RBX@@QAE@XZ@4JA): the original
	// most likely kept this function and the constructor in Guid.cpp sharing that once_flag.
	const Name& Guid::getLocalScope()
	{
		static boost::once_flag flag = BOOST_ONCE_INIT;
		boost::call_once(initLocalScope, flag);
		return *localScope;
	}
}
