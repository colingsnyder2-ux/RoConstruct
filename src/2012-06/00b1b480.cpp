// roc 2012-06 00b1b480  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b480
//
// 00b1b480  b9dc87e400           mov ecx, 0xe487dc
// 00b1b485  e9e6e9c5ff           jmp 0x779e70
// auto-matched from its assembly shape

struct T_func_00b1b480 { void m(); };
extern T_func_00b1b480 G1_func_00b1b480;
void func_00b1b480()
{
    G1_func_00b1b480.m();
}
