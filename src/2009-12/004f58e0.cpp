// from server: 100% by nuck16
// roc 2009-12 004f58e0  unit: RBX::GfxAttachement  size: 99 bytes
//
// 004f58e0  64a100000000         mov eax, dword ptr fs:[0]
// 004f58e6  6aff                 push -1
// 004f58e8  68ae569300           push 0x9356ae
// 004f58ed  50                   push eax
// 004f58ee  b801000000           mov eax, 1
// 004f58f3  64892500000000       mov dword ptr fs:[0], esp
// 004f58fa  8405d8ddb700         test byte ptr [0xb7ddd8], al
// 004f5900  752e                 jne 0x4f5930
// 004f5902  0905d8ddb700         or dword ptr [0xb7ddd8], eax
// 004f5908  68347ab400           push 0xb47a34
// 004f590d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 004f5915  e8c6c91300           call 0x6322e0
// 004f591a  83c404               add esp, 4
// 004f591d  a3d4ddb700           mov dword ptr [0xb7ddd4], eax
// 004f5922  8b0c24               mov ecx, dword ptr [esp]
// 004f5925  64890d00000000       mov dword ptr fs:[0], ecx
// 004f592c  83c40c               add esp, 0xc
// 004f592f  c3                   ret 
// 004f5930  8b0c24               mov ecx, dword ptr [esp]
// 004f5933  a1d4ddb700           mov eax, dword ptr [0xb7ddd4]
// 004f5938  64890d00000000       mov dword ptr fs:[0], ecx
// 004f593f  83c40c               add esp, 0xc
// 004f5942  c3                   ret 

extern char string_00b47a34[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b47a34);
    return *name;
}
