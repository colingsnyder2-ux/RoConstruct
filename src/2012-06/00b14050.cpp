// roc 2012-06 00b14050  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14050
//
// 00b14050  a1bc3be200           mov eax, dword ptr [0xe23bbc]
// 00b14055  50                   push eax
// 00b14056  e8b9e0e6ff           call 0x982114
// 00b1405b  83c404               add esp, 4
// 00b1405e  c705943be2002c3cb400 mov dword ptr [0xe23b94], 0xb43c2c
// 00b14068  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b14050(int);
void func_00b14050()
{
    G4_func_00b14050(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
