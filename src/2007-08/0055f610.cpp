// from server: 100% by EspClaude
// from server: 48% by atomic.potato
// roc 2007-08 0055f610  unit: RBX::ClearBackpack  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0055f610
//
// 0055f610  83ec08               sub esp, 8
// 0055f613  53                   push ebx
// 0055f614  8b99fc000000         mov ebx, dword ptr [ecx + 0xfc]
// 0055f61a  3999f8000000         cmp dword ptr [ecx + 0xf8], ebx
// 0055f620  55                   push ebp
// 0055f621  8b2dd8e67700         mov ebp, dword ptr [0x77e6d8]
// 0055f627  56                   push esi
// 0055f628  8db1f4000000         lea esi, [ecx + 0xf4]
// 0055f62e  7602                 jbe 0x55f632
// 0055f630  ffd5                 call ebp
// 0055f632  57                   push edi
// 0055f633  8b7e04               mov edi, dword ptr [esi + 4]
// 0055f636  3b7e08               cmp edi, dword ptr [esi + 8]
// 0055f639  7602                 jbe 0x55f63d
// 0055f63b  ffd5                 call ebp
// 0055f63d  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0055f641  50                   push eax
// 0055f642  53                   push ebx
// 0055f643  57                   push edi
// 0055f644  897c2420             mov dword ptr [esp + 0x20], edi
// 0055f648  e833f1ffff           call 0x55e780
// 0055f64d  8b7e08               mov edi, dword ptr [esi + 8]
// 0055f650  83c40c               add esp, 0xc
// 0055f653  397e04               cmp dword ptr [esi + 4], edi
// 0055f656  8bd8                 mov ebx, eax
// 0055f658  7602                 jbe 0x55f65c
// 0055f65a  ffd5                 call ebp
// 0055f65c  85f6                 test esi, esi
// 0055f65e  7404                 je 0x55f664
// 0055f660  3bf6                 cmp esi, esi
// 0055f662  7402                 je 0x55f666
// 0055f664  ffd5                 call ebp
// 0055f666  3bdf                 cmp ebx, edi
// 0055f668  5f                   pop edi
// 0055f669  7418                 je 0x55f683
// 0055f66b  85f6                 test esi, esi
// 0055f66d  7502                 jne 0x55f671
// 0055f66f  ffd5                 call ebp
// 0055f671  3b5e08               cmp ebx, dword ptr [esi + 8]
// 0055f674  7202                 jb 0x55f678
// 0055f676  ffd5                 call ebp
// 0055f678  8b03                 mov eax, dword ptr [ebx]
// 0055f67a  5e                   pop esi
// 0055f67b  5d                   pop ebp
// 0055f67c  5b                   pop ebx
// 0055f67d  83c408               add esp, 8
// 0055f680  c20400               ret 4
// 0055f683  5e                   pop esi
// 0055f684  5d                   pop ebp
// 0055f685  33c0                 xor eax, eax
// 0055f687  5b                   pop ebx
// 0055f688  83c408               add esp, 8
// 0055f68b  c20400               ret 4

#include <vector>
#include <algorithm>

class Item;

struct ClearBackpack {
    char pad[0xf4];
    std::vector<Item*> items;
    Item* method(bool (*pred)(Item*));
};

Item* ClearBackpack::method(bool (*pred)(Item*)) {
    std::vector<Item*>::iterator it = std::find_if(items.begin(), items.end(), pred);
    if (it != items.end())
        return *it;
    return 0;
}
