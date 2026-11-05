// roc 2012-06 00b13030  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13030
//
// 00b13030  a19c14e200           mov eax, dword ptr [0xe2149c]
// 00b13035  50                   push eax
// 00b13036  e8d9f0e6ff           call 0x982114
// 00b1303b  83c404               add esp, 4
// 00b1303e  c7057014e2002c3cb400 mov dword ptr [0xe21470], 0xb43c2c
// 00b13048  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b13030(int);
void func_00b13030()
{
    G4_func_00b13030(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
