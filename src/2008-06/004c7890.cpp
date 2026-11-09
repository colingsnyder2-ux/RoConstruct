// from server: 100% by auto
// roc 2008-06 004c7890  unit: RBX::VInstance::?$Association::Item  size: 374 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c7890
//
// 004c7890  55                   push ebp
// 004c7891  56                   push esi
// 004c7892  8bf1                 mov esi, ecx
// 004c7894  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004c7897  57                   push edi
// 004c7898  85c9                 test ecx, ecx
// 004c789a  7504                 jne 0x4c78a0
// 004c789c  33ed                 xor ebp, ebp
// 004c789e  eb08                 jmp 0x4c78a8
// 004c78a0  8b6e14               mov ebp, dword ptr [esi + 0x14]
// 004c78a3  2be9                 sub ebp, ecx
// 004c78a5  c1fd02               sar ebp, 2
// 004c78a8  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 004c78ac  85ff                 test edi, edi
// 004c78ae  0f844c010000         je 0x4c7a00
// 004c78b4  53                   push ebx
// 004c78b5  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 004c78b8  8bc3                 mov eax, ebx
// 004c78ba  2bc1                 sub eax, ecx
// 004c78bc  c1f802               sar eax, 2
// 004c78bf  b9ffffff3f           mov ecx, 0x3fffffff
// 004c78c4  2bc8                 sub ecx, eax
// 004c78c6  3bcf                 cmp ecx, edi
// 004c78c8  7305                 jae 0x4c78cf
// 004c78ca  e871f4ffff           call 0x4c6d40
// 004c78cf  8d0c38               lea ecx, [eax + edi]
// 004c78d2  3be9                 cmp ebp, ecx
// 004c78d4  0f8388000000         jae 0x4c7962
// 004c78da  8bc5                 mov eax, ebp
// 004c78dc  d1e8                 shr eax, 1
// 004c78de  baffffff3f           mov edx, 0x3fffffff
// 004c78e3  2bd0                 sub edx, eax
// 004c78e5  3bd5                 cmp edx, ebp
// 004c78e7  7304                 jae 0x4c78ed
// 004c78e9  33ed                 xor ebp, ebp
// 004c78eb  eb02                 jmp 0x4c78ef
// 004c78ed  03e8                 add ebp, eax
// 004c78ef  3be9                 cmp ebp, ecx
// 004c78f1  7302                 jae 0x4c78f5
// 004c78f3  8be9                 mov ebp, ecx
// 004c78f5  6a00                 push 0
// 004c78f7  55                   push ebp
// 004c78f8  e85392f5ff           call 0x420b50
// 004c78fd  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004c7900  83c408               add esp, 8
// 004c7903  8bd8                 mov ebx, eax
// 004c7905  8b442418             mov eax, dword ptr [esp + 0x18]
// 004c7909  53                   push ebx
// 004c790a  50                   push eax
// 004c790b  51                   push ecx
// 004c790c  8bce                 mov ecx, esi
// 004c790e  e8edc2f5ff           call 0x423c00
// 004c7913  8b542420             mov edx, dword ptr [esp + 0x20]
// 004c7917  52                   push edx
// 004c7918  57                   push edi
// 004c7919  50                   push eax
// 004c791a  8bce                 mov ecx, esi
// 004c791c  e82f470a00           call 0x56c050
// 004c7921  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004c7925  50                   push eax
// 004c7926  8b4610               mov eax, dword ptr [esi + 0x10]
// 004c7929  50                   push eax
// 004c792a  51                   push ecx
// 004c792b  8bce                 mov ecx, esi
// 004c792d  e8cec2f5ff           call 0x423c00
// 004c7932  8b460c               mov eax, dword ptr [esi + 0xc]
// 004c7935  8b5610               mov edx, dword ptr [esi + 0x10]
// 004c7938  2bd0                 sub edx, eax
// 004c793a  c1fa02               sar edx, 2
// 004c793d  03fa                 add edi, edx
// 004c793f  85c0                 test eax, eax
// 004c7941  7409                 je 0x4c794c
// 004c7943  50                   push eax
// 004c7944  e8318d1d00           call 0x6a067a
// 004c7949  83c404               add esp, 4
// 004c794c  8d04ab               lea eax, [ebx + ebp*4]
// 004c794f  8d0cbb               lea ecx, [ebx + edi*4]
// 004c7952  895e0c               mov dword ptr [esi + 0xc], ebx
// 004c7955  5b                   pop ebx
// 004c7956  5f                   pop edi
// 004c7957  894614               mov dword ptr [esi + 0x14], eax
// 004c795a  894e10               mov dword ptr [esi + 0x10], ecx
// 004c795d  5e                   pop esi
// 004c795e  5d                   pop ebp
// 004c795f  c21000               ret 0x10
// 004c7962  8b442418             mov eax, dword ptr [esp + 0x18]
// 004c7966  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004c796a  8bd3                 mov edx, ebx
// 004c796c  2bd0                 sub edx, eax
// 004c796e  c1fa02               sar edx, 2
// 004c7971  3bd7                 cmp edx, edi
// 004c7973  8b11                 mov edx, dword ptr [ecx]
// 004c7975  8d2cbd00000000       lea ebp, [edi*4]
// 004c797c  89542420             mov dword ptr [esp + 0x20], edx
// 004c7980  734b                 jae 0x4c79cd
// 004c7982  8d0c28               lea ecx, [eax + ebp]
// 004c7985  51                   push ecx
// 004c7986  53                   push ebx
// 004c7987  50                   push eax
// 004c7988  8bce                 mov ecx, esi
// 004c798a  e871c2f5ff           call 0x423c00
// 004c798f  8b4610               mov eax, dword ptr [esi + 0x10]
// 004c7992  8bc8                 mov ecx, eax
// 004c7994  2b4c2418             sub ecx, dword ptr [esp + 0x18]
// 004c7998  8d542420             lea edx, [esp + 0x20]
// 004c799c  c1f902               sar ecx, 2
// 004c799f  52                   push edx
// 004c79a0  2bf9                 sub edi, ecx
// 004c79a2  57                   push edi
// 004c79a3  50                   push eax
// 004c79a4  8bce                 mov ecx, esi
// 004c79a6  e8a5460a00           call 0x56c050
// 004c79ab  016e10               add dword ptr [esi + 0x10], ebp
// 004c79ae  8b7610               mov esi, dword ptr [esi + 0x10]
// 004c79b1  8b442418             mov eax, dword ptr [esp + 0x18]
// 004c79b5  8d542420             lea edx, [esp + 0x20]
// 004c79b9  52                   push edx
// 004c79ba  2bf5                 sub esi, ebp
// 004c79bc  56                   push esi
// 004c79bd  50                   push eax
// 004c79be  e87dc20900           call 0x563c40
// 004c79c3  83c40c               add esp, 0xc
// 004c79c6  5b                   pop ebx
// 004c79c7  5f                   pop edi
// 004c79c8  5e                   pop esi
// 004c79c9  5d                   pop ebp
// 004c79ca  c21000               ret 0x10
// 004c79cd  53                   push ebx
// 004c79ce  8bfb                 mov edi, ebx
// 004c79d0  53                   push ebx
// 004c79d1  2bfd                 sub edi, ebp
// 004c79d3  57                   push edi
// 004c79d4  8bce                 mov ecx, esi
// 004c79d6  e825c2f5ff           call 0x423c00
// 004c79db  53                   push ebx
// 004c79dc  894610               mov dword ptr [esi + 0x10], eax
// 004c79df  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004c79e3  57                   push edi
// 004c79e4  50                   push eax
// 004c79e5  e8861cf9ff           call 0x459670
// 004c79ea  8b442424             mov eax, dword ptr [esp + 0x24]
// 004c79ee  8d4c242c             lea ecx, [esp + 0x2c]
// 004c79f2  51                   push ecx
// 004c79f3  03e8                 add ebp, eax
// 004c79f5  55                   push ebp
// 004c79f6  50                   push eax
// 004c79f7  e844c20900           call 0x563c40
// 004c79fc  83c418               add esp, 0x18
// 004c79ff  5b                   pop ebx
// 004c7a00  5f                   pop edi
// 004c7a01  5e                   pop esi
// 004c7a02  5d                   pop ebp
// 004c7a03  c21000               ret 0x10
// standard library vector<ptr> (function ?_Insert_n@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEXV?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@IABQAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
