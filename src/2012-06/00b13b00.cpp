// roc 2012-06 00b13b00  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13b00
//
// 00b13b00  b9701be200           mov ecx, 0xe21b70
// 00b13b05  e966be8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b13b00 { void m(); };
extern T_func_00b13b00 G1_func_00b13b00;
void func_00b13b00()
{
    G1_func_00b13b00.m();
}
