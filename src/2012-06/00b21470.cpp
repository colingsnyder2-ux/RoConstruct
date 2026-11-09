// roc 2012-06 00b21470  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b21470
//
// 00b21470  b9b872e500           mov ecx, 0xe572b8
// 00b21475  e9d6aee4ff           jmp 0x96c350
// auto-matched from its assembly shape

struct T_func_00b21470 { void m(); };
extern T_func_00b21470 G1_func_00b21470;
void func_00b21470()
{
    G1_func_00b21470.m();
}
