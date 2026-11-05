// roc 2012-06 00a792a0  unit: CXTWndHook  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a792a0
//
// 00a792a0  c7013498c200         mov dword ptr [ecx], 0xc29834
// 00a792a6  e9bb080200           jmp 0xa99b66
// auto-matched from its assembly shape

struct B_func_00a792a0 { virtual ~B_func_00a792a0(); };
struct S_func_00a792a0 : B_func_00a792a0 { ~S_func_00a792a0(); };
S_func_00a792a0::~S_func_00a792a0()
{
}
