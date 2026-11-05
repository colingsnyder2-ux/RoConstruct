// roc 2012-06 00b18b10  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18b10
//
// 00b18b10  a1e06fe300           mov eax, dword ptr [0xe36fe0]
// 00b18b15  50                   push eax
// 00b18b16  e8f995e6ff           call 0x982114
// 00b18b1b  83c404               add esp, 4
// 00b18b1e  c705b86fe3002c3cb400 mov dword ptr [0xe36fb8], 0xb43c2c
// 00b18b28  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b18b10(int);
void func_00b18b10()
{
    G4_func_00b18b10(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
