// roc 2012-06 00b157f0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b157f0
//
// 00b157f0  a1a0a5e200           mov eax, dword ptr [0xe2a5a0]
// 00b157f5  50                   push eax
// 00b157f6  e819c9e6ff           call 0x982114
// 00b157fb  83c404               add esp, 4
// 00b157fe  c70578a5e2002c3cb400 mov dword ptr [0xe2a578], 0xb43c2c
// 00b15808  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b157f0(int);
void func_00b157f0()
{
    G4_func_00b157f0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
