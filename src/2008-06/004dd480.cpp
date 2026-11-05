// from server: 100% by auto
// roc 2008-06 004dd480  unit: RBX::RenderBase::Mesh::Level  size: 399 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004dd480
//
// 004dd480  55                   push ebp
// 004dd481  56                   push esi
// 004dd482  8bf1                 mov esi, ecx
// 004dd484  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004dd487  57                   push edi
// 004dd488  85c9                 test ecx, ecx
// 004dd48a  7504                 jne 0x4dd490
// 004dd48c  33ed                 xor ebp, ebp
// 004dd48e  eb07                 jmp 0x4dd497
// 004dd490  8b6e14               mov ebp, dword ptr [esi + 0x14]
// 004dd493  2be9                 sub ebp, ecx
// 004dd495  d1fd                 sar ebp, 1
// 004dd497  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 004dd49b  85ff                 test edi, edi
// 004dd49d  0f8466010000         je 0x4dd609
// 004dd4a3  53                   push ebx
// 004dd4a4  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 004dd4a7  8bc3                 mov eax, ebx
// 004dd4a9  2bc1                 sub eax, ecx
// 004dd4ab  d1f8                 sar eax, 1
// 004dd4ad  b9ffffff7f           mov ecx, 0x7fffffff
// 004dd4b2  2bc8                 sub ecx, eax
// 004dd4b4  3bcf                 cmp ecx, edi
// 004dd4b6  7305                 jae 0x4dd4bd
// 004dd4b8  e88398feff           call 0x4c6d40
// 004dd4bd  03c7                 add eax, edi
// 004dd4bf  3be8                 cmp ebp, eax
// 004dd4c1  0f83a9000000         jae 0x4dd570
// 004dd4c7  8bcd                 mov ecx, ebp
// 004dd4c9  d1e9                 shr ecx, 1
// 004dd4cb  baffffff7f           mov edx, 0x7fffffff
// 004dd4d0  2bd1                 sub edx, ecx
// 004dd4d2  3bd5                 cmp edx, ebp
// 004dd4d4  7304                 jae 0x4dd4da
// 004dd4d6  33ed                 xor ebp, ebp
// 004dd4d8  eb02                 jmp 0x4dd4dc
// 004dd4da  03e9                 add ebp, ecx
// 004dd4dc  3be8                 cmp ebp, eax
// 004dd4de  7302                 jae 0x4dd4e2
// 004dd4e0  8be8                 mov ebp, eax
// 004dd4e2  6a00                 push 0
// 004dd4e4  55                   push ebp
// 004dd4e5  e896efffff           call 0x4dc480
// 004dd4ea  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004dd4ed  8bd8                 mov ebx, eax
// 004dd4ef  8b442420             mov eax, dword ptr [esp + 0x20]
// 004dd4f3  2bc1                 sub eax, ecx
// 004dd4f5  83c408               add esp, 8
// 004dd4f8  d1f8                 sar eax, 1
// 004dd4fa  8d0400               lea eax, [eax + eax]
// 004dd4fd  8d1418               lea edx, [eax + ebx]
// 004dd500  8954241c             mov dword ptr [esp + 0x1c], edx
// 004dd504  740d                 je 0x4dd513
// 004dd506  50                   push eax
// 004dd507  51                   push ecx
// 004dd508  50                   push eax
// 004dd509  53                   push ebx
// 004dd50a  ff1550288000         call dword ptr [0x802850]
// 004dd510  83c410               add esp, 0x10
// 004dd513  8b442420             mov eax, dword ptr [esp + 0x20]
// 004dd517  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004dd51b  50                   push eax
// 004dd51c  57                   push edi
// 004dd51d  51                   push ecx
// 004dd51e  8bce                 mov ecx, esi
// 004dd520  e8dbfeffff           call 0x4dd400
// 004dd525  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 004dd528  8b542418             mov edx, dword ptr [esp + 0x18]
// 004dd52c  2bca                 sub ecx, edx
// 004dd52e  d1f9                 sar ecx, 1
// 004dd530  740f                 je 0x4dd541
// 004dd532  03c9                 add ecx, ecx
// 004dd534  51                   push ecx
// 004dd535  52                   push edx
// 004dd536  51                   push ecx
// 004dd537  50                   push eax
// 004dd538  ff1550288000         call dword ptr [0x802850]
// 004dd53e  83c410               add esp, 0x10
// 004dd541  8b460c               mov eax, dword ptr [esi + 0xc]
// 004dd544  8b5610               mov edx, dword ptr [esi + 0x10]
// 004dd547  2bd0                 sub edx, eax
// 004dd549  d1fa                 sar edx, 1
// 004dd54b  03fa                 add edi, edx
// 004dd54d  85c0                 test eax, eax
// 004dd54f  7409                 je 0x4dd55a
// 004dd551  50                   push eax
// 004dd552  e823311c00           call 0x6a067a
// 004dd557  83c404               add esp, 4
// 004dd55a  8d046b               lea eax, [ebx + ebp*2]
// 004dd55d  8d0c7b               lea ecx, [ebx + edi*2]
// 004dd560  895e0c               mov dword ptr [esi + 0xc], ebx
// 004dd563  5b                   pop ebx
// 004dd564  5f                   pop edi
// 004dd565  894614               mov dword ptr [esi + 0x14], eax
// 004dd568  894e10               mov dword ptr [esi + 0x10], ecx
// 004dd56b  5e                   pop esi
// 004dd56c  5d                   pop ebp
// 004dd56d  c21000               ret 0x10
// 004dd570  8b442418             mov eax, dword ptr [esp + 0x18]
// 004dd574  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004dd578  8bd3                 mov edx, ebx
// 004dd57a  2bd0                 sub edx, eax
// 004dd57c  d1fa                 sar edx, 1
// 004dd57e  3bd7                 cmp edx, edi
// 004dd580  0fb711               movzx edx, word ptr [ecx]
// 004dd583  8d2c3f               lea ebp, [edi + edi]
// 004dd586  89542420             mov dword ptr [esp + 0x20], edx
// 004dd58a  734a                 jae 0x4dd5d6
// 004dd58c  8d0c28               lea ecx, [eax + ebp]
// 004dd58f  51                   push ecx
// 004dd590  53                   push ebx
// 004dd591  50                   push eax
// 004dd592  8bce                 mov ecx, esi
// 004dd594  e817fdffff           call 0x4dd2b0
// 004dd599  8b4610               mov eax, dword ptr [esi + 0x10]
// 004dd59c  8bc8                 mov ecx, eax
// 004dd59e  2b4c2418             sub ecx, dword ptr [esp + 0x18]
// 004dd5a2  8d542420             lea edx, [esp + 0x20]
// 004dd5a6  d1f9                 sar ecx, 1
// 004dd5a8  52                   push edx
// 004dd5a9  2bf9                 sub edi, ecx
// 004dd5ab  57                   push edi
// 004dd5ac  50                   push eax
// 004dd5ad  8bce                 mov ecx, esi
// 004dd5af  e84cfeffff           call 0x4dd400
// 004dd5b4  016e10               add dword ptr [esi + 0x10], ebp
// 004dd5b7  8b7610               mov esi, dword ptr [esi + 0x10]
// 004dd5ba  8b442418             mov eax, dword ptr [esp + 0x18]
// 004dd5be  8d542420             lea edx, [esp + 0x20]
// 004dd5c2  52                   push edx
// 004dd5c3  2bf5                 sub esi, ebp
// 004dd5c5  56                   push esi
// 004dd5c6  50                   push eax
// 004dd5c7  e854f4ffff           call 0x4dca20
// 004dd5cc  83c40c               add esp, 0xc
// 004dd5cf  5b                   pop ebx
// 004dd5d0  5f                   pop edi
// 004dd5d1  5e                   pop esi
// 004dd5d2  5d                   pop ebp
// 004dd5d3  c21000               ret 0x10
// 004dd5d6  53                   push ebx
// 004dd5d7  8bfb                 mov edi, ebx
// 004dd5d9  53                   push ebx
// 004dd5da  2bfd                 sub edi, ebp
// 004dd5dc  57                   push edi
// 004dd5dd  8bce                 mov ecx, esi
// 004dd5df  e8ccfcffff           call 0x4dd2b0
// 004dd5e4  53                   push ebx
// 004dd5e5  894610               mov dword ptr [esi + 0x10], eax
// 004dd5e8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004dd5ec  57                   push edi
// 004dd5ed  50                   push eax
// 004dd5ee  e84df4ffff           call 0x4dca40
// 004dd5f3  8b442424             mov eax, dword ptr [esp + 0x24]
// 004dd5f7  8d4c242c             lea ecx, [esp + 0x2c]
// 004dd5fb  51                   push ecx
// 004dd5fc  03e8                 add ebp, eax
// 004dd5fe  55                   push ebp
// 004dd5ff  50                   push eax
// 004dd600  e81bf4ffff           call 0x4dca20
// 004dd605  83c418               add esp, 0x18
// 004dd608  5b                   pop ebx
// 004dd609  5f                   pop edi
// 004dd60a  5e                   pop esi
// 004dd60b  5d                   pop ebp
// 004dd60c  c21000               ret 0x10
// standard library vector<short> (function ?_Insert_n@?$vector@FV?$allocator@F@std@@@std@@IAEXV?$_Vector_const_iterator@FV?$allocator@F@std@@@2@IABF@Z)

// stl: vector<short>
typedef short E;
#include <vector>
template class std::vector<E>;
