// from server: 100% by nuck16
// roc 2009-12 00652a00  unit: RBX::Humanoid::W4Status::?$EnumDesc  size: 88 bytes
//
// 00652a00  8b442404             mov eax, dword ptr [esp + 4]
// 00652a04  56                   push esi
// 00652a05  57                   push edi
// 00652a06  50                   push eax
// 00652a07  8bf1                 mov esi, ecx
// 00652a09  e8e2a5ffff           call 0x64cff0
// 00652a0e  8b38                 mov edi, dword ptr [eax]
// 00652a10  83c404               add esp, 4
// 00652a13  85ff                 test edi, edi
// 00652a15  7d07                 jge 0x652a1e
// 00652a17  5f                   pop edi
// 00652a18  33c0                 xor eax, eax
// 00652a1a  5e                   pop esi
// 00652a1b  c20400               ret 4
// 00652a1e  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 00652a24  2b8eb0000000         sub ecx, dword ptr [esi + 0xb0]
// 00652a2a  c1f902               sar ecx, 2
// 00652a2d  3bf9                 cmp edi, ecx
// 00652a2f  73e6                 jae 0x652a17
// 00652a31  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 00652a37  2b96b0000000         sub edx, dword ptr [esi + 0xb0]
// 00652a3d  c1fa02               sar edx, 2
// 00652a40  3bfa                 cmp edi, edx
// 00652a42  7206                 jb 0x652a4a
// 00652a44  ff1560b79800         call dword ptr [0x98b760]
// 00652a4a  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 00652a50  8b04b8               mov eax, dword ptr [eax + edi*4]
// 00652a53  5f                   pop edi
// 00652a54  5e                   pop esi
// 00652a55  c20400               ret 4

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
