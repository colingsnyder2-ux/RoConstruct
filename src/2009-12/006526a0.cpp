// from server: 100% by nuck16
// roc 2009-12 006526a0  unit: RBX::LegacyController::W4InputType::?$EnumDesc  size: 88 bytes
//
// 006526a0  8b442404             mov eax, dword ptr [esp + 4]
// 006526a4  56                   push esi
// 006526a5  57                   push edi
// 006526a6  50                   push eax
// 006526a7  8bf1                 mov esi, ecx
// 006526a9  e8a28cffff           call 0x64b350
// 006526ae  8b38                 mov edi, dword ptr [eax]
// 006526b0  83c404               add esp, 4
// 006526b3  85ff                 test edi, edi
// 006526b5  7d07                 jge 0x6526be
// 006526b7  5f                   pop edi
// 006526b8  33c0                 xor eax, eax
// 006526ba  5e                   pop esi
// 006526bb  c20400               ret 4
// 006526be  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 006526c4  2b8eb0000000         sub ecx, dword ptr [esi + 0xb0]
// 006526ca  c1f902               sar ecx, 2
// 006526cd  3bf9                 cmp edi, ecx
// 006526cf  73e6                 jae 0x6526b7
// 006526d1  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 006526d7  2b96b0000000         sub edx, dword ptr [esi + 0xb0]
// 006526dd  c1fa02               sar edx, 2
// 006526e0  3bfa                 cmp edi, edx
// 006526e2  7206                 jb 0x6526ea
// 006526e4  ff1560b79800         call dword ptr [0x98b760]
// 006526ea  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 006526f0  8b04b8               mov eax, dword ptr [eax + edi*4]
// 006526f3  5f                   pop edi
// 006526f4  5e                   pop esi
// 006526f5  c20400               ret 4

#include <vector>

struct Key;
struct Item;

int *lookupIndex(const Key &key);

struct S
{
    char pad[0xa4];
    std::vector<Item *> items;
    Item *f(const Key &key);
};

Item *S::f(const Key &key)
{
    int index = *lookupIndex(key);
    if (index < 0)
        return 0;
    if ((size_t)index >= items.size())
        return 0;
    return items[index];
}
