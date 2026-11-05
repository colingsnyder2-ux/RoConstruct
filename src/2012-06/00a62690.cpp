// roc 2012-06 00a62690  unit: CXTColorBase  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a62690
//
// 00a62690  c7010449c200         mov dword ptr [ecx], 0xc24904
// 00a62696  e925ffffff           jmp 0xa625c0
// auto-matched from its assembly shape

struct B_func_00a62690 { virtual ~B_func_00a62690(); };
struct S_func_00a62690 : B_func_00a62690 { ~S_func_00a62690(); };
S_func_00a62690::~S_func_00a62690()
{
}
