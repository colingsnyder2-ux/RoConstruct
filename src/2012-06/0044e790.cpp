// from server: 100% by Xemicl
// roc 2012-06 0044e790  unit: boost::gregorian::Ubad_day_of_year::?$error_info_injector  size: 133 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0044e790
//
// 0044e790  53                   push ebx
// 0044e791  56                   push esi
// 0044e792  8bf1                 mov esi, ecx
// 0044e794  33db                 xor ebx, ebx
// 0044e796  57                   push edi
// 0044e797  395e1c               cmp dword ptr [esi + 0x1c], ebx
// 0044e79a  7437                 je 0x44e7d3
// 0044e79c  83cfff               or edi, 0xffffffff
// 0044e79f  90                   nop 
// 0044e7a0  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0044e7a3  3bc3                 cmp eax, ebx
// 0044e7a5  7427                 je 0x44e7ce
// 0044e7a7  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0044e7aa  8d4408ff             lea eax, [eax + ecx - 1]
// 0044e7ae  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 0044e7b1  3bc8                 cmp ecx, eax
// 0044e7b3  7702                 ja 0x44e7b7
// 0044e7b5  2bc1                 sub eax, ecx
// 0044e7b7  8b5610               mov edx, dword ptr [esi + 0x10]
// 0044e7ba  8b0c82               mov ecx, dword ptr [edx + eax*4]
// 0044e7bd  83c104               add ecx, 4
// 0044e7c0  ff153c26b200         call dword ptr [0xb2263c]
// 0044e7c6  017e1c               add dword ptr [esi + 0x1c], edi
// 0044e7c9  7503                 jne 0x44e7ce
// 0044e7cb  895e18               mov dword ptr [esi + 0x18], ebx
// 0044e7ce  395e1c               cmp dword ptr [esi + 0x1c], ebx
// 0044e7d1  75cd                 jne 0x44e7a0
// 0044e7d3  8b7e14               mov edi, dword ptr [esi + 0x14]
// 0044e7d6  3bfb                 cmp edi, ebx
// 0044e7d8  7621                 jbe 0x44e7fb
// 0044e7da  8d9b00000000         lea ebx, [ebx]
// 0044e7e0  8b4610               mov eax, dword ptr [esi + 0x10]
// 0044e7e3  4f                   dec edi
// 0044e7e4  391cb8               cmp dword ptr [eax + edi*4], ebx
// 0044e7e7  8d04b8               lea eax, [eax + edi*4]
// 0044e7ea  740b                 je 0x44e7f7
// 0044e7ec  8b08                 mov ecx, dword ptr [eax]
// 0044e7ee  51                   push ecx
// 0044e7ef  e820395300           call 0x982114
// 0044e7f4  83c404               add esp, 4
// 0044e7f7  3bfb                 cmp edi, ebx
// 0044e7f9  77e5                 ja 0x44e7e0
// 0044e7fb  8b4610               mov eax, dword ptr [esi + 0x10]
// 0044e7fe  3bc3                 cmp eax, ebx
// 0044e800  7409                 je 0x44e80b
// 0044e802  50                   push eax
// 0044e803  e80c395300           call 0x982114
// 0044e808  83c404               add esp, 4
// 0044e80b  5f                   pop edi
// 0044e80c  895e10               mov dword ptr [esi + 0x10], ebx
// 0044e80f  895e14               mov dword ptr [esi + 0x14], ebx
// 0044e812  5e                   pop esi
// 0044e813  5b                   pop ebx
// 0044e814  c3                   ret 
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