// from server: 100% by nuck16
// roc 2009-12 00447b40  unit: RBX::CRenderSettings::W4GeometryQuality::?$EnumDesc  size: 88 bytes
//
// 00447b40  8b442404             mov eax, dword ptr [esp + 4]
// 00447b44  56                   push esi
// 00447b45  57                   push edi
// 00447b46  50                   push eax
// 00447b47  8bf1                 mov esi, ecx
// 00447b49  e812f9ffff           call 0x447460
// 00447b4e  8b38                 mov edi, dword ptr [eax]
// 00447b50  83c404               add esp, 4
// 00447b53  85ff                 test edi, edi
// 00447b55  7d07                 jge 0x447b5e
// 00447b57  5f                   pop edi
// 00447b58  33c0                 xor eax, eax
// 00447b5a  5e                   pop esi
// 00447b5b  c20400               ret 4
// 00447b5e  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 00447b64  2b8eb0000000         sub ecx, dword ptr [esi + 0xb0]
// 00447b6a  c1f902               sar ecx, 2
// 00447b6d  3bf9                 cmp edi, ecx
// 00447b6f  73e6                 jae 0x447b57
// 00447b71  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 00447b77  2b96b0000000         sub edx, dword ptr [esi + 0xb0]
// 00447b7d  c1fa02               sar edx, 2
// 00447b80  3bfa                 cmp edi, edx
// 00447b82  7206                 jb 0x447b8a
// 00447b84  ff1560b79800         call dword ptr [0x98b760]
// 00447b8a  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 00447b90  8b04b8               mov eax, dword ptr [eax + edi*4]
// 00447b93  5f                   pop edi
// 00447b94  5e                   pop esi
// 00447b95  c20400               ret 4

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
