// roc 2012-06 00b16080  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16080
//
// 00b16080  a128d1e200           mov eax, dword ptr [0xe2d128]
// 00b16085  50                   push eax
// 00b16086  e889c0e6ff           call 0x982114
// 00b1608b  83c404               add esp, 4
// 00b1608e  c70500d1e2002c3cb400 mov dword ptr [0xe2d100], 0xb43c2c
// 00b16098  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b16080(int);
void func_00b16080()
{
    G4_func_00b16080(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
