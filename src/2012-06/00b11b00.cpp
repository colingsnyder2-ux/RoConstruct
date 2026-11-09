// roc 2012-06 00b11b00  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11b00
//
// 00b11b00  b95c89e100           mov ecx, 0xe1895c
// 00b11b05  e946da92ff           jmp 0x43f550
// auto-matched from its assembly shape

struct T_func_00b11b00 { void m(); };
extern T_func_00b11b00 G1_func_00b11b00;
void func_00b11b00()
{
    G1_func_00b11b00.m();
}
