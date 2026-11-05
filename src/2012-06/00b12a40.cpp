// roc 2012-06 00b12a40  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12a40
//
// 00b12a40  b928c3e100           mov ecx, 0xe1c328
// 00b12a45  ff253c26b200         jmp dword ptr [0xb2263c]
// auto-matched from its assembly shape

struct __declspec(dllimport) T_func_00b12a40 { void m(); };
extern T_func_00b12a40 G1_func_00b12a40;
void func_00b12a40()
{
    G1_func_00b12a40.m();
}
