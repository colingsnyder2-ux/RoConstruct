// from server: 100% by EspClaude
// from server: 43% by colin
// roc 2007-08 004aa0e0  unit: RBX::VInstance::?$NonFactoryProduct  size: 233 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004aa0e0
//
// 004aa0e0  83ec0c               sub esp, 0xc
// 004aa0e3  55                   push ebp
// 004aa0e4  8be9                 mov ebp, ecx
// 004aa0e6  837d1800             cmp dword ptr [ebp + 0x18], 0
// 004aa0ea  896c240c             mov dword ptr [esp + 0xc], ebp
// 004aa0ee  0f84ce000000         je 0x4aa1c2
// 004aa0f4  56                   push esi
// 004aa0f5  57                   push edi
// 004aa0f6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004aa0fa  8bcf                 mov ecx, edi
// 004aa0fc  e8cf241000           call 0x5ac5d0
// 004aa101  84c0                 test al, al
// 004aa103  751a                 jne 0x4aa11f
// 004aa105  8b4514               mov eax, dword ptr [ebp + 0x14]
// 004aa108  8b30                 mov esi, dword ptr [eax]
// 004aa10a  3bf0                 cmp esi, eax
// 004aa10c  7506                 jne 0x4aa114
// 004aa10e  ff15d8e67700         call dword ptr [0x77e6d8]
// 004aa114  8b4e08               mov ecx, dword ptr [esi + 8]
// 004aa117  51                   push ecx
// 004aa118  8bcf                 mov ecx, edi
// 004aa11a  e8d1271000           call 0x5ac8f0
// 004aa11f  8bcf                 mov ecx, edi
// 004aa121  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 004aa129  e87264fbff           call 0x4605a0
// 004aa12e  837d1800             cmp dword ptr [ebp + 0x18], 0
// 004aa132  8bf0                 mov esi, eax
// 004aa134  0f867e000000         jbe 0x4aa1b8
// 004aa13a  83c510               add ebp, 0x10
// 004aa13d  53                   push ebx
// 004aa13e  8bff                 mov edi, edi
// 004aa140  8b7e1c               mov edi, dword ptr [esi + 0x1c]
// 004aa143  8344241001           add dword ptr [esp + 0x10], 1
// 004aa148  85ff                 test edi, edi
// 004aa14a  89742414             mov dword ptr [esp + 0x14], esi
// 004aa14e  8b7620               mov esi, dword ptr [esi + 0x20]
// 004aa151  7506                 jne 0x4aa159
// 004aa153  ff15d8e67700         call dword ptr [0x77e6d8]
// 004aa159  3b7704               cmp esi, dword ptr [edi + 4]
// 004aa15c  7506                 jne 0x4aa164
// 004aa15e  ff15d8e67700         call dword ptr [0x77e6d8]
// 004aa164  3bfd                 cmp edi, ebp
// 004aa166  8b36                 mov esi, dword ptr [esi]
// 004aa168  8b5d04               mov ebx, dword ptr [ebp + 4]
// 004aa16b  7406                 je 0x4aa173
// 004aa16d  ff15d8e67700         call dword ptr [0x77e6d8]
// 004aa173  3bf3                 cmp esi, ebx
// 004aa175  7509                 jne 0x4aa180
// 004aa177  8b5504               mov edx, dword ptr [ebp + 4]
// 004aa17a  8b32                 mov esi, dword ptr [edx]
// 004aa17c  3bf2                 cmp esi, edx
// 004aa17e  eb03                 jmp 0x4aa183
// 004aa180  3b7704               cmp esi, dword ptr [edi + 4]
// 004aa183  7506                 jne 0x4aa18b
// 004aa185  ff15d8e67700         call dword ptr [0x77e6d8]
// 004aa18b  8b442414             mov eax, dword ptr [esp + 0x14]
// 004aa18f  3b442428             cmp eax, dword ptr [esp + 0x28]
// 004aa193  8b7608               mov esi, dword ptr [esi + 8]
// 004aa196  740e                 je 0x4aa1a6
// 004aa198  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004aa19c  50                   push eax
// 004aa19d  e89ef3ffff           call 0x4a9540
// 004aa1a2  84c0                 test al, al
// 004aa1a4  740d                 je 0x4aa1b3
// 004aa1a6  8b442410             mov eax, dword ptr [esp + 0x10]
// 004aa1aa  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004aa1ae  3b4118               cmp eax, dword ptr [ecx + 0x18]
// 004aa1b1  728d                 jb 0x4aa140

#include <list>

struct Item;
typedef std::list<Item*> ItemList;

struct Item {
    char pad[0x1c];
    ItemList::iterator self;
};

struct Cursor {
    bool hasItem();
    void setItem(Item* item);
    Item* getItem();
};

struct Filter {
    bool accept(Item* item);
};

struct Ring {
    char pad[0x10];
    ItemList items;
    void advance(Filter* filter, Cursor* cursor, Item* stop);
};

void Ring::advance(Filter* filter, Cursor* cursor, Item* stop)
{
    if (items.empty())
        return;

    if (!cursor->hasItem())
        cursor->setItem(items.front());

    unsigned int i = 0;
    Item* item = cursor->getItem();
    while (i < items.size()) {
        ++i;
        Item* prev = item;
        ItemList::iterator it = item->self;
        ++it;
        if (it == items.end())
            item = *items.begin();
        else
            item = *it;
        if (prev != stop && !filter->accept(prev))
            break;
    }
    cursor->setItem(item);
}
