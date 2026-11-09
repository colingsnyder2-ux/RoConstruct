// roc 2012-06 00b1b6d0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b6d0
//
// 00b1b6d0  b9f08ee400           mov ecx, 0xe48ef0
// 00b1b6d5  e91668a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1b6d0 { void m(); };
extern T_func_00b1b6d0 G1_func_00b1b6d0;
void func_00b1b6d0()
{
    G1_func_00b1b6d0.m();
}
