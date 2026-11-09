// roc 2012-06 00b123a0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b123a0
//
// 00b123a0  a1d09ce100           mov eax, dword ptr [0xe19cd0]
// 00b123a5  50                   push eax
// 00b123a6  e869fde6ff           call 0x982114
// 00b123ab  83c404               add esp, 4
// 00b123ae  c705a89ce1002c3cb400 mov dword ptr [0xe19ca8], 0xb43c2c
// 00b123b8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b123a0(int);
void func_00b123a0()
{
    G4_func_00b123a0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
