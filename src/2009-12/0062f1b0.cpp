// from server: 100% by nuck16
// roc 2009-12 0062f1b0  unit: RBX::DebugSettings::W4ErrorReporting::?$EnumDesc  size: 88 bytes
//
// 0062f1b0  8b442404             mov eax, dword ptr [esp + 4]
// 0062f1b4  56                   push esi
// 0062f1b5  57                   push edi
// 0062f1b6  50                   push eax
// 0062f1b7  8bf1                 mov esi, ecx
// 0062f1b9  e892f5ffff           call 0x62e750
// 0062f1be  8b38                 mov edi, dword ptr [eax]
// 0062f1c0  83c404               add esp, 4
// 0062f1c3  85ff                 test edi, edi
// 0062f1c5  7d07                 jge 0x62f1ce
// 0062f1c7  5f                   pop edi
// 0062f1c8  33c0                 xor eax, eax
// 0062f1ca  5e                   pop esi
// 0062f1cb  c20400               ret 4
// 0062f1ce  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 0062f1d4  2b8eb0000000         sub ecx, dword ptr [esi + 0xb0]
// 0062f1da  c1f902               sar ecx, 2
// 0062f1dd  3bf9                 cmp edi, ecx
// 0062f1df  73e6                 jae 0x62f1c7
// 0062f1e1  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 0062f1e7  2b96b0000000         sub edx, dword ptr [esi + 0xb0]
// 0062f1ed  c1fa02               sar edx, 2
// 0062f1f0  3bfa                 cmp edi, edx
// 0062f1f2  7206                 jb 0x62f1fa
// 0062f1f4  ff1560b79800         call dword ptr [0x98b760]
// 0062f1fa  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 0062f200  8b04b8               mov eax, dword ptr [eax + edi*4]
// 0062f203  5f                   pop edi
// 0062f204  5e                   pop esi
// 0062f205  c20400               ret 4

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
