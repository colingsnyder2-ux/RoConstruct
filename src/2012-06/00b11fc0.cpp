// roc 2012-06 00b11fc0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11fc0
//
// 00b11fc0  a1709ce100           mov eax, dword ptr [0xe19c70]
// 00b11fc5  50                   push eax
// 00b11fc6  e84901e7ff           call 0x982114
// 00b11fcb  83c404               add esp, 4
// 00b11fce  c705449ce1002c3cb400 mov dword ptr [0xe19c44], 0xb43c2c
// 00b11fd8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b11fc0(int);
void func_00b11fc0()
{
    G4_func_00b11fc0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
