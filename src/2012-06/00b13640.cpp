// roc 2012-06 00b13640  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13640
//
// 00b13640  b9a007e200           mov ecx, 0xe207a0
// 00b13645  e906c3bcff           jmp 0x6df950
// auto-matched from its assembly shape

struct T_func_00b13640 { void m(); };
extern T_func_00b13640 G1_func_00b13640;
void func_00b13640()
{
    G1_func_00b13640.m();
}
