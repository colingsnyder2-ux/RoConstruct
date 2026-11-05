// roc 2012-06 00b12260  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12260
//
// 00b12260  a19497e100           mov eax, dword ptr [0xe19794]
// 00b12265  50                   push eax
// 00b12266  e8a9fee6ff           call 0x982114
// 00b1226b  83c404               add esp, 4
// 00b1226e  c7056c97e1002c3cb400 mov dword ptr [0xe1976c], 0xb43c2c
// 00b12278  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b12260(int);
void func_00b12260()
{
    G4_func_00b12260(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
