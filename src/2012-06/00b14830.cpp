// roc 2012-06 00b14830  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14830
//
// 00b14830  b9784ee200           mov ecx, 0xe24e78
// 00b14835  e90691a6ff           jmp 0x57d940
// auto-matched from its assembly shape

struct T_func_00b14830 { void m(); };
extern T_func_00b14830 G1_func_00b14830;
void func_00b14830()
{
    G1_func_00b14830.m();
}
