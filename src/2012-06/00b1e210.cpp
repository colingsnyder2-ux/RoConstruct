// roc 2012-06 00b1e210  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1e210
//
// 00b1e210  a12cffe400           mov eax, dword ptr [0xe4ff2c]
// 00b1e215  50                   push eax
// 00b1e216  e8f93ee6ff           call 0x982114
// 00b1e21b  83c404               add esp, 4
// 00b1e21e  c70504ffe4002c3cb400 mov dword ptr [0xe4ff04], 0xb43c2c
// 00b1e228  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1e210(int);
void func_00b1e210()
{
    G4_func_00b1e210(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
