// roc 2012-06 00b13050  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13050
//
// 00b13050  a1c80ee200           mov eax, dword ptr [0xe20ec8]
// 00b13055  50                   push eax
// 00b13056  e8b9f0e6ff           call 0x982114
// 00b1305b  83c404               add esp, 4
// 00b1305e  c705a00ee2002c3cb400 mov dword ptr [0xe20ea0], 0xb43c2c
// 00b13068  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b13050(int);
void func_00b13050()
{
    G4_func_00b13050(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
