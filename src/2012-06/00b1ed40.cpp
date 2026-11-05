// roc 2012-06 00b1ed40  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ed40
//
// 00b1ed40  b93818e500           mov ecx, 0xe51838
// 00b1ed45  e9f60cd6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b1ed40 { void m(); };
extern T_func_00b1ed40 G1_func_00b1ed40;
void func_00b1ed40()
{
    G1_func_00b1ed40.m();
}
