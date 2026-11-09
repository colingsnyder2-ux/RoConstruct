// roc 2012-06 00b12200  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12200
//
// 00b12200  a1c497e100           mov eax, dword ptr [0xe197c4]
// 00b12205  50                   push eax
// 00b12206  e809ffe6ff           call 0x982114
// 00b1220b  83c404               add esp, 4
// 00b1220e  c7059c97e1002c3cb400 mov dword ptr [0xe1979c], 0xb43c2c
// 00b12218  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b12200(int);
void func_00b12200()
{
    G4_func_00b12200(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
