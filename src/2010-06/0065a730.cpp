// from server: 100% by auto
// roc 2010-06 0065a730  unit: RBX::KeyframeSequence  size: 166 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0065a730
//
// 0065a730  83ec08               sub esp, 8
// 0065a733  53                   push ebx
// 0065a734  55                   push ebp
// 0065a735  56                   push esi
// 0065a736  57                   push edi
// 0065a737  8bf9                 mov edi, ecx
// 0065a739  8b6f0c               mov ebp, dword ptr [edi + 0xc]
// 0065a73c  85ed                 test ebp, ebp
// 0065a73e  7504                 jne 0x65a744
// 0065a740  33f6                 xor esi, esi
// 0065a742  eb18                 jmp 0x65a75c
// 0065a744  8b4f14               mov ecx, dword ptr [edi + 0x14]
// 0065a747  2bcd                 sub ecx, ebp
// 0065a749  b893244992           mov eax, 0x92492493
// 0065a74e  f7e9                 imul ecx
// 0065a750  03d1                 add edx, ecx
// 0065a752  c1fa04               sar edx, 4
// 0065a755  8bf2                 mov esi, edx
// 0065a757  c1ee1f               shr esi, 0x1f
// 0065a75a  03f2                 add esi, edx
// 0065a75c  8b5f10               mov ebx, dword ptr [edi + 0x10]
// 0065a75f  8bcb                 mov ecx, ebx
// 0065a761  2bcd                 sub ecx, ebp
// 0065a763  b893244992           mov eax, 0x92492493
// 0065a768  f7e9                 imul ecx
// 0065a76a  03d1                 add edx, ecx
// 0065a76c  c1fa04               sar edx, 4
// 0065a76f  8bc2                 mov eax, edx
// 0065a771  c1e81f               shr eax, 0x1f
// 0065a774  03c2                 add eax, edx
// 0065a776  3bc6                 cmp eax, esi
// 0065a778  7333                 jae 0x65a7ad
// 0065a77a  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0065a77e  c644241000           mov byte ptr [esp + 0x10], 0
// 0065a783  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0065a787  51                   push ecx
// 0065a788  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0065a78c  52                   push edx
// 0065a78d  8d4708               lea eax, [edi + 8]
// 0065a790  50                   push eax
// 0065a791  51                   push ecx
// 0065a792  6a01                 push 1
// 0065a794  53                   push ebx
// 0065a795  e816e2ffff           call 0x6589b0
// 0065a79a  83c418               add esp, 0x18
// 0065a79d  83c31c               add ebx, 0x1c
// 0065a7a0  895f10               mov dword ptr [edi + 0x10], ebx
// 0065a7a3  5f                   pop edi
// 0065a7a4  5e                   pop esi
// 0065a7a5  5d                   pop ebp
// 0065a7a6  5b                   pop ebx
// 0065a7a7  83c408               add esp, 8
// 0065a7aa  c20400               ret 4
// 0065a7ad  3beb                 cmp ebp, ebx
// 0065a7af  7606                 jbe 0x65a7b7
// 0065a7b1  ff150ca99e00         call dword ptr [0x9ea90c]
// 0065a7b7  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0065a7bb  8b07                 mov eax, dword ptr [edi]
// 0065a7bd  52                   push edx
// 0065a7be  53                   push ebx
// 0065a7bf  50                   push eax
// 0065a7c0  8d44241c             lea eax, [esp + 0x1c]
// 0065a7c4  50                   push eax
// 0065a7c5  8bcf                 mov ecx, edi
// 0065a7c7  e834fcffff           call 0x65a400
// 0065a7cc  5f                   pop edi
// 0065a7cd  5e                   pop esi
// 0065a7ce  5d                   pop ebp
// 0065a7cf  5b                   pop ebx
// 0065a7d0  83c408               add esp, 8
// 0065a7d3  c20400               ret 4
// standard library vector<string> (function ?push_back@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAEXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
