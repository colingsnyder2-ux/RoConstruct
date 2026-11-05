// roc 2012-06 00acc2be  unit: seg_00ac0000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00acc2be
//
// 00acc2be  b94808e500           mov ecx, 0xe50848
// 00acc2c3  ff253c26b200         jmp dword ptr [0xb2263c]
// auto-matched from its assembly shape

struct __declspec(dllimport) T_func_00acc2be { void m(); };
extern T_func_00acc2be G1_func_00acc2be;
void func_00acc2be()
{
    G1_func_00acc2be.m();
}
