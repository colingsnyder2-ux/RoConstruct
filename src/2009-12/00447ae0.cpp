// from server: 100% by nuck16
// roc 2009-12 00447ae0  unit: RBX::CRenderSettings::W4BevelMode::?$EnumDesc  size: 88 bytes
//
// 00447ae0  8b442404             mov eax, dword ptr [esp + 4]
// 00447ae4  56                   push esi
// 00447ae5  57                   push edi
// 00447ae6  50                   push eax
// 00447ae7  8bf1                 mov esi, ecx
// 00447ae9  e8e2f8ffff           call 0x4473d0
// 00447aee  8b38                 mov edi, dword ptr [eax]
// 00447af0  83c404               add esp, 4
// 00447af3  85ff                 test edi, edi
// 00447af5  7d07                 jge 0x447afe
// 00447af7  5f                   pop edi
// 00447af8  33c0                 xor eax, eax
// 00447afa  5e                   pop esi
// 00447afb  c20400               ret 4
// 00447afe  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 00447b04  2b8eb0000000         sub ecx, dword ptr [esi + 0xb0]
// 00447b0a  c1f902               sar ecx, 2
// 00447b0d  3bf9                 cmp edi, ecx
// 00447b0f  73e6                 jae 0x447af7
// 00447b11  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 00447b17  2b96b0000000         sub edx, dword ptr [esi + 0xb0]
// 00447b1d  c1fa02               sar edx, 2
// 00447b20  3bfa                 cmp edi, edx
// 00447b22  7206                 jb 0x447b2a
// 00447b24  ff1560b79800         call dword ptr [0x98b760]
// 00447b2a  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 00447b30  8b04b8               mov eax, dword ptr [eax + edi*4]
// 00447b33  5f                   pop edi
// 00447b34  5e                   pop esi
// 00447b35  c20400               ret 4

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
