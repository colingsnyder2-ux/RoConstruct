// from server: 100% by auto
// roc 2008-06 004192a0  unit: VCLuaFunction::?$CComObject  size: 352 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004192a0
//
// 004192a0  8b542404             mov edx, dword ptr [esp + 4]
// 004192a4  83ec08               sub esp, 8
// 004192a7  53                   push ebx
// 004192a8  8bd9                 mov ebx, ecx
// 004192aa  8b4314               mov eax, dword ptr [ebx + 0x14]
// 004192ad  b9ffffff07           mov ecx, 0x7ffffff
// 004192b2  2bc8                 sub ecx, eax
// 004192b4  3bca                 cmp ecx, edx
// 004192b6  7305                 jae 0x4192bd
// 004192b8  e853d70f00           call 0x516a10
// 004192bd  8bc8                 mov ecx, eax
// 004192bf  d1e9                 shr ecx, 1
// 004192c1  83f908               cmp ecx, 8
// 004192c4  7305                 jae 0x4192cb
// 004192c6  b908000000           mov ecx, 8
// 004192cb  55                   push ebp
// 004192cc  56                   push esi
// 004192cd  57                   push edi
// 004192ce  3bd1                 cmp edx, ecx
// 004192d0  7311                 jae 0x4192e3
// 004192d2  beffffff07           mov esi, 0x7ffffff
// 004192d7  2bf1                 sub esi, ecx
// 004192d9  3bc6                 cmp eax, esi
// 004192db  7706                 ja 0x4192e3
// 004192dd  8bd1                 mov edx, ecx
// 004192df  8954241c             mov dword ptr [esp + 0x1c], edx
// 004192e3  8b7318               mov esi, dword ptr [ebx + 0x18]
// 004192e6  03c2                 add eax, edx
// 004192e8  6a00                 push 0
// 004192ea  50                   push eax
// 004192eb  89742418             mov dword ptr [esp + 0x18], esi
// 004192ef  e85c780000           call 0x420b50
// 004192f4  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 004192f7  8944241c             mov dword ptr [esp + 0x1c], eax
// 004192fb  03f6                 add esi, esi
// 004192fd  03f6                 add esi, esi
// 004192ff  8d3c06               lea edi, [esi + eax]
// 00419302  8b4314               mov eax, dword ptr [ebx + 0x14]
// 00419305  03c0                 add eax, eax
// 00419307  03c0                 add eax, eax
// 00419309  8d140e               lea edx, [esi + ecx]
// 0041930c  2bc2                 sub eax, edx
// 0041930e  03c1                 add eax, ecx
// 00419310  c1f802               sar eax, 2
// 00419313  83c408               add esp, 8
// 00419316  8d0c8500000000       lea ecx, [eax*4]
// 0041931d  8d2c39               lea ebp, [ecx + edi]
// 00419320  85c0                 test eax, eax
// 00419322  760d                 jbe 0x419331
// 00419324  51                   push ecx
// 00419325  52                   push edx
// 00419326  51                   push ecx
// 00419327  57                   push edi
// 00419328  ff1550288000         call dword ptr [0x802850]
// 0041932e  83c410               add esp, 0x10
// 00419331  8b542410             mov edx, dword ptr [esp + 0x10]
// 00419335  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00419339  3bd0                 cmp edx, eax
// 0041933b  7743                 ja 0x419380
// 0041933d  8b4310               mov eax, dword ptr [ebx + 0x10]
// 00419340  c1fe02               sar esi, 2
// 00419343  8d0cb500000000       lea ecx, [esi*4]
// 0041934a  8d3c29               lea edi, [ecx + ebp]
// 0041934d  85f6                 test esi, esi
// 0041934f  7611                 jbe 0x419362
// 00419351  51                   push ecx
// 00419352  50                   push eax
// 00419353  51                   push ecx
// 00419354  55                   push ebp
// 00419355  ff1550288000         call dword ptr [0x802850]
// 0041935b  8b542420             mov edx, dword ptr [esp + 0x20]
// 0041935f  83c410               add esp, 0x10
// 00419362  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00419366  2bca                 sub ecx, edx
// 00419368  7408                 je 0x419372
// 0041936a  8b542410             mov edx, dword ptr [esp + 0x10]
// 0041936e  33c0                 xor eax, eax
// 00419370  f3ab                 rep stosd dword ptr es:[edi], eax
// 00419372  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 00419376  85d2                 test edx, edx
// 00419378  7662                 jbe 0x4193dc
// 0041937a  8bca                 mov ecx, edx
// 0041937c  8bfd                 mov edi, ebp
// 0041937e  eb58                 jmp 0x4193d8
// 00419380  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 00419383  8d3c8500000000       lea edi, [eax*4]
// 0041938a  8bc7                 mov eax, edi
// 0041938c  c1f802               sar eax, 2
// 0041938f  85c0                 test eax, eax
// 00419391  7611                 jbe 0x4193a4
// 00419393  03c0                 add eax, eax
// 00419395  03c0                 add eax, eax
// 00419397  50                   push eax
// 00419398  51                   push ecx
// 00419399  50                   push eax
// 0041939a  55                   push ebp
// 0041939b  ff1550288000         call dword ptr [0x802850]
// 004193a1  83c410               add esp, 0x10
// 004193a4  8b4310               mov eax, dword ptr [ebx + 0x10]
// 004193a7  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 004193ab  8d0c07               lea ecx, [edi + eax]
// 004193ae  2bf1                 sub esi, ecx
// 004193b0  03f0                 add esi, eax
// 004193b2  c1fe02               sar esi, 2
// 004193b5  8d04b500000000       lea eax, [esi*4]
// 004193bc  8d3c28               lea edi, [eax + ebp]
// 004193bf  85f6                 test esi, esi
// 004193c1  760d                 jbe 0x4193d0
// 004193c3  50                   push eax
// 004193c4  51                   push ecx
// 004193c5  50                   push eax
// 004193c6  55                   push ebp
// 004193c7  ff1550288000         call dword ptr [0x802850]
// 004193cd  83c410               add esp, 0x10
// 004193d0  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004193d4  85c9                 test ecx, ecx
// 004193d6  7604                 jbe 0x4193dc
// 004193d8  33c0                 xor eax, eax
// 004193da  f3ab                 rep stosd dword ptr es:[edi], eax
// 004193dc  8b4310               mov eax, dword ptr [ebx + 0x10]
// 004193df  85c0                 test eax, eax
// 004193e1  7409                 je 0x4193ec
// 004193e3  50                   push eax
// 004193e4  e891722800           call 0x6a067a
// 004193e9  83c404               add esp, 4
// 004193ec  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 004193f0  015314               add dword ptr [ebx + 0x14], edx
// 004193f3  5f                   pop edi
// 004193f4  5e                   pop esi
// 004193f5  896b10               mov dword ptr [ebx + 0x10], ebp
// 004193f8  5d                   pop ebp
// 004193f9  5b                   pop ebx
// 004193fa  83c408               add esp, 8
// 004193fd  c20400               ret 4
// standard library deque<pod32> (function ?_Growmap@?$deque@UE@@V?$allocator@UE@@@std@@@std@@IAEXI@Z)

// stl: deque<pod32>
struct E { int v[8]; };
#include <deque>
template class std::deque<E>;
