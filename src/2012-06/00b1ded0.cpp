// roc 2012-06 00b1ded0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ded0
//
// 00b1ded0  a170fce400           mov eax, dword ptr [0xe4fc70]
// 00b1ded5  50                   push eax
// 00b1ded6  e83942e6ff           call 0x982114
// 00b1dedb  83c404               add esp, 4
// 00b1dede  c70544fce4002c3cb400 mov dword ptr [0xe4fc44], 0xb43c2c
// 00b1dee8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1ded0(int);
void func_00b1ded0()
{
    G4_func_00b1ded0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
