// roc 2012-06 00b1b410  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b410
//
// 00b1b410  b9108de400           mov ecx, 0xe48d10
// 00b1b415  e9060dc6ff           jmp 0x77c120
// auto-matched from its assembly shape

struct T_func_00b1b410 { void m(); };
extern T_func_00b1b410 G1_func_00b1b410;
void func_00b1b410()
{
    G1_func_00b1b410.m();
}
