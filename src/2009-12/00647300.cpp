// from server: 100% by nuck16
// roc 2009-12 00647300  unit: RBX::W4NormalId::?$EnumDesc  size: 88 bytes
//
// 00647300  8b442404             mov eax, dword ptr [esp + 4]
// 00647304  56                   push esi
// 00647305  57                   push edi
// 00647306  50                   push eax
// 00647307  8bf1                 mov esi, ecx
// 00647309  e8a2fdffff           call 0x6470b0
// 0064730e  8b38                 mov edi, dword ptr [eax]
// 00647310  83c404               add esp, 4
// 00647313  85ff                 test edi, edi
// 00647315  7d07                 jge 0x64731e
// 00647317  5f                   pop edi
// 00647318  33c0                 xor eax, eax
// 0064731a  5e                   pop esi
// 0064731b  c20400               ret 4
// 0064731e  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 00647324  2b8eb0000000         sub ecx, dword ptr [esi + 0xb0]
// 0064732a  c1f902               sar ecx, 2
// 0064732d  3bf9                 cmp edi, ecx
// 0064732f  73e6                 jae 0x647317
// 00647331  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 00647337  2b96b0000000         sub edx, dword ptr [esi + 0xb0]
// 0064733d  c1fa02               sar edx, 2
// 00647340  3bfa                 cmp edi, edx
// 00647342  7206                 jb 0x64734a
// 00647344  ff1560b79800         call dword ptr [0x98b760]
// 0064734a  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 00647350  8b04b8               mov eax, dword ptr [eax + edi*4]
// 00647353  5f                   pop edi
// 00647354  5e                   pop esi
// 00647355  c20400               ret 4

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
