// from server: 100% by EspClaude
// roc 2009-06 00430060  unit: COutputView  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00430060
//
// 00430060  56                   push esi
// 00430061  8bf1                 mov esi, ecx
// 00430063  8b461c               mov eax, dword ptr [esi + 0x1c]
// 00430066  40                   inc eax
// 00430067  57                   push edi
// 00430068  394614               cmp dword ptr [esi + 0x14], eax
// 0043006b  7707                 ja 0x430074
// 0043006d  6a01                 push 1
// 0043006f  e8acfdffff           call 0x42fe20
// 00430074  8b7e18               mov edi, dword ptr [esi + 0x18]
// 00430077  037e1c               add edi, dword ptr [esi + 0x1c]
// 0043007a  8b4614               mov eax, dword ptr [esi + 0x14]
// 0043007d  3bc7                 cmp eax, edi
// 0043007f  7702                 ja 0x430083
// 00430081  2bf8                 sub edi, eax
// 00430083  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00430086  833cb900             cmp dword ptr [ecx + edi*4], 0
// 0043008a  7510                 jne 0x43009c
// 0043008c  6a28                 push 0x28
// 0043008e  e8a5892e00           call 0x718a38
// 00430093  8b5610               mov edx, dword ptr [esi + 0x10]
// 00430096  83c404               add esp, 4
// 00430099  8904ba               mov dword ptr [edx + edi*4], eax
// 0043009c  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004300a0  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 004300a3  8b14b9               mov edx, dword ptr [ecx + edi*4]
// 004300a6  50                   push eax
// 004300a7  52                   push edx
// 004300a8  e843f8ffff           call 0x42f8f0
// 004300ad  ff461c               inc dword ptr [esi + 0x1c]
// 004300b0  83c408               add esp, 8
// 004300b3  5f                   pop edi
// 004300b4  5e                   pop esi
// 004300b5  c20400               ret 4
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
        blocks[index] = allocate(40);

    construct(blocks[index], value);
    ++count;
}
}
