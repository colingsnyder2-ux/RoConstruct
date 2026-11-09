// roc 2012-06 00b14fe0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14fe0
//
// 00b14fe0  a1c895e200           mov eax, dword ptr [0xe295c8]
// 00b14fe5  50                   push eax
// 00b14fe6  e829d1e6ff           call 0x982114
// 00b14feb  83c404               add esp, 4
// 00b14fee  c705a095e2002c3cb400 mov dword ptr [0xe295a0], 0xb43c2c
// 00b14ff8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b14fe0(int);
void func_00b14fe0()
{
    G4_func_00b14fe0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
