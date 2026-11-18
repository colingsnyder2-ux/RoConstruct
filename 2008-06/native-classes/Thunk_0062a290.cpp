// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../native-classes
// 0062a290: forwarding thunk generated from its proven jump target (thunk_lane.py, no model)
#include "Explosion.cpp"
// INFERRED: 0062a290 is a 5-byte jump to RBX::FactoryProduct<class RBX::Explosion,class RBX::Instance,RBX::sExplosion>::~FactoryProduct<class RBX::Explosion,class RBX::Instance,RBX::sExplosion>: the destructor of a derived class with nothing of its own to destroy; the class name is a placeholder.
struct __declspec(novtable) Thunk_0062a290 : RBX::FactoryProduct<class RBX::Explosion,class RBX::Instance,RBX::sExplosion> { ~Thunk_0062a290(); };
Thunk_0062a290::~Thunk_0062a290() {}
