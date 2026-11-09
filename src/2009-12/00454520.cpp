// from server: 100% by nuck16
// roc 2009-12 00454520  unit: RBX::PartInstance::W4Material::?$EnumDesc  size: 88 bytes
//
// 00454520  8b442404             mov eax, dword ptr [esp + 4]
// 00454524  56                   push esi
// 00454525  57                   push edi
// 00454526  50                   push eax
// 00454527  8bf1                 mov esi, ecx
// 00454529  e862ffffff           call 0x454490
// 0045452e  8b38                 mov edi, dword ptr [eax]
// 00454530  83c404               add esp, 4
// 00454533  85ff                 test edi, edi
// 00454535  7d07                 jge 0x45453e
// 00454537  5f                   pop edi
// 00454538  33c0                 xor eax, eax
// 0045453a  5e                   pop esi
// 0045453b  c20400               ret 4
// 0045453e  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 00454544  2b8eb0000000         sub ecx, dword ptr [esi + 0xb0]
// 0045454a  c1f902               sar ecx, 2
// 0045454d  3bf9                 cmp edi, ecx
// 0045454f  73e6                 jae 0x454537
// 00454551  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 00454557  2b96b0000000         sub edx, dword ptr [esi + 0xb0]
// 0045455d  c1fa02               sar edx, 2
// 00454560  3bfa                 cmp edi, edx
// 00454562  7206                 jb 0x45456a
// 00454564  ff1560b79800         call dword ptr [0x98b760]
// 0045456a  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 00454570  8b04b8               mov eax, dword ptr [eax + edi*4]
// 00454573  5f                   pop edi
// 00454574  5e                   pop esi
// 00454575  c20400               ret 4

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
