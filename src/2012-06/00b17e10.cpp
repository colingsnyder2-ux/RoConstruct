// roc 2012-06 00b17e10  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17e10
//
// 00b17e10  a18c41e300           mov eax, dword ptr [0xe3418c]
// 00b17e15  50                   push eax
// 00b17e16  e8f9a2e6ff           call 0x982114
// 00b17e1b  83c404               add esp, 4
// 00b17e1e  c7056041e3002c3cb400 mov dword ptr [0xe34160], 0xb43c2c
// 00b17e28  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b17e10(int);
void func_00b17e10()
{
    G4_func_00b17e10(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
