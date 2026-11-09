// roc 2012-06 00b1ce50  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ce50
//
// 00b1ce50  a15cdbe400           mov eax, dword ptr [0xe4db5c]
// 00b1ce55  50                   push eax
// 00b1ce56  e8b952e6ff           call 0x982114
// 00b1ce5b  83c404               add esp, 4
// 00b1ce5e  c70534dbe4002c3cb400 mov dword ptr [0xe4db34], 0xb43c2c
// 00b1ce68  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1ce50(int);
void func_00b1ce50()
{
    G4_func_00b1ce50(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
