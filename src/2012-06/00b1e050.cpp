// roc 2012-06 00b1e050  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1e050
//
// 00b1e050  a1ccfce400           mov eax, dword ptr [0xe4fccc]
// 00b1e055  50                   push eax
// 00b1e056  e8b940e6ff           call 0x982114
// 00b1e05b  83c404               add esp, 4
// 00b1e05e  c705a4fce4002c3cb400 mov dword ptr [0xe4fca4], 0xb43c2c
// 00b1e068  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1e050(int);
void func_00b1e050()
{
    G4_func_00b1e050(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
