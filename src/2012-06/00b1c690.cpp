// roc 2012-06 00b1c690  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c690
//
// 00b1c690  a1b0b3e400           mov eax, dword ptr [0xe4b3b0]
// 00b1c695  50                   push eax
// 00b1c696  e8795ae6ff           call 0x982114
// 00b1c69b  83c404               add esp, 4
// 00b1c69e  c70588b3e4002c3cb400 mov dword ptr [0xe4b388], 0xb43c2c
// 00b1c6a8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1c690(int);
void func_00b1c690()
{
    G4_func_00b1c690(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
