// roc 2012-06 00b16e70  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16e70
//
// 00b16e70  b9ec00e300           mov ecx, 0xe300ec
// 00b16e75  e9e67bbcff           jmp 0x6dea60
// auto-matched from its assembly shape

struct T_func_00b16e70 { void m(); };
extern T_func_00b16e70 G1_func_00b16e70;
void func_00b16e70()
{
    G1_func_00b16e70.m();
}
