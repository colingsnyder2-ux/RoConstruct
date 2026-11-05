// from server: 100% by auto
// roc 2010-06 004c4db0  unit: RBX::VInstance::?$NonFactoryProduct  size: 352 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004c4db0
//
// 004c4db0  8b542404             mov edx, dword ptr [esp + 4]
// 004c4db4  83ec08               sub esp, 8
// 004c4db7  53                   push ebx
// 004c4db8  8bd9                 mov ebx, ecx
// 004c4dba  8b4314               mov eax, dword ptr [ebx + 0x14]
// 004c4dbd  b9ffffff03           mov ecx, 0x3ffffff
// 004c4dc2  2bc8                 sub ecx, eax
// 004c4dc4  3bca                 cmp ecx, edx
// 004c4dc6  7305                 jae 0x4c4dcd
// 004c4dc8  e803b0ffff           call 0x4bfdd0
// 004c4dcd  8bc8                 mov ecx, eax
// 004c4dcf  d1e9                 shr ecx, 1
// 004c4dd1  83f908               cmp ecx, 8
// 004c4dd4  7305                 jae 0x4c4ddb
// 004c4dd6  b908000000           mov ecx, 8
// 004c4ddb  55                   push ebp
// 004c4ddc  56                   push esi
// 004c4ddd  57                   push edi
// 004c4dde  3bd1                 cmp edx, ecx
// 004c4de0  7311                 jae 0x4c4df3
// 004c4de2  beffffff03           mov esi, 0x3ffffff
// 004c4de7  2bf1                 sub esi, ecx
// 004c4de9  3bc6                 cmp eax, esi
// 004c4deb  7706                 ja 0x4c4df3
// 004c4ded  8bd1                 mov edx, ecx
// 004c4def  8954241c             mov dword ptr [esp + 0x1c], edx
// 004c4df3  8b7318               mov esi, dword ptr [ebx + 0x18]
// 004c4df6  03c2                 add eax, edx
// 004c4df8  6a00                 push 0
// 004c4dfa  50                   push eax
// 004c4dfb  89742418             mov dword ptr [esp + 0x18], esi
// 004c4dff  e80c054100           call 0x8d5310
// 004c4e04  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 004c4e07  8944241c             mov dword ptr [esp + 0x1c], eax
// 004c4e0b  03f6                 add esi, esi
// 004c4e0d  03f6                 add esi, esi
// 004c4e0f  8d3c06               lea edi, [esi + eax]
// 004c4e12  8b4314               mov eax, dword ptr [ebx + 0x14]
// 004c4e15  03c0                 add eax, eax
// 004c4e17  03c0                 add eax, eax
// 004c4e19  8d140e               lea edx, [esi + ecx]
// 004c4e1c  2bc2                 sub eax, edx
// 004c4e1e  03c1                 add eax, ecx
// 004c4e20  c1f802               sar eax, 2
// 004c4e23  83c408               add esp, 8
// 004c4e26  8d0c8500000000       lea ecx, [eax*4]
// 004c4e2d  8d2c39               lea ebp, [ecx + edi]
// 004c4e30  85c0                 test eax, eax
// 004c4e32  760d                 jbe 0x4c4e41
// 004c4e34  51                   push ecx
// 004c4e35  52                   push edx
// 004c4e36  51                   push ecx
// 004c4e37  57                   push edi
// 004c4e38  ff1580a89e00         call dword ptr [0x9ea880]
// 004c4e3e  83c410               add esp, 0x10
// 004c4e41  8b542410             mov edx, dword ptr [esp + 0x10]
// 004c4e45  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004c4e49  3bd0                 cmp edx, eax
// 004c4e4b  7743                 ja 0x4c4e90
// 004c4e4d  8b4310               mov eax, dword ptr [ebx + 0x10]
// 004c4e50  c1fe02               sar esi, 2
// 004c4e53  8d0cb500000000       lea ecx, [esi*4]
// 004c4e5a  8d3c29               lea edi, [ecx + ebp]
// 004c4e5d  85f6                 test esi, esi
// 004c4e5f  7611                 jbe 0x4c4e72
// 004c4e61  51                   push ecx
// 004c4e62  50                   push eax
// 004c4e63  51                   push ecx
// 004c4e64  55                   push ebp
// 004c4e65  ff1580a89e00         call dword ptr [0x9ea880]
// 004c4e6b  8b542420             mov edx, dword ptr [esp + 0x20]
// 004c4e6f  83c410               add esp, 0x10
// 004c4e72  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004c4e76  2bca                 sub ecx, edx
// 004c4e78  7408                 je 0x4c4e82
// 004c4e7a  8b542410             mov edx, dword ptr [esp + 0x10]
// 004c4e7e  33c0                 xor eax, eax
// 004c4e80  f3ab                 rep stosd dword ptr es:[edi], eax
// 004c4e82  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 004c4e86  85d2                 test edx, edx
// 004c4e88  7662                 jbe 0x4c4eec
// 004c4e8a  8bca                 mov ecx, edx
// 004c4e8c  8bfd                 mov edi, ebp
// 004c4e8e  eb58                 jmp 0x4c4ee8
// 004c4e90  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 004c4e93  8d3c8500000000       lea edi, [eax*4]
// 004c4e9a  8bc7                 mov eax, edi
// 004c4e9c  c1f802               sar eax, 2
// 004c4e9f  85c0                 test eax, eax
// 004c4ea1  7611                 jbe 0x4c4eb4
// 004c4ea3  03c0                 add eax, eax
// 004c4ea5  03c0                 add eax, eax
// 004c4ea7  50                   push eax
// 004c4ea8  51                   push ecx
// 004c4ea9  50                   push eax
// 004c4eaa  55                   push ebp
// 004c4eab  ff1580a89e00         call dword ptr [0x9ea880]
// 004c4eb1  83c410               add esp, 0x10
// 004c4eb4  8b4310               mov eax, dword ptr [ebx + 0x10]
// 004c4eb7  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 004c4ebb  8d0c07               lea ecx, [edi + eax]
// 004c4ebe  2bf1                 sub esi, ecx
// 004c4ec0  03f0                 add esi, eax
// 004c4ec2  c1fe02               sar esi, 2
// 004c4ec5  8d04b500000000       lea eax, [esi*4]
// 004c4ecc  8d3c28               lea edi, [eax + ebp]
// 004c4ecf  85f6                 test esi, esi
// 004c4ed1  760d                 jbe 0x4c4ee0
// 004c4ed3  50                   push eax
// 004c4ed4  51                   push ecx
// 004c4ed5  50                   push eax
// 004c4ed6  55                   push ebp
// 004c4ed7  ff1580a89e00         call dword ptr [0x9ea880]
// 004c4edd  83c410               add esp, 0x10
// 004c4ee0  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004c4ee4  85c9                 test ecx, ecx
// 004c4ee6  7604                 jbe 0x4c4eec
// 004c4ee8  33c0                 xor eax, eax
// 004c4eea  f3ab                 rep stosd dword ptr es:[edi], eax
// 004c4eec  8b4310               mov eax, dword ptr [ebx + 0x10]
// 004c4eef  85c0                 test eax, eax
// 004c4ef1  7409                 je 0x4c4efc
// 004c4ef3  50                   push eax
// 004c4ef4  e8a12a2e00           call 0x7a799a
// 004c4ef9  83c404               add esp, 4
// 004c4efc  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 004c4f00  015314               add dword ptr [ebx + 0x14], edx
// 004c4f03  5f                   pop edi
// 004c4f04  5e                   pop esi
// 004c4f05  896b10               mov dword ptr [ebx + 0x10], ebp
// 004c4f08  5d                   pop ebp
// 004c4f09  5b                   pop ebx
// 004c4f0a  83c408               add esp, 8
// 004c4f0d  c20400               ret 4
// standard library deque<pod64> (function ?_Growmap@?$deque@UE@@V?$allocator@UE@@@std@@@std@@IAEXI@Z)

// stl: deque<pod64>
struct E { int v[16]; };
#include <deque>
template class std::deque<E>;
