// from server: 100% by auto
// roc 2008-06 004dd360  unit: RBX::RenderBase::Mesh::Level  size: 157 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004dd360
//
// 004dd360  8b542404             mov edx, dword ptr [esp + 4]
// 004dd364  56                   push esi
// 004dd365  8bf1                 mov esi, ecx
// 004dd367  81faffffff7f         cmp edx, 0x7fffffff
// 004dd36d  7605                 jbe 0x4dd374
// 004dd36f  e8cc99feff           call 0x4c6d40
// 004dd374  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004dd377  85c9                 test ecx, ecx
// 004dd379  7504                 jne 0x4dd37f
// 004dd37b  33c0                 xor eax, eax
// 004dd37d  eb07                 jmp 0x4dd386
// 004dd37f  8b4614               mov eax, dword ptr [esi + 0x14]
// 004dd382  2bc1                 sub eax, ecx
// 004dd384  d1f8                 sar eax, 1
// 004dd386  3bc2                 cmp eax, edx
// 004dd388  736f                 jae 0x4dd3f9
// 004dd38a  53                   push ebx
// 004dd38b  57                   push edi
// 004dd38c  6a00                 push 0
// 004dd38e  52                   push edx
// 004dd38f  e8ecf0ffff           call 0x4dc480
// 004dd394  8b7e10               mov edi, dword ptr [esi + 0x10]
// 004dd397  83c408               add esp, 8
// 004dd39a  8bd8                 mov ebx, eax
// 004dd39c  397e0c               cmp dword ptr [esi + 0xc], edi
// 004dd39f  7606                 jbe 0x4dd3a7
// 004dd3a1  ff1590288000         call dword ptr [0x802890]
// 004dd3a7  55                   push ebp
// 004dd3a8  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 004dd3ab  3b6e10               cmp ebp, dword ptr [esi + 0x10]
// 004dd3ae  7606                 jbe 0x4dd3b6
// 004dd3b0  ff1590288000         call dword ptr [0x802890]
// 004dd3b6  2bfd                 sub edi, ebp
// 004dd3b8  d1ff                 sar edi, 1
// 004dd3ba  7410                 je 0x4dd3cc
// 004dd3bc  8d043f               lea eax, [edi + edi]
// 004dd3bf  50                   push eax
// 004dd3c0  55                   push ebp
// 004dd3c1  50                   push eax
// 004dd3c2  53                   push ebx
// 004dd3c3  ff1550288000         call dword ptr [0x802850]
// 004dd3c9  83c410               add esp, 0x10
// 004dd3cc  8b460c               mov eax, dword ptr [esi + 0xc]
// 004dd3cf  8b7e10               mov edi, dword ptr [esi + 0x10]
// 004dd3d2  2bf8                 sub edi, eax
// 004dd3d4  d1ff                 sar edi, 1
// 004dd3d6  5d                   pop ebp
// 004dd3d7  85c0                 test eax, eax
// 004dd3d9  7409                 je 0x4dd3e4
// 004dd3db  50                   push eax
// 004dd3dc  e899321c00           call 0x6a067a
// 004dd3e1  83c404               add esp, 4
// 004dd3e4  8b442410             mov eax, dword ptr [esp + 0x10]
// 004dd3e8  8d147b               lea edx, [ebx + edi*2]
// 004dd3eb  8d0c43               lea ecx, [ebx + eax*2]
// 004dd3ee  5f                   pop edi
// 004dd3ef  895e0c               mov dword ptr [esi + 0xc], ebx
// 004dd3f2  894e14               mov dword ptr [esi + 0x14], ecx
// 004dd3f5  895610               mov dword ptr [esi + 0x10], edx
// 004dd3f8  5b                   pop ebx
// 004dd3f9  5e                   pop esi
// 004dd3fa  c20400               ret 4
// standard library vector<short> (function ?reserve@?$vector@FV?$allocator@F@std@@@std@@QAEXI@Z)

// stl: vector<short>
typedef short E;
#include <vector>
template class std::vector<E>;
