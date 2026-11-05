// from server: 100% by auto
// roc 2009-06 00575200  unit: G3D::BinaryInput  size: 169 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00575200
//
// 00575200  83ec10               sub esp, 0x10
// 00575203  53                   push ebx
// 00575204  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00575208  56                   push esi
// 00575209  8bf1                 mov esi, ecx
// 0057520b  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0057520e  57                   push edi
// 0057520f  8b7e10               mov edi, dword ptr [esi + 0x10]
// 00575212  8bc7                 mov eax, edi
// 00575214  2bc1                 sub eax, ecx
// 00575216  c1f803               sar eax, 3
// 00575219  3bd8                 cmp ebx, eax
// 0057521b  762f                 jbe 0x57524c
// 0057521d  3bcf                 cmp ecx, edi
// 0057521f  7606                 jbe 0x575227
// 00575221  ff15ace98900         call dword ptr [0x89e9ac]
// 00575227  8b5610               mov edx, dword ptr [esi + 0x10]
// 0057522a  2b560c               sub edx, dword ptr [esi + 0xc]
// 0057522d  8b06                 mov eax, dword ptr [esi]
// 0057522f  8d4c2424             lea ecx, [esp + 0x24]
// 00575233  51                   push ecx
// 00575234  c1fa03               sar edx, 3
// 00575237  2bda                 sub ebx, edx
// 00575239  53                   push ebx
// 0057523a  57                   push edi
// 0057523b  50                   push eax
// 0057523c  8bce                 mov ecx, esi
// 0057523e  e8fdfdffff           call 0x575040
// 00575243  5f                   pop edi
// 00575244  5e                   pop esi
// 00575245  5b                   pop ebx
// 00575246  83c410               add esp, 0x10
// 00575249  c20c00               ret 0xc
// 0057524c  7352                 jae 0x5752a0
// 0057524e  3bcf                 cmp ecx, edi
// 00575250  7606                 jbe 0x575258
// 00575252  ff15ace98900         call dword ptr [0x89e9ac]
// 00575258  8b06                 mov eax, dword ptr [esi]
// 0057525a  55                   push ebp
// 0057525b  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 0057525e  89442410             mov dword ptr [esp + 0x10], eax
// 00575262  3b6e10               cmp ebp, dword ptr [esi + 0x10]
// 00575265  7606                 jbe 0x57526d
// 00575267  ff15ace98900         call dword ptr [0x89e9ac]
// 0057526d  8b0e                 mov ecx, dword ptr [esi]
// 0057526f  53                   push ebx
// 00575270  8d54241c             lea edx, [esp + 0x1c]
// 00575274  894c242c             mov dword ptr [esp + 0x2c], ecx
// 00575278  52                   push edx
// 00575279  8d4c2430             lea ecx, [esp + 0x30]
// 0057527d  896c2434             mov dword ptr [esp + 0x34], ebp
// 00575281  e89aade9ff           call 0x410020
// 00575286  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0057528a  8b5004               mov edx, dword ptr [eax + 4]
// 0057528d  8b00                 mov eax, dword ptr [eax]
// 0057528f  57                   push edi
// 00575290  51                   push ecx
// 00575291  52                   push edx
// 00575292  50                   push eax
// 00575293  8d4c2438             lea ecx, [esp + 0x38]
// 00575297  51                   push ecx
// 00575298  8bce                 mov ecx, esi
// 0057529a  e8e1fcffff           call 0x574f80
// 0057529f  5d                   pop ebp
// 005752a0  5f                   pop edi
// 005752a1  5e                   pop esi
// 005752a2  5b                   pop ebx
// 005752a3  83c410               add esp, 0x10
// 005752a6  c20c00               ret 0xc
// standard library vector<double> (function ?resize@?$vector@NV?$allocator@N@std@@@std@@QAEXIN@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
