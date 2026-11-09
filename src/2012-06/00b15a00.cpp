// roc 2012-06 00b15a00  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15a00
//
// 00b15a00  b918a3e200           mov ecx, 0xe2a318
// 00b15a05  e936a0d6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b15a00 { void m(); };
extern T_func_00b15a00 G1_func_00b15a00;
void func_00b15a00()
{
    G1_func_00b15a00.m();
}
