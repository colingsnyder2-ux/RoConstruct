// roc 2012-06 00b20d70  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20d70
//
// 00b20d70  a14063e500           mov eax, dword ptr [0xe56340]
// 00b20d75  50                   push eax
// 00b20d76  e89913e6ff           call 0x982114
// 00b20d7b  83c404               add esp, 4
// 00b20d7e  c7051863e5002c3cb400 mov dword ptr [0xe56318], 0xb43c2c
// 00b20d88  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b20d70(int);
void func_00b20d70()
{
    G4_func_00b20d70(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
