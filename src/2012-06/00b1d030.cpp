// roc 2012-06 00b1d030  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d030
//
// 00b1d030  a164dde400           mov eax, dword ptr [0xe4dd64]
// 00b1d035  50                   push eax
// 00b1d036  e8d950e6ff           call 0x982114
// 00b1d03b  83c404               add esp, 4
// 00b1d03e  c7053cdde4002c3cb400 mov dword ptr [0xe4dd3c], 0xb43c2c
// 00b1d048  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1d030(int);
void func_00b1d030()
{
    G4_func_00b1d030(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
