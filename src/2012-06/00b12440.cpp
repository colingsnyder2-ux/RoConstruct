// roc 2012-06 00b12440  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12440
//
// 00b12440  b92090e100           mov ecx, 0xe19020
// 00b12445  e9463c95ff           jmp 0x466090
// auto-matched from its assembly shape

struct T_func_00b12440 { void m(); };
extern T_func_00b12440 G1_func_00b12440;
void func_00b12440()
{
    G1_func_00b12440.m();
}
