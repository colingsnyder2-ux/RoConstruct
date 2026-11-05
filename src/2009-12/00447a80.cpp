// from server: 100% by nuck16
// roc 2009-12 00447a80  unit: RBX::CRenderSettings::W4AntialiasingMode::?$EnumDesc  size: 88 bytes
//
// 00447a80  8b442404             mov eax, dword ptr [esp + 4]
// 00447a84  56                   push esi
// 00447a85  57                   push edi
// 00447a86  50                   push eax
// 00447a87  8bf1                 mov esi, ecx
// 00447a89  e8b2f8ffff           call 0x447340
// 00447a8e  8b38                 mov edi, dword ptr [eax]
// 00447a90  83c404               add esp, 4
// 00447a93  85ff                 test edi, edi
// 00447a95  7d07                 jge 0x447a9e
// 00447a97  5f                   pop edi
// 00447a98  33c0                 xor eax, eax
// 00447a9a  5e                   pop esi
// 00447a9b  c20400               ret 4
// 00447a9e  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 00447aa4  2b8eb0000000         sub ecx, dword ptr [esi + 0xb0]
// 00447aaa  c1f902               sar ecx, 2
// 00447aad  3bf9                 cmp edi, ecx
// 00447aaf  73e6                 jae 0x447a97
// 00447ab1  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 00447ab7  2b96b0000000         sub edx, dword ptr [esi + 0xb0]
// 00447abd  c1fa02               sar edx, 2
// 00447ac0  3bfa                 cmp edi, edx
// 00447ac2  7206                 jb 0x447aca
// 00447ac4  ff1560b79800         call dword ptr [0x98b760]
// 00447aca  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 00447ad0  8b04b8               mov eax, dword ptr [eax + edi*4]
// 00447ad3  5f                   pop edi
// 00447ad4  5e                   pop esi
// 00447ad5  c20400               ret 4

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
