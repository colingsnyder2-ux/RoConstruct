// roc 2012-06 00b18c60  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18c60
//
// 00b18c60  b9f875e300           mov ecx, 0xe375f8
// 00b18c65  e9066d8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b18c60 { void m(); };
extern T_func_00b18c60 G1_func_00b18c60;
void func_00b18c60()
{
    G1_func_00b18c60.m();
}
