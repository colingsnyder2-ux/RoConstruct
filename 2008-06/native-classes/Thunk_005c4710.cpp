// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS- /I{headers}/../native-classes
// 005c4710: forwarding thunk generated from its proven jump target (thunk_lane.py, no model)
#include "AppUnit5BC_2008Visit.cpp"
// INFERRED: 005c4710 is a 5-byte jump to RBX::FactoryProduct<class RBX::Visit,class RBX::Instance,RBX::sVisit>::~FactoryProduct<class RBX::Visit,class RBX::Instance,RBX::sVisit>: the destructor of a derived class with nothing of its own to destroy; the class name is a placeholder.
struct __declspec(novtable) Thunk_005c4710 : RBX::FactoryProduct<class RBX::Visit,class RBX::Instance,RBX::sVisit> { ~Thunk_005c4710(); };
Thunk_005c4710::~Thunk_005c4710() {}
