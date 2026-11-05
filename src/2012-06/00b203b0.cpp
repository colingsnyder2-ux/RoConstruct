// roc 2012-06 00b203b0  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b203b0
//
// 00b203b0  a18052e500           mov eax, dword ptr [0xe55280]
// 00b203b5  50                   push eax
// 00b203b6  e8591de6ff           call 0x982114
// 00b203bb  83c404               add esp, 4
// 00b203be  c7055852e5002c3cb400 mov dword ptr [0xe55258], 0xb43c2c
// 00b203c8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b203b0(int);
void func_00b203b0()
{
    G4_func_00b203b0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
