// from server: 100% by nuck16
// roc 2009-12 00652880  unit: RBX::Joint::W4JointType::?$EnumDesc  size: 88 bytes
//
// 00652880  8b442404             mov eax, dword ptr [esp + 4]
// 00652884  56                   push esi
// 00652885  57                   push edi
// 00652886  50                   push eax
// 00652887  8bf1                 mov esi, ecx
// 00652889  e8129affff           call 0x64c2a0
// 0065288e  8b38                 mov edi, dword ptr [eax]
// 00652890  83c404               add esp, 4
// 00652893  85ff                 test edi, edi
// 00652895  7d07                 jge 0x65289e
// 00652897  5f                   pop edi
// 00652898  33c0                 xor eax, eax
// 0065289a  5e                   pop esi
// 0065289b  c20400               ret 4
// 0065289e  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 006528a4  2b8eb0000000         sub ecx, dword ptr [esi + 0xb0]
// 006528aa  c1f902               sar ecx, 2
// 006528ad  3bf9                 cmp edi, ecx
// 006528af  73e6                 jae 0x652897
// 006528b1  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 006528b7  2b96b0000000         sub edx, dword ptr [esi + 0xb0]
// 006528bd  c1fa02               sar edx, 2
// 006528c0  3bfa                 cmp edi, edx
// 006528c2  7206                 jb 0x6528ca
// 006528c4  ff1560b79800         call dword ptr [0x98b760]
// 006528ca  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 006528d0  8b04b8               mov eax, dword ptr [eax + edi*4]
// 006528d3  5f                   pop edi
// 006528d4  5e                   pop esi
// 006528d5  c20400               ret 4

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
