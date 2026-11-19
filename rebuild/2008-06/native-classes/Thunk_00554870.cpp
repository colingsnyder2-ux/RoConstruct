// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/std-noinline-string /I{headers}/runservice-events /I{headers}/../native-classes
// 00554870: forwarding thunk generated from its proven jump target (thunk_lane.py, no model)
#include "RunService.cpp"
// INFERRED: 00554870 is a 5-byte jump to RBX::FactoryProduct<class RBX::RunService,class RBX::Instance,RBX::sRunService>::~FactoryProduct<class RBX::RunService,class RBX::Instance,RBX::sRunService>: the destructor of a derived class with nothing of its own to destroy; the class name is a placeholder.
struct __declspec(novtable) Thunk_00554870 : RBX::FactoryProduct<class RBX::RunService,class RBX::Instance,RBX::sRunService> { ~Thunk_00554870(); };
Thunk_00554870::~Thunk_00554870() {}
