// roc 2012-06 00b14810  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14810
//
// 00b14810  b97c4ee200           mov ecx, 0xe24e7c
// 00b14815  e9c69aa6ff           jmp 0x57e2e0
// auto-matched from its assembly shape

struct T_func_00b14810 { void m(); };
extern T_func_00b14810 G1_func_00b14810;
void func_00b14810()
{
    G1_func_00b14810.m();
}
