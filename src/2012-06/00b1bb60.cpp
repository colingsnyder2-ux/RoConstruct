// roc 2012-06 00b1bb60  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1bb60
//
// 00b1bb60  a11c9de400           mov eax, dword ptr [0xe49d1c]
// 00b1bb65  50                   push eax
// 00b1bb66  e8a965e6ff           call 0x982114
// 00b1bb6b  83c404               add esp, 4
// 00b1bb6e  c705f49ce4002c3cb400 mov dword ptr [0xe49cf4], 0xb43c2c
// 00b1bb78  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1bb60(int);
void func_00b1bb60()
{
    G4_func_00b1bb60(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
