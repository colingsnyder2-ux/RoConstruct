// roc 2012-06 00b147d0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b147d0
//
// 00b147d0  b9984ee200           mov ecx, 0xe24e98
// 00b147d5  e946aea6ff           jmp 0x57f620
// auto-matched from its assembly shape

struct T_func_00b147d0 { void m(); };
extern T_func_00b147d0 G1_func_00b147d0;
void func_00b147d0()
{
    G1_func_00b147d0.m();
}
