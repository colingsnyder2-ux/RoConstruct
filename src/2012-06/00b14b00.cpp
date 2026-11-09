// roc 2012-06 00b14b00  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14b00
//
// 00b14b00  b9a87be200           mov ecx, 0xe27ba8
// 00b14b05  e966ae8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b14b00 { void m(); };
extern T_func_00b14b00 G1_func_00b14b00;
void func_00b14b00()
{
    G1_func_00b14b00.m();
}
