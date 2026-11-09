// roc 2012-06 00b1cf90  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1cf90
//
// 00b1cf90  a100dde400           mov eax, dword ptr [0xe4dd00]
// 00b1cf95  50                   push eax
// 00b1cf96  e87951e6ff           call 0x982114
// 00b1cf9b  83c404               add esp, 4
// 00b1cf9e  c705d8dce4002c3cb400 mov dword ptr [0xe4dcd8], 0xb43c2c
// 00b1cfa8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1cf90(int);
void func_00b1cf90()
{
    G4_func_00b1cf90(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
