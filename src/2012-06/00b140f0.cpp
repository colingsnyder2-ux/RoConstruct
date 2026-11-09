// roc 2012-06 00b140f0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b140f0
//
// 00b140f0  a1e838e200           mov eax, dword ptr [0xe238e8]
// 00b140f5  50                   push eax
// 00b140f6  e819e0e6ff           call 0x982114
// 00b140fb  83c404               add esp, 4
// 00b140fe  c705c038e2002c3cb400 mov dword ptr [0xe238c0], 0xb43c2c
// 00b14108  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b140f0(int);
void func_00b140f0()
{
    G4_func_00b140f0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
