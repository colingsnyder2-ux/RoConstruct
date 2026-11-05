// from server: 100% by auto
// roc 2010-06 0053daa0  unit: RBX::AdornG3D  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0053daa0
//
// 0053daa0  83ec08               sub esp, 8
// 0053daa3  53                   push ebx
// 0053daa4  56                   push esi
// 0053daa5  8bf1                 mov esi, ecx
// 0053daa7  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0053daaa  57                   push edi
// 0053daab  85db                 test ebx, ebx
// 0053daad  7504                 jne 0x53dab3
// 0053daaf  33c9                 xor ecx, ecx
// 0053dab1  eb16                 jmp 0x53dac9
// 0053dab3  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 0053dab6  2bcb                 sub ecx, ebx
// 0053dab8  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0053dabd  f7e9                 imul ecx
// 0053dabf  c1fa02               sar edx, 2
// 0053dac2  8bca                 mov ecx, edx
// 0053dac4  c1e91f               shr ecx, 0x1f
// 0053dac7  03ca                 add ecx, edx
// 0053dac9  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0053dacc  8bd7                 mov edx, edi
// 0053dace  2bd3                 sub edx, ebx
// 0053dad0  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0053dad5  f7ea                 imul edx
// 0053dad7  c1fa02               sar edx, 2
// 0053dada  8bc2                 mov eax, edx
// 0053dadc  c1e81f               shr eax, 0x1f
// 0053dadf  03c2                 add eax, edx
// 0053dae1  3bc1                 cmp eax, ecx
// 0053dae3  7332                 jae 0x53db17
// 0053dae5  8b542418             mov edx, dword ptr [esp + 0x18]
// 0053dae9  c644240c00           mov byte ptr [esp + 0xc], 0
// 0053daee  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0053daf2  51                   push ecx
// 0053daf3  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0053daf7  52                   push edx
// 0053daf8  8d4608               lea eax, [esi + 8]
// 0053dafb  50                   push eax
// 0053dafc  51                   push ecx
// 0053dafd  6a01                 push 1
// 0053daff  57                   push edi
// 0053db00  e8abf8ffff           call 0x53d3b0
// 0053db05  83c418               add esp, 0x18
// 0053db08  83c718               add edi, 0x18
// 0053db0b  897e10               mov dword ptr [esi + 0x10], edi
// 0053db0e  5f                   pop edi
// 0053db0f  5e                   pop esi
// 0053db10  5b                   pop ebx
// 0053db11  83c408               add esp, 8
// 0053db14  c20400               ret 4
// 0053db17  3bdf                 cmp ebx, edi
// 0053db19  7606                 jbe 0x53db21
// 0053db1b  ff150ca99e00         call dword ptr [0x9ea90c]
// 0053db21  8b542418             mov edx, dword ptr [esp + 0x18]
// 0053db25  8b06                 mov eax, dword ptr [esi]
// 0053db27  52                   push edx
// 0053db28  57                   push edi
// 0053db29  50                   push eax
// 0053db2a  8d442418             lea eax, [esp + 0x18]
// 0053db2e  50                   push eax
// 0053db2f  8bce                 mov ecx, esi
// 0053db31  e8bafeffff           call 0x53d9f0
// 0053db36  5f                   pop edi
// 0053db37  5e                   pop esi
// 0053db38  5b                   pop ebx
// 0053db39  83c408               add esp, 8
// 0053db3c  c20400               ret 4
// standard library vector<pod24> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
