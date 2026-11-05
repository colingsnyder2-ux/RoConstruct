// roc 2012-06 00b208d0  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b208d0
//
// 00b208d0  a1985ae500           mov eax, dword ptr [0xe55a98]
// 00b208d5  50                   push eax
// 00b208d6  e83918e6ff           call 0x982114
// 00b208db  83c404               add esp, 4
// 00b208de  c705705ae5002c3cb400 mov dword ptr [0xe55a70], 0xb43c2c
// 00b208e8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b208d0(int);
void func_00b208d0()
{
    G4_func_00b208d0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
