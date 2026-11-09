// from server: 100% by nuck16
// roc 2009-12 00652580  unit: RBX::GuiText::W4XAlignment::?$EnumDesc  size: 88 bytes
//
// 00652580  8b442404             mov eax, dword ptr [esp + 4]
// 00652584  56                   push esi
// 00652585  57                   push edi
// 00652586  50                   push eax
// 00652587  8bf1                 mov esi, ecx
// 00652589  e8f284ffff           call 0x64aa80
// 0065258e  8b38                 mov edi, dword ptr [eax]
// 00652590  83c404               add esp, 4
// 00652593  85ff                 test edi, edi
// 00652595  7d07                 jge 0x65259e
// 00652597  5f                   pop edi
// 00652598  33c0                 xor eax, eax
// 0065259a  5e                   pop esi
// 0065259b  c20400               ret 4
// 0065259e  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 006525a4  2b8eb0000000         sub ecx, dword ptr [esi + 0xb0]
// 006525aa  c1f902               sar ecx, 2
// 006525ad  3bf9                 cmp edi, ecx
// 006525af  73e6                 jae 0x652597
// 006525b1  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 006525b7  2b96b0000000         sub edx, dword ptr [esi + 0xb0]
// 006525bd  c1fa02               sar edx, 2
// 006525c0  3bfa                 cmp edi, edx
// 006525c2  7206                 jb 0x6525ca
// 006525c4  ff1560b79800         call dword ptr [0x98b760]
// 006525ca  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 006525d0  8b04b8               mov eax, dword ptr [eax + edi*4]
// 006525d3  5f                   pop edi
// 006525d4  5e                   pop esi
// 006525d5  c20400               ret 4

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
