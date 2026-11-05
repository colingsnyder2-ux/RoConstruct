// from server: 100% by EspClaude
// roc 2009-06 0042fd80  unit: COutputView  size: 149 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0042fd80
//
// 0042fd80  53                   push ebx
// 0042fd81  56                   push esi
// 0042fd82  8bf1                 mov esi, ecx
// 0042fd84  33db                 xor ebx, ebx
// 0042fd86  57                   push edi
// 0042fd87  395e1c               cmp dword ptr [esi + 0x1c], ebx
// 0042fd8a  7447                 je 0x42fdd3
// 0042fd8c  83cfff               or edi, 0xffffffff
// 0042fd8f  90                   nop 
// 0042fd90  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0042fd93  3bc3                 cmp eax, ebx
// 0042fd95  7437                 je 0x42fdce
// 0042fd97  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0042fd9a  8b5614               mov edx, dword ptr [esi + 0x14]
// 0042fd9d  8d4408ff             lea eax, [eax + ecx - 1]
// 0042fda1  8bc8                 mov ecx, eax
// 0042fda3  c1e902               shr ecx, 2
// 0042fda6  3bd1                 cmp edx, ecx
// 0042fda8  7702                 ja 0x42fdac
// 0042fdaa  2bca                 sub ecx, edx
// 0042fdac  8b5610               mov edx, dword ptr [esi + 0x10]
// 0042fdaf  8b0c8a               mov ecx, dword ptr [edx + ecx*4]
// 0042fdb2  83e003               and eax, 3
// 0042fdb5  8d0481               lea eax, [ecx + eax*4]
// 0042fdb8  8b00                 mov eax, dword ptr [eax]
// 0042fdba  3bc3                 cmp eax, ebx
// 0042fdbc  7408                 je 0x42fdc6
// 0042fdbe  8b10                 mov edx, dword ptr [eax]
// 0042fdc0  50                   push eax
// 0042fdc1  8b4208               mov eax, dword ptr [edx + 8]
// 0042fdc4  ffd0                 call eax
// 0042fdc6  017e1c               add dword ptr [esi + 0x1c], edi
// 0042fdc9  7503                 jne 0x42fdce
// 0042fdcb  895e18               mov dword ptr [esi + 0x18], ebx
// 0042fdce  395e1c               cmp dword ptr [esi + 0x1c], ebx
// 0042fdd1  75bd                 jne 0x42fd90
// 0042fdd3  8b7e14               mov edi, dword ptr [esi + 0x14]
// 0042fdd6  3bfb                 cmp edi, ebx
// 0042fdd8  7621                 jbe 0x42fdfb
// 0042fdda  8d9b00000000         lea ebx, [ebx]
// 0042fde0  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0042fde3  4f                   dec edi
// 0042fde4  391cb9               cmp dword ptr [ecx + edi*4], ebx
// 0042fde7  8d04b9               lea eax, [ecx + edi*4]
// 0042fdea  740b                 je 0x42fdf7
// 0042fdec  8b10                 mov edx, dword ptr [eax]
// 0042fdee  52                   push edx
// 0042fdef  e83e8c2e00           call 0x718a32
// 0042fdf4  83c404               add esp, 4
// 0042fdf7  3bfb                 cmp edi, ebx
// 0042fdf9  77e5                 ja 0x42fde0
// 0042fdfb  8b4610               mov eax, dword ptr [esi + 0x10]
// 0042fdfe  3bc3                 cmp eax, ebx
// 0042fe00  7409                 je 0x42fe0b
// 0042fe02  50                   push eax
// 0042fe03  e82a8c2e00           call 0x718a32
// 0042fe08  83c404               add esp, 4
// 0042fe0b  5f                   pop edi
// 0042fe0c  895e10               mov dword ptr [esi + 0x10], ebx
// 0042fe0f  895e14               mov dword ptr [esi + 0x14], ebx
// 0042fe12  5e                   pop esi
// 0042fe13  5b                   pop ebx
// 0042fe14  c3                   ret 
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
