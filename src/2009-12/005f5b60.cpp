// from server: 100% by auto
// roc 2009-12 005f5b60  unit: G3D::BinaryInput  size: 169 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005f5b60
//
// 005f5b60  83ec10               sub esp, 0x10
// 005f5b63  53                   push ebx
// 005f5b64  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 005f5b68  56                   push esi
// 005f5b69  8bf1                 mov esi, ecx
// 005f5b6b  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 005f5b6e  57                   push edi
// 005f5b6f  8b7e10               mov edi, dword ptr [esi + 0x10]
// 005f5b72  8bc7                 mov eax, edi
// 005f5b74  2bc1                 sub eax, ecx
// 005f5b76  c1f803               sar eax, 3
// 005f5b79  3bd8                 cmp ebx, eax
// 005f5b7b  762f                 jbe 0x5f5bac
// 005f5b7d  3bcf                 cmp ecx, edi
// 005f5b7f  7606                 jbe 0x5f5b87
// 005f5b81  ff1560b79800         call dword ptr [0x98b760]
// 005f5b87  8b5610               mov edx, dword ptr [esi + 0x10]
// 005f5b8a  2b560c               sub edx, dword ptr [esi + 0xc]
// 005f5b8d  8b06                 mov eax, dword ptr [esi]
// 005f5b8f  8d4c2424             lea ecx, [esp + 0x24]
// 005f5b93  51                   push ecx
// 005f5b94  c1fa03               sar edx, 3
// 005f5b97  2bda                 sub ebx, edx
// 005f5b99  53                   push ebx
// 005f5b9a  57                   push edi
// 005f5b9b  50                   push eax
// 005f5b9c  8bce                 mov ecx, esi
// 005f5b9e  e8fdfdffff           call 0x5f59a0
// 005f5ba3  5f                   pop edi
// 005f5ba4  5e                   pop esi
// 005f5ba5  5b                   pop ebx
// 005f5ba6  83c410               add esp, 0x10
// 005f5ba9  c20c00               ret 0xc
// 005f5bac  7352                 jae 0x5f5c00
// 005f5bae  3bcf                 cmp ecx, edi
// 005f5bb0  7606                 jbe 0x5f5bb8
// 005f5bb2  ff1560b79800         call dword ptr [0x98b760]
// 005f5bb8  8b06                 mov eax, dword ptr [esi]
// 005f5bba  55                   push ebp
// 005f5bbb  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 005f5bbe  89442410             mov dword ptr [esp + 0x10], eax
// 005f5bc2  3b6e10               cmp ebp, dword ptr [esi + 0x10]
// 005f5bc5  7606                 jbe 0x5f5bcd
// 005f5bc7  ff1560b79800         call dword ptr [0x98b760]
// 005f5bcd  8b0e                 mov ecx, dword ptr [esi]
// 005f5bcf  53                   push ebx
// 005f5bd0  8d54241c             lea edx, [esp + 0x1c]
// 005f5bd4  894c242c             mov dword ptr [esp + 0x2c], ecx
// 005f5bd8  52                   push edx
// 005f5bd9  8d4c2430             lea ecx, [esp + 0x30]
// 005f5bdd  896c2434             mov dword ptr [esp + 0x34], ebp
// 005f5be1  e8da81ecff           call 0x4bddc0
// 005f5be6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005f5bea  8b5004               mov edx, dword ptr [eax + 4]
// 005f5bed  8b00                 mov eax, dword ptr [eax]
// 005f5bef  57                   push edi
// 005f5bf0  51                   push ecx
// 005f5bf1  52                   push edx
// 005f5bf2  50                   push eax
// 005f5bf3  8d4c2438             lea ecx, [esp + 0x38]
// 005f5bf7  51                   push ecx
// 005f5bf8  8bce                 mov ecx, esi
// 005f5bfa  e8e1fcffff           call 0x5f58e0
// 005f5bff  5d                   pop ebp
// 005f5c00  5f                   pop edi
// 005f5c01  5e                   pop esi
// 005f5c02  5b                   pop ebx
// 005f5c03  83c410               add esp, 0x10
// 005f5c06  c20c00               ret 0xc
// standard library vector<double> (function ?resize@?$vector@NV?$allocator@N@std@@@std@@QAEXIN@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
