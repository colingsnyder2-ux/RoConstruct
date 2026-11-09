// roc 2012-06 00b14af0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14af0
//
// 00b14af0  b9c873e200           mov ecx, 0xe273c8
// 00b14af5  e976ae8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b14af0 { void m(); };
extern T_func_00b14af0 G1_func_00b14af0;
void func_00b14af0()
{
    G1_func_00b14af0.m();
}
