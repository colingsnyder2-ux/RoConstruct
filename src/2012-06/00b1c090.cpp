// roc 2012-06 00b1c090  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c090
//
// 00b1c090  a110a8e400           mov eax, dword ptr [0xe4a810]
// 00b1c095  50                   push eax
// 00b1c096  e87960e6ff           call 0x982114
// 00b1c09b  83c404               add esp, 4
// 00b1c09e  c705e8a7e4002c3cb400 mov dword ptr [0xe4a7e8], 0xb43c2c
// 00b1c0a8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1c090(int);
void func_00b1c090()
{
    G4_func_00b1c090(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
