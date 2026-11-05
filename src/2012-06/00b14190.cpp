// roc 2012-06 00b14190  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14190
//
// 00b14190  a1b437e200           mov eax, dword ptr [0xe237b4]
// 00b14195  50                   push eax
// 00b14196  e879dfe6ff           call 0x982114
// 00b1419b  83c404               add esp, 4
// 00b1419e  c7058c37e2002c3cb400 mov dword ptr [0xe2378c], 0xb43c2c
// 00b141a8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b14190(int);
void func_00b14190()
{
    G4_func_00b14190(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
