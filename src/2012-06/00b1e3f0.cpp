// roc 2012-06 00b1e3f0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1e3f0
//
// 00b1e3f0  a15c03e500           mov eax, dword ptr [0xe5035c]
// 00b1e3f5  50                   push eax
// 00b1e3f6  e8193de6ff           call 0x982114
// 00b1e3fb  83c404               add esp, 4
// 00b1e3fe  c7053403e5002c3cb400 mov dword ptr [0xe50334], 0xb43c2c
// 00b1e408  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1e3f0(int);
void func_00b1e3f0()
{
    G4_func_00b1e3f0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
