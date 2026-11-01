// from server: 100% by auto
// roc 2009-12 006c2810  unit: seg_006c0000  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006c2810
//
// 006c2810  83ec08               sub esp, 8
// 006c2813  56                   push esi
// 006c2814  8bf1                 mov esi, ecx
// 006c2816  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 006c2819  57                   push edi
// 006c281a  85c9                 test ecx, ecx
// 006c281c  7504                 jne 0x6c2822
// 006c281e  33c0                 xor eax, eax
// 006c2820  eb08                 jmp 0x6c282a
// 006c2822  8b4614               mov eax, dword ptr [esi + 0x14]
// 006c2825  2bc1                 sub eax, ecx
// 006c2827  c1f805               sar eax, 5
// 006c282a  8b7e10               mov edi, dword ptr [esi + 0x10]
// 006c282d  8bd7                 mov edx, edi
// 006c282f  2bd1                 sub edx, ecx
// 006c2831  c1fa05               sar edx, 5
// 006c2834  3bd0                 cmp edx, eax
// 006c2836  7331                 jae 0x6c2869
// 006c2838  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 006c283c  c644240800           mov byte ptr [esp + 8], 0
// 006c2841  8b442408             mov eax, dword ptr [esp + 8]
// 006c2845  50                   push eax
// 006c2846  8b442418             mov eax, dword ptr [esp + 0x18]
// 006c284a  51                   push ecx
// 006c284b  8d5608               lea edx, [esi + 8]
// 006c284e  52                   push edx
// 006c284f  50                   push eax
// 006c2850  6a01                 push 1
// 006c2852  57                   push edi
// 006c2853  e848dbffff           call 0x6c03a0
// 006c2858  83c418               add esp, 0x18
// 006c285b  83c720               add edi, 0x20
// 006c285e  897e10               mov dword ptr [esi + 0x10], edi
// 006c2861  5f                   pop edi
// 006c2862  5e                   pop esi
// 006c2863  83c408               add esp, 8
// 006c2866  c20400               ret 4
// 006c2869  3bcf                 cmp ecx, edi
// 006c286b  7606                 jbe 0x6c2873
// 006c286d  ff1560b79800         call dword ptr [0x98b760]
// 006c2873  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 006c2877  8b06                 mov eax, dword ptr [esi]
// 006c2879  51                   push ecx
// 006c287a  57                   push edi
// 006c287b  50                   push eax
// 006c287c  8d542414             lea edx, [esp + 0x14]
// 006c2880  52                   push edx
// 006c2881  8bce                 mov ecx, esi
// 006c2883  e8a8fdffff           call 0x6c2630
// 006c2888  5f                   pop edi
// 006c2889  5e                   pop esi
// 006c288a  83c408               add esp, 8
// 006c288d  c20400               ret 4
// standard library vector<pod32> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod32>
struct E { int v[8]; };
#include <vector>
template class std::vector<E>;
