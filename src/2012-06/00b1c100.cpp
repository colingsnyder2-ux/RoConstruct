// roc 2012-06 00b1c100  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c100
//
// 00b1c100  a104a9e400           mov eax, dword ptr [0xe4a904]
// 00b1c105  50                   push eax
// 00b1c106  e80960e6ff           call 0x982114
// 00b1c10b  83c404               add esp, 4
// 00b1c10e  c705d8a8e4002c3cb400 mov dword ptr [0xe4a8d8], 0xb43c2c
// 00b1c118  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1c100(int);
void func_00b1c100()
{
    G4_func_00b1c100(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
