// from server: 100% by EspClaude
// roc 2009-06 0042fc40  unit: COutputView  size: 133 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0042fc40
//
// 0042fc40  53                   push ebx
// 0042fc41  56                   push esi
// 0042fc42  8bf1                 mov esi, ecx
// 0042fc44  33db                 xor ebx, ebx
// 0042fc46  57                   push edi
// 0042fc47  395e1c               cmp dword ptr [esi + 0x1c], ebx
// 0042fc4a  7437                 je 0x42fc83
// 0042fc4c  83cfff               or edi, 0xffffffff
// 0042fc4f  90                   nop 
// 0042fc50  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0042fc53  3bc3                 cmp eax, ebx
// 0042fc55  7427                 je 0x42fc7e
// 0042fc57  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0042fc5a  8d4408ff             lea eax, [eax + ecx - 1]
// 0042fc5e  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 0042fc61  3bc8                 cmp ecx, eax
// 0042fc63  7702                 ja 0x42fc67
// 0042fc65  2bc1                 sub eax, ecx
// 0042fc67  8b5610               mov edx, dword ptr [esi + 0x10]
// 0042fc6a  8b0c82               mov ecx, dword ptr [edx + eax*4]
// 0042fc6d  83c104               add ecx, 4
// 0042fc70  ff15c4e48900         call dword ptr [0x89e4c4]
// 0042fc76  017e1c               add dword ptr [esi + 0x1c], edi
// 0042fc79  7503                 jne 0x42fc7e
// 0042fc7b  895e18               mov dword ptr [esi + 0x18], ebx
// 0042fc7e  395e1c               cmp dword ptr [esi + 0x1c], ebx
// 0042fc81  75cd                 jne 0x42fc50
// 0042fc83  8b7e14               mov edi, dword ptr [esi + 0x14]
// 0042fc86  3bfb                 cmp edi, ebx
// 0042fc88  7621                 jbe 0x42fcab
// 0042fc8a  8d9b00000000         lea ebx, [ebx]
// 0042fc90  8b4610               mov eax, dword ptr [esi + 0x10]
// 0042fc93  4f                   dec edi
// 0042fc94  391cb8               cmp dword ptr [eax + edi*4], ebx
// 0042fc97  8d04b8               lea eax, [eax + edi*4]
// 0042fc9a  740b                 je 0x42fca7
// 0042fc9c  8b08                 mov ecx, dword ptr [eax]
// 0042fc9e  51                   push ecx
// 0042fc9f  e88e8d2e00           call 0x718a32
// 0042fca4  83c404               add esp, 4
// 0042fca7  3bfb                 cmp edi, ebx
// 0042fca9  77e5                 ja 0x42fc90
// 0042fcab  8b4610               mov eax, dword ptr [esi + 0x10]
// 0042fcae  3bc3                 cmp eax, ebx
// 0042fcb0  7409                 je 0x42fcbb
// 0042fcb2  50                   push eax
// 0042fcb3  e87a8d2e00           call 0x718a32
// 0042fcb8  83c404               add esp, 4
// 0042fcbb  5f                   pop edi
// 0042fcbc  895e10               mov dword ptr [esi + 0x10], ebx
// 0042fcbf  895e14               mov dword ptr [esi + 0x14], ebx
// 0042fcc2  5e                   pop esi
// 0042fcc3  5b                   pop ebx
// 0042fcc4  c3                   ret 
// copied from an identical function in another client (function ?clear@COutputView@ns_ROCX000017@@QAEXXZ)

namespace ns_ROCX000017 {
extern void (__thiscall *destroyString)(void *);
extern void __cdecl release(void *);

struct COutputView {
    unsigned char padding[16];
    char **slots;
    unsigned capacity;
    unsigned first;
    unsigned count;

    void clear();
};

void COutputView::clear()
{
    while (count != 0) {
        if (count != 0) {
            unsigned index = first + count - 1;
            if (capacity <= index)
                index -= capacity;

            destroyString(slots[index] + 4);

            if (--count == 0)
                first = 0;
        }
    }

    unsigned i = capacity;
    while (i > 0) {
        --i;
        if (slots[i] != 0)
            release(slots[i]);
    }

    if (slots != 0)
        release(slots);

    capacity = 0;
    slots = 0;
}
}
