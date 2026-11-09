// roc 2012-06 00a31c20  unit: CXTPDockingPaneBase  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a31c20
//
// 00a31c20  c701c006c200         mov dword ptr [ecx], 0xc206c0
// 00a31c26  e9853aa2ff           jmp 0x4556b0
// auto-matched from its assembly shape

struct B_func_00a31c20 { virtual ~B_func_00a31c20(); };
struct S_func_00a31c20 : B_func_00a31c20 { ~S_func_00a31c20(); };
S_func_00a31c20::~S_func_00a31c20()
{
}
