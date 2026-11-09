// roc 2012-06 00b1bd60  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1bd60
//
// 00b1bd60  b9c89de400           mov ecx, 0xe49dc8
// 00b1bd65  e98661a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1bd60 { void m(); };
extern T_func_00b1bd60 G1_func_00b1bd60;
void func_00b1bd60()
{
    G1_func_00b1bd60.m();
}
