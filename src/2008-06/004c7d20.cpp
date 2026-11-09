// from server: 100% by auto
// roc 2008-06 004c7d20  unit: RBX::VInstance::?$Association::Item  size: 169 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c7d20
//
// 004c7d20  83ec18               sub esp, 0x18
// 004c7d23  53                   push ebx
// 004c7d24  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 004c7d28  56                   push esi
// 004c7d29  8bf1                 mov esi, ecx
// 004c7d2b  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004c7d2e  57                   push edi
// 004c7d2f  8b7e10               mov edi, dword ptr [esi + 0x10]
// 004c7d32  8bc7                 mov eax, edi
// 004c7d34  2bc1                 sub eax, ecx
// 004c7d36  c1f802               sar eax, 2
// 004c7d39  3bd8                 cmp ebx, eax
// 004c7d3b  762f                 jbe 0x4c7d6c
// 004c7d3d  3bcf                 cmp ecx, edi
// 004c7d3f  7606                 jbe 0x4c7d47
// 004c7d41  ff1590288000         call dword ptr [0x802890]
// 004c7d47  8b5610               mov edx, dword ptr [esi + 0x10]
// 004c7d4a  2b560c               sub edx, dword ptr [esi + 0xc]
// 004c7d4d  8b06                 mov eax, dword ptr [esi]
// 004c7d4f  8d4c242c             lea ecx, [esp + 0x2c]
// 004c7d53  51                   push ecx
// 004c7d54  c1fa02               sar edx, 2
// 004c7d57  2bda                 sub ebx, edx
// 004c7d59  53                   push ebx
// 004c7d5a  57                   push edi
// 004c7d5b  50                   push eax
// 004c7d5c  8bce                 mov ecx, esi
// 004c7d5e  e82dfdffff           call 0x4c7a90
// 004c7d63  5f                   pop edi
// 004c7d64  5e                   pop esi
// 004c7d65  5b                   pop ebx
// 004c7d66  83c418               add esp, 0x18
// 004c7d69  c20800               ret 8
// 004c7d6c  7352                 jae 0x4c7dc0
// 004c7d6e  3bcf                 cmp ecx, edi
// 004c7d70  7606                 jbe 0x4c7d78
// 004c7d72  ff1590288000         call dword ptr [0x802890]
// 004c7d78  8b06                 mov eax, dword ptr [esi]
// 004c7d7a  55                   push ebp
// 004c7d7b  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 004c7d7e  89442418             mov dword ptr [esp + 0x18], eax
// 004c7d82  3b6e10               cmp ebp, dword ptr [esi + 0x10]
// 004c7d85  7606                 jbe 0x4c7d8d
// 004c7d87  ff1590288000         call dword ptr [0x802890]
// 004c7d8d  8b0e                 mov ecx, dword ptr [esi]
// 004c7d8f  53                   push ebx
// 004c7d90  8d542424             lea edx, [esp + 0x24]
// 004c7d94  894c2414             mov dword ptr [esp + 0x14], ecx
// 004c7d98  52                   push edx
// 004c7d99  8d4c2418             lea ecx, [esp + 0x18]
// 004c7d9d  896c241c             mov dword ptr [esp + 0x1c], ebp
// 004c7da1  e85a2b1800           call 0x64a900
// 004c7da6  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004c7daa  8b5004               mov edx, dword ptr [eax + 4]
// 004c7dad  8b00                 mov eax, dword ptr [eax]
// 004c7daf  57                   push edi
// 004c7db0  51                   push ecx
// 004c7db1  52                   push edx
// 004c7db2  50                   push eax
// 004c7db3  8d4c2428             lea ecx, [esp + 0x28]
// 004c7db7  51                   push ecx
// 004c7db8  8bce                 mov ecx, esi
// 004c7dba  e801e0f7ff           call 0x445dc0
// 004c7dbf  5d                   pop ebp
// 004c7dc0  5f                   pop edi
// 004c7dc1  5e                   pop esi
// 004c7dc2  5b                   pop ebx
// 004c7dc3  83c418               add esp, 0x18
// 004c7dc6  c20800               ret 8
// standard library vector<ptr> (function ?resize@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXIPAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
