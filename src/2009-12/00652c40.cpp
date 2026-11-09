// from server: 100% by nuck16
// roc 2009-12 00652c40  unit: RBX::W4SurfaceType::?$EnumDesc  size: 88 bytes
//
// 00652c40  8b442404             mov eax, dword ptr [esp + 4]
// 00652c44  56                   push esi
// 00652c45  57                   push edi
// 00652c46  50                   push eax
// 00652c47  8bf1                 mov esi, ecx
// 00652c49  e842b5ffff           call 0x64e190
// 00652c4e  8b38                 mov edi, dword ptr [eax]
// 00652c50  83c404               add esp, 4
// 00652c53  85ff                 test edi, edi
// 00652c55  7d07                 jge 0x652c5e
// 00652c57  5f                   pop edi
// 00652c58  33c0                 xor eax, eax
// 00652c5a  5e                   pop esi
// 00652c5b  c20400               ret 4
// 00652c5e  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 00652c64  2b8eb0000000         sub ecx, dword ptr [esi + 0xb0]
// 00652c6a  c1f902               sar ecx, 2
// 00652c6d  3bf9                 cmp edi, ecx
// 00652c6f  73e6                 jae 0x652c57
// 00652c71  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 00652c77  2b96b0000000         sub edx, dword ptr [esi + 0xb0]
// 00652c7d  c1fa02               sar edx, 2
// 00652c80  3bfa                 cmp edi, edx
// 00652c82  7206                 jb 0x652c8a
// 00652c84  ff1560b79800         call dword ptr [0x98b760]
// 00652c8a  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 00652c90  8b04b8               mov eax, dword ptr [eax + edi*4]
// 00652c93  5f                   pop edi
// 00652c94  5e                   pop esi
// 00652c95  c20400               ret 4

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
