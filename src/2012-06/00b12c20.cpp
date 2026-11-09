// roc 2012-06 00b12c20  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12c20
//
// 00b12c20  b908d9e100           mov ecx, 0xe1d908
// 00b12c25  e946cd8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b12c20 { void m(); };
extern T_func_00b12c20 G1_func_00b12c20;
void func_00b12c20()
{
    G1_func_00b12c20.m();
}
