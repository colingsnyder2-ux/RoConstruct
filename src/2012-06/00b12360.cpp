// roc 2012-06 00b12360  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12360
//
// 00b12360  a1e898e100           mov eax, dword ptr [0xe198e8]
// 00b12365  50                   push eax
// 00b12366  e8a9fde6ff           call 0x982114
// 00b1236b  83c404               add esp, 4
// 00b1236e  c705c098e1002c3cb400 mov dword ptr [0xe198c0], 0xb43c2c
// 00b12378  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b12360(int);
void func_00b12360()
{
    G4_func_00b12360(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
