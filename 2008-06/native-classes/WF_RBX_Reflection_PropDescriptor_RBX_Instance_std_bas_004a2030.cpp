// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <memory>
#include <string>
#include "v8tree/Instance.h"

// Only getset is instantiated explicitly. GetImpl's vtable, getValue and
// isReadOnly are then instantiated implicitly through getset's `new GetImpl`.
// NEEDS-DECL: template<class Getter> static std::auto_ptr<TypedPropertyDescriptor<std::string>::GetSet> getset(Getter getter, int dummy);

template std::auto_ptr<RBX::Reflection::TypedPropertyDescriptor<std::string>::GetSet>
RBX::Reflection::PropDescriptor<RBX::Instance, std::string>::getset<std::string (RBX::Instance::*)() const>(
    std::string (RBX::Instance::*)() const, int);
