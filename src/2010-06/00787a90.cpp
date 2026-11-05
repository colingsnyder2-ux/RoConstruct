// from server: 100% by auto
// roc 2010-06 00787a90  unit: RBX::HUMAN::GettingUp  size: 405 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00787a90
//
// 00787a90  55                   push ebp
// 00787a91  8bec                 mov ebp, esp
// 00787a93  6aff                 push -1
// 00787a95  6800cf9a00           push 0x9acf00
// 00787a9a  64a100000000         mov eax, dword ptr fs:[0]
// 00787aa0  50                   push eax
// 00787aa1  64892500000000       mov dword ptr fs:[0], esp
// 00787aa8  83ec1c               sub esp, 0x1c
// 00787aab  53                   push ebx
// 00787aac  56                   push esi
// 00787aad  8bf1                 mov esi, ecx
// 00787aaf  8b460c               mov eax, dword ptr [esi + 0xc]
// 00787ab2  57                   push edi
// 00787ab3  8965f0               mov dword ptr [ebp - 0x10], esp
// 00787ab6  85c0                 test eax, eax
// 00787ab8  7504                 jne 0x787abe
// 00787aba  33c9                 xor ecx, ecx
// 00787abc  eb18                 jmp 0x787ad6
// 00787abe  8b5614               mov edx, dword ptr [esi + 0x14]
// 00787ac1  2bd0                 sub edx, eax
// 00787ac3  b867666666           mov eax, 0x66666667
// 00787ac8  f7ea                 imul edx
// 00787aca  c1fa03               sar edx, 3
// 00787acd  8bc2                 mov eax, edx
// 00787acf  c1e81f               shr eax, 0x1f
// 00787ad2  03c2                 add eax, edx
// 00787ad4  8bc8                 mov ecx, eax
// 00787ad6  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 00787ad9  85ff                 test edi, edi
// 00787adb  0f8466020000         je 0x787d47
// 00787ae1  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 00787ae4  8bd3                 mov edx, ebx
// 00787ae6  2b560c               sub edx, dword ptr [esi + 0xc]
// 00787ae9  b867666666           mov eax, 0x66666667
// 00787aee  f7ea                 imul edx
// 00787af0  c1fa03               sar edx, 3
// 00787af3  8bc2                 mov eax, edx
// 00787af5  c1e81f               shr eax, 0x1f
// 00787af8  03c2                 add eax, edx
// 00787afa  bacccccc0c           mov edx, 0xccccccc
// 00787aff  2bd0                 sub edx, eax
// 00787b01  3bd7                 cmp edx, edi
// 00787b03  7305                 jae 0x787b0a
// 00787b05  e8e6c2c9ff           call 0x423df0
// 00787b0a  8d1438               lea edx, [eax + edi]
// 00787b0d  3bca                 cmp ecx, edx
// 00787b0f  0f8325010000         jae 0x787c3a
// 00787b15  8bc1                 mov eax, ecx
// 00787b17  d1e8                 shr eax, 1
// 00787b19  bbcccccc0c           mov ebx, 0xccccccc
// 00787b1e  2bd8                 sub ebx, eax
// 00787b20  3bd9                 cmp ebx, ecx
// 00787b22  730c                 jae 0x787b30
// 00787b24  c745ec00000000       mov dword ptr [ebp - 0x14], 0
// 00787b2b  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 00787b2e  eb05                 jmp 0x787b35
// 00787b30  03c8                 add ecx, eax
// 00787b32  894dec               mov dword ptr [ebp - 0x14], ecx
// 00787b35  3bca                 cmp ecx, edx
// 00787b37  7305                 jae 0x787b3e
// 00787b39  8955ec               mov dword ptr [ebp - 0x14], edx
// 00787b3c  8bca                 mov ecx, edx
// 00787b3e  6a00                 push 0
// 00787b40  51                   push ecx
// 00787b41  e82adcfcff           call 0x755770
// 00787b46  8b550c               mov edx, dword ptr [ebp + 0xc]
// 00787b49  2b560c               sub edx, dword ptr [esi + 0xc]
// 00787b4c  8bc8                 mov ecx, eax
// 00787b4e  b867666666           mov eax, 0x66666667
// 00787b53  f7ea                 imul edx
// 00787b55  8b4514               mov eax, dword ptr [ebp + 0x14]
// 00787b58  c1fa03               sar edx, 3
// 00787b5b  8bda                 mov ebx, edx
// 00787b5d  83c408               add esp, 8
// 00787b60  c1eb1f               shr ebx, 0x1f
// 00787b63  03da                 add ebx, edx
// 00787b65  50                   push eax
// 00787b66  8d149b               lea edx, [ebx + ebx*4]
// 00787b69  8d0491               lea eax, [ecx + edx*4]
// 00787b6c  57                   push edi
// 00787b6d  894d10               mov dword ptr [ebp + 0x10], ecx
// 00787b70  50                   push eax
// 00787b71  8bce                 mov ecx, esi
// 00787b73  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00787b7a  e861fbffff           call 0x7876e0
// 00787b7f  8b460c               mov eax, dword ptr [esi + 0xc]
// 00787b82  c6451400             mov byte ptr [ebp + 0x14], 0
// 00787b86  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00787b89  52                   push edx
// 00787b8a  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00787b8d  52                   push edx
// 00787b8e  8b550c               mov edx, dword ptr [ebp + 0xc]
// 00787b91  8d4e08               lea ecx, [esi + 8]
// 00787b94  51                   push ecx
// 00787b95  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 00787b98  51                   push ecx
// 00787b99  52                   push edx
// 00787b9a  50                   push eax
// 00787b9b  e870f5ffff           call 0x787110
// 00787ba0  8b5510               mov edx, dword ptr [ebp + 0x10]
// 00787ba3  8b4610               mov eax, dword ptr [esi + 0x10]
// 00787ba6  83c418               add esp, 0x18
// 00787ba9  03df                 add ebx, edi
// 00787bab  8d0c9b               lea ecx, [ebx + ebx*4]
// 00787bae  8d0c8a               lea ecx, [edx + ecx*4]
// 00787bb1  c6451400             mov byte ptr [ebp + 0x14], 0
// 00787bb5  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00787bb8  52                   push edx
// 00787bb9  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00787bbc  52                   push edx
// 00787bbd  8d5608               lea edx, [esi + 8]
// 00787bc0  52                   push edx
// 00787bc1  51                   push ecx
// 00787bc2  50                   push eax
// 00787bc3  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00787bc6  50                   push eax
// 00787bc7  e844f5ffff           call 0x787110
// 00787bcc  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00787bcf  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00787bd2  2bcb                 sub ecx, ebx
// 00787bd4  b867666666           mov eax, 0x66666667
// 00787bd9  f7e9                 imul ecx
// 00787bdb  c1fa03               sar edx, 3
// 00787bde  8bca                 mov ecx, edx
// 00787be0  c1e91f               shr ecx, 0x1f
// 00787be3  03ca                 add ecx, edx
// 00787be5  83c418               add esp, 0x18
// 00787be8  03f9                 add edi, ecx
// 00787bea  85db                 test ebx, ebx
// 00787bec  7409                 je 0x787bf7
// 00787bee  53                   push ebx
// 00787bef  e8a6fd0100           call 0x7a799a
// 00787bf4  83c404               add esp, 4
// 00787bf7  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 00787bfa  8d1480               lea edx, [eax + eax*4]
// 00787bfd  8b4510               mov eax, dword ptr [ebp + 0x10]
// 00787c00  8d0c90               lea ecx, [eax + edx*4]
// 00787c03  8d14bf               lea edx, [edi + edi*4]
// 00787c06  894e14               mov dword ptr [esi + 0x14], ecx
// 00787c09  8d0c90               lea ecx, [eax + edx*4]
// 00787c0c  894e10               mov dword ptr [esi + 0x10], ecx
// 00787c0f  89460c               mov dword ptr [esi + 0xc], eax
// 00787c12  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00787c15  64890d00000000       mov dword ptr fs:[0], ecx
// 00787c1c  5f                   pop edi
// 00787c1d  5e                   pop esi
// 00787c1e  5b                   pop ebx
// 00787c1f  8be5                 mov esp, ebp
// 00787c21  5d                   pop ebp
// 00787c22  c21000               ret 0x10
// standard library vector<pod20> (function ?_Insert_n@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEXV?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@IABUE@@@Z)

// stl: vector<pod20>
struct E { int v[5]; };
#include <vector>
template class std::vector<E>;
