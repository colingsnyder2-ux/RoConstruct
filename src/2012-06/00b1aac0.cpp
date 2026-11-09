// roc 2012-06 00b1aac0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1aac0
//
// 00b1aac0  b91088e300           mov ecx, 0xe38810
// 00b1aac5  e966c9c2ff           jmp 0x747430
// auto-matched from its assembly shape

struct T_func_00b1aac0 { void m(); };
extern T_func_00b1aac0 G1_func_00b1aac0;
void func_00b1aac0()
{
    G1_func_00b1aac0.m();
}
