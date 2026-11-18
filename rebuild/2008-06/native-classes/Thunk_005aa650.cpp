// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS- /I{headers}/../native-classes
// 005aa650: forwarding thunk generated from its proven jump target (thunk_lane.py, no model)
#include "ScriptContextLifetime.cpp"
// INFERRED: 005aa650 is a 5-byte jump to RBX::FactoryProduct<class RBX::ScriptContext,class RBX::Instance,RBX::sScriptContext>::~FactoryProduct<class RBX::ScriptContext,class RBX::Instance,RBX::sScriptContext>: the destructor of a derived class with nothing of its own to destroy; the class name is a placeholder.
struct __declspec(novtable) Thunk_005aa650 : RBX::FactoryProduct<class RBX::ScriptContext,class RBX::Instance,RBX::sScriptContext> { ~Thunk_005aa650(); };
Thunk_005aa650::~Thunk_005aa650() {}
