// roc 2012-06 00b15360  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15360
//
// 00b15360  a14498e200           mov eax, dword ptr [0xe29844]
// 00b15365  50                   push eax
// 00b15366  e8a9cde6ff           call 0x982114
// 00b1536b  83c404               add esp, 4
// 00b1536e  c7051898e2002c3cb400 mov dword ptr [0xe29818], 0xb43c2c
// 00b15378  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b15360(int);
void func_00b15360()
{
    G4_func_00b15360(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
