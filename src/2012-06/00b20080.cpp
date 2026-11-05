// roc 2012-06 00b20080  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20080
//
// 00b20080  a1c44ee500           mov eax, dword ptr [0xe54ec4]
// 00b20085  50                   push eax
// 00b20086  e88920e6ff           call 0x982114
// 00b2008b  83c404               add esp, 4
// 00b2008e  c7059c4ee5002c3cb400 mov dword ptr [0xe54e9c], 0xb43c2c
// 00b20098  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b20080(int);
void func_00b20080()
{
    G4_func_00b20080(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
