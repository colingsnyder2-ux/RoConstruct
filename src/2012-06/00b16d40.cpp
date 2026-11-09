// roc 2012-06 00b16d40  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16d40
//
// 00b16d40  b980f6e200           mov ecx, 0xe2f680
// 00b16d45  e9f68cd6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b16d40 { void m(); };
extern T_func_00b16d40 G1_func_00b16d40;
void func_00b16d40()
{
    G1_func_00b16d40.m();
}
