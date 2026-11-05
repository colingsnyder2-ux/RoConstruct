// roc 2012-06 00a23ce0  unit: CXTPRibbonBar  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a23ce0
//
// 00a23ce0  c701ccf5c100         mov dword ptr [ecx], 0xc1f5cc
// 00a23ce6  e981eff5ff           jmp 0x982c6c
// auto-matched from its assembly shape

struct B_func_00a23ce0 { virtual ~B_func_00a23ce0(); };
struct S_func_00a23ce0 : B_func_00a23ce0 { ~S_func_00a23ce0(); };
S_func_00a23ce0::~S_func_00a23ce0()
{
}
