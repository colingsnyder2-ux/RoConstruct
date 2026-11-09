// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_unit_68a0f9d1608548af.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#include "reflection/property.h"
#include "reflection/object.h"
#include "script/ThreadRef.h"
#include <typeinfo>
namespace RBX {namespace Reflection {
template<class T> T ConstProperty::getValue() const {
    const TypedPropertyDescriptor<T>* typed = dynamic_cast<const TypedPropertyDescriptor<T>*>(&getDescriptor());
    if (typed == NULL) throw std::bad_cast();
    return typed->getValue(getInstance());
}
template boost::shared_ptr<RBX::Reflection::DescribedBase> ConstProperty::getValue<boost::shared_ptr<RBX::Reflection::DescribedBase>>() const;
template RBX::Lua::FunctionRef ConstProperty::getValue<RBX::Lua::FunctionRef>() const;
template boost::shared_ptr<const std::vector<boost::shared_ptr<RBX::Instance> > > ConstProperty::getValue<boost::shared_ptr<const std::vector<boost::shared_ptr<RBX::Instance> > >>() const;
template std::string ConstProperty::getValue<std::string>() const;
template bool ConstProperty::getValue<bool>() const;
template int ConstProperty::getValue<int>() const;
template float ConstProperty::getValue<float>() const;
template double ConstProperty::getValue<double>() const;
}}
