// roc 2012-06 00b12040  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12040
//
// 00b12040  a1349de100           mov eax, dword ptr [0xe19d34]
// 00b12045  50                   push eax
// 00b12046  e8c900e7ff           call 0x982114
// 00b1204b  83c404               add esp, 4
// 00b1204e  c705089de1002c3cb400 mov dword ptr [0xe19d08], 0xb43c2c
// 00b12058  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b12040(int);
void func_00b12040()
{
    G4_func_00b12040(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
