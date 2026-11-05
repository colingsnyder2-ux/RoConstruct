// roc 2012-06 00b20650  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20650
//
// 00b20650  a1a055e500           mov eax, dword ptr [0xe555a0]
// 00b20655  50                   push eax
// 00b20656  e8b91ae6ff           call 0x982114
// 00b2065b  83c404               add esp, 4
// 00b2065e  c7057855e5002c3cb400 mov dword ptr [0xe55578], 0xb43c2c
// 00b20668  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b20650(int);
void func_00b20650()
{
    G4_func_00b20650(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
