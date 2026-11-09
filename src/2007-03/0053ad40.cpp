// from server: 100% by auto
// roc 2007-03 0053ad40  unit: seg_00530000  size: 166 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0053ad40
//
// 0053ad40  55                   push ebp
// 0053ad41  8bec                 mov ebp, esp
// 0053ad43  6aff                 push -1
// 0053ad45  68901b7500           push 0x751b90
// 0053ad4a  64a100000000         mov eax, dword ptr fs:[0]
// 0053ad50  50                   push eax
// 0053ad51  64892500000000       mov dword ptr fs:[0], esp
// 0053ad58  83ec08               sub esp, 8
// 0053ad5b  53                   push ebx
// 0053ad5c  8b5d08               mov ebx, dword ptr [ebp + 8]
// 0053ad5f  33c0                 xor eax, eax
// 0053ad61  3bd8                 cmp ebx, eax
// 0053ad63  56                   push esi
// 0053ad64  8bf1                 mov esi, ecx
// 0053ad66  57                   push edi
// 0053ad67  8965f0               mov dword ptr [ebp - 0x10], esp
// 0053ad6a  8975ec               mov dword ptr [ebp - 0x14], esi
// 0053ad6d  894604               mov dword ptr [esi + 4], eax
// 0053ad70  894608               mov dword ptr [esi + 8], eax
// 0053ad73  89460c               mov dword ptr [esi + 0xc], eax
// 0053ad76  744a                 je 0x53adc2
// 0053ad78  81fbffffff1f         cmp ebx, 0x1fffffff
// 0053ad7e  7605                 jbe 0x53ad85
// 0053ad80  e88bfbf0ff           call 0x44a910
// 0053ad85  50                   push eax
// 0053ad86  53                   push ebx
// 0053ad87  e8a438efff           call 0x42e630
// 0053ad8c  8bf8                 mov edi, eax
// 0053ad8e  c6450800             mov byte ptr [ebp + 8], 0
// 0053ad92  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0053ad95  8b5508               mov edx, dword ptr [ebp + 8]
// 0053ad98  51                   push ecx
// 0053ad99  52                   push edx
// 0053ad9a  8d04df               lea eax, [edi + ebx*8]
// 0053ad9d  89460c               mov dword ptr [esi + 0xc], eax
// 0053ada0  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0053ada3  56                   push esi
// 0053ada4  50                   push eax
// 0053ada5  53                   push ebx
// 0053ada6  57                   push edi
// 0053ada7  897e04               mov dword ptr [esi + 4], edi
// 0053adaa  897e08               mov dword ptr [esi + 8], edi
// 0053adad  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0053adb4  e8173befff           call 0x42e8d0
// 0053adb9  8d0cdf               lea ecx, [edi + ebx*8]
// 0053adbc  83c420               add esp, 0x20
// 0053adbf  894e08               mov dword ptr [esi + 8], ecx
// 0053adc2  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0053adc5  5f                   pop edi
// 0053adc6  5e                   pop esi
// 0053adc7  64890d00000000       mov dword ptr fs:[0], ecx
// 0053adce  5b                   pop ebx
// 0053adcf  8be5                 mov esp, ebp
// 0053add1  5d                   pop ebp
// 0053add2  c20800               ret 8
// 0053add5  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 0053add8  e8933fefff           call 0x42ed70
// 0053addd  6a00                 push 0
// 0053addf  6a00                 push 0
// 0053ade1  e848420e00           call 0x61f02e
// standard library vector<pod8> (function ?_Construct_n@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXIABUE@@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
