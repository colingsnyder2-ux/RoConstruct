// from server: 100% by auto
// roc 2010-06 00658078  unit: RBX::VKeyframeSequence::?$FactoryProduct  size: 232 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00658078
//
// 00658078  6a00                 push 0
// 0065807a  6a00                 push 0
// 0065807c  e831091500           call 0x7a89b2
// 00658081  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00658084  8bcb                 mov ecx, ebx
// 00658086  2bc8                 sub ecx, eax
// 00658088  c1f903               sar ecx, 3
// 0065808b  3bcf                 cmp ecx, edi
// 0065808d  7374                 jae 0x658103
// 0065808f  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 00658092  8b11                 mov edx, dword ptr [ecx]
// 00658094  8b4904               mov ecx, dword ptr [ecx + 4]
// 00658097  894dec               mov dword ptr [ebp - 0x14], ecx
// 0065809a  8d0cfd00000000       lea ecx, [edi*8]
// 006580a1  894d14               mov dword ptr [ebp + 0x14], ecx
// 006580a4  03c8                 add ecx, eax
// 006580a6  51                   push ecx
// 006580a7  53                   push ebx
// 006580a8  50                   push eax
// 006580a9  8bce                 mov ecx, esi
// 006580ab  8955e8               mov dword ptr [ebp - 0x18], edx
// 006580ae  e84dc72a00           call 0x904800
// 006580b3  8b4610               mov eax, dword ptr [esi + 0x10]
// 006580b6  8bc8                 mov ecx, eax
// 006580b8  2b4d0c               sub ecx, dword ptr [ebp + 0xc]
// 006580bb  8d55e8               lea edx, [ebp - 0x18]
// 006580be  c1f903               sar ecx, 3
// 006580c1  52                   push edx
// 006580c2  2bf9                 sub edi, ecx
// 006580c4  57                   push edi
// 006580c5  50                   push eax
// 006580c6  8bce                 mov ecx, esi
// 006580c8  c745fc02000000       mov dword ptr [ebp - 4], 2
// 006580cf  e82c42ffff           call 0x64c300
// 006580d4  8b4514               mov eax, dword ptr [ebp + 0x14]
// 006580d7  014610               add dword ptr [esi + 0x10], eax
// 006580da  8b7610               mov esi, dword ptr [esi + 0x10]
// 006580dd  8d55e8               lea edx, [ebp - 0x18]
// 006580e0  52                   push edx
// 006580e1  2bf0                 sub esi, eax
// 006580e3  8b450c               mov eax, dword ptr [ebp + 0xc]
// 006580e6  56                   push esi
// 006580e7  50                   push eax
// 006580e8  e853c42a00           call 0x904540
// 006580ed  83c40c               add esp, 0xc
// 006580f0  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 006580f3  64890d00000000       mov dword ptr fs:[0], ecx
// 006580fa  5f                   pop edi
// 006580fb  5e                   pop esi
// 006580fc  5b                   pop ebx
// 006580fd  8be5                 mov esp, ebp
// 006580ff  5d                   pop ebp
// 00658100  c21000               ret 0x10
// 00658103  8b4514               mov eax, dword ptr [ebp + 0x14]
// 00658106  8b08                 mov ecx, dword ptr [eax]
// 00658108  8b5004               mov edx, dword ptr [eax + 4]
// 0065810b  8d04fd00000000       lea eax, [edi*8]
// 00658112  53                   push ebx
// 00658113  8bfb                 mov edi, ebx
// 00658115  2bf8                 sub edi, eax
// 00658117  53                   push ebx
// 00658118  894de8               mov dword ptr [ebp - 0x18], ecx
// 0065811b  57                   push edi
// 0065811c  8bce                 mov ecx, esi
// 0065811e  8955ec               mov dword ptr [ebp - 0x14], edx
// 00658121  894514               mov dword ptr [ebp + 0x14], eax
// 00658124  e8d7c62a00           call 0x904800
// 00658129  53                   push ebx
// 0065812a  894610               mov dword ptr [esi + 0x10], eax
// 0065812d  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00658130  57                   push edi
// 00658131  50                   push eax
// 00658132  e879652a00           call 0x8fe6b0
// 00658137  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0065813a  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0065813d  8d4de8               lea ecx, [ebp - 0x18]
// 00658140  51                   push ecx
// 00658141  03d0                 add edx, eax
// 00658143  52                   push edx
// 00658144  50                   push eax
// 00658145  e8f6c32a00           call 0x904540
// 0065814a  83c418               add esp, 0x18
// 0065814d  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00658150  5f                   pop edi
// 00658151  5e                   pop esi
// 00658152  64890d00000000       mov dword ptr fs:[0], ecx
// 00658159  5b                   pop ebx
// 0065815a  8be5                 mov esp, ebp
// 0065815c  5d                   pop ebp
// 0065815d  c21000               ret 0x10
// standard library vector<pod8> (function __catch$?_Insert_n@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEXV?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@IABUE@@@Z$2)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
