// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../native-classes
// 00590020: forwarding thunk generated from its proven jump target (thunk_lane.py, no model)
#include "AppUnit57C_2008ModelInstance.cpp"
// INFERRED: 00590020 is a 5-byte jump to RBX::ModelInstance::~ModelInstance: the destructor of a derived class with nothing of its own to destroy; the class name is a placeholder.
struct __declspec(novtable) Thunk_00590020 : RBX::ModelInstance { ~Thunk_00590020(); };
Thunk_00590020::~Thunk_00590020() {}
