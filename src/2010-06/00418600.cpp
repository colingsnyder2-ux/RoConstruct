// from server: 100% by auto
// roc 2010-06 00418600  unit: RBX::VTool::?$FactoryProduct::Creator  size: 352 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00418600
//
// 00418600  8b542404             mov edx, dword ptr [esp + 4]
// 00418604  83ec08               sub esp, 8
// 00418607  53                   push ebx
// 00418608  8bd9                 mov ebx, ecx
// 0041860a  8b4314               mov eax, dword ptr [ebx + 0x14]
// 0041860d  b949922409           mov ecx, 0x9249249
// 00418612  2bc8                 sub ecx, eax
// 00418614  3bca                 cmp ecx, edx
// 00418616  7305                 jae 0x41861d
// 00418618  e8b3770a00           call 0x4bfdd0
// 0041861d  8bc8                 mov ecx, eax
// 0041861f  d1e9                 shr ecx, 1
// 00418621  83f908               cmp ecx, 8
// 00418624  7305                 jae 0x41862b
// 00418626  b908000000           mov ecx, 8
// 0041862b  55                   push ebp
// 0041862c  56                   push esi
// 0041862d  57                   push edi
// 0041862e  3bd1                 cmp edx, ecx
// 00418630  7311                 jae 0x418643
// 00418632  be49922409           mov esi, 0x9249249
// 00418637  2bf1                 sub esi, ecx
// 00418639  3bc6                 cmp eax, esi
// 0041863b  7706                 ja 0x418643
// 0041863d  8bd1                 mov edx, ecx
// 0041863f  8954241c             mov dword ptr [esp + 0x1c], edx
// 00418643  8b7318               mov esi, dword ptr [ebx + 0x18]
// 00418646  03c2                 add eax, edx
// 00418648  6a00                 push 0
// 0041864a  50                   push eax
// 0041864b  89742418             mov dword ptr [esp + 0x18], esi
// 0041864f  e8bccc4b00           call 0x8d5310
// 00418654  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 00418657  8944241c             mov dword ptr [esp + 0x1c], eax
// 0041865b  03f6                 add esi, esi
// 0041865d  03f6                 add esi, esi
// 0041865f  8d3c06               lea edi, [esi + eax]
// 00418662  8b4314               mov eax, dword ptr [ebx + 0x14]
// 00418665  03c0                 add eax, eax
// 00418667  03c0                 add eax, eax
// 00418669  8d140e               lea edx, [esi + ecx]
// 0041866c  2bc2                 sub eax, edx
// 0041866e  03c1                 add eax, ecx
// 00418670  c1f802               sar eax, 2
// 00418673  83c408               add esp, 8
// 00418676  8d0c8500000000       lea ecx, [eax*4]
// 0041867d  8d2c39               lea ebp, [ecx + edi]
// 00418680  85c0                 test eax, eax
// 00418682  760d                 jbe 0x418691
// 00418684  51                   push ecx
// 00418685  52                   push edx
// 00418686  51                   push ecx
// 00418687  57                   push edi
// 00418688  ff1580a89e00         call dword ptr [0x9ea880]
// 0041868e  83c410               add esp, 0x10
// 00418691  8b542410             mov edx, dword ptr [esp + 0x10]
// 00418695  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00418699  3bd0                 cmp edx, eax
// 0041869b  7743                 ja 0x4186e0
// 0041869d  8b4310               mov eax, dword ptr [ebx + 0x10]
// 004186a0  c1fe02               sar esi, 2
// 004186a3  8d0cb500000000       lea ecx, [esi*4]
// 004186aa  8d3c29               lea edi, [ecx + ebp]
// 004186ad  85f6                 test esi, esi
// 004186af  7611                 jbe 0x4186c2
// 004186b1  51                   push ecx
// 004186b2  50                   push eax
// 004186b3  51                   push ecx
// 004186b4  55                   push ebp
// 004186b5  ff1580a89e00         call dword ptr [0x9ea880]
// 004186bb  8b542420             mov edx, dword ptr [esp + 0x20]
// 004186bf  83c410               add esp, 0x10
// 004186c2  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004186c6  2bca                 sub ecx, edx
// 004186c8  7408                 je 0x4186d2
// 004186ca  8b542410             mov edx, dword ptr [esp + 0x10]
// 004186ce  33c0                 xor eax, eax
// 004186d0  f3ab                 rep stosd dword ptr es:[edi], eax
// 004186d2  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 004186d6  85d2                 test edx, edx
// 004186d8  7662                 jbe 0x41873c
// 004186da  8bca                 mov ecx, edx
// 004186dc  8bfd                 mov edi, ebp
// 004186de  eb58                 jmp 0x418738
// 004186e0  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 004186e3  8d3c8500000000       lea edi, [eax*4]
// 004186ea  8bc7                 mov eax, edi
// 004186ec  c1f802               sar eax, 2
// 004186ef  85c0                 test eax, eax
// 004186f1  7611                 jbe 0x418704
// 004186f3  03c0                 add eax, eax
// 004186f5  03c0                 add eax, eax
// 004186f7  50                   push eax
// 004186f8  51                   push ecx
// 004186f9  50                   push eax
// 004186fa  55                   push ebp
// 004186fb  ff1580a89e00         call dword ptr [0x9ea880]
// 00418701  83c410               add esp, 0x10
// 00418704  8b4310               mov eax, dword ptr [ebx + 0x10]
// 00418707  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0041870b  8d0c07               lea ecx, [edi + eax]
// 0041870e  2bf1                 sub esi, ecx
// 00418710  03f0                 add esi, eax
// 00418712  c1fe02               sar esi, 2
// 00418715  8d04b500000000       lea eax, [esi*4]
// 0041871c  8d3c28               lea edi, [eax + ebp]
// 0041871f  85f6                 test esi, esi
// 00418721  760d                 jbe 0x418730
// 00418723  50                   push eax
// 00418724  51                   push ecx
// 00418725  50                   push eax
// 00418726  55                   push ebp
// 00418727  ff1580a89e00         call dword ptr [0x9ea880]
// 0041872d  83c410               add esp, 0x10
// 00418730  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00418734  85c9                 test ecx, ecx
// 00418736  7604                 jbe 0x41873c
// 00418738  33c0                 xor eax, eax
// 0041873a  f3ab                 rep stosd dword ptr es:[edi], eax
// 0041873c  8b4310               mov eax, dword ptr [ebx + 0x10]
// 0041873f  85c0                 test eax, eax
// 00418741  7409                 je 0x41874c
// 00418743  50                   push eax
// 00418744  e851f23800           call 0x7a799a
// 00418749  83c404               add esp, 4
// 0041874c  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00418750  015314               add dword ptr [ebx + 0x14], edx
// 00418753  5f                   pop edi
// 00418754  5e                   pop esi
// 00418755  896b10               mov dword ptr [ebx + 0x10], ebp
// 00418758  5d                   pop ebp
// 00418759  5b                   pop ebx
// 0041875a  83c408               add esp, 8
// 0041875d  c20400               ret 4
// standard library deque<string> (function ?_Growmap@?$deque@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEXI@Z)

// stl: deque<string>
#include <string>
typedef std::string E;
#include <deque>
template class std::deque<E>;
