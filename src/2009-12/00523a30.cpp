// from server: 100% by nuck16
// roc 2009-12 00523a30  unit: RBX::NetworkSettings::W4PhysicsReceiveMethod::?$EnumDesc  size: 88 bytes
//
// 00523a30  8b442404             mov eax, dword ptr [esp + 4]
// 00523a34  56                   push esi
// 00523a35  57                   push edi
// 00523a36  50                   push eax
// 00523a37  8bf1                 mov esi, ecx
// 00523a39  e852faffff           call 0x523490
// 00523a3e  8b38                 mov edi, dword ptr [eax]
// 00523a40  83c404               add esp, 4
// 00523a43  85ff                 test edi, edi
// 00523a45  7d07                 jge 0x523a4e
// 00523a47  5f                   pop edi
// 00523a48  33c0                 xor eax, eax
// 00523a4a  5e                   pop esi
// 00523a4b  c20400               ret 4
// 00523a4e  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 00523a54  2b8eb0000000         sub ecx, dword ptr [esi + 0xb0]
// 00523a5a  c1f902               sar ecx, 2
// 00523a5d  3bf9                 cmp edi, ecx
// 00523a5f  73e6                 jae 0x523a47
// 00523a61  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 00523a67  2b96b0000000         sub edx, dword ptr [esi + 0xb0]
// 00523a6d  c1fa02               sar edx, 2
// 00523a70  3bfa                 cmp edi, edx
// 00523a72  7206                 jb 0x523a7a
// 00523a74  ff1560b79800         call dword ptr [0x98b760]
// 00523a7a  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 00523a80  8b04b8               mov eax, dword ptr [eax + edi*4]
// 00523a83  5f                   pop edi
// 00523a84  5e                   pop esi
// 00523a85  c20400               ret 4

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
