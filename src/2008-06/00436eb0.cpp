// from server: 100% by auto
// roc 2008-06 00436eb0  unit: CStandardOutputView  size: 352 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00436eb0
//
// 00436eb0  8b542404             mov edx, dword ptr [esp + 4]
// 00436eb4  83ec08               sub esp, 8
// 00436eb7  53                   push ebx
// 00436eb8  8bd9                 mov ebx, ecx
// 00436eba  8b4314               mov eax, dword ptr [ebx + 0x14]
// 00436ebd  b966666606           mov ecx, 0x6666666
// 00436ec2  2bc8                 sub ecx, eax
// 00436ec4  3bca                 cmp ecx, edx
// 00436ec6  7305                 jae 0x436ecd
// 00436ec8  e843fb0d00           call 0x516a10
// 00436ecd  8bc8                 mov ecx, eax
// 00436ecf  d1e9                 shr ecx, 1
// 00436ed1  83f908               cmp ecx, 8
// 00436ed4  7305                 jae 0x436edb
// 00436ed6  b908000000           mov ecx, 8
// 00436edb  55                   push ebp
// 00436edc  56                   push esi
// 00436edd  57                   push edi
// 00436ede  3bd1                 cmp edx, ecx
// 00436ee0  7311                 jae 0x436ef3
// 00436ee2  be66666606           mov esi, 0x6666666
// 00436ee7  2bf1                 sub esi, ecx
// 00436ee9  3bc6                 cmp eax, esi
// 00436eeb  7706                 ja 0x436ef3
// 00436eed  8bd1                 mov edx, ecx
// 00436eef  8954241c             mov dword ptr [esp + 0x1c], edx
// 00436ef3  8b7318               mov esi, dword ptr [ebx + 0x18]
// 00436ef6  03c2                 add eax, edx
// 00436ef8  6a00                 push 0
// 00436efa  50                   push eax
// 00436efb  89742418             mov dword ptr [esp + 0x18], esi
// 00436eff  e84c9cfeff           call 0x420b50
// 00436f04  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 00436f07  8944241c             mov dword ptr [esp + 0x1c], eax
// 00436f0b  03f6                 add esi, esi
// 00436f0d  03f6                 add esi, esi
// 00436f0f  8d3c06               lea edi, [esi + eax]
// 00436f12  8b4314               mov eax, dword ptr [ebx + 0x14]
// 00436f15  03c0                 add eax, eax
// 00436f17  03c0                 add eax, eax
// 00436f19  8d140e               lea edx, [esi + ecx]
// 00436f1c  2bc2                 sub eax, edx
// 00436f1e  03c1                 add eax, ecx
// 00436f20  c1f802               sar eax, 2
// 00436f23  83c408               add esp, 8
// 00436f26  8d0c8500000000       lea ecx, [eax*4]
// 00436f2d  8d2c39               lea ebp, [ecx + edi]
// 00436f30  85c0                 test eax, eax
// 00436f32  760d                 jbe 0x436f41
// 00436f34  51                   push ecx
// 00436f35  52                   push edx
// 00436f36  51                   push ecx
// 00436f37  57                   push edi
// 00436f38  ff1550288000         call dword ptr [0x802850]
// 00436f3e  83c410               add esp, 0x10
// 00436f41  8b542410             mov edx, dword ptr [esp + 0x10]
// 00436f45  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00436f49  3bd0                 cmp edx, eax
// 00436f4b  7743                 ja 0x436f90
// 00436f4d  8b4310               mov eax, dword ptr [ebx + 0x10]
// 00436f50  c1fe02               sar esi, 2
// 00436f53  8d0cb500000000       lea ecx, [esi*4]
// 00436f5a  8d3c29               lea edi, [ecx + ebp]
// 00436f5d  85f6                 test esi, esi
// 00436f5f  7611                 jbe 0x436f72
// 00436f61  51                   push ecx
// 00436f62  50                   push eax
// 00436f63  51                   push ecx
// 00436f64  55                   push ebp
// 00436f65  ff1550288000         call dword ptr [0x802850]
// 00436f6b  8b542420             mov edx, dword ptr [esp + 0x20]
// 00436f6f  83c410               add esp, 0x10
// 00436f72  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00436f76  2bca                 sub ecx, edx
// 00436f78  7408                 je 0x436f82
// 00436f7a  8b542410             mov edx, dword ptr [esp + 0x10]
// 00436f7e  33c0                 xor eax, eax
// 00436f80  f3ab                 rep stosd dword ptr es:[edi], eax
// 00436f82  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 00436f86  85d2                 test edx, edx
// 00436f88  7662                 jbe 0x436fec
// 00436f8a  8bca                 mov ecx, edx
// 00436f8c  8bfd                 mov edi, ebp
// 00436f8e  eb58                 jmp 0x436fe8
// 00436f90  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 00436f93  8d3c8500000000       lea edi, [eax*4]
// 00436f9a  8bc7                 mov eax, edi
// 00436f9c  c1f802               sar eax, 2
// 00436f9f  85c0                 test eax, eax
// 00436fa1  7611                 jbe 0x436fb4
// 00436fa3  03c0                 add eax, eax
// 00436fa5  03c0                 add eax, eax
// 00436fa7  50                   push eax
// 00436fa8  51                   push ecx
// 00436fa9  50                   push eax
// 00436faa  55                   push ebp
// 00436fab  ff1550288000         call dword ptr [0x802850]
// 00436fb1  83c410               add esp, 0x10
// 00436fb4  8b4310               mov eax, dword ptr [ebx + 0x10]
// 00436fb7  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 00436fbb  8d0c07               lea ecx, [edi + eax]
// 00436fbe  2bf1                 sub esi, ecx
// 00436fc0  03f0                 add esi, eax
// 00436fc2  c1fe02               sar esi, 2
// 00436fc5  8d04b500000000       lea eax, [esi*4]
// 00436fcc  8d3c28               lea edi, [eax + ebp]
// 00436fcf  85f6                 test esi, esi
// 00436fd1  760d                 jbe 0x436fe0
// 00436fd3  50                   push eax
// 00436fd4  51                   push ecx
// 00436fd5  50                   push eax
// 00436fd6  55                   push ebp
// 00436fd7  ff1550288000         call dword ptr [0x802850]
// 00436fdd  83c410               add esp, 0x10
// 00436fe0  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00436fe4  85c9                 test ecx, ecx
// 00436fe6  7604                 jbe 0x436fec
// 00436fe8  33c0                 xor eax, eax
// 00436fea  f3ab                 rep stosd dword ptr es:[edi], eax
// 00436fec  8b4310               mov eax, dword ptr [ebx + 0x10]
// 00436fef  85c0                 test eax, eax
// 00436ff1  7409                 je 0x436ffc
// 00436ff3  50                   push eax
// 00436ff4  e881962600           call 0x6a067a
// 00436ff9  83c404               add esp, 4
// 00436ffc  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00437000  015314               add dword ptr [ebx + 0x14], edx
// 00437003  5f                   pop edi
// 00437004  5e                   pop esi
// 00437005  896b10               mov dword ptr [ebx + 0x10], ebp
// 00437008  5d                   pop ebp
// 00437009  5b                   pop ebx
// 0043700a  83c408               add esp, 8
// 0043700d  c20400               ret 4
// standard library deque<pod40> (function ?_Growmap@?$deque@UE@@V?$allocator@UE@@@std@@@std@@IAEXI@Z)

// stl: deque<pod40>
struct E { int v[10]; };
#include <deque>
template class std::deque<E>;
