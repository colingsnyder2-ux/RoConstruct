// from server: 100% by auto
// roc 2010-06 00907890  unit: RBX::RbxParticleEmitter  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00907890
//
// 00907890  83ec08               sub esp, 8
// 00907893  56                   push esi
// 00907894  8bf1                 mov esi, ecx
// 00907896  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00907899  57                   push edi
// 0090789a  85c9                 test ecx, ecx
// 0090789c  7504                 jne 0x9078a2
// 0090789e  33c0                 xor eax, eax
// 009078a0  eb08                 jmp 0x9078aa
// 009078a2  8b4614               mov eax, dword ptr [esi + 0x14]
// 009078a5  2bc1                 sub eax, ecx
// 009078a7  c1f803               sar eax, 3
// 009078aa  8b7e10               mov edi, dword ptr [esi + 0x10]
// 009078ad  8bd7                 mov edx, edi
// 009078af  2bd1                 sub edx, ecx
// 009078b1  c1fa03               sar edx, 3
// 009078b4  3bd0                 cmp edx, eax
// 009078b6  7331                 jae 0x9078e9
// 009078b8  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 009078bc  c644240800           mov byte ptr [esp + 8], 0
// 009078c1  8b442408             mov eax, dword ptr [esp + 8]
// 009078c5  50                   push eax
// 009078c6  8b442418             mov eax, dword ptr [esp + 0x18]
// 009078ca  51                   push ecx
// 009078cb  8d5608               lea edx, [esi + 8]
// 009078ce  52                   push edx
// 009078cf  50                   push eax
// 009078d0  6a01                 push 1
// 009078d2  57                   push edi
// 009078d3  e828f8ffff           call 0x907100
// 009078d8  83c418               add esp, 0x18
// 009078db  83c708               add edi, 8
// 009078de  897e10               mov dword ptr [esi + 0x10], edi
// 009078e1  5f                   pop edi
// 009078e2  5e                   pop esi
// 009078e3  83c408               add esp, 8
// 009078e6  c20400               ret 4
// 009078e9  3bcf                 cmp ecx, edi
// 009078eb  7606                 jbe 0x9078f3
// 009078ed  ff150ca99e00         call dword ptr [0x9ea90c]
// 009078f3  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 009078f7  8b06                 mov eax, dword ptr [esi]
// 009078f9  51                   push ecx
// 009078fa  57                   push edi
// 009078fb  50                   push eax
// 009078fc  8d542414             lea edx, [esp + 0x14]
// 00907900  52                   push edx
// 00907901  8bce                 mov ecx, esi
// 00907903  e8b8fdffff           call 0x9076c0
// 00907908  5f                   pop edi
// 00907909  5e                   pop esi
// 0090790a  83c408               add esp, 8
// 0090790d  c20400               ret 4
// standard library vector<pod8> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
