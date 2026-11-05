// roc 2012-06 00b1fa40  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1fa40
//
// 00b1fa40  a19c34e500           mov eax, dword ptr [0xe5349c]
// 00b1fa45  50                   push eax
// 00b1fa46  e8c926e6ff           call 0x982114
// 00b1fa4b  83c404               add esp, 4
// 00b1fa4e  c7057034e5002c3cb400 mov dword ptr [0xe53470], 0xb43c2c
// 00b1fa58  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1fa40(int);
void func_00b1fa40()
{
    G4_func_00b1fa40(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
