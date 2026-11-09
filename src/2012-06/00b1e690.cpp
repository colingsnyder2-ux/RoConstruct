// roc 2012-06 00b1e690  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1e690
//
// 00b1e690  a19408e500           mov eax, dword ptr [0xe50894]
// 00b1e695  50                   push eax
// 00b1e696  e8793ae6ff           call 0x982114
// 00b1e69b  83c404               add esp, 4
// 00b1e69e  c7056c08e5002c3cb400 mov dword ptr [0xe5086c], 0xb43c2c
// 00b1e6a8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1e690(int);
void func_00b1e690()
{
    G4_func_00b1e690(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
