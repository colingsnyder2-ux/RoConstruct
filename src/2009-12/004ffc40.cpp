// from server: 100% by nuck16
// roc 2009-12 004ffc40  unit: RBX::Network::Player::W4BuildPermission::?$EnumDesc  size: 88 bytes
//
// 004ffc40  8b442404             mov eax, dword ptr [esp + 4]
// 004ffc44  56                   push esi
// 004ffc45  57                   push edi
// 004ffc46  50                   push eax
// 004ffc47  8bf1                 mov esi, ecx
// 004ffc49  e872e9ffff           call 0x4fe5c0
// 004ffc4e  8b38                 mov edi, dword ptr [eax]
// 004ffc50  83c404               add esp, 4
// 004ffc53  85ff                 test edi, edi
// 004ffc55  7d07                 jge 0x4ffc5e
// 004ffc57  5f                   pop edi
// 004ffc58  33c0                 xor eax, eax
// 004ffc5a  5e                   pop esi
// 004ffc5b  c20400               ret 4
// 004ffc5e  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 004ffc64  2b8eb0000000         sub ecx, dword ptr [esi + 0xb0]
// 004ffc6a  c1f902               sar ecx, 2
// 004ffc6d  3bf9                 cmp edi, ecx
// 004ffc6f  73e6                 jae 0x4ffc57
// 004ffc71  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 004ffc77  2b96b0000000         sub edx, dword ptr [esi + 0xb0]
// 004ffc7d  c1fa02               sar edx, 2
// 004ffc80  3bfa                 cmp edi, edx
// 004ffc82  7206                 jb 0x4ffc8a
// 004ffc84  ff1560b79800         call dword ptr [0x98b760]
// 004ffc8a  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 004ffc90  8b04b8               mov eax, dword ptr [eax + edi*4]
// 004ffc93  5f                   pop edi
// 004ffc94  5e                   pop esi
// 004ffc95  c20400               ret 4

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
