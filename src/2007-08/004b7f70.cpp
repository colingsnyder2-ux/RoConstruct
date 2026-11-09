// from server: 100% by colin
// roc 2007-08 004b7f70  unit: seg_004b0000  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004b7f70
//
// 004b7f70  e8cbfeffff           call 0x4b7e40
// 004b7f75  6a00                 push 0
// 004b7f77  68e8030000           push 0x3e8
// 004b7f7c  52                   push edx
// 004b7f7d  50                   push eax
// 004b7f7e  e82d921700           call 0x6311b0
// 004b7f83  c3                   ret 

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD

struct Pair { unsigned int a; unsigned int b; };

extern "C" Pair __cdecl sub_4b7e40();
extern "C" void __stdcall sub_6311b0(unsigned int, unsigned int, unsigned int, unsigned int);

void sub_4b7f70()
{
    Pair p = sub_4b7e40();
    sub_6311b0(p.a, p.b, 0x3e8, 0);
}
