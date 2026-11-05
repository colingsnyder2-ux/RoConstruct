// from server: 100% by nuck16
// roc 2009-12 006529a0  unit: G3D::Vector3::W4Axis::?$EnumDesc  size: 88 bytes
//
// 006529a0  8b442404             mov eax, dword ptr [esp + 4]
// 006529a4  56                   push esi
// 006529a5  57                   push edi
// 006529a6  50                   push eax
// 006529a7  8bf1                 mov esi, ecx
// 006529a9  e812a2ffff           call 0x64cbc0
// 006529ae  8b38                 mov edi, dword ptr [eax]
// 006529b0  83c404               add esp, 4
// 006529b3  85ff                 test edi, edi
// 006529b5  7d07                 jge 0x6529be
// 006529b7  5f                   pop edi
// 006529b8  33c0                 xor eax, eax
// 006529ba  5e                   pop esi
// 006529bb  c20400               ret 4
// 006529be  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 006529c4  2b8eb0000000         sub ecx, dword ptr [esi + 0xb0]
// 006529ca  c1f902               sar ecx, 2
// 006529cd  3bf9                 cmp edi, ecx
// 006529cf  73e6                 jae 0x6529b7
// 006529d1  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 006529d7  2b96b0000000         sub edx, dword ptr [esi + 0xb0]
// 006529dd  c1fa02               sar edx, 2
// 006529e0  3bfa                 cmp edi, edx
// 006529e2  7206                 jb 0x6529ea
// 006529e4  ff1560b79800         call dword ptr [0x98b760]
// 006529ea  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 006529f0  8b04b8               mov eax, dword ptr [eax + edi*4]
// 006529f3  5f                   pop edi
// 006529f4  5e                   pop esi
// 006529f5  c20400               ret 4

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
