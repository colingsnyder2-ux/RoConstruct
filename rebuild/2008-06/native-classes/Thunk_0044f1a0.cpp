// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../native-classes
// 0044f1a0: forwarding thunk generated from its proven jump target (thunk_lane.py, no model)
#include "Verb.cpp"
// INFERRED: 0044f1a0 is a 5-byte jump to RBX::RunStateVerb::~RunStateVerb: the destructor of a derived class with nothing of its own to destroy; the class name is a placeholder.
struct __declspec(novtable) Thunk_0044f1a0 : RBX::RunStateVerb { ~Thunk_0044f1a0(); };
Thunk_0044f1a0::~Thunk_0044f1a0() {}
