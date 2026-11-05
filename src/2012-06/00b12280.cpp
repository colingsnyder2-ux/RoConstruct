// roc 2012-06 00b12280  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12280
//
// 00b12280  a1889be100           mov eax, dword ptr [0xe19b88]
// 00b12285  50                   push eax
// 00b12286  e889fee6ff           call 0x982114
// 00b1228b  83c404               add esp, 4
// 00b1228e  c705609be1002c3cb400 mov dword ptr [0xe19b60], 0xb43c2c
// 00b12298  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b12280(int);
void func_00b12280()
{
    G4_func_00b12280(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
