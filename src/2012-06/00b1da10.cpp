// roc 2012-06 00b1da10  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1da10
//
// 00b1da10  a170f1e400           mov eax, dword ptr [0xe4f170]
// 00b1da15  50                   push eax
// 00b1da16  e8f946e6ff           call 0x982114
// 00b1da1b  83c404               add esp, 4
// 00b1da1e  c70548f1e4002c3cb400 mov dword ptr [0xe4f148], 0xb43c2c
// 00b1da28  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1da10(int);
void func_00b1da10()
{
    G4_func_00b1da10(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
