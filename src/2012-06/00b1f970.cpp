// roc 2012-06 00b1f970  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f970
//
// 00b1f970  a16032e500           mov eax, dword ptr [0xe53260]
// 00b1f975  50                   push eax
// 00b1f976  e89927e6ff           call 0x982114
// 00b1f97b  83c404               add esp, 4
// 00b1f97e  c7053832e5002c3cb400 mov dword ptr [0xe53238], 0xb43c2c
// 00b1f988  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1f970(int);
void func_00b1f970()
{
    G4_func_00b1f970(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
