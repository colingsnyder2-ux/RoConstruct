// from server: 100% by nuck16
// roc 2009-12 006527c0  unit: RBX::Feature::W4LeftRight::?$EnumDesc  size: 88 bytes
//
// 006527c0  8b442404             mov eax, dword ptr [esp + 4]
// 006527c4  56                   push esi
// 006527c5  57                   push edi
// 006527c6  50                   push eax
// 006527c7  8bf1                 mov esi, ecx
// 006527c9  e87294ffff           call 0x64bc40
// 006527ce  8b38                 mov edi, dword ptr [eax]
// 006527d0  83c404               add esp, 4
// 006527d3  85ff                 test edi, edi
// 006527d5  7d07                 jge 0x6527de
// 006527d7  5f                   pop edi
// 006527d8  33c0                 xor eax, eax
// 006527da  5e                   pop esi
// 006527db  c20400               ret 4
// 006527de  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 006527e4  2b8eb0000000         sub ecx, dword ptr [esi + 0xb0]
// 006527ea  c1f902               sar ecx, 2
// 006527ed  3bf9                 cmp edi, ecx
// 006527ef  73e6                 jae 0x6527d7
// 006527f1  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 006527f7  2b96b0000000         sub edx, dword ptr [esi + 0xb0]
// 006527fd  c1fa02               sar edx, 2
// 00652800  3bfa                 cmp edi, edx
// 00652802  7206                 jb 0x65280a
// 00652804  ff1560b79800         call dword ptr [0x98b760]
// 0065280a  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 00652810  8b04b8               mov eax, dword ptr [eax + edi*4]
// 00652813  5f                   pop edi
// 00652814  5e                   pop esi
// 00652815  c20400               ret 4

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
