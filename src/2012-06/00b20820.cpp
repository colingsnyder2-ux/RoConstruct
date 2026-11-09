// roc 2012-06 00b20820  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20820
//
// 00b20820  a1c058e500           mov eax, dword ptr [0xe558c0]
// 00b20825  50                   push eax
// 00b20826  e8e918e6ff           call 0x982114
// 00b2082b  83c404               add esp, 4
// 00b2082e  c7059858e5002c3cb400 mov dword ptr [0xe55898], 0xb43c2c
// 00b20838  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b20820(int);
void func_00b20820()
{
    G4_func_00b20820(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
