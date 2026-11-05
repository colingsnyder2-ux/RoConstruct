// from server: 100% by nuck16
// roc 2009-12 00447ba0  unit: RBX::CRenderSettings::W4ShadowMode::?$EnumDesc  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00447ba0
//
// 00447ba0  8b442404             mov eax, dword ptr [esp + 4]
// 00447ba4  56                   push esi
// 00447ba5  57                   push edi
// 00447ba6  50                   push eax
// 00447ba7  8bf1                 mov esi, ecx
// 00447ba9  e842f9ffff           call 0x4474f0
// 00447bae  8b38                 mov edi, dword ptr [eax]
// 00447bb0  83c404               add esp, 4
// 00447bb3  85ff                 test edi, edi
// 00447bb5  7d07                 jge 0x447bbe
// 00447bb7  5f                   pop edi
// 00447bb8  33c0                 xor eax, eax
// 00447bba  5e                   pop esi
// 00447bbb  c20400               ret 4
// 00447bbe  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 00447bc4  2b8eb0000000         sub ecx, dword ptr [esi + 0xb0]
// 00447bca  c1f902               sar ecx, 2
// 00447bcd  3bf9                 cmp edi, ecx
// 00447bcf  73e6                 jae 0x447bb7
// 00447bd1  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 00447bd7  2b96b0000000         sub edx, dword ptr [esi + 0xb0]
// 00447bdd  c1fa02               sar edx, 2
// 00447be0  3bfa                 cmp edi, edx
// 00447be2  7206                 jb 0x447bea
// 00447be4  ff1560b79800         call dword ptr [0x98b760]
// 00447bea  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 00447bf0  8b04b8               mov eax, dword ptr [eax + edi*4]
// 00447bf3  5f                   pop edi
// 00447bf4  5e                   pop esi
// 00447bf5  c20400               ret 4

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
