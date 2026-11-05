// from server: 100% by auto
// roc 2009-06 004e7260  unit: RBX::Network::DirectPhysicsReceiver  size: 350 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004e7260
//
// 004e7260  51                   push ecx
// 004e7261  8b542408             mov edx, dword ptr [esp + 8]
// 004e7265  53                   push ebx
// 004e7266  8bd9                 mov ebx, ecx
// 004e7268  8b4314               mov eax, dword ptr [ebx + 0x14]
// 004e726b  b9ffffff0f           mov ecx, 0xfffffff
// 004e7270  2bc8                 sub ecx, eax
// 004e7272  3bca                 cmp ecx, edx
// 004e7274  7305                 jae 0x4e727b
// 004e7276  e8f585f4ff           call 0x42f870
// 004e727b  8bc8                 mov ecx, eax
// 004e727d  d1e9                 shr ecx, 1
// 004e727f  83f908               cmp ecx, 8
// 004e7282  7305                 jae 0x4e7289
// 004e7284  b908000000           mov ecx, 8
// 004e7289  55                   push ebp
// 004e728a  56                   push esi
// 004e728b  57                   push edi
// 004e728c  3bd1                 cmp edx, ecx
// 004e728e  7311                 jae 0x4e72a1
// 004e7290  beffffff0f           mov esi, 0xfffffff
// 004e7295  2bf1                 sub esi, ecx
// 004e7297  3bc6                 cmp eax, esi
// 004e7299  7706                 ja 0x4e72a1
// 004e729b  894c2418             mov dword ptr [esp + 0x18], ecx
// 004e729f  8bd1                 mov edx, ecx
// 004e72a1  8b6b18               mov ebp, dword ptr [ebx + 0x18]
// 004e72a4  03c2                 add eax, edx
// 004e72a6  6a00                 push 0
// 004e72a8  50                   push eax
// 004e72a9  c1ed02               shr ebp, 2
// 004e72ac  e84f171100           call 0x5f8a00
// 004e72b1  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 004e72b4  89442418             mov dword ptr [esp + 0x18], eax
// 004e72b8  8d34ad00000000       lea esi, [ebp*4]
// 004e72bf  8d3c06               lea edi, [esi + eax]
// 004e72c2  8b4314               mov eax, dword ptr [ebx + 0x14]
// 004e72c5  03c0                 add eax, eax
// 004e72c7  03c0                 add eax, eax
// 004e72c9  8d140e               lea edx, [esi + ecx]
// 004e72cc  2bc2                 sub eax, edx
// 004e72ce  03c1                 add eax, ecx
// 004e72d0  c1f802               sar eax, 2
// 004e72d3  8d0c8500000000       lea ecx, [eax*4]
// 004e72da  83c408               add esp, 8
// 004e72dd  03f9                 add edi, ecx
// 004e72df  85c0                 test eax, eax
// 004e72e1  7614                 jbe 0x4e72f7
// 004e72e3  51                   push ecx
// 004e72e4  52                   push edx
// 004e72e5  8b542418             mov edx, dword ptr [esp + 0x18]
// 004e72e9  51                   push ecx
// 004e72ea  8d0416               lea eax, [esi + edx]
// 004e72ed  50                   push eax
// 004e72ee  ff155ce98900         call dword ptr [0x89e95c]
// 004e72f4  83c410               add esp, 0x10
// 004e72f7  8b442418             mov eax, dword ptr [esp + 0x18]
// 004e72fb  3be8                 cmp ebp, eax
// 004e72fd  773d                 ja 0x4e733c
// 004e72ff  8b4310               mov eax, dword ptr [ebx + 0x10]
// 004e7302  c1fe02               sar esi, 2
// 004e7305  8bce                 mov ecx, esi
// 004e7307  8d148d00000000       lea edx, [ecx*4]
// 004e730e  8d343a               lea esi, [edx + edi]
// 004e7311  85c9                 test ecx, ecx
// 004e7313  760d                 jbe 0x4e7322
// 004e7315  52                   push edx
// 004e7316  50                   push eax
// 004e7317  52                   push edx
// 004e7318  57                   push edi
// 004e7319  ff155ce98900         call dword ptr [0x89e95c]
// 004e731f  83c410               add esp, 0x10
// 004e7322  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004e7326  2bcd                 sub ecx, ebp
// 004e7328  7406                 je 0x4e7330
// 004e732a  33c0                 xor eax, eax
// 004e732c  8bfe                 mov edi, esi
// 004e732e  f3ab                 rep stosd dword ptr es:[edi], eax
// 004e7330  85ed                 test ebp, ebp
// 004e7332  7664                 jbe 0x4e7398
// 004e7334  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004e7338  8bcd                 mov ecx, ebp
// 004e733a  eb58                 jmp 0x4e7394
// 004e733c  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 004e733f  8d2c8500000000       lea ebp, [eax*4]
// 004e7346  8bc5                 mov eax, ebp
// 004e7348  c1f802               sar eax, 2
// 004e734b  85c0                 test eax, eax
// 004e734d  7611                 jbe 0x4e7360
// 004e734f  03c0                 add eax, eax
// 004e7351  03c0                 add eax, eax
// 004e7353  50                   push eax
// 004e7354  51                   push ecx
// 004e7355  50                   push eax
// 004e7356  57                   push edi
// 004e7357  ff155ce98900         call dword ptr [0x89e95c]
// 004e735d  83c410               add esp, 0x10
// 004e7360  8b4310               mov eax, dword ptr [ebx + 0x10]
// 004e7363  8b542410             mov edx, dword ptr [esp + 0x10]
// 004e7367  8d0c28               lea ecx, [eax + ebp]
// 004e736a  2bf1                 sub esi, ecx
// 004e736c  03f0                 add esi, eax
// 004e736e  c1fe02               sar esi, 2
// 004e7371  8d04b500000000       lea eax, [esi*4]
// 004e7378  8d3c10               lea edi, [eax + edx]
// 004e737b  85f6                 test esi, esi
// 004e737d  760d                 jbe 0x4e738c
// 004e737f  50                   push eax
// 004e7380  51                   push ecx
// 004e7381  50                   push eax
// 004e7382  52                   push edx
// 004e7383  ff155ce98900         call dword ptr [0x89e95c]
// 004e7389  83c410               add esp, 0x10
// 004e738c  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004e7390  85c9                 test ecx, ecx
// 004e7392  7604                 jbe 0x4e7398
// 004e7394  33c0                 xor eax, eax
// 004e7396  f3ab                 rep stosd dword ptr es:[edi], eax
// 004e7398  8b4310               mov eax, dword ptr [ebx + 0x10]
// 004e739b  5f                   pop edi
// 004e739c  5e                   pop esi
// 004e739d  5d                   pop ebp
// 004e739e  85c0                 test eax, eax
// 004e73a0  7409                 je 0x4e73ab
// 004e73a2  50                   push eax
// 004e73a3  e88a162300           call 0x718a32
// 004e73a8  83c404               add esp, 4
// 004e73ab  8b442404             mov eax, dword ptr [esp + 4]
// 004e73af  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004e73b3  014b14               add dword ptr [ebx + 0x14], ecx
// 004e73b6  894310               mov dword ptr [ebx + 0x10], eax
// 004e73b9  5b                   pop ebx
// 004e73ba  59                   pop ecx
// 004e73bb  c20400               ret 4
// standard library deque<ptr> (function ?_Growmap@?$deque@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEXI@Z)

// stl: deque<ptr>
struct T; typedef T* E;
#include <deque>
template class std::deque<E>;
