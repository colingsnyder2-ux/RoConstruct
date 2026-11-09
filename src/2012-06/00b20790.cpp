// roc 2012-06 00b20790  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20790
//
// 00b20790  b95856e500           mov ecx, 0xe55658
// 00b20795  e95617a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b20790 { void m(); };
extern T_func_00b20790 G1_func_00b20790;
void func_00b20790()
{
    G1_func_00b20790.m();
}
