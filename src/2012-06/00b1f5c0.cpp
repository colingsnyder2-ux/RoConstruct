// roc 2012-06 00b1f5c0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f5c0
//
// 00b1f5c0  b9ec27e500           mov ecx, 0xe527ec
// 00b1f5c5  e92629a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1f5c0 { void m(); };
extern T_func_00b1f5c0 G1_func_00b1f5c0;
void func_00b1f5c0()
{
    G1_func_00b1f5c0.m();
}
