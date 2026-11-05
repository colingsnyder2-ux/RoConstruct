// roc 2012-06 00b1c120  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c120
//
// 00b1c120  a134a9e400           mov eax, dword ptr [0xe4a934]
// 00b1c125  50                   push eax
// 00b1c126  e8e95fe6ff           call 0x982114
// 00b1c12b  83c404               add esp, 4
// 00b1c12e  c7050ca9e4002c3cb400 mov dword ptr [0xe4a90c], 0xb43c2c
// 00b1c138  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1c120(int);
void func_00b1c120()
{
    G4_func_00b1c120(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
