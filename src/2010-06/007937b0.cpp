// from server: 100% by auto
// roc 2010-06 007937b0  unit: RBX::CircleRadialNormal  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007937b0
//
// 007937b0  83ec08               sub esp, 8
// 007937b3  56                   push esi
// 007937b4  8bf1                 mov esi, ecx
// 007937b6  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 007937b9  57                   push edi
// 007937ba  85c9                 test ecx, ecx
// 007937bc  7504                 jne 0x7937c2
// 007937be  33c0                 xor eax, eax
// 007937c0  eb08                 jmp 0x7937ca
// 007937c2  8b4614               mov eax, dword ptr [esi + 0x14]
// 007937c5  2bc1                 sub eax, ecx
// 007937c7  c1f803               sar eax, 3
// 007937ca  8b7e10               mov edi, dword ptr [esi + 0x10]
// 007937cd  8bd7                 mov edx, edi
// 007937cf  2bd1                 sub edx, ecx
// 007937d1  c1fa03               sar edx, 3
// 007937d4  3bd0                 cmp edx, eax
// 007937d6  7331                 jae 0x793809
// 007937d8  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007937dc  c644240800           mov byte ptr [esp + 8], 0
// 007937e1  8b442408             mov eax, dword ptr [esp + 8]
// 007937e5  50                   push eax
// 007937e6  8b442418             mov eax, dword ptr [esp + 0x18]
// 007937ea  51                   push ecx
// 007937eb  8d5608               lea edx, [esi + 8]
// 007937ee  52                   push edx
// 007937ef  50                   push eax
// 007937f0  6a01                 push 1
// 007937f2  57                   push edi
// 007937f3  e8c8fbffff           call 0x7933c0
// 007937f8  83c418               add esp, 0x18
// 007937fb  83c708               add edi, 8
// 007937fe  897e10               mov dword ptr [esi + 0x10], edi
// 00793801  5f                   pop edi
// 00793802  5e                   pop esi
// 00793803  83c408               add esp, 8
// 00793806  c20400               ret 4
// 00793809  3bcf                 cmp ecx, edi
// 0079380b  7606                 jbe 0x793813
// 0079380d  ff150ca99e00         call dword ptr [0x9ea90c]
// 00793813  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00793817  8b06                 mov eax, dword ptr [esi]
// 00793819  51                   push ecx
// 0079381a  57                   push edi
// 0079381b  50                   push eax
// 0079381c  8d542414             lea edx, [esp + 0x14]
// 00793820  52                   push edx
// 00793821  8bce                 mov ecx, esi
// 00793823  e8c8feffff           call 0x7936f0
// 00793828  5f                   pop edi
// 00793829  5e                   pop esi
// 0079382a  83c408               add esp, 8
// 0079382d  c20400               ret 4
// standard library vector<pod8> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
