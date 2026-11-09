// roc 2012-06 00b201e0  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b201e0
//
// 00b201e0  a1ec4ae500           mov eax, dword ptr [0xe54aec]
// 00b201e5  50                   push eax
// 00b201e6  e8291fe6ff           call 0x982114
// 00b201eb  83c404               add esp, 4
// 00b201ee  c705c44ae5002c3cb400 mov dword ptr [0xe54ac4], 0xb43c2c
// 00b201f8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b201e0(int);
void func_00b201e0()
{
    G4_func_00b201e0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
