// roc 2012-06 00b12b60  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12b60
//
// 00b12b60  b9f4d3e100           mov ecx, 0xe1d3f4
// 00b12b65  ff25d82db200         jmp dword ptr [0xb22dd8]
// auto-matched from its assembly shape

struct __declspec(dllimport) T_func_00b12b60 { void m(); };
extern T_func_00b12b60 G1_func_00b12b60;
void func_00b12b60()
{
    G1_func_00b12b60.m();
}
