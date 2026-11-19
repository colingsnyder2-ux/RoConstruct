// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-embedded /I{headers}/engine-world /I{headers}/../native-classes
// 0066ea90: forwarding thunk generated from its proven jump target (thunk_lane.py, no model)
#include "HumanoidState.cpp"
// INFERRED: 0066ea90 is a 5-byte jump to RBX::HUMAN::HumanoidState::~HumanoidState: the destructor of a derived class with nothing of its own to destroy; the class name is a placeholder.
struct __declspec(novtable) Thunk_0066ea90 : RBX::HUMAN::HumanoidState { ~Thunk_0066ea90(); };
Thunk_0066ea90::~Thunk_0066ea90() {}
