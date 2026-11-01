// from server: 100% by auto
// roc 2009-12 00530a70  unit: RBX::VInstance::$$A6AXV?$shared_ptr::?$signal::Vslot::?$sp_counted_impl_p  size: 352 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00530a70
//
// 00530a70  8b542404             mov edx, dword ptr [esp + 4]
// 00530a74  83ec08               sub esp, 8
// 00530a77  53                   push ebx
// 00530a78  8bd9                 mov ebx, ecx
// 00530a7a  8b4314               mov eax, dword ptr [ebx + 0x14]
// 00530a7d  b9ffffff07           mov ecx, 0x7ffffff
// 00530a82  2bc8                 sub ecx, eax
// 00530a84  3bca                 cmp ecx, edx
// 00530a86  7305                 jae 0x530a8d
// 00530a88  e8c3c51800           call 0x6bd050
// 00530a8d  8bc8                 mov ecx, eax
// 00530a8f  d1e9                 shr ecx, 1
// 00530a91  83f908               cmp ecx, 8
// 00530a94  7305                 jae 0x530a9b
// 00530a96  b908000000           mov ecx, 8
// 00530a9b  55                   push ebp
// 00530a9c  56                   push esi
// 00530a9d  57                   push edi
// 00530a9e  3bd1                 cmp edx, ecx
// 00530aa0  7311                 jae 0x530ab3
// 00530aa2  beffffff07           mov esi, 0x7ffffff
// 00530aa7  2bf1                 sub esi, ecx
// 00530aa9  3bc6                 cmp eax, esi
// 00530aab  7706                 ja 0x530ab3
// 00530aad  8bd1                 mov edx, ecx
// 00530aaf  8954241c             mov dword ptr [esp + 0x1c], edx
// 00530ab3  8b7318               mov esi, dword ptr [ebx + 0x18]
// 00530ab6  03c2                 add eax, edx
// 00530ab8  6a00                 push 0
// 00530aba  50                   push eax
// 00530abb  89742418             mov dword ptr [esp + 0x18], esi
// 00530abf  e87cfeefff           call 0x430940
// 00530ac4  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 00530ac7  8944241c             mov dword ptr [esp + 0x1c], eax
// 00530acb  03f6                 add esi, esi
// 00530acd  03f6                 add esi, esi
// 00530acf  8d3c06               lea edi, [esi + eax]
// 00530ad2  8b4314               mov eax, dword ptr [ebx + 0x14]
// 00530ad5  03c0                 add eax, eax
// 00530ad7  03c0                 add eax, eax
// 00530ad9  8d140e               lea edx, [esi + ecx]
// 00530adc  2bc2                 sub eax, edx
// 00530ade  03c1                 add eax, ecx
// 00530ae0  c1f802               sar eax, 2
// 00530ae3  83c408               add esp, 8
// 00530ae6  8d0c8500000000       lea ecx, [eax*4]
// 00530aed  8d2c39               lea ebp, [ecx + edi]
// 00530af0  85c0                 test eax, eax
// 00530af2  760d                 jbe 0x530b01
// 00530af4  51                   push ecx
// 00530af5  52                   push edx
// 00530af6  51                   push ecx
// 00530af7  57                   push edi
// 00530af8  ff15c0b79800         call dword ptr [0x98b7c0]
// 00530afe  83c410               add esp, 0x10
// 00530b01  8b542410             mov edx, dword ptr [esp + 0x10]
// 00530b05  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00530b09  3bd0                 cmp edx, eax
// 00530b0b  7743                 ja 0x530b50
// 00530b0d  8b4310               mov eax, dword ptr [ebx + 0x10]
// 00530b10  c1fe02               sar esi, 2
// 00530b13  8d0cb500000000       lea ecx, [esi*4]
// 00530b1a  8d3c29               lea edi, [ecx + ebp]
// 00530b1d  85f6                 test esi, esi
// 00530b1f  7611                 jbe 0x530b32
// 00530b21  51                   push ecx
// 00530b22  50                   push eax
// 00530b23  51                   push ecx
// 00530b24  55                   push ebp
// 00530b25  ff15c0b79800         call dword ptr [0x98b7c0]
// 00530b2b  8b542420             mov edx, dword ptr [esp + 0x20]
// 00530b2f  83c410               add esp, 0x10
// 00530b32  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00530b36  2bca                 sub ecx, edx
// 00530b38  7408                 je 0x530b42
// 00530b3a  8b542410             mov edx, dword ptr [esp + 0x10]
// 00530b3e  33c0                 xor eax, eax
// 00530b40  f3ab                 rep stosd dword ptr es:[edi], eax
// 00530b42  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 00530b46  85d2                 test edx, edx
// 00530b48  7662                 jbe 0x530bac
// 00530b4a  8bca                 mov ecx, edx
// 00530b4c  8bfd                 mov edi, ebp
// 00530b4e  eb58                 jmp 0x530ba8
// 00530b50  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 00530b53  8d3c8500000000       lea edi, [eax*4]
// 00530b5a  8bc7                 mov eax, edi
// 00530b5c  c1f802               sar eax, 2
// 00530b5f  85c0                 test eax, eax
// 00530b61  7611                 jbe 0x530b74
// 00530b63  03c0                 add eax, eax
// 00530b65  03c0                 add eax, eax
// 00530b67  50                   push eax
// 00530b68  51                   push ecx
// 00530b69  50                   push eax
// 00530b6a  55                   push ebp
// 00530b6b  ff15c0b79800         call dword ptr [0x98b7c0]
// 00530b71  83c410               add esp, 0x10
// 00530b74  8b4310               mov eax, dword ptr [ebx + 0x10]
// 00530b77  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 00530b7b  8d0c07               lea ecx, [edi + eax]
// 00530b7e  2bf1                 sub esi, ecx
// 00530b80  03f0                 add esi, eax
// 00530b82  c1fe02               sar esi, 2
// 00530b85  8d04b500000000       lea eax, [esi*4]
// 00530b8c  8d3c28               lea edi, [eax + ebp]
// 00530b8f  85f6                 test esi, esi
// 00530b91  760d                 jbe 0x530ba0
// 00530b93  50                   push eax
// 00530b94  51                   push ecx
// 00530b95  50                   push eax
// 00530b96  55                   push ebp
// 00530b97  ff15c0b79800         call dword ptr [0x98b7c0]
// 00530b9d  83c410               add esp, 0x10
// 00530ba0  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00530ba4  85c9                 test ecx, ecx
// 00530ba6  7604                 jbe 0x530bac
// 00530ba8  33c0                 xor eax, eax
// 00530baa  f3ab                 rep stosd dword ptr es:[edi], eax
// 00530bac  8b4310               mov eax, dword ptr [ebx + 0x10]
// 00530baf  85c0                 test eax, eax
// 00530bb1  7409                 je 0x530bbc
// 00530bb3  50                   push eax
// 00530bb4  e8a12c2c00           call 0x7f385a
// 00530bb9  83c404               add esp, 4
// 00530bbc  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00530bc0  015314               add dword ptr [ebx + 0x14], edx
// 00530bc3  5f                   pop edi
// 00530bc4  5e                   pop esi
// 00530bc5  896b10               mov dword ptr [ebx + 0x10], ebp
// 00530bc8  5d                   pop ebp
// 00530bc9  5b                   pop ebx
// 00530bca  83c408               add esp, 8
// 00530bcd  c20400               ret 4
// standard library deque<pod32> (function ?_Growmap@?$deque@UE@@V?$allocator@UE@@@std@@@std@@IAEXI@Z)

// stl: deque<pod32>
struct E { int v[8]; };
#include <deque>
template class std::deque<E>;
