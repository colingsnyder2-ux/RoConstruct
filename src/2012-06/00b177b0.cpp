// roc 2012-06 00b177b0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b177b0
//
// 00b177b0  a19c23e300           mov eax, dword ptr [0xe3239c]
// 00b177b5  50                   push eax
// 00b177b6  e859a9e6ff           call 0x982114
// 00b177bb  83c404               add esp, 4
// 00b177be  c7057023e3002c3cb400 mov dword ptr [0xe32370], 0xb43c2c
// 00b177c8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b177b0(int);
void func_00b177b0()
{
    G4_func_00b177b0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
