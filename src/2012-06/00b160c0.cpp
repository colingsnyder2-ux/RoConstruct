// roc 2012-06 00b160c0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b160c0
//
// 00b160c0  a15cd1e200           mov eax, dword ptr [0xe2d15c]
// 00b160c5  50                   push eax
// 00b160c6  e849c0e6ff           call 0x982114
// 00b160cb  83c404               add esp, 4
// 00b160ce  c70534d1e2002c3cb400 mov dword ptr [0xe2d134], 0xb43c2c
// 00b160d8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b160c0(int);
void func_00b160c0()
{
    G4_func_00b160c0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
