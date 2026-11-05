// roc 2012-06 00b1d850  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d850
//
// 00b1d850  a19cede400           mov eax, dword ptr [0xe4ed9c]
// 00b1d855  50                   push eax
// 00b1d856  e8b948e6ff           call 0x982114
// 00b1d85b  83c404               add esp, 4
// 00b1d85e  c70574ede4002c3cb400 mov dword ptr [0xe4ed74], 0xb43c2c
// 00b1d868  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1d850(int);
void func_00b1d850()
{
    G4_func_00b1d850(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
