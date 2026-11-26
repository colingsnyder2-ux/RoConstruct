// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 Instance Lua function descriptors (file statics of v8tree/Instance.cpp).
// Initializers (each: push security 0 / push name / push 0, push <member fn> (8-byte member pointer: Instance has
// several bases) / mov ecx, <object> / call BoundFuncDesc ctor / atexit):
//   007f2910 FindFirstChild("name", "recursive", default false) -> 00973f80
//   007f2940 Clone -> 00973cd8      007f2970 Remove -> 00973ec8
//   007f29a0 children -> 00973f08   007f29d0 GetChildren -> 00973db8   (both 005580e0)
//   007f2a00 IsDescendantOf("ancestor") 00557890 -> 00973df8
//   007f2a30 IsAncestorOf("descendant") 00557640 -> 00973d70
// Strings from the original .rdata; donor tools/rbxgs Client/App/v8tree/Instance.cpp lines 15-21 declare the same
// statics (its 2013 spelling "IsDescendentOf" / "descendent" differs from the 2008-06 literals used here).
#include "v8tree/Instance.h"
#include "reflection/function.h"
#include <vector>

namespace RBX
{
	static Reflection::BoundFuncDesc<Instance, boost::shared_ptr<Instance>(std::string, bool), 2> func_findFirstChild(&Instance::findFirstChildByName2, "FindFirstChild", "name", "recursive", false, static_cast<Reflection::FunctionDescriptor::Security>(0));
	static Reflection::BoundFuncDesc<Instance, boost::shared_ptr<Instance>(), 0> func_clone(&Instance::clone, "Clone", static_cast<Reflection::FunctionDescriptor::Security>(0));
	static Reflection::BoundFuncDesc<Instance, void(), 0> func_remove(&Instance::remove, "Remove", static_cast<Reflection::FunctionDescriptor::Security>(0));
	static Reflection::BoundFuncDesc<Instance, boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > >(), 0> func_childrenOld(&Instance::getChildren2, "children", static_cast<Reflection::FunctionDescriptor::Security>(0));
	static Reflection::BoundFuncDesc<Instance, boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > >(), 0> func_children(&Instance::getChildren2, "GetChildren", static_cast<Reflection::FunctionDescriptor::Security>(0));
	static Reflection::BoundFuncDesc<Instance, bool(boost::shared_ptr<Instance>), 1> func_isDescendantOf(&Instance::isDescendentOf2, "IsDescendantOf", "ancestor", static_cast<Reflection::FunctionDescriptor::Security>(0));
	static Reflection::BoundFuncDesc<Instance, bool(boost::shared_ptr<Instance>), 1> func_isAncestorOf(&Instance::isAncestorOf2, "IsAncestorOf", "descendant", static_cast<Reflection::FunctionDescriptor::Security>(0));
}
