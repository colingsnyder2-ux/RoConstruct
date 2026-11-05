// roc 2012-06 00b17710  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17710
//
// 00b17710  a19c20e300           mov eax, dword ptr [0xe3209c]
// 00b17715  50                   push eax
// 00b17716  e8f9a9e6ff           call 0x982114
// 00b1771b  83c404               add esp, 4
// 00b1771e  c7057420e3002c3cb400 mov dword ptr [0xe32074], 0xb43c2c
// 00b17728  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b17710(int);
void func_00b17710()
{
    G4_func_00b17710(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
