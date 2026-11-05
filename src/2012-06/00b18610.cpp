// roc 2012-06 00b18610  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18610
//
// 00b18610  a15c5de300           mov eax, dword ptr [0xe35d5c]
// 00b18615  50                   push eax
// 00b18616  e8f99ae6ff           call 0x982114
// 00b1861b  83c404               add esp, 4
// 00b1861e  c705345de3002c3cb400 mov dword ptr [0xe35d34], 0xb43c2c
// 00b18628  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b18610(int);
void func_00b18610()
{
    G4_func_00b18610(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
