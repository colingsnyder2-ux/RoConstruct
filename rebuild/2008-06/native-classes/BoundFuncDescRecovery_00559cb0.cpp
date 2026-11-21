// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// 2008-06 BoundFuncDesc<RBX::Instance,boost::shared_ptr<RBX::Instance>(std::string,bool),2> ctor at 00559cb0 and
// BoundFuncDesc<RBX::DataModel,std::string(std::string,bool),2> ctor at 00579360 (both 177 bytes, ret 0x1c).
// Owner class + declarations recovered from the binary (vftable slots, RTTI, link order); ctor bodies are the
// // INFERRED: out-of-line definitions declared in reflection/reflection.h (never defined here).
// Explicit class instantiation emits the constructor; no hand-written bodies here.
#include "Network/Peer2008.h"
#include "reflection/reflection.h"
#include "v8tree/Instance.h"
#include "v8datamodel/DataModel.h"
#include "v8tree/Service.h"
#include "v8datamodel/ChangeHistoryService.h"
#include "v8datamodel/Selection.h"
#include "util/ContentProvider.h"
#include <boost/shared_ptr.hpp>
#include <string>

namespace RBX
{
	namespace Reflection
	{
		template class BoundFuncDesc<RBX::Instance, boost::shared_ptr<RBX::Instance>(std::string, bool), 2>;
		template class BoundFuncDesc<RBX::DataModel, std::string(std::string, bool), 2>;

		// 00572fa0 call<shared_ptr<Instance> > (177 B, ret 0xc) and 00573060 execute: the descriptor type of the donor
		// v8tree/Service.cpp statics ServiceProvider::func_service ("service") and func_GetService ("GetService"),
		// both bound to ServiceProvider::findServiceByClassNameString(std::string). Identity: registry decorated names
		// ??$call@...$?$BoundFuncDesc@VServiceProvider@RBX@@...$00@...ABEXPAVServiceProvider@2@AAVValue@12@1@Z and
		// ?execute@?$BoundFuncDesc@VServiceProvider@RBX@@...; both sit at the end of the Service.cpp object
		// (005726a0..00573130). 00572fa0 calls Value::convert<std::string> 0056f0b0, the member pointer at +0x38/+0x3c,
		// then Value::set<shared_ptr<Instance> > (Type::singleton 0056cae0, any assign 0048dd00).
		template class BoundFuncDesc<RBX::ServiceProvider, boost::shared_ptr<RBX::Instance>(std::string), 1>;

		// N=0 Instance descriptors: RTTI 00943fc0 BoundFuncDesc<Instance, shared_ptr<Instance>(), 0> and 00944030
		// BoundFuncDesc<Instance, void(), 0> (vtables 0082d7d0 / 0082d7dc). 0055a130 execute (84 B, beside 00559cb0 in
		// the Instance object) is the void() one. The shared_ptr<Instance>() execute/call bodies are byte-identical to
		// several registry candidates (0055a060 / 0055a200 and call 004b3fa0 / 00559fc0 / 005d6750): COMDAT-twin
		// identity, registry proposal only.
		template class BoundFuncDesc<RBX::Instance, boost::shared_ptr<RBX::Instance>(), 0>;
		template class BoundFuncDesc<RBX::Instance, void(), 0>;

		// N=1 descriptors whose 159-byte constructors the registry misnames as BoundFuncDesc<Lighting, void(double), 1>
		// (18 addresses share that one decorated name). Each constructor's vtable store names the real class through
		// its RTTI complete-object locator (vtable-4 -> type descriptor):
		//   004b4240 vtable 00824ccc .?AV?$BoundFuncDesc@VPeer@Network@RBX@@$$A6AX_N@Z$00@...
		//   0055a260 vtable 0082d7f4 BoundFuncDesc<Instance, bool(shared_ptr<Instance>), 1> (instantiated in
		//            BoundFuncDescCallTemplates2008.cpp / BoundFuncDescTemplates2008.cpp, not repeated here)
		//   00567fe0 vtable 0082eed4 BoundFuncDesc<Selection, void(shared_ptr<const Instances>), 1>
		//   00572f00 vtable 0082f810 BoundFuncDesc<ServiceProvider, shared_ptr<Instance>(std::string), 1> (above)
		//   00578fa0 vtable 0083005c BoundFuncDesc<DataModel, shared_ptr<const Instances>(ContentId), 1>
		//   005791d0 vtable 00830068 BoundFuncDesc<DataModel, void(ContentId), 1>
		//   005799f0 vtable 00830098 BoundFuncDesc<DataModel, void(std::string), 1>
		//   0058ad20 vtable 0083190c BoundFuncDesc<ChangeHistoryService, void(bool), 1>
		//   0058aea0 vtable 00831918 BoundFuncDesc<ChangeHistoryService, void(std::string), 1>
		// Each constructor calls its class's classDescriptor (Peer 0049ea10, Selection 005671a0, DataModel 005788c0,
		// ChangeHistoryService 0058a2a0) before FunctionDescriptor's constructor 00595790.
		template class BoundFuncDesc<RBX::Network::Peer, void(bool), 1>;
		template class BoundFuncDesc<RBX::Selection, void(boost::shared_ptr<const std::vector<boost::shared_ptr<RBX::Instance> > >), 1>;
		template class BoundFuncDesc<RBX::DataModel, boost::shared_ptr<const std::vector<boost::shared_ptr<RBX::Instance> > >(RBX::ContentId), 1>;
		template class BoundFuncDesc<RBX::DataModel, void(RBX::ContentId), 1>;
		template class BoundFuncDesc<RBX::DataModel, void(std::string), 1>;
		template class BoundFuncDesc<RBX::ChangeHistoryService, void(bool), 1>;
		template class BoundFuncDesc<RBX::ChangeHistoryService, void(std::string), 1>;
	}
}
