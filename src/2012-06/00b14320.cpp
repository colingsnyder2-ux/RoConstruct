// roc 2012-06 00b14320  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14320
//
// 00b14320  b9803ce200           mov ecx, 0xe23c80
// 00b14325  e9c6dba7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b14320 { void m(); };
extern T_func_00b14320 G1_func_00b14320;
void func_00b14320()
{
    G1_func_00b14320.m();
}
