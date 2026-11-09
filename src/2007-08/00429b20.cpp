// from server: 100% by auto
// roc 2007-08 00429b20  unit: ThreadLogManager  size: 166 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00429b20
//
// 00429b20  83ec08               sub esp, 8
// 00429b23  53                   push ebx
// 00429b24  56                   push esi
// 00429b25  8bf1                 mov esi, ecx
// 00429b27  8b5e04               mov ebx, dword ptr [esi + 4]
// 00429b2a  85db                 test ebx, ebx
// 00429b2c  57                   push edi
// 00429b2d  7504                 jne 0x429b33
// 00429b2f  33ff                 xor edi, edi
// 00429b31  eb18                 jmp 0x429b4b
// 00429b33  8b4e08               mov ecx, dword ptr [esi + 8]
// 00429b36  2bcb                 sub ecx, ebx
// 00429b38  b893244992           mov eax, 0x92492493
// 00429b3d  f7e9                 imul ecx
// 00429b3f  03d1                 add edx, ecx
// 00429b41  c1fa04               sar edx, 4
// 00429b44  8bfa                 mov edi, edx
// 00429b46  c1ef1f               shr edi, 0x1f
// 00429b49  03fa                 add edi, edx
// 00429b4b  85db                 test ebx, ebx
// 00429b4d  744e                 je 0x429b9d
// 00429b4f  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00429b52  2bcb                 sub ecx, ebx
// 00429b54  b893244992           mov eax, 0x92492493
// 00429b59  f7e9                 imul ecx
// 00429b5b  03d1                 add edx, ecx
// 00429b5d  c1fa04               sar edx, 4
// 00429b60  8bc2                 mov eax, edx
// 00429b62  c1e81f               shr eax, 0x1f
// 00429b65  03c2                 add eax, edx
// 00429b67  3bf8                 cmp edi, eax
// 00429b69  7332                 jae 0x429b9d
// 00429b6b  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00429b6f  8b542418             mov edx, dword ptr [esp + 0x18]
// 00429b73  8b7e08               mov edi, dword ptr [esi + 8]
// 00429b76  c644240c00           mov byte ptr [esp + 0xc], 0
// 00429b7b  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00429b7f  50                   push eax
// 00429b80  51                   push ecx
// 00429b81  56                   push esi
// 00429b82  52                   push edx
// 00429b83  6a01                 push 1
// 00429b85  57                   push edi
// 00429b86  e835f4ffff           call 0x428fc0
// 00429b8b  83c418               add esp, 0x18
// 00429b8e  83c71c               add edi, 0x1c
// 00429b91  897e08               mov dword ptr [esi + 8], edi
// 00429b94  5f                   pop edi
// 00429b95  5e                   pop esi
// 00429b96  5b                   pop ebx
// 00429b97  83c408               add esp, 8
// 00429b9a  c20400               ret 4
// 00429b9d  8b7e08               mov edi, dword ptr [esi + 8]
// 00429ba0  3bdf                 cmp ebx, edi
// 00429ba2  7606                 jbe 0x429baa
// 00429ba4  ff15d8e67700         call dword ptr [0x77e6d8]
// 00429baa  8b442418             mov eax, dword ptr [esp + 0x18]
// 00429bae  50                   push eax
// 00429baf  57                   push edi
// 00429bb0  56                   push esi
// 00429bb1  8d4c2418             lea ecx, [esp + 0x18]
// 00429bb5  51                   push ecx
// 00429bb6  8bce                 mov ecx, esi
// 00429bb8  e8f3faffff           call 0x4296b0
// 00429bbd  5f                   pop edi
// 00429bbe  5e                   pop esi
// 00429bbf  5b                   pop ebx
// 00429bc0  83c408               add esp, 8
// 00429bc3  c20400               ret 4
// standard library vector<string> (function ?push_back@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAEXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
