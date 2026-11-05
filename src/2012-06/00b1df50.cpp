// roc 2012-06 00b1df50  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1df50
//
// 00b1df50  a154fde400           mov eax, dword ptr [0xe4fd54]
// 00b1df55  50                   push eax
// 00b1df56  e8b941e6ff           call 0x982114
// 00b1df5b  83c404               add esp, 4
// 00b1df5e  c7052cfde4002c3cb400 mov dword ptr [0xe4fd2c], 0xb43c2c
// 00b1df68  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1df50(int);
void func_00b1df50()
{
    G4_func_00b1df50(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
