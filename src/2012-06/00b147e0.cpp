// roc 2012-06 00b147e0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b147e0
//
// 00b147e0  b9744ee200           mov ecx, 0xe24e74
// 00b147e5  e966a9a6ff           jmp 0x57f150
// auto-matched from its assembly shape

struct T_func_00b147e0 { void m(); };
extern T_func_00b147e0 G1_func_00b147e0;
void func_00b147e0()
{
    G1_func_00b147e0.m();
}
