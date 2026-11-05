// roc 2012-06 00b217e0  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b217e0
//
// 00b217e0  b97ca0e500           mov ecx, 0xe5a07c
// 00b217e5  e9b64aefff           jmp 0xa162a0
// auto-matched from its assembly shape

struct T_func_00b217e0 { void m(); };
extern T_func_00b217e0 G1_func_00b217e0;
void func_00b217e0()
{
    G1_func_00b217e0.m();
}
