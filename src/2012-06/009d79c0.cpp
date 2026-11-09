// roc 2012-06 009d79c0  unit: CXTPPropExchange  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009d79c0
//
// 009d79c0  c701ac5fc100         mov dword ptr [ecx], 0xc15fac
// 009d79c6  e9a1b2faff           jmp 0x982c6c
// auto-matched from its assembly shape

struct B_func_009d79c0 { virtual ~B_func_009d79c0(); };
struct S_func_009d79c0 : B_func_009d79c0 { ~S_func_009d79c0(); };
S_func_009d79c0::~S_func_009d79c0()
{
}
