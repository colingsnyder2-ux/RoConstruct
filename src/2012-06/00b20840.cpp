// roc 2012-06 00b20840  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20840
//
// 00b20840  b9f858e500           mov ecx, 0xe558f8
// 00b20845  e9a616a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b20840 { void m(); };
extern T_func_00b20840 G1_func_00b20840;
void func_00b20840()
{
    G1_func_00b20840.m();
}
