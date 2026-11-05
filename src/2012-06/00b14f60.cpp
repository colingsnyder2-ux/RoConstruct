// roc 2012-06 00b14f60  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14f60
//
// 00b14f60  a1d497e200           mov eax, dword ptr [0xe297d4]
// 00b14f65  50                   push eax
// 00b14f66  e8a9d1e6ff           call 0x982114
// 00b14f6b  83c404               add esp, 4
// 00b14f6e  c705ac97e2002c3cb400 mov dword ptr [0xe297ac], 0xb43c2c
// 00b14f78  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b14f60(int);
void func_00b14f60()
{
    G4_func_00b14f60(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
