// roc 2012-06 00b1f660  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f660
//
// 00b1f660  a1c82ce500           mov eax, dword ptr [0xe52cc8]
// 00b1f665  50                   push eax
// 00b1f666  e8a92ae6ff           call 0x982114
// 00b1f66b  83c404               add esp, 4
// 00b1f66e  c705a02ce5002c3cb400 mov dword ptr [0xe52ca0], 0xb43c2c
// 00b1f678  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1f660(int);
void func_00b1f660()
{
    G4_func_00b1f660(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
