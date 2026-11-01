// from server: 100% by EspClaude
// from server: 87% by EspClaude
// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_fec74b6c38faee85.cpp

// Candidate translation unit (score above; library headers required).
#include "reflection/reflection.h"
namespace RBX {namespace Reflection {struct Tuple:std::vector<Value> {}; template<class T> struct ExeCounter { static int n; }; template<class T> inline const T& exeCounted(const T& v) { ++ExeCounter<T>::n; return v; }}}
struct __multiple_inheritance Object;
struct Descriptor {char prefix[56];RBX::Reflection::Tuple (Object::*method)(double);void call(Object*,RBX::Reflection::Value&,RBX::Reflection::Value&) const;};
void Descriptor::call(Object* o,RBX::Reflection::Value& result,RBX::Reflection::Value& arg) const {result=RBX::Reflection::exeCounted((o->*method)(arg.convert<double>()));}
