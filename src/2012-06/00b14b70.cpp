// roc 2012-06 00b14b70  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14b70
//
// 00b14b70  b90082e200           mov ecx, 0xe28200
// 00b14b75  e9f6ad8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b14b70 { void m(); };
extern T_func_00b14b70 G1_func_00b14b70;
void func_00b14b70()
{
    G1_func_00b14b70.m();
}
