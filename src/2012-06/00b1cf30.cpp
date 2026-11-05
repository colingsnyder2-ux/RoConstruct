// roc 2012-06 00b1cf30  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1cf30
//
// 00b1cf30  a1a0dbe400           mov eax, dword ptr [0xe4dba0]
// 00b1cf35  50                   push eax
// 00b1cf36  e8d951e6ff           call 0x982114
// 00b1cf3b  83c404               add esp, 4
// 00b1cf3e  c70578dbe4002c3cb400 mov dword ptr [0xe4db78], 0xb43c2c
// 00b1cf48  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1cf30(int);
void func_00b1cf30()
{
    G4_func_00b1cf30(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
