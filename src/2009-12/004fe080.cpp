// from server: 100% by auto
// roc 2009-12 004fe080  unit: RBX::Network::Player::W4BuildPermission::?$EnumDesc  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004fe080
//
// 004fe080  83ec08               sub esp, 8
// 004fe083  53                   push ebx
// 004fe084  55                   push ebp
// 004fe085  56                   push esi
// 004fe086  8bf1                 mov esi, ecx
// 004fe088  8b4610               mov eax, dword ptr [esi + 0x10]
// 004fe08b  57                   push edi
// 004fe08c  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 004fe08f  8bc8                 mov ecx, eax
// 004fe091  2bcf                 sub ecx, edi
// 004fe093  f7c1fcffffff         test ecx, 0xfffffffc
// 004fe099  7504                 jne 0x4fe09f
// 004fe09b  33db                 xor ebx, ebx
// 004fe09d  eb27                 jmp 0x4fe0c6
// 004fe09f  3bf8                 cmp edi, eax
// 004fe0a1  7606                 jbe 0x4fe0a9
// 004fe0a3  ff1560b79800         call dword ptr [0x98b760]
// 004fe0a9  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004fe0ad  8b06                 mov eax, dword ptr [esi]
// 004fe0af  85c9                 test ecx, ecx
// 004fe0b1  7404                 je 0x4fe0b7
// 004fe0b3  3bc8                 cmp ecx, eax
// 004fe0b5  7406                 je 0x4fe0bd
// 004fe0b7  ff1560b79800         call dword ptr [0x98b760]
// 004fe0bd  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004fe0c1  2bdf                 sub ebx, edi
// 004fe0c3  c1fb02               sar ebx, 2
// 004fe0c6  8b542428             mov edx, dword ptr [esp + 0x28]
// 004fe0ca  8b442424             mov eax, dword ptr [esp + 0x24]
// 004fe0ce  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004fe0d2  52                   push edx
// 004fe0d3  6a01                 push 1
// 004fe0d5  50                   push eax
// 004fe0d6  51                   push ecx
// 004fe0d7  8bce                 mov ecx, esi
// 004fe0d9  e812ebffff           call 0x4fcbf0
// 004fe0de  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 004fe0e1  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 004fe0e4  7606                 jbe 0x4fe0ec
// 004fe0e6  ff1560b79800         call dword ptr [0x98b760]
// 004fe0ec  8b36                 mov esi, dword ptr [esi]
// 004fe0ee  8bee                 mov ebp, esi
// 004fe0f0  897c2414             mov dword ptr [esp + 0x14], edi
// 004fe0f4  85f6                 test esi, esi
// 004fe0f6  7518                 jne 0x4fe110
// 004fe0f8  ff1560b79800         call dword ptr [0x98b760]
// 004fe0fe  33c0                 xor eax, eax
// 004fe100  8d3c9f               lea edi, [edi + ebx*4]
// 004fe103  3b7810               cmp edi, dword ptr [eax + 0x10]
// 004fe106  7713                 ja 0x4fe11b
// 004fe108  85f6                 test esi, esi
// 004fe10a  7408                 je 0x4fe114
// 004fe10c  8b36                 mov esi, dword ptr [esi]
// 004fe10e  eb06                 jmp 0x4fe116
// 004fe110  8b06                 mov eax, dword ptr [esi]
// 004fe112  ebec                 jmp 0x4fe100
// 004fe114  33f6                 xor esi, esi
// 004fe116  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 004fe119  7306                 jae 0x4fe121
// 004fe11b  ff1560b79800         call dword ptr [0x98b760]
// 004fe121  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004fe125  897804               mov dword ptr [eax + 4], edi
// 004fe128  5f                   pop edi
// 004fe129  5e                   pop esi
// 004fe12a  8928                 mov dword ptr [eax], ebp
// 004fe12c  5d                   pop ebp
// 004fe12d  5b                   pop ebx
// 004fe12e  83c408               add esp, 8
// 004fe131  c21000               ret 0x10
// standard library vector<ptr> (function ?insert@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@V?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@ABQAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
