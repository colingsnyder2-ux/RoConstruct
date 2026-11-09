// roc 2012-06 00b13650  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13650
//
// 00b13650  b90807e200           mov ecx, 0xe20708
// 00b13655  e9e6c3d6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b13650 { void m(); };
extern T_func_00b13650 G1_func_00b13650;
void func_00b13650()
{
    G1_func_00b13650.m();
}
