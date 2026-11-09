// from server: 100% by nuck16
// roc 2009-12 00652a60  unit: RBX::BasicPartInstance::W4LegacyPartType::?$EnumDesc  size: 88 bytes
//
// 00652a60  8b442404             mov eax, dword ptr [esp + 4]
// 00652a64  56                   push esi
// 00652a65  57                   push edi
// 00652a66  50                   push eax
// 00652a67  8bf1                 mov esi, ecx
// 00652a69  e872a8ffff           call 0x64d2e0
// 00652a6e  8b38                 mov edi, dword ptr [eax]
// 00652a70  83c404               add esp, 4
// 00652a73  85ff                 test edi, edi
// 00652a75  7d07                 jge 0x652a7e
// 00652a77  5f                   pop edi
// 00652a78  33c0                 xor eax, eax
// 00652a7a  5e                   pop esi
// 00652a7b  c20400               ret 4
// 00652a7e  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 00652a84  2b8eb0000000         sub ecx, dword ptr [esi + 0xb0]
// 00652a8a  c1f902               sar ecx, 2
// 00652a8d  3bf9                 cmp edi, ecx
// 00652a8f  73e6                 jae 0x652a77
// 00652a91  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 00652a97  2b96b0000000         sub edx, dword ptr [esi + 0xb0]
// 00652a9d  c1fa02               sar edx, 2
// 00652aa0  3bfa                 cmp edi, edx
// 00652aa2  7206                 jb 0x652aaa
// 00652aa4  ff1560b79800         call dword ptr [0x98b760]
// 00652aaa  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 00652ab0  8b04b8               mov eax, dword ptr [eax + edi*4]
// 00652ab3  5f                   pop edi
// 00652ab4  5e                   pop esi
// 00652ab5  c20400               ret 4

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
