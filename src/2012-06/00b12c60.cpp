// roc 2012-06 00b12c60  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12c60
//
// 00b12c60  b9ecdce100           mov ecx, 0xe1dcec
// 00b12c65  e9762a9fff           jmp 0x5056e0
// auto-matched from its assembly shape

struct T_func_00b12c60 { void m(); };
extern T_func_00b12c60 G1_func_00b12c60;
void func_00b12c60()
{
    G1_func_00b12c60.m();
}
