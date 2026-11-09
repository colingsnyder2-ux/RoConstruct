// from server: 100% by colin
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc 2007-08 0076f350  unit: seg_00760000  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0076f350
//
// 0076f350  33c9                 xor ecx, ecx
// 0076f352  51                   push ecx
// 0076f353  68b80b0000           push 0xbb8
// 0076f358  6824c57900           push 0x79c524
// 0076f35d  6818c57900           push 0x79c518
// 0076f362  51                   push ecx
// 0076f363  b860964900           mov eax, 0x499660
// 0076f368  50                   push eax
// 0076f369  b9a0e58b00           mov ecx, 0x8be5a0
// 0076f36e  e8fdc8d2ff           call 0x49bc70
// 0076f373  6810877700           push 0x778710
// 0076f378  e8a619ecff           call 0x630d23
// 0076f37d  59                   pop ecx
// 0076f37e  c3                   ret 
// library rbxgs-net/Players.cpp (function ??__EblockDuration@@YAXXZ)

// roc-lang: cpp
// roc-lib: rbxgs-net Players.cpp

extern "C" int __cdecl sub_49BC70(int, int, int, int, int, int);
extern "C" int __cdecl sub_630D23(int);

int __cdecl sub_76F350()
{
    sub_49BC70(0, 0x499660, 0, 0x79C518, 0x79C524, 0xBB8);
    sub_630D23(0x778710);
    return 0;
}
