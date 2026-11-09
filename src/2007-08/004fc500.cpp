// from server: 100% by auto
// roc 2007-08 004fc500  unit: RBX::Render::AggregateChunk  size: 152 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004fc500
//
// 004fc500  53                   push ebx
// 004fc501  8b5c2408             mov ebx, dword ptr [esp + 8]
// 004fc505  8b4304               mov eax, dword ptr [ebx + 4]
// 004fc508  56                   push esi
// 004fc509  57                   push edi
// 004fc50a  8bf9                 mov edi, ecx
// 004fc50c  33c9                 xor ecx, ecx
// 004fc50e  3bc1                 cmp eax, ecx
// 004fc510  7504                 jne 0x4fc516
// 004fc512  33f6                 xor esi, esi
// 004fc514  eb08                 jmp 0x4fc51e
// 004fc516  8b7308               mov esi, dword ptr [ebx + 8]
// 004fc519  2bf0                 sub esi, eax
// 004fc51b  c1fe02               sar esi, 2
// 004fc51e  3bf1                 cmp esi, ecx
// 004fc520  894f04               mov dword ptr [edi + 4], ecx
// 004fc523  894f08               mov dword ptr [edi + 8], ecx
// 004fc526  894f0c               mov dword ptr [edi + 0xc], ecx
// 004fc529  7465                 je 0x4fc590
// 004fc52b  81feffffff3f         cmp esi, 0x3fffffff
// 004fc531  7605                 jbe 0x4fc538
// 004fc533  e8c8b2f1ff           call 0x417800
// 004fc538  51                   push ecx
// 004fc539  56                   push esi
// 004fc53a  e821380b00           call 0x5afd60
// 004fc53f  894704               mov dword ptr [edi + 4], eax
// 004fc542  894708               mov dword ptr [edi + 8], eax
// 004fc545  8d04b0               lea eax, [eax + esi*4]
// 004fc548  89470c               mov dword ptr [edi + 0xc], eax
// 004fc54b  8b7308               mov esi, dword ptr [ebx + 8]
// 004fc54e  83c408               add esp, 8
// 004fc551  397304               cmp dword ptr [ebx + 4], esi
// 004fc554  7606                 jbe 0x4fc55c
// 004fc556  ff15d8e67700         call dword ptr [0x77e6d8]
// 004fc55c  55                   push ebp
// 004fc55d  8b6b04               mov ebp, dword ptr [ebx + 4]
// 004fc560  3b6b08               cmp ebp, dword ptr [ebx + 8]
// 004fc563  7606                 jbe 0x4fc56b
// 004fc565  ff15d8e67700         call dword ptr [0x77e6d8]
// 004fc56b  8b4f04               mov ecx, dword ptr [edi + 4]
// 004fc56e  2bf5                 sub esi, ebp
// 004fc570  c1fe02               sar esi, 2
// 004fc573  8d04b500000000       lea eax, [esi*4]
// 004fc57a  8d3408               lea esi, [eax + ecx]
// 004fc57d  740d                 je 0x4fc58c
// 004fc57f  50                   push eax
// 004fc580  55                   push ebp
// 004fc581  50                   push eax
// 004fc582  51                   push ecx
// 004fc583  ff1548e77700         call dword ptr [0x77e748]
// 004fc589  83c410               add esp, 0x10
// 004fc58c  897708               mov dword ptr [edi + 8], esi
// 004fc58f  5d                   pop ebp
// 004fc590  8bc7                 mov eax, edi
// 004fc592  5f                   pop edi
// 004fc593  5e                   pop esi
// 004fc594  5b                   pop ebx
// 004fc595  c20400               ret 4
// standard library vector<ptr> (function ??0?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@ABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
