// roc 2012-06 00b14e60  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14e60
//
// 00b14e60  a12096e200           mov eax, dword ptr [0xe29620]
// 00b14e65  50                   push eax
// 00b14e66  e8a9d2e6ff           call 0x982114
// 00b14e6b  83c404               add esp, 4
// 00b14e6e  c705f895e2002c3cb400 mov dword ptr [0xe295f8], 0xb43c2c
// 00b14e78  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b14e60(int);
void func_00b14e60()
{
    G4_func_00b14e60(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
