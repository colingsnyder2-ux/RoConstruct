// roc 2012-06 00b1e370  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1e370
//
// 00b1e370  a1d404e500           mov eax, dword ptr [0xe504d4]
// 00b1e375  50                   push eax
// 00b1e376  e8993de6ff           call 0x982114
// 00b1e37b  83c404               add esp, 4
// 00b1e37e  c705ac04e5002c3cb400 mov dword ptr [0xe504ac], 0xb43c2c
// 00b1e388  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1e370(int);
void func_00b1e370()
{
    G4_func_00b1e370(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
