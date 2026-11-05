// from server: 100% by auto
// roc 2010-06 008d4290  unit: Ogre::VertexStreamer  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008d4290
//
// 008d4290  83ec08               sub esp, 8
// 008d4293  53                   push ebx
// 008d4294  56                   push esi
// 008d4295  8bf1                 mov esi, ecx
// 008d4297  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 008d429a  57                   push edi
// 008d429b  85db                 test ebx, ebx
// 008d429d  7504                 jne 0x8d42a3
// 008d429f  33c9                 xor ecx, ecx
// 008d42a1  eb16                 jmp 0x8d42b9
// 008d42a3  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 008d42a6  2bcb                 sub ecx, ebx
// 008d42a8  b8abaaaa2a           mov eax, 0x2aaaaaab
// 008d42ad  f7e9                 imul ecx
// 008d42af  c1fa02               sar edx, 2
// 008d42b2  8bca                 mov ecx, edx
// 008d42b4  c1e91f               shr ecx, 0x1f
// 008d42b7  03ca                 add ecx, edx
// 008d42b9  8b7e10               mov edi, dword ptr [esi + 0x10]
// 008d42bc  8bd7                 mov edx, edi
// 008d42be  2bd3                 sub edx, ebx
// 008d42c0  b8abaaaa2a           mov eax, 0x2aaaaaab
// 008d42c5  f7ea                 imul edx
// 008d42c7  c1fa02               sar edx, 2
// 008d42ca  8bc2                 mov eax, edx
// 008d42cc  c1e81f               shr eax, 0x1f
// 008d42cf  03c2                 add eax, edx
// 008d42d1  3bc1                 cmp eax, ecx
// 008d42d3  7332                 jae 0x8d4307
// 008d42d5  8b542418             mov edx, dword ptr [esp + 0x18]
// 008d42d9  c644240c00           mov byte ptr [esp + 0xc], 0
// 008d42de  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008d42e2  51                   push ecx
// 008d42e3  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 008d42e7  52                   push edx
// 008d42e8  8d4608               lea eax, [esi + 8]
// 008d42eb  50                   push eax
// 008d42ec  51                   push ecx
// 008d42ed  6a01                 push 1
// 008d42ef  57                   push edi
// 008d42f0  e86be9ffff           call 0x8d2c60
// 008d42f5  83c418               add esp, 0x18
// 008d42f8  83c718               add edi, 0x18
// 008d42fb  897e10               mov dword ptr [esi + 0x10], edi
// 008d42fe  5f                   pop edi
// 008d42ff  5e                   pop esi
// 008d4300  5b                   pop ebx
// 008d4301  83c408               add esp, 8
// 008d4304  c20400               ret 4
// 008d4307  3bdf                 cmp ebx, edi
// 008d4309  7606                 jbe 0x8d4311
// 008d430b  ff150ca99e00         call dword ptr [0x9ea90c]
// 008d4311  8b542418             mov edx, dword ptr [esp + 0x18]
// 008d4315  8b06                 mov eax, dword ptr [esi]
// 008d4317  52                   push edx
// 008d4318  57                   push edi
// 008d4319  50                   push eax
// 008d431a  8d442418             lea eax, [esp + 0x18]
// 008d431e  50                   push eax
// 008d431f  8bce                 mov ecx, esi
// 008d4321  e8cafcffff           call 0x8d3ff0
// 008d4326  5f                   pop edi
// 008d4327  5e                   pop esi
// 008d4328  5b                   pop ebx
// 008d4329  83c408               add esp, 8
// 008d432c  c20400               ret 4
// standard library vector<pod24> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
