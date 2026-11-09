// roc 2012-06 00b16370  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16370
//
// 00b16370  b990d9e200           mov ecx, 0xe2d990
// 00b16375  e9763cb9ff           jmp 0x6a9ff0
// auto-matched from its assembly shape

struct T_func_00b16370 { void m(); };
extern T_func_00b16370 G1_func_00b16370;
void func_00b16370()
{
    G1_func_00b16370.m();
}
