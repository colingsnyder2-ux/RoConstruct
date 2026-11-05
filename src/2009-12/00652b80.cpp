// from server: 100% by nuck16
// roc 2009-12 00652b80  unit: RBX::W4SoundType::?$EnumDesc  size: 88 bytes
//
// 00652b80  8b442404             mov eax, dword ptr [esp + 4]
// 00652b84  56                   push esi
// 00652b85  57                   push edi
// 00652b86  50                   push eax
// 00652b87  8bf1                 mov esi, ecx
// 00652b89  e822b0ffff           call 0x64dbb0
// 00652b8e  8b38                 mov edi, dword ptr [eax]
// 00652b90  83c404               add esp, 4
// 00652b93  85ff                 test edi, edi
// 00652b95  7d07                 jge 0x652b9e
// 00652b97  5f                   pop edi
// 00652b98  33c0                 xor eax, eax
// 00652b9a  5e                   pop esi
// 00652b9b  c20400               ret 4
// 00652b9e  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 00652ba4  2b8eb0000000         sub ecx, dword ptr [esi + 0xb0]
// 00652baa  c1f902               sar ecx, 2
// 00652bad  3bf9                 cmp edi, ecx
// 00652baf  73e6                 jae 0x652b97
// 00652bb1  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 00652bb7  2b96b0000000         sub edx, dword ptr [esi + 0xb0]
// 00652bbd  c1fa02               sar edx, 2
// 00652bc0  3bfa                 cmp edi, edx
// 00652bc2  7206                 jb 0x652bca
// 00652bc4  ff1560b79800         call dword ptr [0x98b760]
// 00652bca  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 00652bd0  8b04b8               mov eax, dword ptr [eax + edi*4]
// 00652bd3  5f                   pop edi
// 00652bd4  5e                   pop esi
// 00652bd5  c20400               ret 4

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
