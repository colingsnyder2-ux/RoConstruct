// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// 2008-06 native Reflection::Value::cast<T>() const instance for the child-list value (inactive). reflection/type.h
// defines the member template inline (return boost::any_cast<T>(value) on the any at +4); flags line copied from the
// reflection leaves unit ReflectionDescriptors.cpp.
// 005ab9e0 ??$cast@V?$shared_ptr@$$CBV?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@...@std@@@boost@@@Value@Reflection@RBX@@QBE?AV...@XZ
// (registry; single caller 005abec9 in the Lua bridge run 005ab240..005abf00, next to Value::operator=<std::string>
// 005ab9a0). Calls any_cast<shared_ptr<const vector<shared_ptr<Instance> > > >(const any&) 005ab240.
#include "reflection/type.h"
#include <boost/any.hpp>
#include <boost/shared_ptr.hpp>
#include <vector>

namespace RBX { class Instance; }

template boost::shared_ptr<const std::vector<boost::shared_ptr<RBX::Instance> > >
RBX::Reflection::Value::cast<boost::shared_ptr<const std::vector<boost::shared_ptr<RBX::Instance> > > >() const;
