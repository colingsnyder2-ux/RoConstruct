// from server: 100% by Xemicl
// roc 2012-06 00864840  unit: RBX::BaseThreadPool::UPoolData::XP6AXV?$shared_ptr::V?$bind_t::?$thread_data  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00864840
//
// 00864840  56                   push esi
// 00864841  8bf1                 mov esi, ecx
// 00864843  8b461c               mov eax, dword ptr [esi + 0x1c]
// 00864846  40                   inc eax
// 00864847  57                   push edi
// 00864848  394614               cmp dword ptr [esi + 0x14], eax
// 0086484b  7707                 ja 0x864854
// 0086484d  6a01                 push 1
// 0086484f  e86cf9ffff           call 0x8641c0
// 00864854  8b7e18               mov edi, dword ptr [esi + 0x18]
// 00864857  037e1c               add edi, dword ptr [esi + 0x1c]
// 0086485a  8b4614               mov eax, dword ptr [esi + 0x14]
// 0086485d  3bc7                 cmp eax, edi
// 0086485f  7702                 ja 0x864863
// 00864861  2bf8                 sub edi, eax
// 00864863  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00864866  833cb900             cmp dword ptr [ecx + edi*4], 0
// 0086486a  7510                 jne 0x86487c
// 0086486c  6a20                 push 0x20
// 0086486e  e8a7d81100           call 0x98211a
// 00864873  8b5610               mov edx, dword ptr [esi + 0x10]
// 00864876  83c404               add esp, 4
// 00864879  8904ba               mov dword ptr [edx + edi*4], eax
// 0086487c  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00864880  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00864883  8b14b9               mov edx, dword ptr [ecx + edi*4]
// 00864886  50                   push eax
// 00864887  52                   push edx
// 00864888  e83322feff           call 0x846ac0
// 0086488d  ff461c               inc dword ptr [esi + 0x1c]
// 00864890  83c408               add esp, 8
// 00864893  5f                   pop edi
// 00864894  5e                   pop esi
// 00864895  c20400               ret 4
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