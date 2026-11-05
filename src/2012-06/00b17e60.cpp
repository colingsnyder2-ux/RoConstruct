// roc 2012-06 00b17e60  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17e60
//
// 00b17e60  a1d441e300           mov eax, dword ptr [0xe341d4]
// 00b17e65  50                   push eax
// 00b17e66  e8a9a2e6ff           call 0x982114
// 00b17e6b  83c404               add esp, 4
// 00b17e6e  c705ac41e3002c3cb400 mov dword ptr [0xe341ac], 0xb43c2c
// 00b17e78  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b17e60(int);
void func_00b17e60()
{
    G4_func_00b17e60(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
