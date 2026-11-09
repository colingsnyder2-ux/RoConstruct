// roc 2012-06 00b20870  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20870
//
// 00b20870  a1c45ae500           mov eax, dword ptr [0xe55ac4]
// 00b20875  50                   push eax
// 00b20876  e89918e6ff           call 0x982114
// 00b2087b  83c404               add esp, 4
// 00b2087e  c7059c5ae5002c3cb400 mov dword ptr [0xe55a9c], 0xb43c2c
// 00b20888  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b20870(int);
void func_00b20870()
{
    G4_func_00b20870(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
