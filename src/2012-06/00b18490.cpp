// roc 2012-06 00b18490  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18490
//
// 00b18490  a1cc63e300           mov eax, dword ptr [0xe363cc]
// 00b18495  50                   push eax
// 00b18496  e8799ce6ff           call 0x982114
// 00b1849b  83c404               add esp, 4
// 00b1849e  c705a463e3002c3cb400 mov dword ptr [0xe363a4], 0xb43c2c
// 00b184a8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b18490(int);
void func_00b18490()
{
    G4_func_00b18490(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
