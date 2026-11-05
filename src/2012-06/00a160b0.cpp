// roc 2012-06 00a160b0  unit: CXTPHookManagerHookAble  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a160b0
//
// 00a160b0  c701a8d4c100         mov dword ptr [ecx], 0xc1d4a8
// 00a160b6  e9f5f5a3ff           jmp 0x4556b0
// auto-matched from its assembly shape

struct B_func_00a160b0 { virtual ~B_func_00a160b0(); };
struct S_func_00a160b0 : B_func_00a160b0 { ~S_func_00a160b0(); };
S_func_00a160b0::~S_func_00a160b0()
{
}
