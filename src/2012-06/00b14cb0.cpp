// roc 2012-06 00b14cb0  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14cb0
//
// 00b14cb0  b9a896e200           mov ecx, 0xe296a8
// 00b14cb5  ff253c26b200         jmp dword ptr [0xb2263c]
// auto-matched from its assembly shape

struct __declspec(dllimport) T_func_00b14cb0 { void m(); };
extern T_func_00b14cb0 G1_func_00b14cb0;
void func_00b14cb0()
{
    G1_func_00b14cb0.m();
}
