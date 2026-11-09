// roc 2012-06 00a31b20  unit: CXTPDockingPaneBase  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a31b20
//
// 00a31b20  c7019006c200         mov dword ptr [ecx], 0xc20690
// 00a31b26  e9553ba2ff           jmp 0x455680
// auto-matched from its assembly shape

struct B_func_00a31b20 { virtual ~B_func_00a31b20(); };
struct S_func_00a31b20 : B_func_00a31b20 { ~S_func_00a31b20(); };
S_func_00a31b20::~S_func_00a31b20()
{
}
