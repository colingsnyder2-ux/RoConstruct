// roc 2012-06 00b15b00  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15b00
//
// 00b15b00  b930aae200           mov ecx, 0xe2aa30
// 00b15b05  e9669e8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b15b00 { void m(); };
extern T_func_00b15b00 G1_func_00b15b00;
void func_00b15b00()
{
    G1_func_00b15b00.m();
}
