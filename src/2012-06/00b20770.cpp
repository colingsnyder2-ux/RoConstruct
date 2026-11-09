// roc 2012-06 00b20770  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20770
//
// 00b20770  a18857e500           mov eax, dword ptr [0xe55788]
// 00b20775  50                   push eax
// 00b20776  e89919e6ff           call 0x982114
// 00b2077b  83c404               add esp, 4
// 00b2077e  c7056057e5002c3cb400 mov dword ptr [0xe55760], 0xb43c2c
// 00b20788  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b20770(int);
void func_00b20770()
{
    G4_func_00b20770(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
