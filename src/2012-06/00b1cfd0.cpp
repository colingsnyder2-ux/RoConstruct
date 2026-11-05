// roc 2012-06 00b1cfd0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1cfd0
//
// 00b1cfd0  a17cdce400           mov eax, dword ptr [0xe4dc7c]
// 00b1cfd5  50                   push eax
// 00b1cfd6  e83951e6ff           call 0x982114
// 00b1cfdb  83c404               add esp, 4
// 00b1cfde  c70554dce4002c3cb400 mov dword ptr [0xe4dc54], 0xb43c2c
// 00b1cfe8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1cfd0(int);
void func_00b1cfd0()
{
    G4_func_00b1cfd0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
