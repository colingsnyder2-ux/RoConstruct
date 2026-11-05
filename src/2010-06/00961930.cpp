// from server: 100% by auto
// roc 2010-06 00961930  unit: RBX::SceneUpdater  size: 166 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00961930
//
// 00961930  8b542404             mov edx, dword ptr [esp + 4]
// 00961934  56                   push esi
// 00961935  8bf1                 mov esi, ecx
// 00961937  81faffffff3f         cmp edx, 0x3fffffff
// 0096193d  7605                 jbe 0x961944
// 0096193f  e8ac24acff           call 0x423df0
// 00961944  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00961947  85c9                 test ecx, ecx
// 00961949  7504                 jne 0x96194f
// 0096194b  33c0                 xor eax, eax
// 0096194d  eb08                 jmp 0x961957
// 0096194f  8b4614               mov eax, dword ptr [esi + 0x14]
// 00961952  2bc1                 sub eax, ecx
// 00961954  c1f802               sar eax, 2
// 00961957  3bc2                 cmp eax, edx
// 00961959  7377                 jae 0x9619d2
// 0096195b  53                   push ebx
// 0096195c  57                   push edi
// 0096195d  6a00                 push 0
// 0096195f  52                   push edx
// 00961960  e8ab39f7ff           call 0x8d5310
// 00961965  8b7e10               mov edi, dword ptr [esi + 0x10]
// 00961968  83c408               add esp, 8
// 0096196b  8bd8                 mov ebx, eax
// 0096196d  397e0c               cmp dword ptr [esi + 0xc], edi
// 00961970  7606                 jbe 0x961978
// 00961972  ff150ca99e00         call dword ptr [0x9ea90c]
// 00961978  55                   push ebp
// 00961979  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 0096197c  3b6e10               cmp ebp, dword ptr [esi + 0x10]
// 0096197f  7606                 jbe 0x961987
// 00961981  ff150ca99e00         call dword ptr [0x9ea90c]
// 00961987  2bfd                 sub edi, ebp
// 00961989  c1ff02               sar edi, 2
// 0096198c  85ff                 test edi, edi
// 0096198e  7614                 jbe 0x9619a4
// 00961990  8d04bd00000000       lea eax, [edi*4]
// 00961997  50                   push eax
// 00961998  55                   push ebp
// 00961999  50                   push eax
// 0096199a  53                   push ebx
// 0096199b  ff1580a89e00         call dword ptr [0x9ea880]
// 009619a1  83c410               add esp, 0x10
// 009619a4  8b460c               mov eax, dword ptr [esi + 0xc]
// 009619a7  8b7e10               mov edi, dword ptr [esi + 0x10]
// 009619aa  2bf8                 sub edi, eax
// 009619ac  c1ff02               sar edi, 2
// 009619af  5d                   pop ebp
// 009619b0  85c0                 test eax, eax
// 009619b2  7409                 je 0x9619bd
// 009619b4  50                   push eax
// 009619b5  e8e05fe4ff           call 0x7a799a
// 009619ba  83c404               add esp, 4
// 009619bd  8b442410             mov eax, dword ptr [esp + 0x10]
// 009619c1  8d14bb               lea edx, [ebx + edi*4]
// 009619c4  8d0c83               lea ecx, [ebx + eax*4]
// 009619c7  5f                   pop edi
// 009619c8  895e0c               mov dword ptr [esi + 0xc], ebx
// 009619cb  894e14               mov dword ptr [esi + 0x14], ecx
// 009619ce  895610               mov dword ptr [esi + 0x10], edx
// 009619d1  5b                   pop ebx
// 009619d2  5e                   pop esi
// 009619d3  c20400               ret 4
// standard library vector<ptr> (function ?reserve@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXI@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
