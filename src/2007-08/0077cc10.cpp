// from server: 100% by colin
// roc 2007-08 0077cc10  unit: seg_00770000  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0077cc10
//
// 0077cc10  6870b94400           push 0x44b970
// 0077cc15  6a28                 push 0x28
// 0077cc17  6a0c                 push 0xc
// 0077cc19  68588d8c00           push 0x8c8d58
// 0077cc1e  e8d43eebff           call 0x630af7
// 0077cc23  c3                   ret 

extern "C" void __stdcall sub_00630AF7(int, int, int, int);

void __stdcall sub_0077CC10()
{
    sub_00630AF7(0x8c8d58, 0xc, 0x28, 0x44b970);
}
