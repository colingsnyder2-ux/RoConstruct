// from server: 100% by auto
// roc 2009-12 007e0350  unit: RBX::CircleRadialNormal  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007e0350
//
// 007e0350  83ec08               sub esp, 8
// 007e0353  56                   push esi
// 007e0354  8bf1                 mov esi, ecx
// 007e0356  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 007e0359  57                   push edi
// 007e035a  85c9                 test ecx, ecx
// 007e035c  7504                 jne 0x7e0362
// 007e035e  33c0                 xor eax, eax
// 007e0360  eb08                 jmp 0x7e036a
// 007e0362  8b4614               mov eax, dword ptr [esi + 0x14]
// 007e0365  2bc1                 sub eax, ecx
// 007e0367  c1f803               sar eax, 3
// 007e036a  8b7e10               mov edi, dword ptr [esi + 0x10]
// 007e036d  8bd7                 mov edx, edi
// 007e036f  2bd1                 sub edx, ecx
// 007e0371  c1fa03               sar edx, 3
// 007e0374  3bd0                 cmp edx, eax
// 007e0376  7331                 jae 0x7e03a9
// 007e0378  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007e037c  c644240800           mov byte ptr [esp + 8], 0
// 007e0381  8b442408             mov eax, dword ptr [esp + 8]
// 007e0385  50                   push eax
// 007e0386  8b442418             mov eax, dword ptr [esp + 0x18]
// 007e038a  51                   push ecx
// 007e038b  8d5608               lea edx, [esi + 8]
// 007e038e  52                   push edx
// 007e038f  50                   push eax
// 007e0390  6a01                 push 1
// 007e0392  57                   push edi
// 007e0393  e8c8fbffff           call 0x7dff60
// 007e0398  83c418               add esp, 0x18
// 007e039b  83c708               add edi, 8
// 007e039e  897e10               mov dword ptr [esi + 0x10], edi
// 007e03a1  5f                   pop edi
// 007e03a2  5e                   pop esi
// 007e03a3  83c408               add esp, 8
// 007e03a6  c20400               ret 4
// 007e03a9  3bcf                 cmp ecx, edi
// 007e03ab  7606                 jbe 0x7e03b3
// 007e03ad  ff1560b79800         call dword ptr [0x98b760]
// 007e03b3  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007e03b7  8b06                 mov eax, dword ptr [esi]
// 007e03b9  51                   push ecx
// 007e03ba  57                   push edi
// 007e03bb  50                   push eax
// 007e03bc  8d542414             lea edx, [esp + 0x14]
// 007e03c0  52                   push edx
// 007e03c1  8bce                 mov ecx, esi
// 007e03c3  e8c8feffff           call 0x7e0290
// 007e03c8  5f                   pop edi
// 007e03c9  5e                   pop esi
// 007e03ca  83c408               add esp, 8
// 007e03cd  c20400               ret 4
// standard library vector<pod8> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
