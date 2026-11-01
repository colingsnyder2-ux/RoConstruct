// from server: 100% by EspClaude
// from server: 72% by EspClaude
// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_d769af775a0def3c.cpp

// Candidate translation unit (score above; library headers required).
#define _CPPUNWIND 1
#undef _RELEASEASSERT
#undef _DEBUG
#include <stdexcept>
#include "reflection/type.h"
#include <boost/shared_ptr.hpp>
namespace RBX {class Instance;namespace Reflection {class DescribedBase;}}
extern boost::shared_ptr<RBX::Reflection::DescribedBase> __cdecl convert(const boost::shared_ptr<RBX::Instance>&);
namespace RBX {namespace Reflection {
template<class T> struct ExeCounter { static int n; };
template<> boost::shared_ptr<DescribedBase>& Value::convert<boost::shared_ptr<DescribedBase> >(){
 typedef boost::shared_ptr<DescribedBase> Shared;
 typedef boost::shared_ptr<Instance> SourceShared;
 if(isType<void>()){value=Shared();++ExeCounter<Shared>::n;_type=&Type::singleton<Shared>();}
 if(isType<SourceShared>()){
  SourceShared* source=boost::any_cast<SourceShared>(&value);
  if(source)value=::convert(*source);else value=Shared();
  ++ExeCounter<Shared>::n;_type=&Type::singleton<Shared>();
 }
 Shared* result=boost::any_cast<Shared>(&value);
 if(!result)throw std::runtime_error("Unable to cast value to Object");
 return *result;
}
}}

