// from server: 100% by auto
// roc 2009-06 00418220  unit: RBX::VTool::?$FactoryProduct::Creator  size: 352 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00418220
//
// 00418220  8b542404             mov edx, dword ptr [esp + 4]
// 00418224  83ec08               sub esp, 8
// 00418227  53                   push ebx
// 00418228  8bd9                 mov ebx, ecx
// 0041822a  8b4314               mov eax, dword ptr [ebx + 0x14]
// 0041822d  b949922409           mov ecx, 0x9249249
// 00418232  2bc8                 sub ecx, eax
// 00418234  3bca                 cmp ecx, edx
// 00418236  7305                 jae 0x41823d
// 00418238  e833760100           call 0x42f870
// 0041823d  8bc8                 mov ecx, eax
// 0041823f  d1e9                 shr ecx, 1
// 00418241  83f908               cmp ecx, 8
// 00418244  7305                 jae 0x41824b
// 00418246  b908000000           mov ecx, 8
// 0041824b  55                   push ebp
// 0041824c  56                   push esi
// 0041824d  57                   push edi
// 0041824e  3bd1                 cmp edx, ecx
// 00418250  7311                 jae 0x418263
// 00418252  be49922409           mov esi, 0x9249249
// 00418257  2bf1                 sub esi, ecx
// 00418259  3bc6                 cmp eax, esi
// 0041825b  7706                 ja 0x418263
// 0041825d  8bd1                 mov edx, ecx
// 0041825f  8954241c             mov dword ptr [esp + 0x1c], edx
// 00418263  8b7318               mov esi, dword ptr [ebx + 0x18]
// 00418266  03c2                 add eax, edx
// 00418268  6a00                 push 0
// 0041826a  50                   push eax
// 0041826b  89742418             mov dword ptr [esp + 0x18], esi
// 0041826f  e88c071e00           call 0x5f8a00
// 00418274  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 00418277  8944241c             mov dword ptr [esp + 0x1c], eax
// 0041827b  03f6                 add esi, esi
// 0041827d  03f6                 add esi, esi
// 0041827f  8d3c06               lea edi, [esi + eax]
// 00418282  8b4314               mov eax, dword ptr [ebx + 0x14]
// 00418285  03c0                 add eax, eax
// 00418287  03c0                 add eax, eax
// 00418289  8d140e               lea edx, [esi + ecx]
// 0041828c  2bc2                 sub eax, edx
// 0041828e  03c1                 add eax, ecx
// 00418290  c1f802               sar eax, 2
// 00418293  83c408               add esp, 8
// 00418296  8d0c8500000000       lea ecx, [eax*4]
// 0041829d  8d2c39               lea ebp, [ecx + edi]
// 004182a0  85c0                 test eax, eax
// 004182a2  760d                 jbe 0x4182b1
// 004182a4  51                   push ecx
// 004182a5  52                   push edx
// 004182a6  51                   push ecx
// 004182a7  57                   push edi
// 004182a8  ff155ce98900         call dword ptr [0x89e95c]
// 004182ae  83c410               add esp, 0x10
// 004182b1  8b542410             mov edx, dword ptr [esp + 0x10]
// 004182b5  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004182b9  3bd0                 cmp edx, eax
// 004182bb  7743                 ja 0x418300
// 004182bd  8b4310               mov eax, dword ptr [ebx + 0x10]
// 004182c0  c1fe02               sar esi, 2
// 004182c3  8d0cb500000000       lea ecx, [esi*4]
// 004182ca  8d3c29               lea edi, [ecx + ebp]
// 004182cd  85f6                 test esi, esi
// 004182cf  7611                 jbe 0x4182e2
// 004182d1  51                   push ecx
// 004182d2  50                   push eax
// 004182d3  51                   push ecx
// 004182d4  55                   push ebp
// 004182d5  ff155ce98900         call dword ptr [0x89e95c]
// 004182db  8b542420             mov edx, dword ptr [esp + 0x20]
// 004182df  83c410               add esp, 0x10
// 004182e2  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004182e6  2bca                 sub ecx, edx
// 004182e8  7408                 je 0x4182f2
// 004182ea  8b542410             mov edx, dword ptr [esp + 0x10]
// 004182ee  33c0                 xor eax, eax
// 004182f0  f3ab                 rep stosd dword ptr es:[edi], eax
// 004182f2  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 004182f6  85d2                 test edx, edx
// 004182f8  7662                 jbe 0x41835c
// 004182fa  8bca                 mov ecx, edx
// 004182fc  8bfd                 mov edi, ebp
// 004182fe  eb58                 jmp 0x418358
// 00418300  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 00418303  8d3c8500000000       lea edi, [eax*4]
// 0041830a  8bc7                 mov eax, edi
// 0041830c  c1f802               sar eax, 2
// 0041830f  85c0                 test eax, eax
// 00418311  7611                 jbe 0x418324
// 00418313  03c0                 add eax, eax
// 00418315  03c0                 add eax, eax
// 00418317  50                   push eax
// 00418318  51                   push ecx
// 00418319  50                   push eax
// 0041831a  55                   push ebp
// 0041831b  ff155ce98900         call dword ptr [0x89e95c]
// 00418321  83c410               add esp, 0x10
// 00418324  8b4310               mov eax, dword ptr [ebx + 0x10]
// 00418327  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0041832b  8d0c07               lea ecx, [edi + eax]
// 0041832e  2bf1                 sub esi, ecx
// 00418330  03f0                 add esi, eax
// 00418332  c1fe02               sar esi, 2
// 00418335  8d04b500000000       lea eax, [esi*4]
// 0041833c  8d3c28               lea edi, [eax + ebp]
// 0041833f  85f6                 test esi, esi
// 00418341  760d                 jbe 0x418350
// 00418343  50                   push eax
// 00418344  51                   push ecx
// 00418345  50                   push eax
// 00418346  55                   push ebp
// 00418347  ff155ce98900         call dword ptr [0x89e95c]
// 0041834d  83c410               add esp, 0x10
// 00418350  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00418354  85c9                 test ecx, ecx
// 00418356  7604                 jbe 0x41835c
// 00418358  33c0                 xor eax, eax
// 0041835a  f3ab                 rep stosd dword ptr es:[edi], eax
// 0041835c  8b4310               mov eax, dword ptr [ebx + 0x10]
// 0041835f  85c0                 test eax, eax
// 00418361  7409                 je 0x41836c
// 00418363  50                   push eax
// 00418364  e8c9063000           call 0x718a32
// 00418369  83c404               add esp, 4
// 0041836c  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00418370  015314               add dword ptr [ebx + 0x14], edx
// 00418373  5f                   pop edi
// 00418374  5e                   pop esi
// 00418375  896b10               mov dword ptr [ebx + 0x10], ebp
// 00418378  5d                   pop ebp
// 00418379  5b                   pop ebx
// 0041837a  83c408               add esp, 8
// 0041837d  c20400               ret 4
// standard library deque<string> (function ?_Growmap@?$deque@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEXI@Z)

// stl: deque<string>
#include <string>
typedef std::string E;
#include <deque>
template class std::deque<E>;
