// from server: 100% by nuck16
// roc 2009-12 006528e0  unit: RBX::W4KeywordFilterType::?$EnumDesc  size: 88 bytes
//
// 006528e0  8b442404             mov eax, dword ptr [esp + 4]
// 006528e4  56                   push esi
// 006528e5  57                   push edi
// 006528e6  50                   push eax
// 006528e7  8bf1                 mov esi, ecx
// 006528e9  e8a29cffff           call 0x64c590
// 006528ee  8b38                 mov edi, dword ptr [eax]
// 006528f0  83c404               add esp, 4
// 006528f3  85ff                 test edi, edi
// 006528f5  7d07                 jge 0x6528fe
// 006528f7  5f                   pop edi
// 006528f8  33c0                 xor eax, eax
// 006528fa  5e                   pop esi
// 006528fb  c20400               ret 4
// 006528fe  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 00652904  2b8eb0000000         sub ecx, dword ptr [esi + 0xb0]
// 0065290a  c1f902               sar ecx, 2
// 0065290d  3bf9                 cmp edi, ecx
// 0065290f  73e6                 jae 0x6528f7
// 00652911  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 00652917  2b96b0000000         sub edx, dword ptr [esi + 0xb0]
// 0065291d  c1fa02               sar edx, 2
// 00652920  3bfa                 cmp edi, edx
// 00652922  7206                 jb 0x65292a
// 00652924  ff1560b79800         call dword ptr [0x98b760]
// 0065292a  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 00652930  8b04b8               mov eax, dword ptr [eax + edi*4]
// 00652933  5f                   pop edi
// 00652934  5e                   pop esi
// 00652935  c20400               ret 4

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
