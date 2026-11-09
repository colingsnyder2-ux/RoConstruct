// roc 2012-06 00b134d0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b134d0
//
// 00b134d0  b9ec14e200           mov ecx, 0xe214ec
// 00b134d5  e9c660a1ff           jmp 0x5295a0
// auto-matched from its assembly shape

struct T_func_00b134d0 { void m(); };
extern T_func_00b134d0 G1_func_00b134d0;
void func_00b134d0()
{
    G1_func_00b134d0.m();
}
