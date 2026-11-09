// from server: 100% by auto
// roc 2009-06 0048add0  unit: Ogre::RbxManualResourceLoaderChain  size: 163 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0048add0
//
// 0048add0  83ec18               sub esp, 0x18
// 0048add3  53                   push ebx
// 0048add4  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 0048add8  56                   push esi
// 0048add9  8bf1                 mov esi, ecx
// 0048addb  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0048adde  57                   push edi
// 0048addf  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0048ade2  8bc7                 mov eax, edi
// 0048ade4  2bc1                 sub eax, ecx
// 0048ade6  3bd8                 cmp ebx, eax
// 0048ade8  762c                 jbe 0x48ae16
// 0048adea  3bcf                 cmp ecx, edi
// 0048adec  7606                 jbe 0x48adf4
// 0048adee  ff15ace98900         call dword ptr [0x89e9ac]
// 0048adf4  8b560c               mov edx, dword ptr [esi + 0xc]
// 0048adf7  2b5610               sub edx, dword ptr [esi + 0x10]
// 0048adfa  8b06                 mov eax, dword ptr [esi]
// 0048adfc  8d4c242c             lea ecx, [esp + 0x2c]
// 0048ae00  51                   push ecx
// 0048ae01  03d3                 add edx, ebx
// 0048ae03  52                   push edx
// 0048ae04  57                   push edi
// 0048ae05  50                   push eax
// 0048ae06  8bce                 mov ecx, esi
// 0048ae08  e833feffff           call 0x48ac40
// 0048ae0d  5f                   pop edi
// 0048ae0e  5e                   pop esi
// 0048ae0f  5b                   pop ebx
// 0048ae10  83c418               add esp, 0x18
// 0048ae13  c20800               ret 8
// 0048ae16  7352                 jae 0x48ae6a
// 0048ae18  3bcf                 cmp ecx, edi
// 0048ae1a  7606                 jbe 0x48ae22
// 0048ae1c  ff15ace98900         call dword ptr [0x89e9ac]
// 0048ae22  8b06                 mov eax, dword ptr [esi]
// 0048ae24  55                   push ebp
// 0048ae25  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 0048ae28  89442418             mov dword ptr [esp + 0x18], eax
// 0048ae2c  3b6e10               cmp ebp, dword ptr [esi + 0x10]
// 0048ae2f  7606                 jbe 0x48ae37
// 0048ae31  ff15ace98900         call dword ptr [0x89e9ac]
// 0048ae37  8b0e                 mov ecx, dword ptr [esi]
// 0048ae39  53                   push ebx
// 0048ae3a  8d542424             lea edx, [esp + 0x24]
// 0048ae3e  894c2414             mov dword ptr [esp + 0x14], ecx
// 0048ae42  52                   push edx
// 0048ae43  8d4c2418             lea ecx, [esp + 0x18]
// 0048ae47  896c241c             mov dword ptr [esp + 0x1c], ebp
// 0048ae4b  e880fbffff           call 0x48a9d0
// 0048ae50  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0048ae54  8b5004               mov edx, dword ptr [eax + 4]
// 0048ae57  8b00                 mov eax, dword ptr [eax]
// 0048ae59  57                   push edi
// 0048ae5a  51                   push ecx
// 0048ae5b  52                   push edx
// 0048ae5c  50                   push eax
// 0048ae5d  8d4c2428             lea ecx, [esp + 0x28]
// 0048ae61  51                   push ecx
// 0048ae62  8bce                 mov ecx, esi
// 0048ae64  e817fdffff           call 0x48ab80
// 0048ae69  5d                   pop ebp
// 0048ae6a  5f                   pop edi
// 0048ae6b  5e                   pop esi
// 0048ae6c  5b                   pop ebx
// 0048ae6d  83c418               add esp, 0x18
// 0048ae70  c20800               ret 8
// standard library vector<char> (function ?resize@?$vector@DV?$allocator@D@std@@@std@@QAEXID@Z)

// stl: vector<char>
typedef char E;
#include <vector>
template class std::vector<E>;
