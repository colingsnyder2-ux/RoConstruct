// from server: 100% by auto
// roc 2009-12 0058b770  unit: RBX::BeveledBlockBuilder  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0058b770
//
// 0058b770  83ec08               sub esp, 8
// 0058b773  53                   push ebx
// 0058b774  56                   push esi
// 0058b775  8bf1                 mov esi, ecx
// 0058b777  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0058b77a  57                   push edi
// 0058b77b  85db                 test ebx, ebx
// 0058b77d  7504                 jne 0x58b783
// 0058b77f  33c9                 xor ecx, ecx
// 0058b781  eb16                 jmp 0x58b799
// 0058b783  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 0058b786  2bcb                 sub ecx, ebx
// 0058b788  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0058b78d  f7e9                 imul ecx
// 0058b78f  c1fa02               sar edx, 2
// 0058b792  8bca                 mov ecx, edx
// 0058b794  c1e91f               shr ecx, 0x1f
// 0058b797  03ca                 add ecx, edx
// 0058b799  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0058b79c  8bd7                 mov edx, edi
// 0058b79e  2bd3                 sub edx, ebx
// 0058b7a0  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0058b7a5  f7ea                 imul edx
// 0058b7a7  c1fa02               sar edx, 2
// 0058b7aa  8bc2                 mov eax, edx
// 0058b7ac  c1e81f               shr eax, 0x1f
// 0058b7af  03c2                 add eax, edx
// 0058b7b1  3bc1                 cmp eax, ecx
// 0058b7b3  7332                 jae 0x58b7e7
// 0058b7b5  8b542418             mov edx, dword ptr [esp + 0x18]
// 0058b7b9  c644240c00           mov byte ptr [esp + 0xc], 0
// 0058b7be  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0058b7c2  51                   push ecx
// 0058b7c3  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0058b7c7  52                   push edx
// 0058b7c8  8d4608               lea eax, [esi + 8]
// 0058b7cb  50                   push eax
// 0058b7cc  51                   push ecx
// 0058b7cd  6a01                 push 1
// 0058b7cf  57                   push edi
// 0058b7d0  e8ebf8ffff           call 0x58b0c0
// 0058b7d5  83c418               add esp, 0x18
// 0058b7d8  83c718               add edi, 0x18
// 0058b7db  897e10               mov dword ptr [esi + 0x10], edi
// 0058b7de  5f                   pop edi
// 0058b7df  5e                   pop esi
// 0058b7e0  5b                   pop ebx
// 0058b7e1  83c408               add esp, 8
// 0058b7e4  c20400               ret 4
// 0058b7e7  3bdf                 cmp ebx, edi
// 0058b7e9  7606                 jbe 0x58b7f1
// 0058b7eb  ff1560b79800         call dword ptr [0x98b760]
// 0058b7f1  8b542418             mov edx, dword ptr [esp + 0x18]
// 0058b7f5  8b06                 mov eax, dword ptr [esi]
// 0058b7f7  52                   push edx
// 0058b7f8  57                   push edi
// 0058b7f9  50                   push eax
// 0058b7fa  8d442418             lea eax, [esp + 0x18]
// 0058b7fe  50                   push eax
// 0058b7ff  8bce                 mov ecx, esi
// 0058b801  e8bafeffff           call 0x58b6c0
// 0058b806  5f                   pop edi
// 0058b807  5e                   pop esi
// 0058b808  5b                   pop ebx
// 0058b809  83c408               add esp, 8
// 0058b80c  c20400               ret 4
// standard library vector<pod24> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
