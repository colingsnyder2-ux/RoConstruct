// from server: 100% by auto
// roc 2010-06 0061c360  unit: RBX::Accoutrement  size: 169 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0061c360
//
// 0061c360  83ec18               sub esp, 0x18
// 0061c363  53                   push ebx
// 0061c364  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 0061c368  56                   push esi
// 0061c369  8bf1                 mov esi, ecx
// 0061c36b  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0061c36e  57                   push edi
// 0061c36f  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0061c372  8bc7                 mov eax, edi
// 0061c374  2bc1                 sub eax, ecx
// 0061c376  c1f802               sar eax, 2
// 0061c379  3bd8                 cmp ebx, eax
// 0061c37b  762f                 jbe 0x61c3ac
// 0061c37d  3bcf                 cmp ecx, edi
// 0061c37f  7606                 jbe 0x61c387
// 0061c381  ff150ca99e00         call dword ptr [0x9ea90c]
// 0061c387  8b5610               mov edx, dword ptr [esi + 0x10]
// 0061c38a  2b560c               sub edx, dword ptr [esi + 0xc]
// 0061c38d  8b06                 mov eax, dword ptr [esi]
// 0061c38f  8d4c242c             lea ecx, [esp + 0x2c]
// 0061c393  51                   push ecx
// 0061c394  c1fa02               sar edx, 2
// 0061c397  2bda                 sub ebx, edx
// 0061c399  53                   push ebx
// 0061c39a  57                   push edi
// 0061c39b  50                   push eax
// 0061c39c  8bce                 mov ecx, esi
// 0061c39e  e81da3e2ff           call 0x4466c0
// 0061c3a3  5f                   pop edi
// 0061c3a4  5e                   pop esi
// 0061c3a5  5b                   pop ebx
// 0061c3a6  83c418               add esp, 0x18
// 0061c3a9  c20800               ret 8
// 0061c3ac  7352                 jae 0x61c400
// 0061c3ae  3bcf                 cmp ecx, edi
// 0061c3b0  7606                 jbe 0x61c3b8
// 0061c3b2  ff150ca99e00         call dword ptr [0x9ea90c]
// 0061c3b8  8b06                 mov eax, dword ptr [esi]
// 0061c3ba  55                   push ebp
// 0061c3bb  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 0061c3be  89442418             mov dword ptr [esp + 0x18], eax
// 0061c3c2  3b6e10               cmp ebp, dword ptr [esi + 0x10]
// 0061c3c5  7606                 jbe 0x61c3cd
// 0061c3c7  ff150ca99e00         call dword ptr [0x9ea90c]
// 0061c3cd  8b0e                 mov ecx, dword ptr [esi]
// 0061c3cf  53                   push ebx
// 0061c3d0  8d542424             lea edx, [esp + 0x24]
// 0061c3d4  894c2414             mov dword ptr [esp + 0x14], ecx
// 0061c3d8  52                   push edx
// 0061c3d9  8d4c2418             lea ecx, [esp + 0x18]
// 0061c3dd  896c241c             mov dword ptr [esp + 0x1c], ebp
// 0061c3e1  e8baa6ecff           call 0x4e6aa0
// 0061c3e6  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0061c3ea  8b5004               mov edx, dword ptr [eax + 4]
// 0061c3ed  8b00                 mov eax, dword ptr [eax]
// 0061c3ef  57                   push edi
// 0061c3f0  51                   push ecx
// 0061c3f1  52                   push edx
// 0061c3f2  50                   push eax
// 0061c3f3  8d4c2428             lea ecx, [esp + 0x28]
// 0061c3f7  51                   push ecx
// 0061c3f8  8bce                 mov ecx, esi
// 0061c3fa  e8419fe2ff           call 0x446340
// 0061c3ff  5d                   pop ebp
// 0061c400  5f                   pop edi
// 0061c401  5e                   pop esi
// 0061c402  5b                   pop ebx
// 0061c403  83c418               add esp, 0x18
// 0061c406  c20800               ret 8
// standard library vector<ptr> (function ?resize@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXIPAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
