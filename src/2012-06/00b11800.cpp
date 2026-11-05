// roc 2012-06 00b11800  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11800
//
// 00b11800  b9a880e100           mov ecx, 0xe180a8
// 00b11805  ff253c26b200         jmp dword ptr [0xb2263c]
// auto-matched from its assembly shape

struct __declspec(dllimport) T_func_00b11800 { void m(); };
extern T_func_00b11800 G1_func_00b11800;
void func_00b11800()
{
    G1_func_00b11800.m();
}
