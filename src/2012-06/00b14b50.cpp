// roc 2012-06 00b14b50  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14b50
//
// 00b14b50  b9a47de200           mov ecx, 0xe27da4
// 00b14b55  e9d6eeabff           jmp 0x5d3a30
// auto-matched from its assembly shape

struct T_func_00b14b50 { void m(); };
extern T_func_00b14b50 G1_func_00b14b50;
void func_00b14b50()
{
    G1_func_00b14b50.m();
}
