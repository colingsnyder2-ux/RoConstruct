// roc 2012-06 00b1df10  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1df10
//
// 00b1df10  a140fce400           mov eax, dword ptr [0xe4fc40]
// 00b1df15  50                   push eax
// 00b1df16  e8f941e6ff           call 0x982114
// 00b1df1b  83c404               add esp, 4
// 00b1df1e  c70518fce4002c3cb400 mov dword ptr [0xe4fc18], 0xb43c2c
// 00b1df28  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1df10(int);
void func_00b1df10()
{
    G4_func_00b1df10(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
