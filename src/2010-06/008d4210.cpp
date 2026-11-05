// from server: 100% by auto
// roc 2010-06 008d4210  unit: Ogre::VertexStreamer  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008d4210
//
// 008d4210  83ec08               sub esp, 8
// 008d4213  56                   push esi
// 008d4214  8bf1                 mov esi, ecx
// 008d4216  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 008d4219  57                   push edi
// 008d421a  85c9                 test ecx, ecx
// 008d421c  7504                 jne 0x8d4222
// 008d421e  33c0                 xor eax, eax
// 008d4220  eb08                 jmp 0x8d422a
// 008d4222  8b4614               mov eax, dword ptr [esi + 0x14]
// 008d4225  2bc1                 sub eax, ecx
// 008d4227  c1f804               sar eax, 4
// 008d422a  8b7e10               mov edi, dword ptr [esi + 0x10]
// 008d422d  8bd7                 mov edx, edi
// 008d422f  2bd1                 sub edx, ecx
// 008d4231  c1fa04               sar edx, 4
// 008d4234  3bd0                 cmp edx, eax
// 008d4236  7331                 jae 0x8d4269
// 008d4238  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008d423c  c644240800           mov byte ptr [esp + 8], 0
// 008d4241  8b442408             mov eax, dword ptr [esp + 8]
// 008d4245  50                   push eax
// 008d4246  8b442418             mov eax, dword ptr [esp + 0x18]
// 008d424a  51                   push ecx
// 008d424b  8d5608               lea edx, [esi + 8]
// 008d424e  52                   push edx
// 008d424f  50                   push eax
// 008d4250  6a01                 push 1
// 008d4252  57                   push edi
// 008d4253  e8c8e9ffff           call 0x8d2c20
// 008d4258  83c418               add esp, 0x18
// 008d425b  83c710               add edi, 0x10
// 008d425e  897e10               mov dword ptr [esi + 0x10], edi
// 008d4261  5f                   pop edi
// 008d4262  5e                   pop esi
// 008d4263  83c408               add esp, 8
// 008d4266  c20400               ret 4
// 008d4269  3bcf                 cmp ecx, edi
// 008d426b  7606                 jbe 0x8d4273
// 008d426d  ff150ca99e00         call dword ptr [0x9ea90c]
// 008d4273  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008d4277  8b06                 mov eax, dword ptr [esi]
// 008d4279  51                   push ecx
// 008d427a  57                   push edi
// 008d427b  50                   push eax
// 008d427c  8d542414             lea edx, [esp + 0x14]
// 008d4280  52                   push edx
// 008d4281  8bce                 mov ecx, esi
// 008d4283  e8a8fcffff           call 0x8d3f30
// 008d4288  5f                   pop edi
// 008d4289  5e                   pop esi
// 008d428a  83c408               add esp, 8
// 008d428d  c20400               ret 4
// standard library vector<pod16> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
