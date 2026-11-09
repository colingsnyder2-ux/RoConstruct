// from server: 100% by auto
// roc 2008-06 006740e0  unit: RBX::AdornRbxGfx  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006740e0
//
// 006740e0  83ec08               sub esp, 8
// 006740e3  56                   push esi
// 006740e4  8bf1                 mov esi, ecx
// 006740e6  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 006740e9  57                   push edi
// 006740ea  85c9                 test ecx, ecx
// 006740ec  7504                 jne 0x6740f2
// 006740ee  33c0                 xor eax, eax
// 006740f0  eb08                 jmp 0x6740fa
// 006740f2  8b4614               mov eax, dword ptr [esi + 0x14]
// 006740f5  2bc1                 sub eax, ecx
// 006740f7  c1f803               sar eax, 3
// 006740fa  8b7e10               mov edi, dword ptr [esi + 0x10]
// 006740fd  8bd7                 mov edx, edi
// 006740ff  2bd1                 sub edx, ecx
// 00674101  c1fa03               sar edx, 3
// 00674104  3bd0                 cmp edx, eax
// 00674106  7331                 jae 0x674139
// 00674108  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0067410c  c644240800           mov byte ptr [esp + 8], 0
// 00674111  8b442408             mov eax, dword ptr [esp + 8]
// 00674115  50                   push eax
// 00674116  8b442418             mov eax, dword ptr [esp + 0x18]
// 0067411a  51                   push ecx
// 0067411b  8d5608               lea edx, [esi + 8]
// 0067411e  52                   push edx
// 0067411f  50                   push eax
// 00674120  6a01                 push 1
// 00674122  57                   push edi
// 00674123  e8f8880000           call 0x67ca20
// 00674128  83c418               add esp, 0x18
// 0067412b  83c708               add edi, 8
// 0067412e  897e10               mov dword ptr [esi + 0x10], edi
// 00674131  5f                   pop edi
// 00674132  5e                   pop esi
// 00674133  83c408               add esp, 8
// 00674136  c20400               ret 4
// 00674139  3bcf                 cmp ecx, edi
// 0067413b  7606                 jbe 0x674143
// 0067413d  ff1590288000         call dword ptr [0x802890]
// 00674143  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00674147  8b06                 mov eax, dword ptr [esi]
// 00674149  51                   push ecx
// 0067414a  57                   push edi
// 0067414b  50                   push eax
// 0067414c  8d542414             lea edx, [esp + 0x14]
// 00674150  52                   push edx
// 00674151  8bce                 mov ecx, esi
// 00674153  e838dbffff           call 0x671c90
// 00674158  5f                   pop edi
// 00674159  5e                   pop esi
// 0067415a  83c408               add esp, 8
// 0067415d  c20400               ret 4
// standard library vector<pod8> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
