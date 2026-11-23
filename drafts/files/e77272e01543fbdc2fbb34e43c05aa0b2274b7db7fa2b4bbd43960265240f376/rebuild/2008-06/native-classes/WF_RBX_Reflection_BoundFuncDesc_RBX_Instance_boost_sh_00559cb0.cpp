// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// 2008-06 BoundFuncDesc<_, _, 2> constructors at 00559cb0 (RBX::Instance) and 00579360 (RBX::DataModel).
// C2995 showed reflection/reflection.h already defines the constructor body, so this file must not redefine it.
// The constructors are emitted by explicitly instantiating the two descriptor classes.
#include "reflection/reflection.h"
#include "v8tree/Instance.h"
#include "v8datamodel/DataModel.h"
#include <boost/shared_ptr.hpp>
#include <string>

namespace RBX
{
	namespace Reflection
	{
		template class BoundFuncDesc<RBX::Instance, boost::shared_ptr<RBX::Instance>(std::string, bool), 2>;
		template class BoundFuncDesc<RBX::DataModel, std::string(std::string, bool), 2>;
		// 00579990 execute (vtable 0083008c slot 1, RTTI .?AV?$BoundFuncDesc@VDataModel@RBX@@$$A6AXXZ$0A@@Reflection@RBX@@):
		// dynamic_cast<DataModel*> (type descriptor 0092e8a0) then the bound void() member call through +0x38/+0x3c.
		template class BoundFuncDesc<RBX::DataModel, void(), 0>;
	}
}
