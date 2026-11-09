// from server: 100% by nuck16
// roc 2009-12 00652be0  unit: RBX::SpecialShape::W4MeshType::?$EnumDesc  size: 88 bytes
//
// 00652be0  8b442404             mov eax, dword ptr [esp + 4]
// 00652be4  56                   push esi
// 00652be5  57                   push edi
// 00652be6  50                   push eax
// 00652be7  8bf1                 mov esi, ecx
// 00652be9  e8b2b2ffff           call 0x64dea0
// 00652bee  8b38                 mov edi, dword ptr [eax]
// 00652bf0  83c404               add esp, 4
// 00652bf3  85ff                 test edi, edi
// 00652bf5  7d07                 jge 0x652bfe
// 00652bf7  5f                   pop edi
// 00652bf8  33c0                 xor eax, eax
// 00652bfa  5e                   pop esi
// 00652bfb  c20400               ret 4
// 00652bfe  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 00652c04  2b8eb0000000         sub ecx, dword ptr [esi + 0xb0]
// 00652c0a  c1f902               sar ecx, 2
// 00652c0d  3bf9                 cmp edi, ecx
// 00652c0f  73e6                 jae 0x652bf7
// 00652c11  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 00652c17  2b96b0000000         sub edx, dword ptr [esi + 0xb0]
// 00652c1d  c1fa02               sar edx, 2
// 00652c20  3bfa                 cmp edi, edx
// 00652c22  7206                 jb 0x652c2a
// 00652c24  ff1560b79800         call dword ptr [0x98b760]
// 00652c2a  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 00652c30  8b04b8               mov eax, dword ptr [eax + edi*4]
// 00652c33  5f                   pop edi
// 00652c34  5e                   pop esi
// 00652c35  c20400               ret 4

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
