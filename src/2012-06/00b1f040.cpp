// roc 2012-06 00b1f040  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f040
//
// 00b1f040  a1a823e500           mov eax, dword ptr [0xe523a8]
// 00b1f045  50                   push eax
// 00b1f046  e8c930e6ff           call 0x982114
// 00b1f04b  83c404               add esp, 4
// 00b1f04e  c7058023e5002c3cb400 mov dword ptr [0xe52380], 0xb43c2c
// 00b1f058  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1f040(int);
void func_00b1f040()
{
    G4_func_00b1f040(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
