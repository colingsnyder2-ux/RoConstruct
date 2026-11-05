// from server: 100% by nuck16
// roc 2009-12 00652640  unit: RBX::PlayerCamera::W4CameraType::?$EnumDesc  size: 88 bytes
//
// 00652640  8b442404             mov eax, dword ptr [esp + 4]
// 00652644  56                   push esi
// 00652645  57                   push edi
// 00652646  50                   push eax
// 00652647  8bf1                 mov esi, ecx
// 00652649  e8128affff           call 0x64b060
// 0065264e  8b38                 mov edi, dword ptr [eax]
// 00652650  83c404               add esp, 4
// 00652653  85ff                 test edi, edi
// 00652655  7d07                 jge 0x65265e
// 00652657  5f                   pop edi
// 00652658  33c0                 xor eax, eax
// 0065265a  5e                   pop esi
// 0065265b  c20400               ret 4
// 0065265e  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 00652664  2b8eb0000000         sub ecx, dword ptr [esi + 0xb0]
// 0065266a  c1f902               sar ecx, 2
// 0065266d  3bf9                 cmp edi, ecx
// 0065266f  73e6                 jae 0x652657
// 00652671  8b96b4000000         mov edx, dword ptr [esi + 0xb4]
// 00652677  2b96b0000000         sub edx, dword ptr [esi + 0xb0]
// 0065267d  c1fa02               sar edx, 2
// 00652680  3bfa                 cmp edi, edx
// 00652682  7206                 jb 0x65268a
// 00652684  ff1560b79800         call dword ptr [0x98b760]
// 0065268a  8b86b0000000         mov eax, dword ptr [esi + 0xb0]
// 00652690  8b04b8               mov eax, dword ptr [eax + edi*4]
// 00652693  5f                   pop edi
// 00652694  5e                   pop esi
// 00652695  c20400               ret 4

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
