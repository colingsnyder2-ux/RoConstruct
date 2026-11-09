// roc 2012-06 00b21864  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b21864
//
// 00b21864  b9c4a4e500           mov ecx, 0xe5a4c4
// 00b21869  e97ca4f5ff           jmp 0xa7bcea
// auto-matched from its assembly shape

struct T_func_00b21864 { void m(); };
extern T_func_00b21864 G1_func_00b21864;
void func_00b21864()
{
    G1_func_00b21864.m();
}
