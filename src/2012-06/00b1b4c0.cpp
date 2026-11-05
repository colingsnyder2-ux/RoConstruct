// roc 2012-06 00b1b4c0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b4c0
//
// 00b1b4c0  b9f08ae400           mov ecx, 0xe48af0
// 00b1b4c5  e966d6c5ff           jmp 0x778b30
// auto-matched from its assembly shape

struct T_func_00b1b4c0 { void m(); };
extern T_func_00b1b4c0 G1_func_00b1b4c0;
void func_00b1b4c0()
{
    G1_func_00b1b4c0.m();
}
