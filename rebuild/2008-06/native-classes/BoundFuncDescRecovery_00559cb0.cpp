// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// 2008-06 BoundFuncDesc<RBX::Instance,boost::shared_ptr<RBX::Instance>(std::string,bool),2> ctor at 00559cb0 and
// BoundFuncDesc<RBX::DataModel,std::string(std::string,bool),2> ctor at 00579360 (both 177 bytes, ret 0x1c).
// Owner class + declarations recovered from the binary (vftable slots, RTTI, link order); ctor bodies are the
// // INFERRED: out-of-line definitions declared in reflection/reflection.h (never defined here).
// Explicit class instantiation emits the constructor; no hand-written bodies here.
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
	}
}
