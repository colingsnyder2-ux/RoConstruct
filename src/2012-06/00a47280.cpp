// roc 2012-06 00a47280  unit: CXTPDockingPaneContext  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a47280
//
// 00a47280  c701342ac200         mov dword ptr [ecx], 0xc22a34
// 00a47286  e9f5e3a0ff           jmp 0x455680
// auto-matched from its assembly shape

struct B_func_00a47280 { virtual ~B_func_00a47280(); };
struct S_func_00a47280 : B_func_00a47280 { ~S_func_00a47280(); };
S_func_00a47280::~S_func_00a47280()
{
}
