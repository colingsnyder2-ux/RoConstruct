// roc 2012-06 00b11630  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11630
//
// 00b11630  a1987de100           mov eax, dword ptr [0xe17d98]
// 00b11635  50                   push eax
// 00b11636  e8d90ae7ff           call 0x982114
// 00b1163b  83c404               add esp, 4
// 00b1163e  c705707de1002c3cb400 mov dword ptr [0xe17d70], 0xb43c2c
// 00b11648  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b11630(int);
void func_00b11630()
{
    G4_func_00b11630(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
