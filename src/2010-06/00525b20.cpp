// from server: 100% by auto
// roc 2010-06 00525b20  unit: RBX::Mesh::Level  size: 169 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00525b20
//
// 00525b20  83ec18               sub esp, 0x18
// 00525b23  53                   push ebx
// 00525b24  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 00525b28  56                   push esi
// 00525b29  8bf1                 mov esi, ecx
// 00525b2b  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00525b2e  57                   push edi
// 00525b2f  8b7e10               mov edi, dword ptr [esi + 0x10]
// 00525b32  8bc7                 mov eax, edi
// 00525b34  2bc1                 sub eax, ecx
// 00525b36  c1f802               sar eax, 2
// 00525b39  3bd8                 cmp ebx, eax
// 00525b3b  762f                 jbe 0x525b6c
// 00525b3d  3bcf                 cmp ecx, edi
// 00525b3f  7606                 jbe 0x525b47
// 00525b41  ff150ca99e00         call dword ptr [0x9ea90c]
// 00525b47  8b5610               mov edx, dword ptr [esi + 0x10]
// 00525b4a  2b560c               sub edx, dword ptr [esi + 0xc]
// 00525b4d  8b06                 mov eax, dword ptr [esi]
// 00525b4f  8d4c242c             lea ecx, [esp + 0x2c]
// 00525b53  51                   push ecx
// 00525b54  c1fa02               sar edx, 2
// 00525b57  2bda                 sub ebx, edx
// 00525b59  53                   push ebx
// 00525b5a  57                   push edi
// 00525b5b  50                   push eax
// 00525b5c  8bce                 mov ecx, esi
// 00525b5e  e84dfcffff           call 0x5257b0
// 00525b63  5f                   pop edi
// 00525b64  5e                   pop esi
// 00525b65  5b                   pop ebx
// 00525b66  83c418               add esp, 0x18
// 00525b69  c20800               ret 8
// 00525b6c  7352                 jae 0x525bc0
// 00525b6e  3bcf                 cmp ecx, edi
// 00525b70  7606                 jbe 0x525b78
// 00525b72  ff150ca99e00         call dword ptr [0x9ea90c]
// 00525b78  8b06                 mov eax, dword ptr [esi]
// 00525b7a  55                   push ebp
// 00525b7b  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 00525b7e  89442418             mov dword ptr [esp + 0x18], eax
// 00525b82  3b6e10               cmp ebp, dword ptr [esi + 0x10]
// 00525b85  7606                 jbe 0x525b8d
// 00525b87  ff150ca99e00         call dword ptr [0x9ea90c]
// 00525b8d  8b0e                 mov ecx, dword ptr [esi]
// 00525b8f  53                   push ebx
// 00525b90  8d542424             lea edx, [esp + 0x24]
// 00525b94  894c2414             mov dword ptr [esp + 0x14], ecx
// 00525b98  52                   push edx
// 00525b99  8d4c2418             lea ecx, [esp + 0x18]
// 00525b9d  896c241c             mov dword ptr [esp + 0x1c], ebp
// 00525ba1  e8fa0efcff           call 0x4e6aa0
// 00525ba6  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00525baa  8b5004               mov edx, dword ptr [eax + 4]
// 00525bad  8b00                 mov eax, dword ptr [eax]
// 00525baf  57                   push edi
// 00525bb0  51                   push ecx
// 00525bb1  52                   push edx
// 00525bb2  50                   push eax
// 00525bb3  8d4c2428             lea ecx, [esp + 0x28]
// 00525bb7  51                   push ecx
// 00525bb8  8bce                 mov ecx, esi
// 00525bba  e831fbffff           call 0x5256f0
// 00525bbf  5d                   pop ebp
// 00525bc0  5f                   pop edi
// 00525bc1  5e                   pop esi
// 00525bc2  5b                   pop ebx
// 00525bc3  83c418               add esp, 0x18
// 00525bc6  c20800               ret 8
// standard library vector<ptr> (function ?resize@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXIPAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
