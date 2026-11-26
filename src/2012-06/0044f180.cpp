// from server: 100% by Xemicl
// roc 2012-06 0044f180  unit: boost::gregorian::Ubad_day_of_year::U?$error_info_injector::?$clone_impl  size: 149 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0044f180
//
// 0044f180  53                   push ebx
// 0044f181  56                   push esi
// 0044f182  8bf1                 mov esi, ecx
// 0044f184  33db                 xor ebx, ebx
// 0044f186  57                   push edi
// 0044f187  395e1c               cmp dword ptr [esi + 0x1c], ebx
// 0044f18a  7447                 je 0x44f1d3
// 0044f18c  83cfff               or edi, 0xffffffff
// 0044f18f  90                   nop 
// 0044f190  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0044f193  3bc3                 cmp eax, ebx
// 0044f195  7437                 je 0x44f1ce
// 0044f197  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0044f19a  8b5614               mov edx, dword ptr [esi + 0x14]
// 0044f19d  8d4408ff             lea eax, [eax + ecx - 1]
// 0044f1a1  8bc8                 mov ecx, eax
// 0044f1a3  c1e902               shr ecx, 2
// 0044f1a6  3bd1                 cmp edx, ecx
// 0044f1a8  7702                 ja 0x44f1ac
// 0044f1aa  2bca                 sub ecx, edx
// 0044f1ac  8b5610               mov edx, dword ptr [esi + 0x10]
// 0044f1af  8b0c8a               mov ecx, dword ptr [edx + ecx*4]
// 0044f1b2  83e003               and eax, 3
// 0044f1b5  8d0481               lea eax, [ecx + eax*4]
// 0044f1b8  8b00                 mov eax, dword ptr [eax]
// 0044f1ba  3bc3                 cmp eax, ebx
// 0044f1bc  7408                 je 0x44f1c6
// 0044f1be  8b10                 mov edx, dword ptr [eax]
// 0044f1c0  50                   push eax
// 0044f1c1  8b4208               mov eax, dword ptr [edx + 8]
// 0044f1c4  ffd0                 call eax
// 0044f1c6  017e1c               add dword ptr [esi + 0x1c], edi
// 0044f1c9  7503                 jne 0x44f1ce
// 0044f1cb  895e18               mov dword ptr [esi + 0x18], ebx
// 0044f1ce  395e1c               cmp dword ptr [esi + 0x1c], ebx
// 0044f1d1  75bd                 jne 0x44f190
// 0044f1d3  8b7e14               mov edi, dword ptr [esi + 0x14]
// 0044f1d6  3bfb                 cmp edi, ebx
// 0044f1d8  7621                 jbe 0x44f1fb
// 0044f1da  8d9b00000000         lea ebx, [ebx]
// 0044f1e0  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0044f1e3  4f                   dec edi
// 0044f1e4  391cb9               cmp dword ptr [ecx + edi*4], ebx
// 0044f1e7  8d04b9               lea eax, [ecx + edi*4]
// 0044f1ea  740b                 je 0x44f1f7
// 0044f1ec  8b10                 mov edx, dword ptr [eax]
// 0044f1ee  52                   push edx
// 0044f1ef  e8202f5300           call 0x982114
// 0044f1f4  83c404               add esp, 4
// 0044f1f7  3bfb                 cmp edi, ebx
// 0044f1f9  77e5                 ja 0x44f1e0
// 0044f1fb  8b4610               mov eax, dword ptr [esi + 0x10]
// 0044f1fe  3bc3                 cmp eax, ebx
// 0044f200  7409                 je 0x44f20b
// 0044f202  50                   push eax
// 0044f203  e80c2f5300           call 0x982114
// 0044f208  83c404               add esp, 4
// 0044f20b  5f                   pop edi
// 0044f20c  895e10               mov dword ptr [esi + 0x10], ebx
// 0044f20f  895e14               mov dword ptr [esi + 0x14], ebx
// 0044f212  5e                   pop esi
// 0044f213  5b                   pop ebx
// 0044f214  c3                   ret 
// copied from an identical function in another client (function ?clear@COutputView@ns_ROCX000018@@QAEXXZ)

namespace ns_ROCX000018 {
extern "C" void __cdecl free_mem(void *);

struct Item;

struct ItemVTable {
    void (__stdcall *slots[3])(Item *);
};

struct Item {
    ItemVTable *vtable;
};

struct COutputView {
    unsigned char padding[16];
    Item ***map;
    unsigned int mapSize;
    unsigned int first;
    unsigned int size;

    void clear();
};

void COutputView::clear()
{
    while (size != 0) {
        if (size != 0) {
            unsigned int idx = size + first - 1;
            unsigned int bucket = idx >> 2;
            if (mapSize <= bucket)
                bucket -= mapSize;
            Item *&item = map[bucket][idx & 3];
            if (item != 0)
                item->vtable->slots[2](item);

            if (--size == 0)
                first = 0;
        }
    }

    unsigned int i = mapSize;
    while (i > 0) {
        --i;
        if (map[i] != 0)
            free_mem(map[i]);
    }

    if (map != 0)
        free_mem(map);

    mapSize = 0;
    map = 0;
}
}