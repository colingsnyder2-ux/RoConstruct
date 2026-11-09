// from server: 100% by auto
// roc 2010-06 004dee60  unit: RBX::VInstance::?$GuidItem::VRegistry::?$sp_counted_impl_p  size: 352 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004dee60
//
// 004dee60  8b542404             mov edx, dword ptr [esp + 4]
// 004dee64  83ec08               sub esp, 8
// 004dee67  53                   push ebx
// 004dee68  8bd9                 mov ebx, ecx
// 004dee6a  8b4314               mov eax, dword ptr [ebx + 0x14]
// 004dee6d  b9ffffff07           mov ecx, 0x7ffffff
// 004dee72  2bc8                 sub ecx, eax
// 004dee74  3bca                 cmp ecx, edx
// 004dee76  7305                 jae 0x4dee7d
// 004dee78  e8530ffeff           call 0x4bfdd0
// 004dee7d  8bc8                 mov ecx, eax
// 004dee7f  d1e9                 shr ecx, 1
// 004dee81  83f908               cmp ecx, 8
// 004dee84  7305                 jae 0x4dee8b
// 004dee86  b908000000           mov ecx, 8
// 004dee8b  55                   push ebp
// 004dee8c  56                   push esi
// 004dee8d  57                   push edi
// 004dee8e  3bd1                 cmp edx, ecx
// 004dee90  7311                 jae 0x4deea3
// 004dee92  beffffff07           mov esi, 0x7ffffff
// 004dee97  2bf1                 sub esi, ecx
// 004dee99  3bc6                 cmp eax, esi
// 004dee9b  7706                 ja 0x4deea3
// 004dee9d  8bd1                 mov edx, ecx
// 004dee9f  8954241c             mov dword ptr [esp + 0x1c], edx
// 004deea3  8b7318               mov esi, dword ptr [ebx + 0x18]
// 004deea6  03c2                 add eax, edx
// 004deea8  6a00                 push 0
// 004deeaa  50                   push eax
// 004deeab  89742418             mov dword ptr [esp + 0x18], esi
// 004deeaf  e85c643f00           call 0x8d5310
// 004deeb4  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 004deeb7  8944241c             mov dword ptr [esp + 0x1c], eax
// 004deebb  03f6                 add esi, esi
// 004deebd  03f6                 add esi, esi
// 004deebf  8d3c06               lea edi, [esi + eax]
// 004deec2  8b4314               mov eax, dword ptr [ebx + 0x14]
// 004deec5  03c0                 add eax, eax
// 004deec7  03c0                 add eax, eax
// 004deec9  8d140e               lea edx, [esi + ecx]
// 004deecc  2bc2                 sub eax, edx
// 004deece  03c1                 add eax, ecx
// 004deed0  c1f802               sar eax, 2
// 004deed3  83c408               add esp, 8
// 004deed6  8d0c8500000000       lea ecx, [eax*4]
// 004deedd  8d2c39               lea ebp, [ecx + edi]
// 004deee0  85c0                 test eax, eax
// 004deee2  760d                 jbe 0x4deef1
// 004deee4  51                   push ecx
// 004deee5  52                   push edx
// 004deee6  51                   push ecx
// 004deee7  57                   push edi
// 004deee8  ff1580a89e00         call dword ptr [0x9ea880]
// 004deeee  83c410               add esp, 0x10
// 004deef1  8b542410             mov edx, dword ptr [esp + 0x10]
// 004deef5  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004deef9  3bd0                 cmp edx, eax
// 004deefb  7743                 ja 0x4def40
// 004deefd  8b4310               mov eax, dword ptr [ebx + 0x10]
// 004def00  c1fe02               sar esi, 2
// 004def03  8d0cb500000000       lea ecx, [esi*4]
// 004def0a  8d3c29               lea edi, [ecx + ebp]
// 004def0d  85f6                 test esi, esi
// 004def0f  7611                 jbe 0x4def22
// 004def11  51                   push ecx
// 004def12  50                   push eax
// 004def13  51                   push ecx
// 004def14  55                   push ebp
// 004def15  ff1580a89e00         call dword ptr [0x9ea880]
// 004def1b  8b542420             mov edx, dword ptr [esp + 0x20]
// 004def1f  83c410               add esp, 0x10
// 004def22  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004def26  2bca                 sub ecx, edx
// 004def28  7408                 je 0x4def32
// 004def2a  8b542410             mov edx, dword ptr [esp + 0x10]
// 004def2e  33c0                 xor eax, eax
// 004def30  f3ab                 rep stosd dword ptr es:[edi], eax
// 004def32  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 004def36  85d2                 test edx, edx
// 004def38  7662                 jbe 0x4def9c
// 004def3a  8bca                 mov ecx, edx
// 004def3c  8bfd                 mov edi, ebp
// 004def3e  eb58                 jmp 0x4def98
// 004def40  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 004def43  8d3c8500000000       lea edi, [eax*4]
// 004def4a  8bc7                 mov eax, edi
// 004def4c  c1f802               sar eax, 2
// 004def4f  85c0                 test eax, eax
// 004def51  7611                 jbe 0x4def64
// 004def53  03c0                 add eax, eax
// 004def55  03c0                 add eax, eax
// 004def57  50                   push eax
// 004def58  51                   push ecx
// 004def59  50                   push eax
// 004def5a  55                   push ebp
// 004def5b  ff1580a89e00         call dword ptr [0x9ea880]
// 004def61  83c410               add esp, 0x10
// 004def64  8b4310               mov eax, dword ptr [ebx + 0x10]
// 004def67  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 004def6b  8d0c07               lea ecx, [edi + eax]
// 004def6e  2bf1                 sub esi, ecx
// 004def70  03f0                 add esi, eax
// 004def72  c1fe02               sar esi, 2
// 004def75  8d04b500000000       lea eax, [esi*4]
// 004def7c  8d3c28               lea edi, [eax + ebp]
// 004def7f  85f6                 test esi, esi
// 004def81  760d                 jbe 0x4def90
// 004def83  50                   push eax
// 004def84  51                   push ecx
// 004def85  50                   push eax
// 004def86  55                   push ebp
// 004def87  ff1580a89e00         call dword ptr [0x9ea880]
// 004def8d  83c410               add esp, 0x10
// 004def90  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004def94  85c9                 test ecx, ecx
// 004def96  7604                 jbe 0x4def9c
// 004def98  33c0                 xor eax, eax
// 004def9a  f3ab                 rep stosd dword ptr es:[edi], eax
// 004def9c  8b4310               mov eax, dword ptr [ebx + 0x10]
// 004def9f  85c0                 test eax, eax
// 004defa1  7409                 je 0x4defac
// 004defa3  50                   push eax
// 004defa4  e8f1892c00           call 0x7a799a
// 004defa9  83c404               add esp, 4
// 004defac  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 004defb0  015314               add dword ptr [ebx + 0x14], edx
// 004defb3  5f                   pop edi
// 004defb4  5e                   pop esi
// 004defb5  896b10               mov dword ptr [ebx + 0x10], ebp
// 004defb8  5d                   pop ebp
// 004defb9  5b                   pop ebx
// 004defba  83c408               add esp, 8
// 004defbd  c20400               ret 4
// standard library deque<pod32> (function ?_Growmap@?$deque@UE@@V?$allocator@UE@@@std@@@std@@IAEXI@Z)

// stl: deque<pod32>
struct E { int v[8]; };
#include <deque>
template class std::deque<E>;
