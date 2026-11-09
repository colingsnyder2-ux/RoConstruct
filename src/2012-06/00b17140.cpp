// roc 2012-06 00b17140  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17140
//
// 00b17140  b99004e300           mov ecx, 0xe30490
// 00b17145  e926a0b6ff           jmp 0x681170
// auto-matched from its assembly shape

struct T_func_00b17140 { void m(); };
extern T_func_00b17140 G1_func_00b17140;
void func_00b17140()
{
    G1_func_00b17140.m();
}
