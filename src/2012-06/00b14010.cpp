// roc 2012-06 00b14010  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14010
//
// 00b14010  a11439e200           mov eax, dword ptr [0xe23914]
// 00b14015  50                   push eax
// 00b14016  e8f9e0e6ff           call 0x982114
// 00b1401b  83c404               add esp, 4
// 00b1401e  c705ec38e2002c3cb400 mov dword ptr [0xe238ec], 0xb43c2c
// 00b14028  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b14010(int);
void func_00b14010()
{
    G4_func_00b14010(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
