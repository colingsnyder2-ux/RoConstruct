// roc 2012-06 00b13c40  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13c40
//
// 00b13c40  b9f425e200           mov ecx, 0xe225f4
// 00b13c45  ff253c26b200         jmp dword ptr [0xb2263c]
// auto-matched from its assembly shape

struct __declspec(dllimport) T_func_00b13c40 { void m(); };
extern T_func_00b13c40 G1_func_00b13c40;
void func_00b13c40()
{
    G1_func_00b13c40.m();
}
