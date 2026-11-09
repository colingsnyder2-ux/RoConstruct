// roc 2012-06 00b21460  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b21460
//
// 00b21460  b96873e500           mov ecx, 0xe57368
// 00b21465  e9f6b2e4ff           jmp 0x96c760
// auto-matched from its assembly shape

struct T_func_00b21460 { void m(); };
extern T_func_00b21460 G1_func_00b21460;
void func_00b21460()
{
    G1_func_00b21460.m();
}
