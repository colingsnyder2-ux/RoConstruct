// roc 2012-06 00b12f70  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12f70
//
// 00b12f70  a16c12e200           mov eax, dword ptr [0xe2126c]
// 00b12f75  50                   push eax
// 00b12f76  e899f1e6ff           call 0x982114
// 00b12f7b  83c404               add esp, 4
// 00b12f7e  c7054412e2002c3cb400 mov dword ptr [0xe21244], 0xb43c2c
// 00b12f88  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b12f70(int);
void func_00b12f70()
{
    G4_func_00b12f70(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
