// roc 2012-06 00b1ac60  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ac60
//
// 00b1ac60  b97872e400           mov ecx, 0xe47278
// 00b1ac65  e9064d8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1ac60 { void m(); };
extern T_func_00b1ac60 G1_func_00b1ac60;
void func_00b1ac60()
{
    G1_func_00b1ac60.m();
}
