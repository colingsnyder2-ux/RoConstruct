// from server: 100% by Yeetserama
// roc 2011-06 005edeb0  unit: boost::io::Vtoo_many_args::U?$error_info_injector::?$clone_impl  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005edeb0
//
// 005edeb0  56                   push esi
// 005edeb1  8bf1                 mov esi, ecx
// 005edeb3  8b461c               mov eax, dword ptr [esi + 0x1c]
// 005edeb6  40                   inc eax
// 005edeb7  57                   push edi
// 005edeb8  394614               cmp dword ptr [esi + 0x14], eax
// 005edebb  7707                 ja 0x5edec4
// 005edebd  6a01                 push 1
// 005edebf  e8ec32e5ff           call 0x4411b0
// 005edec4  8b7e18               mov edi, dword ptr [esi + 0x18]
// 005edec7  037e1c               add edi, dword ptr [esi + 0x1c]
// 005edeca  8b4614               mov eax, dword ptr [esi + 0x14]
// 005edecd  3bc7                 cmp eax, edi
// 005edecf  7702                 ja 0x5eded3
// 005eded1  2bf8                 sub edi, eax
// 005eded3  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 005eded6  833cb900             cmp dword ptr [ecx + edi*4], 0
// 005ededa  7510                 jne 0x5edeec
// 005ededc  6a28                 push 0x28
// 005edede  e87bc12100           call 0x80a05e
// 005edee3  8b5610               mov edx, dword ptr [esi + 0x10]
// 005edee6  83c404               add esp, 4
// 005edee9  8904ba               mov dword ptr [edx + edi*4], eax
// 005edeec  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005edef0  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 005edef3  8b14b9               mov edx, dword ptr [ecx + edi*4]
// 005edef6  50                   push eax
// 005edef7  52                   push edx
// 005edef8  e8f3d8ffff           call 0x5eb7f0
// 005edefd  ff461c               inc dword ptr [esi + 0x1c]
// 005edf00  83c408               add esp, 8
// 005edf03  5f                   pop edi
// 005edf04  5e                   pop esi
// 005edf05  c20400               ret 4
// copied from an identical function in another client (function ?append@S@ns_ROCX000016@@QAEXPBX@Z)

namespace ns_ROCX000016 {
// from server: 100% by tester
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
        blocks[index] = allocate(40);

    construct(blocks[index], value);
    ++count;
}
}
