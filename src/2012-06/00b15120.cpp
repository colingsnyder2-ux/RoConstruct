// roc 2012-06 00b15120  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15120
//
// 00b15120  a17c9ae200           mov eax, dword ptr [0xe29a7c]
// 00b15125  50                   push eax
// 00b15126  e8e9cfe6ff           call 0x982114
// 00b1512b  83c404               add esp, 4
// 00b1512e  c705549ae2002c3cb400 mov dword ptr [0xe29a54], 0xb43c2c
// 00b15138  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b15120(int);
void func_00b15120()
{
    G4_func_00b15120(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
