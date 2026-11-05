// roc 2012-06 00b1f180  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f180
//
// 00b1f180  a11023e500           mov eax, dword ptr [0xe52310]
// 00b1f185  50                   push eax
// 00b1f186  e8892fe6ff           call 0x982114
// 00b1f18b  83c404               add esp, 4
// 00b1f18e  c705e822e5002c3cb400 mov dword ptr [0xe522e8], 0xb43c2c
// 00b1f198  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1f180(int);
void func_00b1f180()
{
    G4_func_00b1f180(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
