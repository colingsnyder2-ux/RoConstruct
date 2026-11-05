// from server: 100% by auto
// roc 2009-06 004db450  unit: RBX::VInstance::?$GuidItem::VRegistry::?$sp_counted_impl_p  size: 352 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004db450
//
// 004db450  8b542404             mov edx, dword ptr [esp + 4]
// 004db454  83ec08               sub esp, 8
// 004db457  53                   push ebx
// 004db458  8bd9                 mov ebx, ecx
// 004db45a  8b4314               mov eax, dword ptr [ebx + 0x14]
// 004db45d  b9ffffff07           mov ecx, 0x7ffffff
// 004db462  2bc8                 sub ecx, eax
// 004db464  3bca                 cmp ecx, edx
// 004db466  7305                 jae 0x4db46d
// 004db468  e80344f5ff           call 0x42f870
// 004db46d  8bc8                 mov ecx, eax
// 004db46f  d1e9                 shr ecx, 1
// 004db471  83f908               cmp ecx, 8
// 004db474  7305                 jae 0x4db47b
// 004db476  b908000000           mov ecx, 8
// 004db47b  55                   push ebp
// 004db47c  56                   push esi
// 004db47d  57                   push edi
// 004db47e  3bd1                 cmp edx, ecx
// 004db480  7311                 jae 0x4db493
// 004db482  beffffff07           mov esi, 0x7ffffff
// 004db487  2bf1                 sub esi, ecx
// 004db489  3bc6                 cmp eax, esi
// 004db48b  7706                 ja 0x4db493
// 004db48d  8bd1                 mov edx, ecx
// 004db48f  8954241c             mov dword ptr [esp + 0x1c], edx
// 004db493  8b7318               mov esi, dword ptr [ebx + 0x18]
// 004db496  03c2                 add eax, edx
// 004db498  6a00                 push 0
// 004db49a  50                   push eax
// 004db49b  89742418             mov dword ptr [esp + 0x18], esi
// 004db49f  e85cd51100           call 0x5f8a00
// 004db4a4  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 004db4a7  8944241c             mov dword ptr [esp + 0x1c], eax
// 004db4ab  03f6                 add esi, esi
// 004db4ad  03f6                 add esi, esi
// 004db4af  8d3c06               lea edi, [esi + eax]
// 004db4b2  8b4314               mov eax, dword ptr [ebx + 0x14]
// 004db4b5  03c0                 add eax, eax
// 004db4b7  03c0                 add eax, eax
// 004db4b9  8d140e               lea edx, [esi + ecx]
// 004db4bc  2bc2                 sub eax, edx
// 004db4be  03c1                 add eax, ecx
// 004db4c0  c1f802               sar eax, 2
// 004db4c3  83c408               add esp, 8
// 004db4c6  8d0c8500000000       lea ecx, [eax*4]
// 004db4cd  8d2c39               lea ebp, [ecx + edi]
// 004db4d0  85c0                 test eax, eax
// 004db4d2  760d                 jbe 0x4db4e1
// 004db4d4  51                   push ecx
// 004db4d5  52                   push edx
// 004db4d6  51                   push ecx
// 004db4d7  57                   push edi
// 004db4d8  ff155ce98900         call dword ptr [0x89e95c]
// 004db4de  83c410               add esp, 0x10
// 004db4e1  8b542410             mov edx, dword ptr [esp + 0x10]
// 004db4e5  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004db4e9  3bd0                 cmp edx, eax
// 004db4eb  7743                 ja 0x4db530
// 004db4ed  8b4310               mov eax, dword ptr [ebx + 0x10]
// 004db4f0  c1fe02               sar esi, 2
// 004db4f3  8d0cb500000000       lea ecx, [esi*4]
// 004db4fa  8d3c29               lea edi, [ecx + ebp]
// 004db4fd  85f6                 test esi, esi
// 004db4ff  7611                 jbe 0x4db512
// 004db501  51                   push ecx
// 004db502  50                   push eax
// 004db503  51                   push ecx
// 004db504  55                   push ebp
// 004db505  ff155ce98900         call dword ptr [0x89e95c]
// 004db50b  8b542420             mov edx, dword ptr [esp + 0x20]
// 004db50f  83c410               add esp, 0x10
// 004db512  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004db516  2bca                 sub ecx, edx
// 004db518  7408                 je 0x4db522
// 004db51a  8b542410             mov edx, dword ptr [esp + 0x10]
// 004db51e  33c0                 xor eax, eax
// 004db520  f3ab                 rep stosd dword ptr es:[edi], eax
// 004db522  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 004db526  85d2                 test edx, edx
// 004db528  7662                 jbe 0x4db58c
// 004db52a  8bca                 mov ecx, edx
// 004db52c  8bfd                 mov edi, ebp
// 004db52e  eb58                 jmp 0x4db588
// 004db530  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 004db533  8d3c8500000000       lea edi, [eax*4]
// 004db53a  8bc7                 mov eax, edi
// 004db53c  c1f802               sar eax, 2
// 004db53f  85c0                 test eax, eax
// 004db541  7611                 jbe 0x4db554
// 004db543  03c0                 add eax, eax
// 004db545  03c0                 add eax, eax
// 004db547  50                   push eax
// 004db548  51                   push ecx
// 004db549  50                   push eax
// 004db54a  55                   push ebp
// 004db54b  ff155ce98900         call dword ptr [0x89e95c]
// 004db551  83c410               add esp, 0x10
// 004db554  8b4310               mov eax, dword ptr [ebx + 0x10]
// 004db557  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 004db55b  8d0c07               lea ecx, [edi + eax]
// 004db55e  2bf1                 sub esi, ecx
// 004db560  03f0                 add esi, eax
// 004db562  c1fe02               sar esi, 2
// 004db565  8d04b500000000       lea eax, [esi*4]
// 004db56c  8d3c28               lea edi, [eax + ebp]
// 004db56f  85f6                 test esi, esi
// 004db571  760d                 jbe 0x4db580
// 004db573  50                   push eax
// 004db574  51                   push ecx
// 004db575  50                   push eax
// 004db576  55                   push ebp
// 004db577  ff155ce98900         call dword ptr [0x89e95c]
// 004db57d  83c410               add esp, 0x10
// 004db580  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004db584  85c9                 test ecx, ecx
// 004db586  7604                 jbe 0x4db58c
// 004db588  33c0                 xor eax, eax
// 004db58a  f3ab                 rep stosd dword ptr es:[edi], eax
// 004db58c  8b4310               mov eax, dword ptr [ebx + 0x10]
// 004db58f  85c0                 test eax, eax
// 004db591  7409                 je 0x4db59c
// 004db593  50                   push eax
// 004db594  e899d42300           call 0x718a32
// 004db599  83c404               add esp, 4
// 004db59c  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 004db5a0  015314               add dword ptr [ebx + 0x14], edx
// 004db5a3  5f                   pop edi
// 004db5a4  5e                   pop esi
// 004db5a5  896b10               mov dword ptr [ebx + 0x10], ebp
// 004db5a8  5d                   pop ebp
// 004db5a9  5b                   pop ebx
// 004db5aa  83c408               add esp, 8
// 004db5ad  c20400               ret 4
// standard library deque<pod32> (function ?_Growmap@?$deque@UE@@V?$allocator@UE@@@std@@@std@@IAEXI@Z)

// stl: deque<pod32>
struct E { int v[8]; };
#include <deque>
template class std::deque<E>;
