// roc 2012-06 00b1b560  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b560
//
// 00b1b560  b99888e400           mov ecx, 0xe48898
// 00b1b565  e9c699c5ff           jmp 0x774f30
// auto-matched from its assembly shape

struct T_func_00b1b560 { void m(); };
extern T_func_00b1b560 G1_func_00b1b560;
void func_00b1b560()
{
    G1_func_00b1b560.m();
}
