// roc 2012-06 00b20a90  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20a90
//
// 00b20a90  a18c5ce500           mov eax, dword ptr [0xe55c8c]
// 00b20a95  50                   push eax
// 00b20a96  e87916e6ff           call 0x982114
// 00b20a9b  83c404               add esp, 4
// 00b20a9e  c705645ce5002c3cb400 mov dword ptr [0xe55c64], 0xb43c2c
// 00b20aa8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b20a90(int);
void func_00b20a90()
{
    G4_func_00b20a90(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
