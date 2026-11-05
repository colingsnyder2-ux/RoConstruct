// from server: 100% by auto
// roc 2010-06 00657f20  unit: RBX::VKeyframeSequence::?$FactoryProduct  size: 332 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00657f20
//
// 00657f20  55                   push ebp
// 00657f21  8bec                 mov ebp, esp
// 00657f23  6aff                 push -1
// 00657f25  6880e09900           push 0x99e080
// 00657f2a  64a100000000         mov eax, dword ptr fs:[0]
// 00657f30  50                   push eax
// 00657f31  64892500000000       mov dword ptr fs:[0], esp
// 00657f38  83ec0c               sub esp, 0xc
// 00657f3b  53                   push ebx
// 00657f3c  56                   push esi
// 00657f3d  8bf1                 mov esi, ecx
// 00657f3f  8b560c               mov edx, dword ptr [esi + 0xc]
// 00657f42  57                   push edi
// 00657f43  8965f0               mov dword ptr [ebp - 0x10], esp
// 00657f46  85d2                 test edx, edx
// 00657f48  7504                 jne 0x657f4e
// 00657f4a  33c9                 xor ecx, ecx
// 00657f4c  eb0a                 jmp 0x657f58
// 00657f4e  8b4614               mov eax, dword ptr [esi + 0x14]
// 00657f51  2bc2                 sub eax, edx
// 00657f53  c1f803               sar eax, 3
// 00657f56  8bc8                 mov ecx, eax
// 00657f58  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 00657f5b  85ff                 test edi, edi
// 00657f5d  0f84ea010000         je 0x65814d
// 00657f63  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 00657f66  8bc3                 mov eax, ebx
// 00657f68  2bc2                 sub eax, edx
// 00657f6a  c1f803               sar eax, 3
// 00657f6d  baffffff1f           mov edx, 0x1fffffff
// 00657f72  2bd0                 sub edx, eax
// 00657f74  3bd7                 cmp edx, edi
// 00657f76  7305                 jae 0x657f7d
// 00657f78  e873bedcff           call 0x423df0
// 00657f7d  8d1438               lea edx, [eax + edi]
// 00657f80  3bca                 cmp ecx, edx
// 00657f82  0f83f9000000         jae 0x658081
// 00657f88  8bc1                 mov eax, ecx
// 00657f8a  d1e8                 shr eax, 1
// 00657f8c  bbffffff1f           mov ebx, 0x1fffffff
// 00657f91  2bd8                 sub ebx, eax
// 00657f93  3bd9                 cmp ebx, ecx
// 00657f95  730c                 jae 0x657fa3
// 00657f97  c745ec00000000       mov dword ptr [ebp - 0x14], 0
// 00657f9e  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 00657fa1  eb05                 jmp 0x657fa8
// 00657fa3  03c8                 add ecx, eax
// 00657fa5  894dec               mov dword ptr [ebp - 0x14], ecx
// 00657fa8  3bca                 cmp ecx, edx
// 00657faa  7305                 jae 0x657fb1
// 00657fac  8955ec               mov dword ptr [ebp - 0x14], edx
// 00657faf  8bca                 mov ecx, edx
// 00657fb1  6a00                 push 0
// 00657fb3  51                   push ecx
// 00657fb4  e8f7652a00           call 0x8fe5b0
// 00657fb9  8b5d0c               mov ebx, dword ptr [ebp + 0xc]
// 00657fbc  2b5e0c               sub ebx, dword ptr [esi + 0xc]
// 00657fbf  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 00657fc2  83c408               add esp, 8
// 00657fc5  51                   push ecx
// 00657fc6  c1fb03               sar ebx, 3
// 00657fc9  57                   push edi
// 00657fca  8d14d8               lea edx, [eax + ebx*8]
// 00657fcd  52                   push edx
// 00657fce  8bce                 mov ecx, esi
// 00657fd0  894510               mov dword ptr [ebp + 0x10], eax
// 00657fd3  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00657fda  e82143ffff           call 0x64c300
// 00657fdf  8b460c               mov eax, dword ptr [esi + 0xc]
// 00657fe2  c6451400             mov byte ptr [ebp + 0x14], 0
// 00657fe6  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00657fe9  52                   push edx
// 00657fea  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00657fed  52                   push edx
// 00657fee  8b550c               mov edx, dword ptr [ebp + 0xc]
// 00657ff1  8d4e08               lea ecx, [esi + 8]
// 00657ff4  51                   push ecx
// 00657ff5  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 00657ff8  51                   push ecx
// 00657ff9  52                   push edx
// 00657ffa  50                   push eax
// 00657ffb  e8a08e3000           call 0x960ea0
// 00658000  8b4610               mov eax, dword ptr [esi + 0x10]
// 00658003  83c418               add esp, 0x18
// 00658006  c6451400             mov byte ptr [ebp + 0x14], 0
// 0065800a  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0065800d  52                   push edx
// 0065800e  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00658011  52                   push edx
// 00658012  8d0c3b               lea ecx, [ebx + edi]
// 00658015  8b5d10               mov ebx, dword ptr [ebp + 0x10]
// 00658018  8d5608               lea edx, [esi + 8]
// 0065801b  52                   push edx
// 0065801c  8d0ccb               lea ecx, [ebx + ecx*8]
// 0065801f  51                   push ecx
// 00658020  50                   push eax
// 00658021  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00658024  50                   push eax
// 00658025  e8768e3000           call 0x960ea0
// 0065802a  8b460c               mov eax, dword ptr [esi + 0xc]
// 0065802d  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00658030  2bc8                 sub ecx, eax
// 00658032  c1f903               sar ecx, 3
// 00658035  83c418               add esp, 0x18
// 00658038  03f9                 add edi, ecx
// 0065803a  85c0                 test eax, eax
// 0065803c  7409                 je 0x658047
// 0065803e  50                   push eax
// 0065803f  e856f91400           call 0x7a799a
// 00658044  83c404               add esp, 4
// 00658047  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 0065804a  8d04d3               lea eax, [ebx + edx*8]
// 0065804d  8d0cfb               lea ecx, [ebx + edi*8]
// 00658050  894614               mov dword ptr [esi + 0x14], eax
// 00658053  894e10               mov dword ptr [esi + 0x10], ecx
// 00658056  895e0c               mov dword ptr [esi + 0xc], ebx
// 00658059  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0065805c  64890d00000000       mov dword ptr fs:[0], ecx
// 00658063  5f                   pop edi
// 00658064  5e                   pop esi
// 00658065  5b                   pop ebx
// 00658066  8be5                 mov esp, ebp
// 00658068  5d                   pop ebp
// 00658069  c21000               ret 0x10
// standard library vector<pod8> (function ?_Insert_n@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEXV?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@IABUE@@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
