// roc 2012-06 00b15180  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15180
//
// 00b15180  a19c9ce200           mov eax, dword ptr [0xe29c9c]
// 00b15185  50                   push eax
// 00b15186  e889cfe6ff           call 0x982114
// 00b1518b  83c404               add esp, 4
// 00b1518e  c705749ce2002c3cb400 mov dword ptr [0xe29c74], 0xb43c2c
// 00b15198  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b15180(int);
void func_00b15180()
{
    G4_func_00b15180(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
