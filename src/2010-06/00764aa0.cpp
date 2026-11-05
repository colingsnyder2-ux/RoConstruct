// from server: 100% by auto
// roc 2010-06 00764aa0  unit: RBX::GuiLayerCollector  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00764aa0
//
// 00764aa0  83ec08               sub esp, 8
// 00764aa3  53                   push ebx
// 00764aa4  56                   push esi
// 00764aa5  8bf1                 mov esi, ecx
// 00764aa7  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00764aaa  57                   push edi
// 00764aab  85db                 test ebx, ebx
// 00764aad  7504                 jne 0x764ab3
// 00764aaf  33c9                 xor ecx, ecx
// 00764ab1  eb16                 jmp 0x764ac9
// 00764ab3  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00764ab6  2bcb                 sub ecx, ebx
// 00764ab8  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00764abd  f7e9                 imul ecx
// 00764abf  c1fa02               sar edx, 2
// 00764ac2  8bca                 mov ecx, edx
// 00764ac4  c1e91f               shr ecx, 0x1f
// 00764ac7  03ca                 add ecx, edx
// 00764ac9  8b7e10               mov edi, dword ptr [esi + 0x10]
// 00764acc  8bd7                 mov edx, edi
// 00764ace  2bd3                 sub edx, ebx
// 00764ad0  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00764ad5  f7ea                 imul edx
// 00764ad7  c1fa02               sar edx, 2
// 00764ada  8bc2                 mov eax, edx
// 00764adc  c1e81f               shr eax, 0x1f
// 00764adf  03c2                 add eax, edx
// 00764ae1  3bc1                 cmp eax, ecx
// 00764ae3  7332                 jae 0x764b17
// 00764ae5  8b542418             mov edx, dword ptr [esp + 0x18]
// 00764ae9  c644240c00           mov byte ptr [esp + 0xc], 0
// 00764aee  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00764af2  51                   push ecx
// 00764af3  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00764af7  52                   push edx
// 00764af8  8d4608               lea eax, [esi + 8]
// 00764afb  50                   push eax
// 00764afc  51                   push ecx
// 00764afd  6a01                 push 1
// 00764aff  57                   push edi
// 00764b00  e8dbf7ffff           call 0x7642e0
// 00764b05  83c418               add esp, 0x18
// 00764b08  83c718               add edi, 0x18
// 00764b0b  897e10               mov dword ptr [esi + 0x10], edi
// 00764b0e  5f                   pop edi
// 00764b0f  5e                   pop esi
// 00764b10  5b                   pop ebx
// 00764b11  83c408               add esp, 8
// 00764b14  c20400               ret 4
// 00764b17  3bdf                 cmp ebx, edi
// 00764b19  7606                 jbe 0x764b21
// 00764b1b  ff150ca99e00         call dword ptr [0x9ea90c]
// 00764b21  8b542418             mov edx, dword ptr [esp + 0x18]
// 00764b25  8b06                 mov eax, dword ptr [esi]
// 00764b27  52                   push edx
// 00764b28  57                   push edi
// 00764b29  50                   push eax
// 00764b2a  8d442418             lea eax, [esp + 0x18]
// 00764b2e  50                   push eax
// 00764b2f  8bce                 mov ecx, esi
// 00764b31  e8bafeffff           call 0x7649f0
// 00764b36  5f                   pop edi
// 00764b37  5e                   pop esi
// 00764b38  5b                   pop ebx
// 00764b39  83c408               add esp, 8
// 00764b3c  c20400               ret 4
// standard library vector<pod24> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
