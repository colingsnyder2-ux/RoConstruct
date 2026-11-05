// roc 2012-06 00b1c000  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c000
//
// 00b1c000  a1a4a7e400           mov eax, dword ptr [0xe4a7a4]
// 00b1c005  50                   push eax
// 00b1c006  e80961e6ff           call 0x982114
// 00b1c00b  83c404               add esp, 4
// 00b1c00e  c7057ca7e4002c3cb400 mov dword ptr [0xe4a77c], 0xb43c2c
// 00b1c018  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1c000(int);
void func_00b1c000()
{
    G4_func_00b1c000(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
