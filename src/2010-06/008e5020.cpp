// from server: 100% by auto
// roc 2010-06 008e5020  unit: Ogre::RbxEntity  size: 219 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008e5020
//
// 008e5020  55                   push ebp
// 008e5021  8bec                 mov ebp, esp
// 008e5023  6aff                 push -1
// 008e5025  6870f79b00           push 0x9bf770
// 008e502a  64a100000000         mov eax, dword ptr fs:[0]
// 008e5030  50                   push eax
// 008e5031  64892500000000       mov dword ptr fs:[0], esp
// 008e5038  83ec10               sub esp, 0x10
// 008e503b  8b5508               mov edx, dword ptr [ebp + 8]
// 008e503e  53                   push ebx
// 008e503f  56                   push esi
// 008e5040  57                   push edi
// 008e5041  8965f0               mov dword ptr [ebp - 0x10], esp
// 008e5044  8bf1                 mov esi, ecx
// 008e5046  81faffffff1f         cmp edx, 0x1fffffff
// 008e504c  7605                 jbe 0x8e5053
// 008e504e  e89dedb3ff           call 0x423df0
// 008e5053  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 008e5056  85c9                 test ecx, ecx
// 008e5058  7504                 jne 0x8e505e
// 008e505a  33c0                 xor eax, eax
// 008e505c  eb08                 jmp 0x8e5066
// 008e505e  8b4614               mov eax, dword ptr [esi + 0x14]
// 008e5061  2bc1                 sub eax, ecx
// 008e5063  c1f803               sar eax, 3
// 008e5066  3bc2                 cmp eax, edx
// 008e5068  737e                 jae 0x8e50e8
// 008e506a  6a00                 push 0
// 008e506c  52                   push edx
// 008e506d  e83e950100           call 0x8fe5b0
// 008e5072  8bd8                 mov ebx, eax
// 008e5074  8b4610               mov eax, dword ptr [esi + 0x10]
// 008e5077  83c408               add esp, 8
// 008e507a  895de4               mov dword ptr [ebp - 0x1c], ebx
// 008e507d  c745fc00000000       mov dword ptr [ebp - 4], 0
// 008e5084  8945e8               mov dword ptr [ebp - 0x18], eax
// 008e5087  39460c               cmp dword ptr [esi + 0xc], eax
// 008e508a  7606                 jbe 0x8e5092
// 008e508c  ff150ca99e00         call dword ptr [0x9ea90c]
// 008e5092  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 008e5095  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 008e5098  7606                 jbe 0x8e50a0
// 008e509a  ff150ca99e00         call dword ptr [0x9ea90c]
// 008e50a0  8b4d08               mov ecx, dword ptr [ebp + 8]
// 008e50a3  c645ec00             mov byte ptr [ebp - 0x14], 0
// 008e50a7  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 008e50aa  50                   push eax
// 008e50ab  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 008e50ae  51                   push ecx
// 008e50af  8d5608               lea edx, [esi + 8]
// 008e50b2  52                   push edx
// 008e50b3  53                   push ebx
// 008e50b4  50                   push eax
// 008e50b5  57                   push edi
// 008e50b6  e8e5bd0700           call 0x960ea0
// 008e50bb  8b460c               mov eax, dword ptr [esi + 0xc]
// 008e50be  8b7e10               mov edi, dword ptr [esi + 0x10]
// 008e50c1  2bf8                 sub edi, eax
// 008e50c3  83c418               add esp, 0x18
// 008e50c6  c1ff03               sar edi, 3
// 008e50c9  85c0                 test eax, eax
// 008e50cb  7409                 je 0x8e50d6
// 008e50cd  50                   push eax
// 008e50ce  e8c728ecff           call 0x7a799a
// 008e50d3  83c404               add esp, 4
// 008e50d6  8b4d08               mov ecx, dword ptr [ebp + 8]
// 008e50d9  8d14cb               lea edx, [ebx + ecx*8]
// 008e50dc  8d04fb               lea eax, [ebx + edi*8]
// 008e50df  895614               mov dword ptr [esi + 0x14], edx
// 008e50e2  894610               mov dword ptr [esi + 0x10], eax
// 008e50e5  895e0c               mov dword ptr [esi + 0xc], ebx
// 008e50e8  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 008e50eb  5f                   pop edi
// 008e50ec  5e                   pop esi
// 008e50ed  64890d00000000       mov dword ptr fs:[0], ecx
// 008e50f4  5b                   pop ebx
// 008e50f5  8be5                 mov esp, ebp
// 008e50f7  5d                   pop ebp
// 008e50f8  c20400               ret 4
// standard library vector<pod8> (function ?reserve@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXI@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
