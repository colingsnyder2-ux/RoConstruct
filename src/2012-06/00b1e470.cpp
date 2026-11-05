// roc 2012-06 00b1e470  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1e470
//
// 00b1e470  a10005e500           mov eax, dword ptr [0xe50500]
// 00b1e475  50                   push eax
// 00b1e476  e8993ce6ff           call 0x982114
// 00b1e47b  83c404               add esp, 4
// 00b1e47e  c705d804e5002c3cb400 mov dword ptr [0xe504d8], 0xb43c2c
// 00b1e488  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1e470(int);
void func_00b1e470()
{
    G4_func_00b1e470(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
