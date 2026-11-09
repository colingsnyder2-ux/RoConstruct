// from server: 100% by auto
// roc 2009-06 0070f0c0  unit: RBX::TaskScheduler::VThread::?$sp_counted_impl_p  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0070f0c0
//
// 0070f0c0  83ec08               sub esp, 8
// 0070f0c3  56                   push esi
// 0070f0c4  8bf1                 mov esi, ecx
// 0070f0c6  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0070f0c9  57                   push edi
// 0070f0ca  85c9                 test ecx, ecx
// 0070f0cc  7504                 jne 0x70f0d2
// 0070f0ce  33c0                 xor eax, eax
// 0070f0d0  eb08                 jmp 0x70f0da
// 0070f0d2  8b4614               mov eax, dword ptr [esi + 0x14]
// 0070f0d5  2bc1                 sub eax, ecx
// 0070f0d7  c1f803               sar eax, 3
// 0070f0da  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0070f0dd  8bd7                 mov edx, edi
// 0070f0df  2bd1                 sub edx, ecx
// 0070f0e1  c1fa03               sar edx, 3
// 0070f0e4  3bd0                 cmp edx, eax
// 0070f0e6  7331                 jae 0x70f119
// 0070f0e8  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0070f0ec  c644240800           mov byte ptr [esp + 8], 0
// 0070f0f1  8b442408             mov eax, dword ptr [esp + 8]
// 0070f0f5  50                   push eax
// 0070f0f6  8b442418             mov eax, dword ptr [esp + 0x18]
// 0070f0fa  51                   push ecx
// 0070f0fb  8d5608               lea edx, [esi + 8]
// 0070f0fe  52                   push edx
// 0070f0ff  50                   push eax
// 0070f100  6a01                 push 1
// 0070f102  57                   push edi
// 0070f103  e8a8f3ffff           call 0x70e4b0
// 0070f108  83c418               add esp, 0x18
// 0070f10b  83c708               add edi, 8
// 0070f10e  897e10               mov dword ptr [esi + 0x10], edi
// 0070f111  5f                   pop edi
// 0070f112  5e                   pop esi
// 0070f113  83c408               add esp, 8
// 0070f116  c20400               ret 4
// 0070f119  3bcf                 cmp ecx, edi
// 0070f11b  7606                 jbe 0x70f123
// 0070f11d  ff15ace98900         call dword ptr [0x89e9ac]
// 0070f123  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0070f127  8b06                 mov eax, dword ptr [esi]
// 0070f129  51                   push ecx
// 0070f12a  57                   push edi
// 0070f12b  50                   push eax
// 0070f12c  8d542414             lea edx, [esp + 0x14]
// 0070f130  52                   push edx
// 0070f131  8bce                 mov ecx, esi
// 0070f133  e808feffff           call 0x70ef40
// 0070f138  5f                   pop edi
// 0070f139  5e                   pop esi
// 0070f13a  83c408               add esp, 8
// 0070f13d  c20400               ret 4
// standard library vector<pod8> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
