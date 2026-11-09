// roc 2012-06 00b175a0  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b175a0
//
// 00b175a0  b9081de300           mov ecx, 0xe31d08
// 00b175a5  ff253c26b200         jmp dword ptr [0xb2263c]
// auto-matched from its assembly shape

struct __declspec(dllimport) T_func_00b175a0 { void m(); };
extern T_func_00b175a0 G1_func_00b175a0;
void func_00b175a0()
{
    G1_func_00b175a0.m();
}
