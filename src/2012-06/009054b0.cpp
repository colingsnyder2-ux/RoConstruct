// from server: 100% by Xemicl
// from server: 100% by Xemicl
// roc 2012-06 0044f6d0  unit: boost::gregorian::Ubad_day_of_year::U?$error_info_injector::?$clone_impl  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0044f6d0
//
// 0044f6d0  56                   push esi
// 0044f6d1  8bf1                 mov esi, ecx
// 0044f6d3  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0044f6d6  40                   inc eax
// 0044f6d7  57                   push edi
// 0044f6d8  394614               cmp dword ptr [esi + 0x14], eax
// 0044f6db  7707                 ja 0x44f6e4
// 0044f6dd  6a01                 push 1
// 0044f6df  e8ec842800           call 0x6d7bd0
// 0044f6e4  8b7e18               mov edi, dword ptr [esi + 0x18]
// 0044f6e7  037e1c               add edi, dword ptr [esi + 0x1c]
// 0044f6ea  8b4614               mov eax, dword ptr [esi + 0x14]
// 0044f6ed  3bc7                 cmp eax, edi
// 0044f6ef  7702                 ja 0x44f6f3
// 0044f6f1  2bf8                 sub edi, eax
// 0044f6f3  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0044f6f6  833cb900             cmp dword ptr [ecx + edi*4], 0
// 0044f6fa  7510                 jne 0x44f70c
// 0044f6fc  6a28                 push 0x28
// 0044f6fe  e8172a5300           call 0x98211a
// 0044f703  8b5610               mov edx, dword ptr [esi + 0x10]
// 0044f706  83c404               add esp, 4
// 0044f709  8904ba               mov dword ptr [edx + edi*4], eax
// 0044f70c  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0044f710  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0044f713  8b14b9               mov edx, dword ptr [ecx + edi*4]
// 0044f716  50                   push eax
// 0044f717  52                   push edx
// 0044f718  e813dfffff           call 0x44d630
// 0044f71d  ff461c               inc dword ptr [esi + 0x1c]
// 0044f720  83c408               add esp, 8
// 0044f723  5f                   pop edi
// 0044f724  5e                   pop esi
// 0044f725  c20400               ret 4

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
        blocks[index] = allocate(36);

    construct(blocks[index], value);
    ++count;
}
}
