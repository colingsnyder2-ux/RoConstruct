// from server: 100% by auto
// roc 2009-12 00430f10  unit: COutputView  size: 352 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00430f10
//
// 00430f10  8b542404             mov edx, dword ptr [esp + 4]
// 00430f14  83ec08               sub esp, 8
// 00430f17  53                   push ebx
// 00430f18  8bd9                 mov ebx, ecx
// 00430f1a  8b4314               mov eax, dword ptr [ebx + 0x14]
// 00430f1d  b966666606           mov ecx, 0x6666666
// 00430f22  2bc8                 sub ecx, eax
// 00430f24  3bca                 cmp ecx, edx
// 00430f26  7305                 jae 0x430f2d
// 00430f28  e823c12800           call 0x6bd050
// 00430f2d  8bc8                 mov ecx, eax
// 00430f2f  d1e9                 shr ecx, 1
// 00430f31  83f908               cmp ecx, 8
// 00430f34  7305                 jae 0x430f3b
// 00430f36  b908000000           mov ecx, 8
// 00430f3b  55                   push ebp
// 00430f3c  56                   push esi
// 00430f3d  57                   push edi
// 00430f3e  3bd1                 cmp edx, ecx
// 00430f40  7311                 jae 0x430f53
// 00430f42  be66666606           mov esi, 0x6666666
// 00430f47  2bf1                 sub esi, ecx
// 00430f49  3bc6                 cmp eax, esi
// 00430f4b  7706                 ja 0x430f53
// 00430f4d  8bd1                 mov edx, ecx
// 00430f4f  8954241c             mov dword ptr [esp + 0x1c], edx
// 00430f53  8b7318               mov esi, dword ptr [ebx + 0x18]
// 00430f56  03c2                 add eax, edx
// 00430f58  6a00                 push 0
// 00430f5a  50                   push eax
// 00430f5b  89742418             mov dword ptr [esp + 0x18], esi
// 00430f5f  e8dcf9ffff           call 0x430940
// 00430f64  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 00430f67  8944241c             mov dword ptr [esp + 0x1c], eax
// 00430f6b  03f6                 add esi, esi
// 00430f6d  03f6                 add esi, esi
// 00430f6f  8d3c06               lea edi, [esi + eax]
// 00430f72  8b4314               mov eax, dword ptr [ebx + 0x14]
// 00430f75  03c0                 add eax, eax
// 00430f77  03c0                 add eax, eax
// 00430f79  8d140e               lea edx, [esi + ecx]
// 00430f7c  2bc2                 sub eax, edx
// 00430f7e  03c1                 add eax, ecx
// 00430f80  c1f802               sar eax, 2
// 00430f83  83c408               add esp, 8
// 00430f86  8d0c8500000000       lea ecx, [eax*4]
// 00430f8d  8d2c39               lea ebp, [ecx + edi]
// 00430f90  85c0                 test eax, eax
// 00430f92  760d                 jbe 0x430fa1
// 00430f94  51                   push ecx
// 00430f95  52                   push edx
// 00430f96  51                   push ecx
// 00430f97  57                   push edi
// 00430f98  ff15c0b79800         call dword ptr [0x98b7c0]
// 00430f9e  83c410               add esp, 0x10
// 00430fa1  8b542410             mov edx, dword ptr [esp + 0x10]
// 00430fa5  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00430fa9  3bd0                 cmp edx, eax
// 00430fab  7743                 ja 0x430ff0
// 00430fad  8b4310               mov eax, dword ptr [ebx + 0x10]
// 00430fb0  c1fe02               sar esi, 2
// 00430fb3  8d0cb500000000       lea ecx, [esi*4]
// 00430fba  8d3c29               lea edi, [ecx + ebp]
// 00430fbd  85f6                 test esi, esi
// 00430fbf  7611                 jbe 0x430fd2
// 00430fc1  51                   push ecx
// 00430fc2  50                   push eax
// 00430fc3  51                   push ecx
// 00430fc4  55                   push ebp
// 00430fc5  ff15c0b79800         call dword ptr [0x98b7c0]
// 00430fcb  8b542420             mov edx, dword ptr [esp + 0x20]
// 00430fcf  83c410               add esp, 0x10
// 00430fd2  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00430fd6  2bca                 sub ecx, edx
// 00430fd8  7408                 je 0x430fe2
// 00430fda  8b542410             mov edx, dword ptr [esp + 0x10]
// 00430fde  33c0                 xor eax, eax
// 00430fe0  f3ab                 rep stosd dword ptr es:[edi], eax
// 00430fe2  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 00430fe6  85d2                 test edx, edx
// 00430fe8  7662                 jbe 0x43104c
// 00430fea  8bca                 mov ecx, edx
// 00430fec  8bfd                 mov edi, ebp
// 00430fee  eb58                 jmp 0x431048
// 00430ff0  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 00430ff3  8d3c8500000000       lea edi, [eax*4]
// 00430ffa  8bc7                 mov eax, edi
// 00430ffc  c1f802               sar eax, 2
// 00430fff  85c0                 test eax, eax
// 00431001  7611                 jbe 0x431014
// 00431003  03c0                 add eax, eax
// 00431005  03c0                 add eax, eax
// 00431007  50                   push eax
// 00431008  51                   push ecx
// 00431009  50                   push eax
// 0043100a  55                   push ebp
// 0043100b  ff15c0b79800         call dword ptr [0x98b7c0]
// 00431011  83c410               add esp, 0x10
// 00431014  8b4310               mov eax, dword ptr [ebx + 0x10]
// 00431017  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0043101b  8d0c07               lea ecx, [edi + eax]
// 0043101e  2bf1                 sub esi, ecx
// 00431020  03f0                 add esi, eax
// 00431022  c1fe02               sar esi, 2
// 00431025  8d04b500000000       lea eax, [esi*4]
// 0043102c  8d3c28               lea edi, [eax + ebp]
// 0043102f  85f6                 test esi, esi
// 00431031  760d                 jbe 0x431040
// 00431033  50                   push eax
// 00431034  51                   push ecx
// 00431035  50                   push eax
// 00431036  55                   push ebp
// 00431037  ff15c0b79800         call dword ptr [0x98b7c0]
// 0043103d  83c410               add esp, 0x10
// 00431040  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00431044  85c9                 test ecx, ecx
// 00431046  7604                 jbe 0x43104c
// 00431048  33c0                 xor eax, eax
// 0043104a  f3ab                 rep stosd dword ptr es:[edi], eax
// 0043104c  8b4310               mov eax, dword ptr [ebx + 0x10]
// 0043104f  85c0                 test eax, eax
// 00431051  7409                 je 0x43105c
// 00431053  50                   push eax
// 00431054  e801283c00           call 0x7f385a
// 00431059  83c404               add esp, 4
// 0043105c  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00431060  015314               add dword ptr [ebx + 0x14], edx
// 00431063  5f                   pop edi
// 00431064  5e                   pop esi
// 00431065  896b10               mov dword ptr [ebx + 0x10], ebp
// 00431068  5d                   pop ebp
// 00431069  5b                   pop ebx
// 0043106a  83c408               add esp, 8
// 0043106d  c20400               ret 4
// standard library deque<pod40> (function ?_Growmap@?$deque@UE@@V?$allocator@UE@@@std@@@std@@IAEXI@Z)

// stl: deque<pod40>
struct E { int v[10]; };
#include <deque>
template class std::deque<E>;
