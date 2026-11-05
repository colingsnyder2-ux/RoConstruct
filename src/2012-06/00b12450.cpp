// roc 2012-06 00b12450  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12450
//
// 00b12450  b9708fe100           mov ecx, 0xe18f70
// 00b12455  e9263a95ff           jmp 0x465e80
// auto-matched from its assembly shape

struct T_func_00b12450 { void m(); };
extern T_func_00b12450 G1_func_00b12450;
void func_00b12450()
{
    G1_func_00b12450.m();
}
