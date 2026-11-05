// roc 2012-06 00b15e10  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15e10
//
// 00b15e10  a158c3e200           mov eax, dword ptr [0xe2c358]
// 00b15e15  50                   push eax
// 00b15e16  e8f9c2e6ff           call 0x982114
// 00b15e1b  83c404               add esp, 4
// 00b15e1e  c70530c3e2002c3cb400 mov dword ptr [0xe2c330], 0xb43c2c
// 00b15e28  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b15e10(int);
void func_00b15e10()
{
    G4_func_00b15e10(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
