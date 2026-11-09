// roc 2012-06 00b1d250  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d250
//
// 00b1d250  a1fce6e400           mov eax, dword ptr [0xe4e6fc]
// 00b1d255  50                   push eax
// 00b1d256  e8b94ee6ff           call 0x982114
// 00b1d25b  83c404               add esp, 4
// 00b1d25e  c705d4e6e4002c3cb400 mov dword ptr [0xe4e6d4], 0xb43c2c
// 00b1d268  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1d250(int);
void func_00b1d250()
{
    G4_func_00b1d250(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
