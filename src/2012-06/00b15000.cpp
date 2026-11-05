// roc 2012-06 00b15000  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15000
//
// 00b15000  a1ec9ee200           mov eax, dword ptr [0xe29eec]
// 00b15005  50                   push eax
// 00b15006  e809d1e6ff           call 0x982114
// 00b1500b  83c404               add esp, 4
// 00b1500e  c705c49ee2002c3cb400 mov dword ptr [0xe29ec4], 0xb43c2c
// 00b15018  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b15000(int);
void func_00b15000()
{
    G4_func_00b15000(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
