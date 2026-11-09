// roc 2012-06 00b1f560  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f560
//
// 00b1f560  a1782ae500           mov eax, dword ptr [0xe52a78]
// 00b1f565  50                   push eax
// 00b1f566  e8a92be6ff           call 0x982114
// 00b1f56b  83c404               add esp, 4
// 00b1f56e  c705502ae5002c3cb400 mov dword ptr [0xe52a50], 0xb43c2c
// 00b1f578  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1f560(int);
void func_00b1f560()
{
    G4_func_00b1f560(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
