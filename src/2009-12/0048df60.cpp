// from server: 100% by auto
// roc 2009-12 0048df60  unit: Ogre::VertexStreamer  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0048df60
//
// 0048df60  83ec08               sub esp, 8
// 0048df63  53                   push ebx
// 0048df64  56                   push esi
// 0048df65  8bf1                 mov esi, ecx
// 0048df67  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0048df6a  57                   push edi
// 0048df6b  85db                 test ebx, ebx
// 0048df6d  7504                 jne 0x48df73
// 0048df6f  33c9                 xor ecx, ecx
// 0048df71  eb16                 jmp 0x48df89
// 0048df73  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 0048df76  2bcb                 sub ecx, ebx
// 0048df78  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0048df7d  f7e9                 imul ecx
// 0048df7f  c1fa02               sar edx, 2
// 0048df82  8bca                 mov ecx, edx
// 0048df84  c1e91f               shr ecx, 0x1f
// 0048df87  03ca                 add ecx, edx
// 0048df89  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0048df8c  8bd7                 mov edx, edi
// 0048df8e  2bd3                 sub edx, ebx
// 0048df90  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0048df95  f7ea                 imul edx
// 0048df97  c1fa02               sar edx, 2
// 0048df9a  8bc2                 mov eax, edx
// 0048df9c  c1e81f               shr eax, 0x1f
// 0048df9f  03c2                 add eax, edx
// 0048dfa1  3bc1                 cmp eax, ecx
// 0048dfa3  7332                 jae 0x48dfd7
// 0048dfa5  8b542418             mov edx, dword ptr [esp + 0x18]
// 0048dfa9  c644240c00           mov byte ptr [esp + 0xc], 0
// 0048dfae  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0048dfb2  51                   push ecx
// 0048dfb3  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0048dfb7  52                   push edx
// 0048dfb8  8d4608               lea eax, [esi + 8]
// 0048dfbb  50                   push eax
// 0048dfbc  51                   push ecx
// 0048dfbd  6a01                 push 1
// 0048dfbf  57                   push edi
// 0048dfc0  e8abe9ffff           call 0x48c970
// 0048dfc5  83c418               add esp, 0x18
// 0048dfc8  83c718               add edi, 0x18
// 0048dfcb  897e10               mov dword ptr [esi + 0x10], edi
// 0048dfce  5f                   pop edi
// 0048dfcf  5e                   pop esi
// 0048dfd0  5b                   pop ebx
// 0048dfd1  83c408               add esp, 8
// 0048dfd4  c20400               ret 4
// 0048dfd7  3bdf                 cmp ebx, edi
// 0048dfd9  7606                 jbe 0x48dfe1
// 0048dfdb  ff1560b79800         call dword ptr [0x98b760]
// 0048dfe1  8b542418             mov edx, dword ptr [esp + 0x18]
// 0048dfe5  8b06                 mov eax, dword ptr [esi]
// 0048dfe7  52                   push edx
// 0048dfe8  57                   push edi
// 0048dfe9  50                   push eax
// 0048dfea  8d442418             lea eax, [esp + 0x18]
// 0048dfee  50                   push eax
// 0048dfef  8bce                 mov ecx, esi
// 0048dff1  e8cafcffff           call 0x48dcc0
// 0048dff6  5f                   pop edi
// 0048dff7  5e                   pop esi
// 0048dff8  5b                   pop ebx
// 0048dff9  83c408               add esp, 8
// 0048dffc  c20400               ret 4
// standard library vector<pod24> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
