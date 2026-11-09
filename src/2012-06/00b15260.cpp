// roc 2012-06 00b15260  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15260
//
// 00b15260  a1f89fe200           mov eax, dword ptr [0xe29ff8]
// 00b15265  50                   push eax
// 00b15266  e8a9cee6ff           call 0x982114
// 00b1526b  83c404               add esp, 4
// 00b1526e  c705cc9fe2002c3cb400 mov dword ptr [0xe29fcc], 0xb43c2c
// 00b15278  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b15260(int);
void func_00b15260()
{
    G4_func_00b15260(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
