// roc 2012-06 00b1f880  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f880
//
// 00b1f880  a1c430e500           mov eax, dword ptr [0xe530c4]
// 00b1f885  50                   push eax
// 00b1f886  e88928e6ff           call 0x982114
// 00b1f88b  83c404               add esp, 4
// 00b1f88e  c7059c30e5002c3cb400 mov dword ptr [0xe5309c], 0xb43c2c
// 00b1f898  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1f880(int);
void func_00b1f880()
{
    G4_func_00b1f880(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
