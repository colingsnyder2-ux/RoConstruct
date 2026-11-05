// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_reflectedstringbool67736eeac1209291.cpp

// Candidate translation unit (score above; library headers required).
#include "reflection/reflection.h"
struct __multiple_inheritance Object;
struct Descriptor {char prefix[56];std::string (Object::*method)(std::string,bool);void call(Object*,RBX::Reflection::Value&,RBX::Reflection::Value&,RBX::Reflection::Value&) const;};
void Descriptor::call(Object* o,RBX::Reflection::Value& result,RBX::Reflection::Value& a,RBX::Reflection::Value& b) const {result=(o->*method)(a.convert<std::string>(),b.convert<bool>());}
