// from server: 100% by auto
// roc 2010-06 005597e0  unit: G3D::BinaryInput  size: 163 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005597e0
//
// 005597e0  83ec18               sub esp, 0x18
// 005597e3  53                   push ebx
// 005597e4  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 005597e8  56                   push esi
// 005597e9  8bf1                 mov esi, ecx
// 005597eb  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 005597ee  57                   push edi
// 005597ef  8b7e10               mov edi, dword ptr [esi + 0x10]
// 005597f2  8bc7                 mov eax, edi
// 005597f4  2bc1                 sub eax, ecx
// 005597f6  3bd8                 cmp ebx, eax
// 005597f8  762c                 jbe 0x559826
// 005597fa  3bcf                 cmp ecx, edi
// 005597fc  7606                 jbe 0x559804
// 005597fe  ff150ca99e00         call dword ptr [0x9ea90c]
// 00559804  8b560c               mov edx, dword ptr [esi + 0xc]
// 00559807  2b5610               sub edx, dword ptr [esi + 0x10]
// 0055980a  8b06                 mov eax, dword ptr [esi]
// 0055980c  8d4c242c             lea ecx, [esp + 0x2c]
// 00559810  51                   push ecx
// 00559811  03d3                 add edx, ebx
// 00559813  52                   push edx
// 00559814  57                   push edi
// 00559815  50                   push eax
// 00559816  8bce                 mov ecx, esi
// 00559818  e8b3faffff           call 0x5592d0
// 0055981d  5f                   pop edi
// 0055981e  5e                   pop esi
// 0055981f  5b                   pop ebx
// 00559820  83c418               add esp, 0x18
// 00559823  c20800               ret 8
// 00559826  7352                 jae 0x55987a
// 00559828  3bcf                 cmp ecx, edi
// 0055982a  7606                 jbe 0x559832
// 0055982c  ff150ca99e00         call dword ptr [0x9ea90c]
// 00559832  8b06                 mov eax, dword ptr [esi]
// 00559834  55                   push ebp
// 00559835  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 00559838  89442418             mov dword ptr [esp + 0x18], eax
// 0055983c  3b6e10               cmp ebp, dword ptr [esi + 0x10]
// 0055983f  7606                 jbe 0x559847
// 00559841  ff150ca99e00         call dword ptr [0x9ea90c]
// 00559847  8b0e                 mov ecx, dword ptr [esi]
// 00559849  53                   push ebx
// 0055984a  8d542424             lea edx, [esp + 0x24]
// 0055984e  894c2414             mov dword ptr [esp + 0x14], ecx
// 00559852  52                   push edx
// 00559853  8d4c2418             lea ecx, [esp + 0x18]
// 00559857  896c241c             mov dword ptr [esp + 0x1c], ebp
// 0055985b  e8e0f6ffff           call 0x558f40
// 00559860  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00559864  8b5004               mov edx, dword ptr [eax + 4]
// 00559867  8b00                 mov eax, dword ptr [eax]
// 00559869  57                   push edi
// 0055986a  51                   push ecx
// 0055986b  52                   push edx
// 0055986c  50                   push eax
// 0055986d  8d4c2428             lea ecx, [esp + 0x28]
// 00559871  51                   push ecx
// 00559872  8bce                 mov ecx, esi
// 00559874  e8a7f8ffff           call 0x559120
// 00559879  5d                   pop ebp
// 0055987a  5f                   pop edi
// 0055987b  5e                   pop esi
// 0055987c  5b                   pop ebx
// 0055987d  83c418               add esp, 0x18
// 00559880  c20800               ret 8
// standard library vector<char> (function ?resize@?$vector@DV?$allocator@D@std@@@std@@QAEXID@Z)

// stl: vector<char>
typedef char E;
#include <vector>
template class std::vector<E>;
