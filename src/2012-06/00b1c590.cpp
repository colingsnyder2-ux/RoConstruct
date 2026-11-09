// roc 2012-06 00b1c590  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c590
//
// 00b1c590  a1bcb1e400           mov eax, dword ptr [0xe4b1bc]
// 00b1c595  50                   push eax
// 00b1c596  e8795be6ff           call 0x982114
// 00b1c59b  83c404               add esp, 4
// 00b1c59e  c70594b1e4002c3cb400 mov dword ptr [0xe4b194], 0xb43c2c
// 00b1c5a8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1c590(int);
void func_00b1c590()
{
    G4_func_00b1c590(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
