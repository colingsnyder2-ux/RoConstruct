// from server: 100% by nuck16
// roc 2009-12 007ecb10  unit: W4_D3DDEVTYPE::?$EnumDesc  size: 88 bytes
//
// 007ecb10  8b442404             mov eax, dword ptr [esp + 4]
// 007ecb14  56                   push esi
// 007ecb15  57                   push edi
// 007ecb16  50                   push eax
// 007ecb17  8bf1                 mov esi, ecx
// 007ecb19  e802fbffff           call 0x7ec620
// 007ecb1e  8b38                 mov edi, dword ptr [eax]
// 007ecb20  83c404               add esp, 4
// 007ecb23  85ff                 test edi, edi
// 007ecb25  7d07                 jge 0x7ecb2e
// 007ecb27  5f                   pop edi
// 007ecb28  33c0                 xor eax, eax
// 007ecb2a  5e                   pop esi
// 007ecb2b  c20400               ret 4
// 007ecb2e  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 007ecb34  2b8eb0000000         sub ecx, dword ptr [esi + 0xb0]
// 007ecb3a  c1f902               sar ecx, 2
// 007ecb3d  3bf9                 cmp edi, ecx
// 007ecb3f  73e6                 jae 0x7ecb27
// 007ecb41  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 007ecb47  2b96b0000000         sub edx, dword ptr [esi + 0xb0]
// 007ecb4d  c1fa02               sar edx, 2
// 007ecb50  3bfa                 cmp edi, edx
// 007ecb52  7206                 jb 0x7ecb5a
// 007ecb54  ff1560b79800         call dword ptr [0x98b760]
// 007ecb5a  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 007ecb60  8b04b8               mov eax, dword ptr [eax + edi*4]
// 007ecb63  5f                   pop edi
// 007ecb64  5e                   pop esi
// 007ecb65  c20400               ret 4

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
