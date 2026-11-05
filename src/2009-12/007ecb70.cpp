// from server: 100% by nuck16
// roc 2009-12 007ecb70  unit: W4_D3DFORMAT::?$EnumDesc  size: 88 bytes
//
// 007ecb70  8b442404             mov eax, dword ptr [esp + 4]
// 007ecb74  56                   push esi
// 007ecb75  57                   push edi
// 007ecb76  50                   push eax
// 007ecb77  8bf1                 mov esi, ecx
// 007ecb79  e8b2feffff           call 0x7eca30
// 007ecb7e  8b38                 mov edi, dword ptr [eax]
// 007ecb80  83c404               add esp, 4
// 007ecb83  85ff                 test edi, edi
// 007ecb85  7d07                 jge 0x7ecb8e
// 007ecb87  5f                   pop edi
// 007ecb88  33c0                 xor eax, eax
// 007ecb8a  5e                   pop esi
// 007ecb8b  c20400               ret 4
// 007ecb8e  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 007ecb94  2b8eb0000000         sub ecx, dword ptr [esi + 0xb0]
// 007ecb9a  c1f902               sar ecx, 2
// 007ecb9d  3bf9                 cmp edi, ecx
// 007ecb9f  73e6                 jae 0x7ecb87
// 007ecba1  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 007ecba7  2b96b0000000         sub edx, dword ptr [esi + 0xb0]
// 007ecbad  c1fa02               sar edx, 2
// 007ecbb0  3bfa                 cmp edi, edx
// 007ecbb2  7206                 jb 0x7ecbba
// 007ecbb4  ff1560b79800         call dword ptr [0x98b760]
// 007ecbba  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 007ecbc0  8b04b8               mov eax, dword ptr [eax + edi*4]
// 007ecbc3  5f                   pop edi
// 007ecbc4  5e                   pop esi
// 007ecbc5  c20400               ret 4

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
