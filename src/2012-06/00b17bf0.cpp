// roc 2012-06 00b17bf0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17bf0
//
// 00b17bf0  b9902ee300           mov ecx, 0xe32e90
// 00b17bf5  e9766cc1ff           jmp 0x72e870
// auto-matched from its assembly shape

struct T_func_00b17bf0 { void m(); };
extern T_func_00b17bf0 G1_func_00b17bf0;
void func_00b17bf0()
{
    G1_func_00b17bf0.m();
}
