// roc 2012-06 00b15900  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15900
//
// 00b15900  b988a4e200           mov ecx, 0xe2a488
// 00b15905  e966b8b6ff           jmp 0x681170
// auto-matched from its assembly shape

struct T_func_00b15900 { void m(); };
extern T_func_00b15900 G1_func_00b15900;
void func_00b15900()
{
    G1_func_00b15900.m();
}
