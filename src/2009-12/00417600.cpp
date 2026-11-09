// from server: 100% by nuck16
// roc 2009-12 00417600  unit: VCContent::?$CComObject  size: 99 bytes
//
// 00417600  64a100000000         mov eax, dword ptr fs:[0]
// 00417606  6aff                 push -1
// 00417608  68be819200           push 0x9281be
// 0041760d  50                   push eax
// 0041760e  b801000000           mov eax, 1
// 00417613  64892500000000       mov dword ptr fs:[0], esp
// 0041761a  8405a0a1b700         test byte ptr [0xb7a1a0], al
// 00417620  752e                 jne 0x417650
// 00417622  0905a0a1b700         or dword ptr [0xb7a1a0], eax
// 00417628  680c119d00           push 0x9d110c
// 0041762d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00417635  e8a6ac2100           call 0x6322e0
// 0041763a  83c404               add esp, 4
// 0041763d  a39ca1b700           mov dword ptr [0xb7a19c], eax
// 00417642  8b0c24               mov ecx, dword ptr [esp]
// 00417645  64890d00000000       mov dword ptr fs:[0], ecx
// 0041764c  83c40c               add esp, 0xc
// 0041764f  c3                   ret 
// 00417650  8b0c24               mov ecx, dword ptr [esp]
// 00417653  a19ca1b700           mov eax, dword ptr [0xb7a19c]
// 00417658  64890d00000000       mov dword ptr fs:[0], ecx
// 0041765f  83c40c               add esp, 0xc
// 00417662  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("StarterPack");
    return *name;
}
