// roc 2012-06 00b11890  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11890
//
// 00b11890  b90c82e100           mov ecx, 0xe1820c
// 00b11895  e9763e91ff           jmp 0x425710
// auto-matched from its assembly shape

struct T_func_00b11890 { void m(); };
extern T_func_00b11890 G1_func_00b11890;
void func_00b11890()
{
    G1_func_00b11890.m();
}
