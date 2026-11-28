// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 DataModel "get" / "GetObjects" function descriptors of the v8datamodel/DataModel.cpp object (inactive).
// Flags copied from 007f3530_httpgetinit.cpp (the HttpGet descriptor of the same object; 007f3530 follows these two).
//
// 007f3470 ??__EgetContentFunctionOld@RBX@@YAXXZ (43 B) and 007f34a0 ??__EgetContentFunction@RBX@@YAXXZ (43 B):
//   push 1 (AnyCaller) / push "url" 0080f08c / push "get" 00830448 (resp. "GetObjects" 0083044c) / push 0, push 00579f70
//   (8-byte member pointer: DataModel has multiple bases) / mov ecx, 009750c8 (resp. 00974f38) / call 00578fa0
//   (BoundFuncDesc<DataModel, shared_ptr<const Instances>(ContentId), 1> ctor; vtable 0083005c per
//   BoundFuncDescRecovery_00559cb0.cpp; the registry names the COMDAT-folded body after Lighting) /
//   atexit(007fd550 resp. 007fd4c0).
// Donor tools/rbxgs/Client/App/v8datamodel/DataModel.cpp lines 19-20 declare both statics with &DataModel::get,
// "url" and FunctionDescriptor::AnyCaller; 00579f70 is DataModel::get(ContentId) (donor DataModel.h line 69).
//
// The core native v8datamodel/DataModel.h now declares DataModel::get(ContentId) 00579f70 (after save), so the
// former DATAMODEL_HEADER_DECLARES_GET guard is dropped (batch 53).
#include "v8datamodel/DataModel.h"
#include "util/ContentProvider.h"
#include "reflection/reflection.h"
#include "v8xml/XmlSerializer.h"
#include "metadata-load/v8xml/SerializerV2.h"

namespace RBX {
	// 00579f70 DataModel::get(ContentId) (ret 0x24: hidden result + ContentId by value). Donor DataModel.cpp body; the
	// 2008-06 provider is `this ? getContentProvider() : 0` (0041eea0, as in save 00579c10), getContent 00561f20,
	// TextXmlParser ctor 00415350 / parse 0058f6c0 / dtor 004147c0, new vector (0x18), loadInstances 00593250.
	boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > DataModel::get(ContentId contentId)
	{
		std::auto_ptr<std::istream> stream = ServiceProvider::create<ContentProvider>(this)->getContent(contentId);

		TextXmlParser machine(stream->rdbuf());
		std::auto_ptr<XmlElement> root = machine.parse();

		boost::shared_ptr<std::vector<boost::shared_ptr<Instance> > > result(new std::vector<boost::shared_ptr<Instance> >);

		SerializerV2 serializer;
		serializer.loadInstances(root.get(), *result);

		return result;
	}

	// 007f3470
	static Reflection::BoundFuncDesc<DataModel, boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > >(ContentId), 1> getContentFunctionOld(&DataModel::get, "get", "url", Reflection::FunctionDescriptor::AnyCaller);
	// 007f34a0
	static Reflection::BoundFuncDesc<DataModel, boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > >(ContentId), 1> getContentFunction(&DataModel::get, "GetObjects", "url", Reflection::FunctionDescriptor::AnyCaller);
}
