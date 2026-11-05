// from server: 100% by auto
// roc 2007-08 00445e50  unit: VCRenderSettings::?$FactoryProduct  size: 183 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00445e50
//
// 00445e50  83ec08               sub esp, 8
// 00445e53  53                   push ebx
// 00445e54  55                   push ebp
// 00445e55  56                   push esi
// 00445e56  8bf1                 mov esi, ecx
// 00445e58  8b4e04               mov ecx, dword ptr [esi + 4]
// 00445e5b  85c9                 test ecx, ecx
// 00445e5d  57                   push edi
// 00445e5e  7504                 jne 0x445e64
// 00445e60  33c0                 xor eax, eax
// 00445e62  eb08                 jmp 0x445e6c
// 00445e64  8b4608               mov eax, dword ptr [esi + 8]
// 00445e67  2bc1                 sub eax, ecx
// 00445e69  c1f802               sar eax, 2
// 00445e6c  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 00445e70  3bc3                 cmp eax, ebx
// 00445e72  7338                 jae 0x445eac
// 00445e74  85c9                 test ecx, ecx
// 00445e76  7504                 jne 0x445e7c
// 00445e78  33ff                 xor edi, edi
// 00445e7a  eb08                 jmp 0x445e84
// 00445e7c  8b7e08               mov edi, dword ptr [esi + 8]
// 00445e7f  2bf9                 sub edi, ecx
// 00445e81  c1ff02               sar edi, 2
// 00445e84  8b6e08               mov ebp, dword ptr [esi + 8]
// 00445e87  3bcd                 cmp ecx, ebp
// 00445e89  7606                 jbe 0x445e91
// 00445e8b  ff15d8e67700         call dword ptr [0x77e6d8]
// 00445e91  8d442420             lea eax, [esp + 0x20]
// 00445e95  50                   push eax
// 00445e96  2bdf                 sub ebx, edi
// 00445e98  53                   push ebx
// 00445e99  55                   push ebp
// 00445e9a  56                   push esi
// 00445e9b  8bce                 mov ecx, esi
// 00445e9d  e84ef9ffff           call 0x4457f0
// 00445ea2  5f                   pop edi
// 00445ea3  5e                   pop esi
// 00445ea4  5d                   pop ebp
// 00445ea5  5b                   pop ebx
// 00445ea6  83c408               add esp, 8
// 00445ea9  c20800               ret 8
// 00445eac  85c9                 test ecx, ecx
// 00445eae  744d                 je 0x445efd
// 00445eb0  8b6e08               mov ebp, dword ptr [esi + 8]
// 00445eb3  8bc5                 mov eax, ebp
// 00445eb5  2bc1                 sub eax, ecx
// 00445eb7  c1f802               sar eax, 2
// 00445eba  3bd8                 cmp ebx, eax
// 00445ebc  733f                 jae 0x445efd
// 00445ebe  3bcd                 cmp ecx, ebp
// 00445ec0  7606                 jbe 0x445ec8
// 00445ec2  ff15d8e67700         call dword ptr [0x77e6d8]
// 00445ec8  8b7e04               mov edi, dword ptr [esi + 4]
// 00445ecb  3b7e08               cmp edi, dword ptr [esi + 8]
// 00445ece  7606                 jbe 0x445ed6
// 00445ed0  ff15d8e67700         call dword ptr [0x77e6d8]
// 00445ed6  897c2414             mov dword ptr [esp + 0x14], edi
// 00445eda  8d3c9f               lea edi, [edi + ebx*4]
// 00445edd  3b7e08               cmp edi, dword ptr [esi + 8]
// 00445ee0  7705                 ja 0x445ee7
// 00445ee2  3b7e04               cmp edi, dword ptr [esi + 4]
// 00445ee5  7306                 jae 0x445eed
// 00445ee7  ff15d8e67700         call dword ptr [0x77e6d8]
// 00445eed  55                   push ebp
// 00445eee  56                   push esi
// 00445eef  57                   push edi
// 00445ef0  56                   push esi
// 00445ef1  8d4c2420             lea ecx, [esp + 0x20]
// 00445ef5  51                   push ecx
// 00445ef6  8bce                 mov ecx, esi
// 00445ef8  e8a37d1800           call 0x5cdca0
// 00445efd  5f                   pop edi
// 00445efe  5e                   pop esi
// 00445eff  5d                   pop ebp
// 00445f00  5b                   pop ebx
// 00445f01  83c408               add esp, 8
// 00445f04  c20800               ret 8
// standard library vector<ptr> (function ?resize@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXIPAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
