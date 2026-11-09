// roc 2012-06 00aef850  unit: seg_00ae0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00aef850
//
// 00aef850  b9d83de200           mov ecx, 0xe23dd8
// 00aef855  e9d621a7ff           jmp 0x561a30
// auto-matched from its assembly shape

struct T_func_00aef850 { void m(); };
extern T_func_00aef850 G1_func_00aef850;
void func_00aef850()
{
    G1_func_00aef850.m();
}
