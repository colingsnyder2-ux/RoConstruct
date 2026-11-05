// from server: 100% by auto
// roc 2010-06 00741570  unit: RBX::VHttp::?$sp_counted_impl_p  size: 352 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00741570
//
// 00741570  8b542404             mov edx, dword ptr [esp + 4]
// 00741574  83ec08               sub esp, 8
// 00741577  53                   push ebx
// 00741578  8bd9                 mov ebx, ecx
// 0074157a  8b4314               mov eax, dword ptr [ebx + 0x14]
// 0074157d  b9ffffff0f           mov ecx, 0xfffffff
// 00741582  2bc8                 sub ecx, eax
// 00741584  3bca                 cmp ecx, edx
// 00741586  7305                 jae 0x74158d
// 00741588  e843e8d7ff           call 0x4bfdd0
// 0074158d  8bc8                 mov ecx, eax
// 0074158f  d1e9                 shr ecx, 1
// 00741591  83f908               cmp ecx, 8
// 00741594  7305                 jae 0x74159b
// 00741596  b908000000           mov ecx, 8
// 0074159b  55                   push ebp
// 0074159c  56                   push esi
// 0074159d  57                   push edi
// 0074159e  3bd1                 cmp edx, ecx
// 007415a0  7311                 jae 0x7415b3
// 007415a2  beffffff0f           mov esi, 0xfffffff
// 007415a7  2bf1                 sub esi, ecx
// 007415a9  3bc6                 cmp eax, esi
// 007415ab  7706                 ja 0x7415b3
// 007415ad  8bd1                 mov edx, ecx
// 007415af  8954241c             mov dword ptr [esp + 0x1c], edx
// 007415b3  8b7318               mov esi, dword ptr [ebx + 0x18]
// 007415b6  03c2                 add eax, edx
// 007415b8  6a00                 push 0
// 007415ba  50                   push eax
// 007415bb  89742418             mov dword ptr [esp + 0x18], esi
// 007415bf  e84c3d1900           call 0x8d5310
// 007415c4  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 007415c7  8944241c             mov dword ptr [esp + 0x1c], eax
// 007415cb  03f6                 add esi, esi
// 007415cd  03f6                 add esi, esi
// 007415cf  8d3c06               lea edi, [esi + eax]
// 007415d2  8b4314               mov eax, dword ptr [ebx + 0x14]
// 007415d5  03c0                 add eax, eax
// 007415d7  03c0                 add eax, eax
// 007415d9  8d140e               lea edx, [esi + ecx]
// 007415dc  2bc2                 sub eax, edx
// 007415de  03c1                 add eax, ecx
// 007415e0  c1f802               sar eax, 2
// 007415e3  83c408               add esp, 8
// 007415e6  8d0c8500000000       lea ecx, [eax*4]
// 007415ed  8d2c39               lea ebp, [ecx + edi]
// 007415f0  85c0                 test eax, eax
// 007415f2  760d                 jbe 0x741601
// 007415f4  51                   push ecx
// 007415f5  52                   push edx
// 007415f6  51                   push ecx
// 007415f7  57                   push edi
// 007415f8  ff1580a89e00         call dword ptr [0x9ea880]
// 007415fe  83c410               add esp, 0x10
// 00741601  8b542410             mov edx, dword ptr [esp + 0x10]
// 00741605  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00741609  3bd0                 cmp edx, eax
// 0074160b  7743                 ja 0x741650
// 0074160d  8b4310               mov eax, dword ptr [ebx + 0x10]
// 00741610  c1fe02               sar esi, 2
// 00741613  8d0cb500000000       lea ecx, [esi*4]
// 0074161a  8d3c29               lea edi, [ecx + ebp]
// 0074161d  85f6                 test esi, esi
// 0074161f  7611                 jbe 0x741632
// 00741621  51                   push ecx
// 00741622  50                   push eax
// 00741623  51                   push ecx
// 00741624  55                   push ebp
// 00741625  ff1580a89e00         call dword ptr [0x9ea880]
// 0074162b  8b542420             mov edx, dword ptr [esp + 0x20]
// 0074162f  83c410               add esp, 0x10
// 00741632  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00741636  2bca                 sub ecx, edx
// 00741638  7408                 je 0x741642
// 0074163a  8b542410             mov edx, dword ptr [esp + 0x10]
// 0074163e  33c0                 xor eax, eax
// 00741640  f3ab                 rep stosd dword ptr es:[edi], eax
// 00741642  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 00741646  85d2                 test edx, edx
// 00741648  7662                 jbe 0x7416ac
// 0074164a  8bca                 mov ecx, edx
// 0074164c  8bfd                 mov edi, ebp
// 0074164e  eb58                 jmp 0x7416a8
// 00741650  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 00741653  8d3c8500000000       lea edi, [eax*4]
// 0074165a  8bc7                 mov eax, edi
// 0074165c  c1f802               sar eax, 2
// 0074165f  85c0                 test eax, eax
// 00741661  7611                 jbe 0x741674
// 00741663  03c0                 add eax, eax
// 00741665  03c0                 add eax, eax
// 00741667  50                   push eax
// 00741668  51                   push ecx
// 00741669  50                   push eax
// 0074166a  55                   push ebp
// 0074166b  ff1580a89e00         call dword ptr [0x9ea880]
// 00741671  83c410               add esp, 0x10
// 00741674  8b4310               mov eax, dword ptr [ebx + 0x10]
// 00741677  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0074167b  8d0c07               lea ecx, [edi + eax]
// 0074167e  2bf1                 sub esi, ecx
// 00741680  03f0                 add esi, eax
// 00741682  c1fe02               sar esi, 2
// 00741685  8d04b500000000       lea eax, [esi*4]
// 0074168c  8d3c28               lea edi, [eax + ebp]
// 0074168f  85f6                 test esi, esi
// 00741691  760d                 jbe 0x7416a0
// 00741693  50                   push eax
// 00741694  51                   push ecx
// 00741695  50                   push eax
// 00741696  55                   push ebp
// 00741697  ff1580a89e00         call dword ptr [0x9ea880]
// 0074169d  83c410               add esp, 0x10
// 007416a0  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 007416a4  85c9                 test ecx, ecx
// 007416a6  7604                 jbe 0x7416ac
// 007416a8  33c0                 xor eax, eax
// 007416aa  f3ab                 rep stosd dword ptr es:[edi], eax
// 007416ac  8b4310               mov eax, dword ptr [ebx + 0x10]
// 007416af  85c0                 test eax, eax
// 007416b1  7409                 je 0x7416bc
// 007416b3  50                   push eax
// 007416b4  e8e1620600           call 0x7a799a
// 007416b9  83c404               add esp, 4
// 007416bc  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 007416c0  015314               add dword ptr [ebx + 0x14], edx
// 007416c3  5f                   pop edi
// 007416c4  5e                   pop esi
// 007416c5  896b10               mov dword ptr [ebx + 0x10], ebp
// 007416c8  5d                   pop ebp
// 007416c9  5b                   pop ebx
// 007416ca  83c408               add esp, 8
// 007416cd  c20400               ret 4
// standard library deque<pod16> (function ?_Growmap@?$deque@UE@@V?$allocator@UE@@@std@@@std@@IAEXI@Z)

// stl: deque<pod16>
struct E { int v[4]; };
#include <deque>
template class std::deque<E>;
