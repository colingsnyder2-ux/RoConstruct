// from server: 100% by nuck16
// roc 2009-12 006b6360  unit: RBX::Soundscape::W4ReverbType::?$EnumDesc  size: 88 bytes
//
// 006b6360  8b442404             mov eax, dword ptr [esp + 4]
// 006b6364  56                   push esi
// 006b6365  57                   push edi
// 006b6366  50                   push eax
// 006b6367  8bf1                 mov esi, ecx
// 006b6369  e8e2fdffff           call 0x6b6150
// 006b636e  8b38                 mov edi, dword ptr [eax]
// 006b6370  83c404               add esp, 4
// 006b6373  85ff                 test edi, edi
// 006b6375  7d07                 jge 0x6b637e
// 006b6377  5f                   pop edi
// 006b6378  33c0                 xor eax, eax
// 006b637a  5e                   pop esi
// 006b637b  c20400               ret 4
// 006b637e  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 006b6384  2b8eb0000000         sub ecx, dword ptr [esi + 0xb0]
// 006b638a  c1f902               sar ecx, 2
// 006b638d  3bf9                 cmp edi, ecx
// 006b638f  73e6                 jae 0x6b6377
// 006b6391  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 006b6397  2b96b0000000         sub edx, dword ptr [esi + 0xb0]
// 006b639d  c1fa02               sar edx, 2
// 006b63a0  3bfa                 cmp edi, edx
// 006b63a2  7206                 jb 0x6b63aa
// 006b63a4  ff1560b79800         call dword ptr [0x98b760]
// 006b63aa  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 006b63b0  8b04b8               mov eax, dword ptr [eax + edi*4]
// 006b63b3  5f                   pop edi
// 006b63b4  5e                   pop esi
// 006b63b5  c20400               ret 4

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
