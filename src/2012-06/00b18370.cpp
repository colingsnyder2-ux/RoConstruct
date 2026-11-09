// roc 2012-06 00b18370  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18370
//
// 00b18370  b9205ae300           mov ecx, 0xe35a20
// 00b18375  ff253c26b200         jmp dword ptr [0xb2263c]
// auto-matched from its assembly shape

struct __declspec(dllimport) T_func_00b18370 { void m(); };
extern T_func_00b18370 G1_func_00b18370;
void func_00b18370()
{
    G1_func_00b18370.m();
}
