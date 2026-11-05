// from server: 100% by auto
// roc 2009-06 0053add0  unit: RBX::VerticalCylinderBuilder  size: 157 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0053add0
//
// 0053add0  8b542404             mov edx, dword ptr [esp + 4]
// 0053add4  56                   push esi
// 0053add5  8bf1                 mov esi, ecx
// 0053add7  81faffffff7f         cmp edx, 0x7fffffff
// 0053addd  7605                 jbe 0x53ade4
// 0053addf  e87c55f5ff           call 0x490360
// 0053ade4  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0053ade7  85c9                 test ecx, ecx
// 0053ade9  7504                 jne 0x53adef
// 0053adeb  33c0                 xor eax, eax
// 0053aded  eb07                 jmp 0x53adf6
// 0053adef  8b4614               mov eax, dword ptr [esi + 0x14]
// 0053adf2  2bc1                 sub eax, ecx
// 0053adf4  d1f8                 sar eax, 1
// 0053adf6  3bc2                 cmp eax, edx
// 0053adf8  736f                 jae 0x53ae69
// 0053adfa  53                   push ebx
// 0053adfb  57                   push edi
// 0053adfc  6a00                 push 0
// 0053adfe  52                   push edx
// 0053adff  e84ca1f4ff           call 0x484f50
// 0053ae04  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0053ae07  83c408               add esp, 8
// 0053ae0a  8bd8                 mov ebx, eax
// 0053ae0c  397e0c               cmp dword ptr [esi + 0xc], edi
// 0053ae0f  7606                 jbe 0x53ae17
// 0053ae11  ff15ace98900         call dword ptr [0x89e9ac]
// 0053ae17  55                   push ebp
// 0053ae18  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 0053ae1b  3b6e10               cmp ebp, dword ptr [esi + 0x10]
// 0053ae1e  7606                 jbe 0x53ae26
// 0053ae20  ff15ace98900         call dword ptr [0x89e9ac]
// 0053ae26  2bfd                 sub edi, ebp
// 0053ae28  d1ff                 sar edi, 1
// 0053ae2a  7410                 je 0x53ae3c
// 0053ae2c  8d043f               lea eax, [edi + edi]
// 0053ae2f  50                   push eax
// 0053ae30  55                   push ebp
// 0053ae31  50                   push eax
// 0053ae32  53                   push ebx
// 0053ae33  ff155ce98900         call dword ptr [0x89e95c]
// 0053ae39  83c410               add esp, 0x10
// 0053ae3c  8b460c               mov eax, dword ptr [esi + 0xc]
// 0053ae3f  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0053ae42  2bf8                 sub edi, eax
// 0053ae44  d1ff                 sar edi, 1
// 0053ae46  5d                   pop ebp
// 0053ae47  85c0                 test eax, eax
// 0053ae49  7409                 je 0x53ae54
// 0053ae4b  50                   push eax
// 0053ae4c  e8e1db1d00           call 0x718a32
// 0053ae51  83c404               add esp, 4
// 0053ae54  8b442410             mov eax, dword ptr [esp + 0x10]
// 0053ae58  8d147b               lea edx, [ebx + edi*2]
// 0053ae5b  8d0c43               lea ecx, [ebx + eax*2]
// 0053ae5e  5f                   pop edi
// 0053ae5f  895e0c               mov dword ptr [esi + 0xc], ebx
// 0053ae62  894e14               mov dword ptr [esi + 0x14], ecx
// 0053ae65  895610               mov dword ptr [esi + 0x10], edx
// 0053ae68  5b                   pop ebx
// 0053ae69  5e                   pop esi
// 0053ae6a  c20400               ret 4
// standard library vector<short> (function ?reserve@?$vector@FV?$allocator@F@std@@@std@@QAEXI@Z)

// stl: vector<short>
typedef short E;
#include <vector>
template class std::vector<E>;
