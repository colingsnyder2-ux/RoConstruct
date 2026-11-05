// roc 2012-06 00b13970  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13970
//
// 00b13970  a16425e200           mov eax, dword ptr [0xe22564]
// 00b13975  50                   push eax
// 00b13976  e899e7e6ff           call 0x982114
// 00b1397b  83c404               add esp, 4
// 00b1397e  c7053c25e2002c3cb400 mov dword ptr [0xe2253c], 0xb43c2c
// 00b13988  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b13970(int);
void func_00b13970()
{
    G4_func_00b13970(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
