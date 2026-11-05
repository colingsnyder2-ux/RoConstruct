// roc 2012-06 00b20970  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20970
//
// 00b20970  a1705be500           mov eax, dword ptr [0xe55b70]
// 00b20975  50                   push eax
// 00b20976  e89917e6ff           call 0x982114
// 00b2097b  83c404               add esp, 4
// 00b2097e  c705445be5002c3cb400 mov dword ptr [0xe55b44], 0xb43c2c
// 00b20988  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b20970(int);
void func_00b20970()
{
    G4_func_00b20970(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
