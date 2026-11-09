// roc 2012-06 00b20890  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20890
//
// 00b20890  a1bc59e500           mov eax, dword ptr [0xe559bc]
// 00b20895  50                   push eax
// 00b20896  e87918e6ff           call 0x982114
// 00b2089b  83c404               add esp, 4
// 00b2089e  c7059459e5002c3cb400 mov dword ptr [0xe55994], 0xb43c2c
// 00b208a8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b20890(int);
void func_00b20890()
{
    G4_func_00b20890(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
