// roc 2012-06 00b18260  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18260
//
// 00b18260  b9a855e300           mov ecx, 0xe355a8
// 00b18265  e9f687c2ff           jmp 0x740a60
// auto-matched from its assembly shape

struct T_func_00b18260 { void m(); };
extern T_func_00b18260 G1_func_00b18260;
void func_00b18260()
{
    G1_func_00b18260.m();
}
