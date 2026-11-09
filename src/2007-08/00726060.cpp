// from server: 100% by auto
// roc 2007-08 00726060  unit: boost::thread_resource_error  size: 183 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00726060
//
// 00726060  83ec08               sub esp, 8
// 00726063  53                   push ebx
// 00726064  55                   push ebp
// 00726065  56                   push esi
// 00726066  8bf1                 mov esi, ecx
// 00726068  8b4e04               mov ecx, dword ptr [esi + 4]
// 0072606b  85c9                 test ecx, ecx
// 0072606d  57                   push edi
// 0072606e  7504                 jne 0x726074
// 00726070  33c0                 xor eax, eax
// 00726072  eb08                 jmp 0x72607c
// 00726074  8b4608               mov eax, dword ptr [esi + 8]
// 00726077  2bc1                 sub eax, ecx
// 00726079  c1f802               sar eax, 2
// 0072607c  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 00726080  3bc3                 cmp eax, ebx
// 00726082  7338                 jae 0x7260bc
// 00726084  85c9                 test ecx, ecx
// 00726086  7504                 jne 0x72608c
// 00726088  33ff                 xor edi, edi
// 0072608a  eb08                 jmp 0x726094
// 0072608c  8b7e08               mov edi, dword ptr [esi + 8]
// 0072608f  2bf9                 sub edi, ecx
// 00726091  c1ff02               sar edi, 2
// 00726094  8b6e08               mov ebp, dword ptr [esi + 8]
// 00726097  3bcd                 cmp ecx, ebp
// 00726099  7606                 jbe 0x7260a1
// 0072609b  ff15d8e67700         call dword ptr [0x77e6d8]
// 007260a1  8d442420             lea eax, [esp + 0x20]
// 007260a5  50                   push eax
// 007260a6  2bdf                 sub ebx, edi
// 007260a8  53                   push ebx
// 007260a9  55                   push ebp
// 007260aa  56                   push esi
// 007260ab  8bce                 mov ecx, esi
// 007260ad  e85efaffff           call 0x725b10
// 007260b2  5f                   pop edi
// 007260b3  5e                   pop esi
// 007260b4  5d                   pop ebp
// 007260b5  5b                   pop ebx
// 007260b6  83c408               add esp, 8
// 007260b9  c20800               ret 8
// 007260bc  85c9                 test ecx, ecx
// 007260be  744d                 je 0x72610d
// 007260c0  8b6e08               mov ebp, dword ptr [esi + 8]
// 007260c3  8bc5                 mov eax, ebp
// 007260c5  2bc1                 sub eax, ecx
// 007260c7  c1f802               sar eax, 2
// 007260ca  3bd8                 cmp ebx, eax
// 007260cc  733f                 jae 0x72610d
// 007260ce  3bcd                 cmp ecx, ebp
// 007260d0  7606                 jbe 0x7260d8
// 007260d2  ff15d8e67700         call dword ptr [0x77e6d8]
// 007260d8  8b7e04               mov edi, dword ptr [esi + 4]
// 007260db  3b7e08               cmp edi, dword ptr [esi + 8]
// 007260de  7606                 jbe 0x7260e6
// 007260e0  ff15d8e67700         call dword ptr [0x77e6d8]
// 007260e6  897c2414             mov dword ptr [esp + 0x14], edi
// 007260ea  8d3c9f               lea edi, [edi + ebx*4]
// 007260ed  3b7e08               cmp edi, dword ptr [esi + 8]
// 007260f0  7705                 ja 0x7260f7
// 007260f2  3b7e04               cmp edi, dword ptr [esi + 4]
// 007260f5  7306                 jae 0x7260fd
// 007260f7  ff15d8e67700         call dword ptr [0x77e6d8]
// 007260fd  55                   push ebp
// 007260fe  56                   push esi
// 007260ff  57                   push edi
// 00726100  56                   push esi
// 00726101  8d4c2420             lea ecx, [esp + 0x20]
// 00726105  51                   push ecx
// 00726106  8bce                 mov ecx, esi
// 00726108  e8937beaff           call 0x5cdca0
// 0072610d  5f                   pop edi
// 0072610e  5e                   pop esi
// 0072610f  5d                   pop ebp
// 00726110  5b                   pop ebx
// 00726111  83c408               add esp, 8
// 00726114  c20800               ret 8
// standard library vector<ptr> (function ?resize@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXIPAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
