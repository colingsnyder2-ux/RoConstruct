// roc 2012-06 00b20040  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20040
//
// 00b20040  a1f44fe500           mov eax, dword ptr [0xe54ff4]
// 00b20045  50                   push eax
// 00b20046  e8c920e6ff           call 0x982114
// 00b2004b  83c404               add esp, 4
// 00b2004e  c705cc4fe5002c3cb400 mov dword ptr [0xe54fcc], 0xb43c2c
// 00b20058  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b20040(int);
void func_00b20040()
{
    G4_func_00b20040(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
