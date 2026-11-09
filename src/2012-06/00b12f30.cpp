// roc 2012-06 00b12f30  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12f30
//
// 00b12f30  a15c0fe200           mov eax, dword ptr [0xe20f5c]
// 00b12f35  50                   push eax
// 00b12f36  e8d9f1e6ff           call 0x982114
// 00b12f3b  83c404               add esp, 4
// 00b12f3e  c705300fe2002c3cb400 mov dword ptr [0xe20f30], 0xb43c2c
// 00b12f48  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b12f30(int);
void func_00b12f30()
{
    G4_func_00b12f30(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
