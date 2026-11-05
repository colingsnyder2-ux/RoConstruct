// roc 2012-06 00a16130  unit: CXTPHookManagerHookAble  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a16130
//
// 00a16130  c701c0d4c100         mov dword ptr [ecx], 0xc1d4c0
// 00a16136  e945f5a3ff           jmp 0x455680
// auto-matched from its assembly shape

struct B_func_00a16130 { virtual ~B_func_00a16130(); };
struct S_func_00a16130 : B_func_00a16130 { ~S_func_00a16130(); };
S_func_00a16130::~S_func_00a16130()
{
}
