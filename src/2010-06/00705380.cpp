// from server: 100% by auto
// roc 2010-06 00705380  unit: RBX::VInstance::?$NonFactoryProduct  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00705380
//
// 00705380  83ec08               sub esp, 8
// 00705383  53                   push ebx
// 00705384  56                   push esi
// 00705385  8bf1                 mov esi, ecx
// 00705387  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0070538a  57                   push edi
// 0070538b  85db                 test ebx, ebx
// 0070538d  7504                 jne 0x705393
// 0070538f  33c9                 xor ecx, ecx
// 00705391  eb16                 jmp 0x7053a9
// 00705393  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00705396  2bcb                 sub ecx, ebx
// 00705398  b8398ee338           mov eax, 0x38e38e39
// 0070539d  f7e9                 imul ecx
// 0070539f  c1fa03               sar edx, 3
// 007053a2  8bca                 mov ecx, edx
// 007053a4  c1e91f               shr ecx, 0x1f
// 007053a7  03ca                 add ecx, edx
// 007053a9  8b7e10               mov edi, dword ptr [esi + 0x10]
// 007053ac  8bd7                 mov edx, edi
// 007053ae  2bd3                 sub edx, ebx
// 007053b0  b8398ee338           mov eax, 0x38e38e39
// 007053b5  f7ea                 imul edx
// 007053b7  c1fa03               sar edx, 3
// 007053ba  8bc2                 mov eax, edx
// 007053bc  c1e81f               shr eax, 0x1f
// 007053bf  03c2                 add eax, edx
// 007053c1  3bc1                 cmp eax, ecx
// 007053c3  7332                 jae 0x7053f7
// 007053c5  8b542418             mov edx, dword ptr [esp + 0x18]
// 007053c9  c644240c00           mov byte ptr [esp + 0xc], 0
// 007053ce  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007053d2  51                   push ecx
// 007053d3  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 007053d7  52                   push edx
// 007053d8  8d4608               lea eax, [esi + 8]
// 007053db  50                   push eax
// 007053dc  51                   push ecx
// 007053dd  6a01                 push 1
// 007053df  57                   push edi
// 007053e0  e85bf3ffff           call 0x704740
// 007053e5  83c418               add esp, 0x18
// 007053e8  83c724               add edi, 0x24
// 007053eb  897e10               mov dword ptr [esi + 0x10], edi
// 007053ee  5f                   pop edi
// 007053ef  5e                   pop esi
// 007053f0  5b                   pop ebx
// 007053f1  83c408               add esp, 8
// 007053f4  c20400               ret 4
// 007053f7  3bdf                 cmp ebx, edi
// 007053f9  7606                 jbe 0x705401
// 007053fb  ff150ca99e00         call dword ptr [0x9ea90c]
// 00705401  8b542418             mov edx, dword ptr [esp + 0x18]
// 00705405  8b06                 mov eax, dword ptr [esi]
// 00705407  52                   push edx
// 00705408  57                   push edi
// 00705409  50                   push eax
// 0070540a  8d442418             lea eax, [esp + 0x18]
// 0070540e  50                   push eax
// 0070540f  8bce                 mov ecx, esi
// 00705411  e8fafdffff           call 0x705210
// 00705416  5f                   pop edi
// 00705417  5e                   pop esi
// 00705418  5b                   pop ebx
// 00705419  83c408               add esp, 8
// 0070541c  c20400               ret 4
// standard library vector<pod36> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod36>
struct E { int v[9]; };
#include <vector>
template class std::vector<E>;
