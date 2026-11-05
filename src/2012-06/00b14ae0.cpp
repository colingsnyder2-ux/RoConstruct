// roc 2012-06 00b14ae0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14ae0
//
// 00b14ae0  b9805fe200           mov ecx, 0xe25f80
// 00b14ae5  e9a65ca8ff           jmp 0x59a790
// auto-matched from its assembly shape

struct T_func_00b14ae0 { void m(); };
extern T_func_00b14ae0 G1_func_00b14ae0;
void func_00b14ae0()
{
    G1_func_00b14ae0.m();
}
