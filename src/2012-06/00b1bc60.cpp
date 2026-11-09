// roc 2012-06 00b1bc60  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1bc60
//
// 00b1bc60  b9909de400           mov ecx, 0xe49d90
// 00b1bc65  e98662a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1bc60 { void m(); };
extern T_func_00b1bc60 G1_func_00b1bc60;
void func_00b1bc60()
{
    G1_func_00b1bc60.m();
}
