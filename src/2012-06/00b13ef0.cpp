// roc 2012-06 00b13ef0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13ef0
//
// 00b13ef0  a18837e200           mov eax, dword ptr [0xe23788]
// 00b13ef5  50                   push eax
// 00b13ef6  e819e2e6ff           call 0x982114
// 00b13efb  83c404               add esp, 4
// 00b13efe  c7056037e2002c3cb400 mov dword ptr [0xe23760], 0xb43c2c
// 00b13f08  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b13ef0(int);
void func_00b13ef0()
{
    G4_func_00b13ef0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
