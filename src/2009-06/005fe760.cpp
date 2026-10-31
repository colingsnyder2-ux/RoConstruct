// from server: 100% by EspClaude
// roc 2009-06 005fe760  unit: RBX::VInstance::?$NonFactoryProduct  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005fe760
//
// 005fe760  56                   push esi
// 005fe761  8bf1                 mov esi, ecx
// 005fe763  8b461c               mov eax, dword ptr [esi + 0x1c]
// 005fe766  40                   inc eax
// 005fe767  57                   push edi
// 005fe768  394614               cmp dword ptr [esi + 0x14], eax
// 005fe76b  7707                 ja 0x5fe774
// 005fe76d  6a01                 push 1
// 005fe76f  e8dcccedff           call 0x4db450
// 005fe774  8b7e18               mov edi, dword ptr [esi + 0x18]
// 005fe777  037e1c               add edi, dword ptr [esi + 0x1c]
// 005fe77a  8b4614               mov eax, dword ptr [esi + 0x14]
// 005fe77d  3bc7                 cmp eax, edi
// 005fe77f  7702                 ja 0x5fe783
// 005fe781  2bf8                 sub edi, eax
// 005fe783  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 005fe786  833cb900             cmp dword ptr [ecx + edi*4], 0
// 005fe78a  7510                 jne 0x5fe79c
// 005fe78c  6a20                 push 0x20
// 005fe78e  e8a5a21100           call 0x718a38
// 005fe793  8b5610               mov edx, dword ptr [esi + 0x10]
// 005fe796  83c404               add esp, 4
// 005fe799  8904ba               mov dword ptr [edx + edi*4], eax
// 005fe79c  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005fe7a0  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 005fe7a3  8b14b9               mov edx, dword ptr [ecx + edi*4]
// 005fe7a6  50                   push eax
// 005fe7a7  52                   push edx
// 005fe7a8  e8633afeff           call 0x5e2210
// 005fe7ad  ff461c               inc dword ptr [esi + 0x1c]
// 005fe7b0  83c408               add esp, 8
// 005fe7b3  5f                   pop edi
// 005fe7b4  5e                   pop esi
// 005fe7b5  c20400               ret 4
// copied from an identical function in another client (function ?append@S@ns_ROCX00001b@@QAEXPBX@Z)

namespace ns_ROCX00001b {
extern "C" void* __cdecl allocate(unsigned int);
extern "C" void __cdecl construct(void*, const void*);

struct S {
    unsigned int reserved[4];
    void** blocks;
    unsigned int capacity;
    unsigned int start;
    unsigned int count;

    void grow(unsigned int);
    void append(const void*);
};

void S::append(const void* value)
{
    if (capacity <= count + 1)
        grow(1);

    unsigned int index = start + count;
    if (capacity <= index)
        index -= capacity;

    if (blocks[index] == 0)
        blocks[index] = allocate(32);

    construct(blocks[index], value);
    ++count;
}
}
