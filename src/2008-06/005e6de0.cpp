// from server: 100% by auto
// roc 2008-06 005e6de0  unit: RBX::Clump  size: 169 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005e6de0
//
// 005e6de0  83ec18               sub esp, 0x18
// 005e6de3  53                   push ebx
// 005e6de4  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 005e6de8  56                   push esi
// 005e6de9  8bf1                 mov esi, ecx
// 005e6deb  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 005e6dee  57                   push edi
// 005e6def  8b7e10               mov edi, dword ptr [esi + 0x10]
// 005e6df2  8bc7                 mov eax, edi
// 005e6df4  2bc1                 sub eax, ecx
// 005e6df6  c1f802               sar eax, 2
// 005e6df9  3bd8                 cmp ebx, eax
// 005e6dfb  762f                 jbe 0x5e6e2c
// 005e6dfd  3bcf                 cmp ecx, edi
// 005e6dff  7606                 jbe 0x5e6e07
// 005e6e01  ff1590288000         call dword ptr [0x802890]
// 005e6e07  8b5610               mov edx, dword ptr [esi + 0x10]
// 005e6e0a  2b560c               sub edx, dword ptr [esi + 0xc]
// 005e6e0d  8b06                 mov eax, dword ptr [esi]
// 005e6e0f  8d4c242c             lea ecx, [esp + 0x2c]
// 005e6e13  51                   push ecx
// 005e6e14  c1fa02               sar edx, 2
// 005e6e17  2bda                 sub ebx, edx
// 005e6e19  53                   push ebx
// 005e6e1a  57                   push edi
// 005e6e1b  50                   push eax
// 005e6e1c  8bce                 mov ecx, esi
// 005e6e1e  e86d0aeeff           call 0x4c7890
// 005e6e23  5f                   pop edi
// 005e6e24  5e                   pop esi
// 005e6e25  5b                   pop ebx
// 005e6e26  83c418               add esp, 0x18
// 005e6e29  c20800               ret 8
// 005e6e2c  7352                 jae 0x5e6e80
// 005e6e2e  3bcf                 cmp ecx, edi
// 005e6e30  7606                 jbe 0x5e6e38
// 005e6e32  ff1590288000         call dword ptr [0x802890]
// 005e6e38  8b06                 mov eax, dword ptr [esi]
// 005e6e3a  55                   push ebp
// 005e6e3b  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 005e6e3e  89442418             mov dword ptr [esp + 0x18], eax
// 005e6e42  3b6e10               cmp ebp, dword ptr [esi + 0x10]
// 005e6e45  7606                 jbe 0x5e6e4d
// 005e6e47  ff1590288000         call dword ptr [0x802890]
// 005e6e4d  8b0e                 mov ecx, dword ptr [esi]
// 005e6e4f  53                   push ebx
// 005e6e50  8d542424             lea edx, [esp + 0x24]
// 005e6e54  894c2414             mov dword ptr [esp + 0x14], ecx
// 005e6e58  52                   push edx
// 005e6e59  8d4c2418             lea ecx, [esp + 0x18]
// 005e6e5d  896c241c             mov dword ptr [esp + 0x1c], ebp
// 005e6e61  e89a3a0600           call 0x64a900
// 005e6e66  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005e6e6a  8b5004               mov edx, dword ptr [eax + 4]
// 005e6e6d  8b00                 mov eax, dword ptr [eax]
// 005e6e6f  57                   push edi
// 005e6e70  51                   push ecx
// 005e6e71  52                   push edx
// 005e6e72  50                   push eax
// 005e6e73  8d4c2428             lea ecx, [esp + 0x28]
// 005e6e77  51                   push ecx
// 005e6e78  8bce                 mov ecx, esi
// 005e6e7a  e841efe5ff           call 0x445dc0
// 005e6e7f  5d                   pop ebp
// 005e6e80  5f                   pop edi
// 005e6e81  5e                   pop esi
// 005e6e82  5b                   pop ebx
// 005e6e83  83c418               add esp, 0x18
// 005e6e86  c20800               ret 8
// standard library vector<ptr> (function ?resize@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXIPAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
