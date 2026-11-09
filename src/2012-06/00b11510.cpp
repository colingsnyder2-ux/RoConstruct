// roc 2012-06 00b11510  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11510
//
// 00b11510  b9b864e100           mov ecx, 0xe164b8
// 00b11515  e9f67e8fff           jmp 0x409410
// auto-matched from its assembly shape

struct T_func_00b11510 { void m(); };
extern T_func_00b11510 G1_func_00b11510;
void func_00b11510()
{
    G1_func_00b11510.m();
}
