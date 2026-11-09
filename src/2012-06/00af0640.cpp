// roc 2012-06 00af0640  unit: seg_00af0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00af0640
//
// 00af0640  b9305ce200           mov ecx, 0xe25c30
// 00af0645  e9e613a7ff           jmp 0x561a30
// auto-matched from its assembly shape

struct T_func_00af0640 { void m(); };
extern T_func_00af0640 G1_func_00af0640;
void func_00af0640()
{
    G1_func_00af0640.m();
}
