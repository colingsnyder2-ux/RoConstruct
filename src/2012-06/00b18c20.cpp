// roc 2012-06 00b18c20  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18c20
//
// 00b18c20  b96871e300           mov ecx, 0xe37168
// 00b18c25  e9466d8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b18c20 { void m(); };
extern T_func_00b18c20 G1_func_00b18c20;
void func_00b18c20()
{
    G1_func_00b18c20.m();
}
