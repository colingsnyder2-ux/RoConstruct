// from server: 100% by auto
// roc 2007-08 005cdec0  unit: RBX::BlockBlockContact  size: 183 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005cdec0
//
// 005cdec0  83ec08               sub esp, 8
// 005cdec3  53                   push ebx
// 005cdec4  55                   push ebp
// 005cdec5  56                   push esi
// 005cdec6  8bf1                 mov esi, ecx
// 005cdec8  8b4e04               mov ecx, dword ptr [esi + 4]
// 005cdecb  85c9                 test ecx, ecx
// 005cdecd  57                   push edi
// 005cdece  7504                 jne 0x5cded4
// 005cded0  33c0                 xor eax, eax
// 005cded2  eb08                 jmp 0x5cdedc
// 005cded4  8b4608               mov eax, dword ptr [esi + 8]
// 005cded7  2bc1                 sub eax, ecx
// 005cded9  c1f802               sar eax, 2
// 005cdedc  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 005cdee0  3bc3                 cmp eax, ebx
// 005cdee2  7338                 jae 0x5cdf1c
// 005cdee4  85c9                 test ecx, ecx
// 005cdee6  7504                 jne 0x5cdeec
// 005cdee8  33ff                 xor edi, edi
// 005cdeea  eb08                 jmp 0x5cdef4
// 005cdeec  8b7e08               mov edi, dword ptr [esi + 8]
// 005cdeef  2bf9                 sub edi, ecx
// 005cdef1  c1ff02               sar edi, 2
// 005cdef4  8b6e08               mov ebp, dword ptr [esi + 8]
// 005cdef7  3bcd                 cmp ecx, ebp
// 005cdef9  7606                 jbe 0x5cdf01
// 005cdefb  ff15d8e67700         call dword ptr [0x77e6d8]
// 005cdf01  8d442420             lea eax, [esp + 0x20]
// 005cdf05  50                   push eax
// 005cdf06  2bdf                 sub ebx, edi
// 005cdf08  53                   push ebx
// 005cdf09  55                   push ebp
// 005cdf0a  56                   push esi
// 005cdf0b  8bce                 mov ecx, esi
// 005cdf0d  e8eefdffff           call 0x5cdd00
// 005cdf12  5f                   pop edi
// 005cdf13  5e                   pop esi
// 005cdf14  5d                   pop ebp
// 005cdf15  5b                   pop ebx
// 005cdf16  83c408               add esp, 8
// 005cdf19  c20800               ret 8
// 005cdf1c  85c9                 test ecx, ecx
// 005cdf1e  744d                 je 0x5cdf6d
// 005cdf20  8b6e08               mov ebp, dword ptr [esi + 8]
// 005cdf23  8bc5                 mov eax, ebp
// 005cdf25  2bc1                 sub eax, ecx
// 005cdf27  c1f802               sar eax, 2
// 005cdf2a  3bd8                 cmp ebx, eax
// 005cdf2c  733f                 jae 0x5cdf6d
// 005cdf2e  3bcd                 cmp ecx, ebp
// 005cdf30  7606                 jbe 0x5cdf38
// 005cdf32  ff15d8e67700         call dword ptr [0x77e6d8]
// 005cdf38  8b7e04               mov edi, dword ptr [esi + 4]
// 005cdf3b  3b7e08               cmp edi, dword ptr [esi + 8]
// 005cdf3e  7606                 jbe 0x5cdf46
// 005cdf40  ff15d8e67700         call dword ptr [0x77e6d8]
// 005cdf46  897c2414             mov dword ptr [esp + 0x14], edi
// 005cdf4a  8d3c9f               lea edi, [edi + ebx*4]
// 005cdf4d  3b7e08               cmp edi, dword ptr [esi + 8]
// 005cdf50  7705                 ja 0x5cdf57
// 005cdf52  3b7e04               cmp edi, dword ptr [esi + 4]
// 005cdf55  7306                 jae 0x5cdf5d
// 005cdf57  ff15d8e67700         call dword ptr [0x77e6d8]
// 005cdf5d  55                   push ebp
// 005cdf5e  56                   push esi
// 005cdf5f  57                   push edi
// 005cdf60  56                   push esi
// 005cdf61  8d4c2420             lea ecx, [esp + 0x20]
// 005cdf65  51                   push ecx
// 005cdf66  8bce                 mov ecx, esi
// 005cdf68  e833fdffff           call 0x5cdca0
// 005cdf6d  5f                   pop edi
// 005cdf6e  5e                   pop esi
// 005cdf6f  5d                   pop ebp
// 005cdf70  5b                   pop ebx
// 005cdf71  83c408               add esp, 8
// 005cdf74  c20800               ret 8
// standard library vector<ptr> (function ?resize@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXIPAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
