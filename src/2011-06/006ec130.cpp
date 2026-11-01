// from server: 100% by Yeetserama
// roc 2011-06 006ec130  unit: RBX::BaseThreadPool::UPoolData::XP6AXV?$shared_ptr::V?$bind_t::?$thread_data  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006ec130
//
// 006ec130  56                   push esi
// 006ec131  8bf1                 mov esi, ecx
// 006ec133  8b461c               mov eax, dword ptr [esi + 0x1c]
// 006ec136  40                   inc eax
// 006ec137  57                   push edi
// 006ec138  394614               cmp dword ptr [esi + 0x14], eax
// 006ec13b  7707                 ja 0x6ec144
// 006ec13d  6a01                 push 1
// 006ec13f  e89cf9ffff           call 0x6ebae0
// 006ec144  8b7e18               mov edi, dword ptr [esi + 0x18]
// 006ec147  037e1c               add edi, dword ptr [esi + 0x1c]
// 006ec14a  8b4614               mov eax, dword ptr [esi + 0x14]
// 006ec14d  3bc7                 cmp eax, edi
// 006ec14f  7702                 ja 0x6ec153
// 006ec151  2bf8                 sub edi, eax
// 006ec153  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 006ec156  833cb900             cmp dword ptr [ecx + edi*4], 0
// 006ec15a  7510                 jne 0x6ec16c
// 006ec15c  6a20                 push 0x20
// 006ec15e  e8fbde1100           call 0x80a05e
// 006ec163  8b5610               mov edx, dword ptr [esi + 0x10]
// 006ec166  83c404               add esp, 4
// 006ec169  8904ba               mov dword ptr [edx + edi*4], eax
// 006ec16c  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006ec170  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 006ec173  8b14b9               mov edx, dword ptr [ecx + edi*4]
// 006ec176  50                   push eax
// 006ec177  52                   push edx
// 006ec178  e863860800           call 0x7747e0
// 006ec17d  ff461c               inc dword ptr [esi + 0x1c]
// 006ec180  83c408               add esp, 8
// 006ec183  5f                   pop edi
// 006ec184  5e                   pop esi
// 006ec185  c20400               ret 4
// copied from an identical function in another client (function ?append@S@ns_ROCX000019@@QAEXPBX@Z)

namespace ns_ROCX000019 {
// from server: 100% by king_originala
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
