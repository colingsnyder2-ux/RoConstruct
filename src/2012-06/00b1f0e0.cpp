// roc 2012-06 00b1f0e0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f0e0
//
// 00b1f0e0  a1141ee500           mov eax, dword ptr [0xe51e14]
// 00b1f0e5  50                   push eax
// 00b1f0e6  e82930e6ff           call 0x982114
// 00b1f0eb  83c404               add esp, 4
// 00b1f0ee  c705ec1de5002c3cb400 mov dword ptr [0xe51dec], 0xb43c2c
// 00b1f0f8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1f0e0(int);
void func_00b1f0e0()
{
    G4_func_00b1f0e0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
