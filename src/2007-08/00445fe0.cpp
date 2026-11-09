// from server: 100% by auto
// roc 2007-08 00445fe0  unit: VCRenderSettings::?$FactoryProduct  size: 304 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00445fe0
//
// 00445fe0  6aff                 push -1
// 00445fe2  6889f67300           push 0x73f689
// 00445fe7  64a100000000         mov eax, dword ptr fs:[0]
// 00445fed  50                   push eax
// 00445fee  83ec08               sub esp, 8
// 00445ff1  53                   push ebx
// 00445ff2  55                   push ebp
// 00445ff3  56                   push esi
// 00445ff4  57                   push edi
// 00445ff5  a188518b00           mov eax, dword ptr [0x8b5188]
// 00445ffa  33c4                 xor eax, esp
// 00445ffc  50                   push eax
// 00445ffd  8d44241c             lea eax, [esp + 0x1c]
// 00446001  64a300000000         mov dword ptr fs:[0], eax
// 00446007  8bf1                 mov esi, ecx
// 00446009  8b7e04               mov edi, dword ptr [esi + 4]
// 0044600c  33db                 xor ebx, ebx
// 0044600e  3bfb                 cmp edi, ebx
// 00446010  895c2424             mov dword ptr [esp + 0x24], ebx
// 00446014  7504                 jne 0x44601a
// 00446016  33c0                 xor eax, eax
// 00446018  eb18                 jmp 0x446032
// 0044601a  8b4e08               mov ecx, dword ptr [esi + 8]
// 0044601d  2bcf                 sub ecx, edi
// 0044601f  b893244992           mov eax, 0x92492493
// 00446024  f7e9                 imul ecx
// 00446026  03d1                 add edx, ecx
// 00446028  c1fa04               sar edx, 4
// 0044602b  8bc2                 mov eax, edx
// 0044602d  c1e81f               shr eax, 0x1f
// 00446030  03c2                 add eax, edx
// 00446032  8b6c242c             mov ebp, dword ptr [esp + 0x2c]
// 00446036  3bc5                 cmp eax, ebp
// 00446038  7344                 jae 0x44607e
// 0044603a  3bfb                 cmp edi, ebx
// 0044603c  7418                 je 0x446056
// 0044603e  8b4e08               mov ecx, dword ptr [esi + 8]
// 00446041  2bcf                 sub ecx, edi
// 00446043  b893244992           mov eax, 0x92492493
// 00446048  f7e9                 imul ecx
// 0044604a  03d1                 add edx, ecx
// 0044604c  c1fa04               sar edx, 4
// 0044604f  8bda                 mov ebx, edx
// 00446051  c1eb1f               shr ebx, 0x1f
// 00446054  03da                 add ebx, edx
// 00446056  8b4608               mov eax, dword ptr [esi + 8]
// 00446059  3bf8                 cmp edi, eax
// 0044605b  89442414             mov dword ptr [esp + 0x14], eax
// 0044605f  760a                 jbe 0x44606b
// 00446061  ff15d8e67700         call dword ptr [0x77e6d8]
// 00446067  8b442414             mov eax, dword ptr [esp + 0x14]
// 0044606b  8d4c2430             lea ecx, [esp + 0x30]
// 0044606f  51                   push ecx
// 00446070  2beb                 sub ebp, ebx
// 00446072  55                   push ebp
// 00446073  50                   push eax
// 00446074  56                   push esi
// 00446075  8bce                 mov ecx, esi
// 00446077  e89432feff           call 0x429310
// 0044607c  eb6a                 jmp 0x4460e8
// 0044607e  3bfb                 cmp edi, ebx
// 00446080  7466                 je 0x4460e8
// 00446082  8b5e08               mov ebx, dword ptr [esi + 8]
// 00446085  8bcb                 mov ecx, ebx
// 00446087  2bcf                 sub ecx, edi
// 00446089  b893244992           mov eax, 0x92492493
// 0044608e  f7e9                 imul ecx
// 00446090  03d1                 add edx, ecx
// 00446092  c1fa04               sar edx, 4
// 00446095  8bc2                 mov eax, edx
// 00446097  c1e81f               shr eax, 0x1f
// 0044609a  03c2                 add eax, edx
// 0044609c  3be8                 cmp ebp, eax
// 0044609e  7348                 jae 0x4460e8
// 004460a0  3bfb                 cmp edi, ebx
// 004460a2  7606                 jbe 0x4460aa
// 004460a4  ff15d8e67700         call dword ptr [0x77e6d8]
// 004460aa  8b7e04               mov edi, dword ptr [esi + 4]
// 004460ad  3b7e08               cmp edi, dword ptr [esi + 8]
// 004460b0  7606                 jbe 0x4460b8
// 004460b2  ff15d8e67700         call dword ptr [0x77e6d8]
// 004460b8  8d14ed00000000       lea edx, [ebp*8]
// 004460bf  2bd5                 sub edx, ebp
// 004460c1  8d2c97               lea ebp, [edi + edx*4]
// 004460c4  3b6e08               cmp ebp, dword ptr [esi + 8]
// 004460c7  897c2418             mov dword ptr [esp + 0x18], edi
// 004460cb  7705                 ja 0x4460d2
// 004460cd  3b6e04               cmp ebp, dword ptr [esi + 4]
// 004460d0  7306                 jae 0x4460d8
// 004460d2  ff15d8e67700         call dword ptr [0x77e6d8]
// 004460d8  53                   push ebx
// 004460d9  56                   push esi
// 004460da  55                   push ebp
// 004460db  56                   push esi
// 004460dc  8d442424             lea eax, [esp + 0x24]
// 004460e0  50                   push eax
// 004460e1  8bce                 mov ecx, esi
// 004460e3  e888f6ffff           call 0x445770
// 004460e8  8d4c2430             lea ecx, [esp + 0x30]
// 004460ec  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 004460f4  ff15ace67700         call dword ptr [0x77e6ac]
// 004460fa  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004460fe  64890d00000000       mov dword ptr fs:[0], ecx
// 00446105  59                   pop ecx
// 00446106  5f                   pop edi
// 00446107  5e                   pop esi
// 00446108  5d                   pop ebp
// 00446109  5b                   pop ebx
// 0044610a  83c414               add esp, 0x14
// 0044610d  c22000               ret 0x20
// standard library vector<string> (function ?resize@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAEXIV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
