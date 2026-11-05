// roc 2012-06 00b13090  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13090
//
// 00b13090  a16811e200           mov eax, dword ptr [0xe21168]
// 00b13095  50                   push eax
// 00b13096  e879f0e6ff           call 0x982114
// 00b1309b  83c404               add esp, 4
// 00b1309e  c7053c11e2002c3cb400 mov dword ptr [0xe2113c], 0xb43c2c
// 00b130a8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b13090(int);
void func_00b13090()
{
    G4_func_00b13090(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
