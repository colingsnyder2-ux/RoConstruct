// roc 2012-06 00b14230  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14230
//
// 00b14230  a1e037e200           mov eax, dword ptr [0xe237e0]
// 00b14235  50                   push eax
// 00b14236  e8d9dee6ff           call 0x982114
// 00b1423b  83c404               add esp, 4
// 00b1423e  c705b837e2002c3cb400 mov dword ptr [0xe237b8], 0xb43c2c
// 00b14248  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b14230(int);
void func_00b14230()
{
    G4_func_00b14230(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
