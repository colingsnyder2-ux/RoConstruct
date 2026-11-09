// roc 2012-06 00b123c0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b123c0
//
// 00b123c0  a1b49be100           mov eax, dword ptr [0xe19bb4]
// 00b123c5  50                   push eax
// 00b123c6  e849fde6ff           call 0x982114
// 00b123cb  83c404               add esp, 4
// 00b123ce  c7058c9be1002c3cb400 mov dword ptr [0xe19b8c], 0xb43c2c
// 00b123d8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b123c0(int);
void func_00b123c0()
{
    G4_func_00b123c0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
