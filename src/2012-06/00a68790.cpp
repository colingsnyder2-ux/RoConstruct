// roc 2012-06 00a68790  unit: CXTShadowWnd  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a68790
//
// 00a68790  c7011c57c200         mov dword ptr [ecx], 0xc2571c
// 00a68796  e9e5ce9eff           jmp 0x455680
// auto-matched from its assembly shape

struct B_func_00a68790 { virtual ~B_func_00a68790(); };
struct S_func_00a68790 : B_func_00a68790 { ~S_func_00a68790(); };
S_func_00a68790::~S_func_00a68790()
{
}
