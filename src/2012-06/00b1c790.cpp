// roc 2012-06 00b1c790  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c790
//
// 00b1c790  a164b4e400           mov eax, dword ptr [0xe4b464]
// 00b1c795  50                   push eax
// 00b1c796  e87959e6ff           call 0x982114
// 00b1c79b  83c404               add esp, 4
// 00b1c79e  c7053cb4e4002c3cb400 mov dword ptr [0xe4b43c], 0xb43c2c
// 00b1c7a8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1c790(int);
void func_00b1c790()
{
    G4_func_00b1c790(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
