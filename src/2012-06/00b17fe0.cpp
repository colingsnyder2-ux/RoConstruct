// roc 2012-06 00b17fe0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17fe0
//
// 00b17fe0  a10847e300           mov eax, dword ptr [0xe34708]
// 00b17fe5  50                   push eax
// 00b17fe6  e829a1e6ff           call 0x982114
// 00b17feb  83c404               add esp, 4
// 00b17fee  c705e046e3002c3cb400 mov dword ptr [0xe346e0], 0xb43c2c
// 00b17ff8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b17fe0(int);
void func_00b17fe0()
{
    G4_func_00b17fe0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
