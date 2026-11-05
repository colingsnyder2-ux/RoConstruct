// roc 2012-06 00b12ef0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12ef0
//
// 00b12ef0  a1700ee200           mov eax, dword ptr [0xe20e70]
// 00b12ef5  50                   push eax
// 00b12ef6  e819f2e6ff           call 0x982114
// 00b12efb  83c404               add esp, 4
// 00b12efe  c705480ee2002c3cb400 mov dword ptr [0xe20e48], 0xb43c2c
// 00b12f08  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b12ef0(int);
void func_00b12ef0()
{
    G4_func_00b12ef0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
