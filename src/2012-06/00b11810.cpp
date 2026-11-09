// roc 2012-06 00b11810  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11810
//
// 00b11810  b9c480e100           mov ecx, 0xe180c4
// 00b11815  ff253c26b200         jmp dword ptr [0xb2263c]
// auto-matched from its assembly shape

struct __declspec(dllimport) T_func_00b11810 { void m(); };
extern T_func_00b11810 G1_func_00b11810;
void func_00b11810()
{
    G1_func_00b11810.m();
}
