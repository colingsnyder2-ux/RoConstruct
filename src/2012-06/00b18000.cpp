// roc 2012-06 00b18000  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18000
//
// 00b18000  a1c845e300           mov eax, dword ptr [0xe345c8]
// 00b18005  50                   push eax
// 00b18006  e809a1e6ff           call 0x982114
// 00b1800b  83c404               add esp, 4
// 00b1800e  c705a045e3002c3cb400 mov dword ptr [0xe345a0], 0xb43c2c
// 00b18018  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b18000(int);
void func_00b18000()
{
    G4_func_00b18000(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
