// roc 2012-06 00b1d890  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d890
//
// 00b1d890  a16cebe400           mov eax, dword ptr [0xe4eb6c]
// 00b1d895  50                   push eax
// 00b1d896  e87948e6ff           call 0x982114
// 00b1d89b  83c404               add esp, 4
// 00b1d89e  c70544ebe4002c3cb400 mov dword ptr [0xe4eb44], 0xb43c2c
// 00b1d8a8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1d890(int);
void func_00b1d890()
{
    G4_func_00b1d890(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
