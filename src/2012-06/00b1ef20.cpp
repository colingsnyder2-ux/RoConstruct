// roc 2012-06 00b1ef20  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ef20
//
// 00b1ef20  b9281ce500           mov ecx, 0xe51c28
// 00b1ef25  e946b6d5ff           jmp 0x87a570
// auto-matched from its assembly shape

struct T_func_00b1ef20 { void m(); };
extern T_func_00b1ef20 G1_func_00b1ef20;
void func_00b1ef20()
{
    G1_func_00b1ef20.m();
}
