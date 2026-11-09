// roc 2012-06 00b1f540  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f540
//
// 00b1f540  a15829e500           mov eax, dword ptr [0xe52958]
// 00b1f545  50                   push eax
// 00b1f546  e8c92be6ff           call 0x982114
// 00b1f54b  83c404               add esp, 4
// 00b1f54e  c7053029e5002c3cb400 mov dword ptr [0xe52930], 0xb43c2c
// 00b1f558  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1f540(int);
void func_00b1f540()
{
    G4_func_00b1f540(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
