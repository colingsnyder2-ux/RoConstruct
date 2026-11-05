// roc 2012-06 00b177d0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b177d0
//
// 00b177d0  a12024e300           mov eax, dword ptr [0xe32420]
// 00b177d5  50                   push eax
// 00b177d6  e839a9e6ff           call 0x982114
// 00b177db  83c404               add esp, 4
// 00b177de  c705f423e3002c3cb400 mov dword ptr [0xe323f4], 0xb43c2c
// 00b177e8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b177d0(int);
void func_00b177d0()
{
    G4_func_00b177d0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
