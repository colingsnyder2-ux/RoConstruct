// roc 2012-06 00b20140  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20140
//
// 00b20140  a1ac4ce500           mov eax, dword ptr [0xe54cac]
// 00b20145  50                   push eax
// 00b20146  e8c91fe6ff           call 0x982114
// 00b2014b  83c404               add esp, 4
// 00b2014e  c705844ce5002c3cb400 mov dword ptr [0xe54c84], 0xb43c2c
// 00b20158  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b20140(int);
void func_00b20140()
{
    G4_func_00b20140(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
