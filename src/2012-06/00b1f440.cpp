// roc 2012-06 00b1f440  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f440
//
// 00b1f440  a18829e500           mov eax, dword ptr [0xe52988]
// 00b1f445  50                   push eax
// 00b1f446  e8c92ce6ff           call 0x982114
// 00b1f44b  83c404               add esp, 4
// 00b1f44e  c7055c29e5002c3cb400 mov dword ptr [0xe5295c], 0xb43c2c
// 00b1f458  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1f440(int);
void func_00b1f440()
{
    G4_func_00b1f440(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
