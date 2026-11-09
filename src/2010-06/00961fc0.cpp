// from server: 100% by auto
// roc 2010-06 00961fc0  unit: RBX::SceneUpdater  size: 146 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00961fc0
//
// 00961fc0  53                   push ebx
// 00961fc1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00961fc5  55                   push ebp
// 00961fc6  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 00961fcc  56                   push esi
// 00961fcd  57                   push edi
// 00961fce  8bf9                 mov edi, ecx
// 00961fd0  c70300000000         mov dword ptr [ebx], 0
// 00961fd6  85ff                 test edi, edi
// 00961fd8  740e                 je 0x961fe8
// 00961fda  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00961fde  39470c               cmp dword ptr [edi + 0xc], eax
// 00961fe1  7705                 ja 0x961fe8
// 00961fe3  3b4710               cmp eax, dword ptr [edi + 0x10]
// 00961fe6  7606                 jbe 0x961fee
// 00961fe8  ffd5                 call ebp
// 00961fea  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00961fee  8b742424             mov esi, dword ptr [esp + 0x24]
// 00961ff2  8b0f                 mov ecx, dword ptr [edi]
// 00961ff4  890b                 mov dword ptr [ebx], ecx
// 00961ff6  894304               mov dword ptr [ebx + 4], eax
// 00961ff9  39770c               cmp dword ptr [edi + 0xc], esi
// 00961ffc  7705                 ja 0x962003
// 00961ffe  3b7710               cmp esi, dword ptr [edi + 0x10]
// 00962001  7606                 jbe 0x962009
// 00962003  ffd5                 call ebp
// 00962005  8b742424             mov esi, dword ptr [esp + 0x24]
// 00962009  8b03                 mov eax, dword ptr [ebx]
// 0096200b  8b0f                 mov ecx, dword ptr [edi]
// 0096200d  85c0                 test eax, eax
// 0096200f  7404                 je 0x962015
// 00962011  3bc1                 cmp eax, ecx
// 00962013  7402                 je 0x962017
// 00962015  ffd5                 call ebp
// 00962017  8b5304               mov edx, dword ptr [ebx + 4]
// 0096201a  3bd6                 cmp edx, esi
// 0096201c  742b                 je 0x962049
// 0096201e  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 00962021  8bc1                 mov eax, ecx
// 00962023  2bc6                 sub eax, esi
// 00962025  c1f803               sar eax, 3
// 00962028  8d2cc2               lea ebp, [edx + eax*8]
// 0096202b  8bc6                 mov eax, esi
// 0096202d  3bf1                 cmp esi, ecx
// 0096202f  7415                 je 0x962046
// 00962031  2bd6                 sub edx, esi
// 00962033  8b30                 mov esi, dword ptr [eax]
// 00962035  893402               mov dword ptr [edx + eax], esi
// 00962038  8b7004               mov esi, dword ptr [eax + 4]
// 0096203b  89740204             mov dword ptr [edx + eax + 4], esi
// 0096203f  83c008               add eax, 8
// 00962042  3bc1                 cmp eax, ecx
// 00962044  75ed                 jne 0x962033
// 00962046  896f10               mov dword ptr [edi + 0x10], ebp
// 00962049  5f                   pop edi
// 0096204a  5e                   pop esi
// 0096204b  5d                   pop ebp
// 0096204c  8bc3                 mov eax, ebx
// 0096204e  5b                   pop ebx
// 0096204f  c21400               ret 0x14
// standard library vector<pod8> (function ?erase@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@0@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
