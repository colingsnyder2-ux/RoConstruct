// roc 2012-06 00b14270  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14270
//
// 00b14270  a10c38e200           mov eax, dword ptr [0xe2380c]
// 00b14275  50                   push eax
// 00b14276  e899dee6ff           call 0x982114
// 00b1427b  83c404               add esp, 4
// 00b1427e  c705e437e2002c3cb400 mov dword ptr [0xe237e4], 0xb43c2c
// 00b14288  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b14270(int);
void func_00b14270()
{
    G4_func_00b14270(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
