// from server: 100% by nuck16
// roc 2009-12 00652940  unit: RBX::Legacy::W4SurfaceConstraint::?$EnumDesc  size: 88 bytes
//
// 00652940  8b442404             mov eax, dword ptr [esp + 4]
// 00652944  56                   push esi
// 00652945  57                   push edi
// 00652946  50                   push eax
// 00652947  8bf1                 mov esi, ecx
// 00652949  e8329fffff           call 0x64c880
// 0065294e  8b38                 mov edi, dword ptr [eax]
// 00652950  83c404               add esp, 4
// 00652953  85ff                 test edi, edi
// 00652955  7d07                 jge 0x65295e
// 00652957  5f                   pop edi
// 00652958  33c0                 xor eax, eax
// 0065295a  5e                   pop esi
// 0065295b  c20400               ret 4
// 0065295e  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 00652964  2b8eb0000000         sub ecx, dword ptr [esi + 0xb0]
// 0065296a  c1f902               sar ecx, 2
// 0065296d  3bf9                 cmp edi, ecx
// 0065296f  73e6                 jae 0x652957
// 00652971  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 00652977  2b96b0000000         sub edx, dword ptr [esi + 0xb0]
// 0065297d  c1fa02               sar edx, 2
// 00652980  3bfa                 cmp edi, edx
// 00652982  7206                 jb 0x65298a
// 00652984  ff1560b79800         call dword ptr [0x98b760]
// 0065298a  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 00652990  8b04b8               mov eax, dword ptr [eax + edi*4]
// 00652993  5f                   pop edi
// 00652994  5e                   pop esi
// 00652995  c20400               ret 4

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
