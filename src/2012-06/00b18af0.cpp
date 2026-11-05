// roc 2012-06 00b18af0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18af0
//
// 00b18af0  a10c70e300           mov eax, dword ptr [0xe3700c]
// 00b18af5  50                   push eax
// 00b18af6  e81996e6ff           call 0x982114
// 00b18afb  83c404               add esp, 4
// 00b18afe  c705e46fe3002c3cb400 mov dword ptr [0xe36fe4], 0xb43c2c
// 00b18b08  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b18af0(int);
void func_00b18af0()
{
    G4_func_00b18af0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
