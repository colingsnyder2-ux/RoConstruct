// roc 2012-06 00b1c530  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c530
//
// 00b1c530  a130b1e400           mov eax, dword ptr [0xe4b130]
// 00b1c535  50                   push eax
// 00b1c536  e8d95be6ff           call 0x982114
// 00b1c53b  83c404               add esp, 4
// 00b1c53e  c70508b1e4002c3cb400 mov dword ptr [0xe4b108], 0xb43c2c
// 00b1c548  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1c530(int);
void func_00b1c530()
{
    G4_func_00b1c530(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
