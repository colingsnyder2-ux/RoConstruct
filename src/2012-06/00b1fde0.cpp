// roc 2012-06 00b1fde0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1fde0
//
// 00b1fde0  a1ec3be500           mov eax, dword ptr [0xe53bec]
// 00b1fde5  50                   push eax
// 00b1fde6  e82923e6ff           call 0x982114
// 00b1fdeb  83c404               add esp, 4
// 00b1fdee  c705c43be5002c3cb400 mov dword ptr [0xe53bc4], 0xb43c2c
// 00b1fdf8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1fde0(int);
void func_00b1fde0()
{
    G4_func_00b1fde0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
