// roc 2012-06 00b15770  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15770
//
// 00b15770  a140a2e200           mov eax, dword ptr [0xe2a240]
// 00b15775  50                   push eax
// 00b15776  e899c9e6ff           call 0x982114
// 00b1577b  83c404               add esp, 4
// 00b1577e  c70518a2e2002c3cb400 mov dword ptr [0xe2a218], 0xb43c2c
// 00b15788  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b15770(int);
void func_00b15770()
{
    G4_func_00b15770(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
