// roc 2012-06 00b147b0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b147b0
//
// 00b147b0  b9844ee200           mov ecx, 0xe24e84
// 00b147b5  e986b6a6ff           jmp 0x57fe40
// auto-matched from its assembly shape

struct T_func_00b147b0 { void m(); };
extern T_func_00b147b0 G1_func_00b147b0;
void func_00b147b0()
{
    G1_func_00b147b0.m();
}
