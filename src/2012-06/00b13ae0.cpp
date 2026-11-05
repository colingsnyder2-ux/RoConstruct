// roc 2012-06 00b13ae0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13ae0
//
// 00b13ae0  b9c822e200           mov ecx, 0xe222c8
// 00b13ae5  e956bfd6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b13ae0 { void m(); };
extern T_func_00b13ae0 G1_func_00b13ae0;
void func_00b13ae0()
{
    G1_func_00b13ae0.m();
}
