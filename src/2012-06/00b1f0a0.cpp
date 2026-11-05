// roc 2012-06 00b1f0a0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f0a0
//
// 00b1f0a0  a13c23e500           mov eax, dword ptr [0xe5233c]
// 00b1f0a5  50                   push eax
// 00b1f0a6  e86930e6ff           call 0x982114
// 00b1f0ab  83c404               add esp, 4
// 00b1f0ae  c7051423e5002c3cb400 mov dword ptr [0xe52314], 0xb43c2c
// 00b1f0b8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1f0a0(int);
void func_00b1f0a0()
{
    G4_func_00b1f0a0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
