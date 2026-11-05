// roc 2012-06 009862a0  unit: CPatchedControlComboBox  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009862a0
//
// 009862a0  c70130cec000         mov dword ptr [ecx], 0xc0ce30
// 009862a6  e905f4acff           jmp 0x4556b0
// auto-matched from its assembly shape

struct B_func_009862a0 { virtual ~B_func_009862a0(); };
struct S_func_009862a0 : B_func_009862a0 { ~S_func_009862a0(); };
S_func_009862a0::~S_func_009862a0()
{
}
