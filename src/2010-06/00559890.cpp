// from server: 100% by auto
// roc 2010-06 00559890  unit: G3D::BinaryInput  size: 169 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00559890
//
// 00559890  83ec10               sub esp, 0x10
// 00559893  53                   push ebx
// 00559894  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00559898  56                   push esi
// 00559899  8bf1                 mov esi, ecx
// 0055989b  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0055989e  57                   push edi
// 0055989f  8b7e10               mov edi, dword ptr [esi + 0x10]
// 005598a2  8bc7                 mov eax, edi
// 005598a4  2bc1                 sub eax, ecx
// 005598a6  c1f803               sar eax, 3
// 005598a9  3bd8                 cmp ebx, eax
// 005598ab  762f                 jbe 0x5598dc
// 005598ad  3bcf                 cmp ecx, edi
// 005598af  7606                 jbe 0x5598b7
// 005598b1  ff150ca99e00         call dword ptr [0x9ea90c]
// 005598b7  8b5610               mov edx, dword ptr [esi + 0x10]
// 005598ba  2b560c               sub edx, dword ptr [esi + 0xc]
// 005598bd  8b06                 mov eax, dword ptr [esi]
// 005598bf  8d4c2424             lea ecx, [esp + 0x24]
// 005598c3  51                   push ecx
// 005598c4  c1fa03               sar edx, 3
// 005598c7  2bda                 sub ebx, edx
// 005598c9  53                   push ebx
// 005598ca  57                   push edi
// 005598cb  50                   push eax
// 005598cc  8bce                 mov ecx, esi
// 005598ce  e84dfdffff           call 0x559620
// 005598d3  5f                   pop edi
// 005598d4  5e                   pop esi
// 005598d5  5b                   pop ebx
// 005598d6  83c410               add esp, 0x10
// 005598d9  c20c00               ret 0xc
// 005598dc  7352                 jae 0x559930
// 005598de  3bcf                 cmp ecx, edi
// 005598e0  7606                 jbe 0x5598e8
// 005598e2  ff150ca99e00         call dword ptr [0x9ea90c]
// 005598e8  8b06                 mov eax, dword ptr [esi]
// 005598ea  55                   push ebp
// 005598eb  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 005598ee  89442410             mov dword ptr [esp + 0x10], eax
// 005598f2  3b6e10               cmp ebp, dword ptr [esi + 0x10]
// 005598f5  7606                 jbe 0x5598fd
// 005598f7  ff150ca99e00         call dword ptr [0x9ea90c]
// 005598fd  8b0e                 mov ecx, dword ptr [esi]
// 005598ff  53                   push ebx
// 00559900  8d54241c             lea edx, [esp + 0x1c]
// 00559904  894c242c             mov dword ptr [esp + 0x2c], ecx
// 00559908  52                   push edx
// 00559909  8d4c2430             lea ecx, [esp + 0x30]
// 0055990d  896c2434             mov dword ptr [esp + 0x34], ebp
// 00559911  e81a0d1500           call 0x6aa630
// 00559916  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0055991a  8b5004               mov edx, dword ptr [eax + 4]
// 0055991d  8b00                 mov eax, dword ptr [eax]
// 0055991f  57                   push edi
// 00559920  51                   push ecx
// 00559921  52                   push edx
// 00559922  50                   push eax
// 00559923  8d4c2438             lea ecx, [esp + 0x38]
// 00559927  51                   push ecx
// 00559928  8bce                 mov ecx, esi
// 0055992a  e881f8ffff           call 0x5591b0
// 0055992f  5d                   pop ebp
// 00559930  5f                   pop edi
// 00559931  5e                   pop esi
// 00559932  5b                   pop ebx
// 00559933  83c410               add esp, 0x10
// 00559936  c20c00               ret 0xc
// standard library vector<double> (function ?resize@?$vector@NV?$allocator@N@std@@@std@@QAEXIN@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
