// from server: 100% by nuck16
// roc 2009-12 006524c0  unit: RBX::HopperBin::W4BinType::?$EnumDesc  size: 88 bytes
//
// 006524c0  8b442404             mov eax, dword ptr [esp + 4]
// 006524c4  56                   push esi
// 006524c5  57                   push edi
// 006524c6  50                   push eax
// 006524c7  8bf1                 mov esi, ecx
// 006524c9  e8d27fffff           call 0x64a4a0
// 006524ce  8b38                 mov edi, dword ptr [eax]
// 006524d0  83c404               add esp, 4
// 006524d3  85ff                 test edi, edi
// 006524d5  7d07                 jge 0x6524de
// 006524d7  5f                   pop edi
// 006524d8  33c0                 xor eax, eax
// 006524da  5e                   pop esi
// 006524db  c20400               ret 4
// 006524de  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 006524e4  2b8eb0000000         sub ecx, dword ptr [esi + 0xb0]
// 006524ea  c1f902               sar ecx, 2
// 006524ed  3bf9                 cmp edi, ecx
// 006524ef  73e6                 jae 0x6524d7
// 006524f1  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 006524f7  2b96b0000000         sub edx, dword ptr [esi + 0xb0]
// 006524fd  c1fa02               sar edx, 2
// 00652500  3bfa                 cmp edi, edx
// 00652502  7206                 jb 0x65250a
// 00652504  ff1560b79800         call dword ptr [0x98b760]
// 0065250a  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 00652510  8b04b8               mov eax, dword ptr [eax + edi*4]
// 00652513  5f                   pop edi
// 00652514  5e                   pop esi
// 00652515  c20400               ret 4

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
