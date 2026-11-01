// from server: 100% by auto
// roc 2009-12 005b0780  unit: seg_005b0000  size: 157 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005b0780
//
// 005b0780  8b542404             mov edx, dword ptr [esp + 4]
// 005b0784  56                   push esi
// 005b0785  8bf1                 mov esi, ecx
// 005b0787  81faffffff7f         cmp edx, 0x7fffffff
// 005b078d  7605                 jbe 0x5b0794
// 005b078f  e8cc19e9ff           call 0x442160
// 005b0794  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 005b0797  85c9                 test ecx, ecx
// 005b0799  7504                 jne 0x5b079f
// 005b079b  33c0                 xor eax, eax
// 005b079d  eb07                 jmp 0x5b07a6
// 005b079f  8b4614               mov eax, dword ptr [esi + 0x14]
// 005b07a2  2bc1                 sub eax, ecx
// 005b07a4  d1f8                 sar eax, 1
// 005b07a6  3bc2                 cmp eax, edx
// 005b07a8  736f                 jae 0x5b0819
// 005b07aa  53                   push ebx
// 005b07ab  57                   push edi
// 005b07ac  6a00                 push 0
// 005b07ae  52                   push edx
// 005b07af  e8ac9feeff           call 0x49a760
// 005b07b4  8b7e10               mov edi, dword ptr [esi + 0x10]
// 005b07b7  83c408               add esp, 8
// 005b07ba  8bd8                 mov ebx, eax
// 005b07bc  397e0c               cmp dword ptr [esi + 0xc], edi
// 005b07bf  7606                 jbe 0x5b07c7
// 005b07c1  ff1560b79800         call dword ptr [0x98b760]
// 005b07c7  55                   push ebp
// 005b07c8  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 005b07cb  3b6e10               cmp ebp, dword ptr [esi + 0x10]
// 005b07ce  7606                 jbe 0x5b07d6
// 005b07d0  ff1560b79800         call dword ptr [0x98b760]
// 005b07d6  2bfd                 sub edi, ebp
// 005b07d8  d1ff                 sar edi, 1
// 005b07da  7410                 je 0x5b07ec
// 005b07dc  8d043f               lea eax, [edi + edi]
// 005b07df  50                   push eax
// 005b07e0  55                   push ebp
// 005b07e1  50                   push eax
// 005b07e2  53                   push ebx
// 005b07e3  ff15c0b79800         call dword ptr [0x98b7c0]
// 005b07e9  83c410               add esp, 0x10
// 005b07ec  8b460c               mov eax, dword ptr [esi + 0xc]
// 005b07ef  8b7e10               mov edi, dword ptr [esi + 0x10]
// 005b07f2  2bf8                 sub edi, eax
// 005b07f4  d1ff                 sar edi, 1
// 005b07f6  5d                   pop ebp
// 005b07f7  85c0                 test eax, eax
// 005b07f9  7409                 je 0x5b0804
// 005b07fb  50                   push eax
// 005b07fc  e859302400           call 0x7f385a
// 005b0801  83c404               add esp, 4
// 005b0804  8b442410             mov eax, dword ptr [esp + 0x10]
// 005b0808  8d147b               lea edx, [ebx + edi*2]
// 005b080b  8d0c43               lea ecx, [ebx + eax*2]
// 005b080e  5f                   pop edi
// 005b080f  895e0c               mov dword ptr [esi + 0xc], ebx
// 005b0812  894e14               mov dword ptr [esi + 0x14], ecx
// 005b0815  895610               mov dword ptr [esi + 0x10], edx
// 005b0818  5b                   pop ebx
// 005b0819  5e                   pop esi
// 005b081a  c20400               ret 4
// standard library vector<short> (function ?reserve@?$vector@FV?$allocator@F@std@@@std@@QAEXI@Z)

// stl: vector<short>
typedef short E;
#include <vector>
template class std::vector<E>;
