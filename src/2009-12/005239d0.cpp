// from server: 100% by nuck16
// roc 2009-12 005239d0  unit: RBX::NetworkSettings::W4PhysicsSendMethod::?$EnumDesc  size: 88 bytes
//
// 005239d0  8b442404             mov eax, dword ptr [esp + 4]
// 005239d4  56                   push esi
// 005239d5  57                   push edi
// 005239d6  50                   push eax
// 005239d7  8bf1                 mov esi, ecx
// 005239d9  e8c2f7ffff           call 0x5231a0
// 005239de  8b38                 mov edi, dword ptr [eax]
// 005239e0  83c404               add esp, 4
// 005239e3  85ff                 test edi, edi
// 005239e5  7d07                 jge 0x5239ee
// 005239e7  5f                   pop edi
// 005239e8  33c0                 xor eax, eax
// 005239ea  5e                   pop esi
// 005239eb  c20400               ret 4
// 005239ee  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 005239f4  2b8eb0000000         sub ecx, dword ptr [esi + 0xb0]
// 005239fa  c1f902               sar ecx, 2
// 005239fd  3bf9                 cmp edi, ecx
// 005239ff  73e6                 jae 0x5239e7
// 00523a01  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 00523a07  2b96b0000000         sub edx, dword ptr [esi + 0xb0]
// 00523a0d  c1fa02               sar edx, 2
// 00523a10  3bfa                 cmp edi, edx
// 00523a12  7206                 jb 0x523a1a
// 00523a14  ff1560b79800         call dword ptr [0x98b760]
// 00523a1a  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 00523a20  8b04b8               mov eax, dword ptr [eax + edi*4]
// 00523a23  5f                   pop edi
// 00523a24  5e                   pop esi
// 00523a25  c20400               ret 4

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
