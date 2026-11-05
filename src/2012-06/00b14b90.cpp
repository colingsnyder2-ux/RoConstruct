// roc 2012-06 00b14b90  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14b90
//
// 00b14b90  b9307ee200           mov ecx, 0xe27e30
// 00b14b95  e9d6ad8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b14b90 { void m(); };
extern T_func_00b14b90 G1_func_00b14b90;
void func_00b14b90()
{
    G1_func_00b14b90.m();
}
