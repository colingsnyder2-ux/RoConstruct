// from server: 100% by auto
// roc 2009-06 0042fe20  unit: COutputView  size: 352 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0042fe20
//
// 0042fe20  8b542404             mov edx, dword ptr [esp + 4]
// 0042fe24  83ec08               sub esp, 8
// 0042fe27  53                   push ebx
// 0042fe28  8bd9                 mov ebx, ecx
// 0042fe2a  8b4314               mov eax, dword ptr [ebx + 0x14]
// 0042fe2d  b966666606           mov ecx, 0x6666666
// 0042fe32  2bc8                 sub ecx, eax
// 0042fe34  3bca                 cmp ecx, edx
// 0042fe36  7305                 jae 0x42fe3d
// 0042fe38  e833faffff           call 0x42f870
// 0042fe3d  8bc8                 mov ecx, eax
// 0042fe3f  d1e9                 shr ecx, 1
// 0042fe41  83f908               cmp ecx, 8
// 0042fe44  7305                 jae 0x42fe4b
// 0042fe46  b908000000           mov ecx, 8
// 0042fe4b  55                   push ebp
// 0042fe4c  56                   push esi
// 0042fe4d  57                   push edi
// 0042fe4e  3bd1                 cmp edx, ecx
// 0042fe50  7311                 jae 0x42fe63
// 0042fe52  be66666606           mov esi, 0x6666666
// 0042fe57  2bf1                 sub esi, ecx
// 0042fe59  3bc6                 cmp eax, esi
// 0042fe5b  7706                 ja 0x42fe63
// 0042fe5d  8bd1                 mov edx, ecx
// 0042fe5f  8954241c             mov dword ptr [esp + 0x1c], edx
// 0042fe63  8b7318               mov esi, dword ptr [ebx + 0x18]
// 0042fe66  03c2                 add eax, edx
// 0042fe68  6a00                 push 0
// 0042fe6a  50                   push eax
// 0042fe6b  89742418             mov dword ptr [esp + 0x18], esi
// 0042fe6f  e88c8b1c00           call 0x5f8a00
// 0042fe74  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 0042fe77  8944241c             mov dword ptr [esp + 0x1c], eax
// 0042fe7b  03f6                 add esi, esi
// 0042fe7d  03f6                 add esi, esi
// 0042fe7f  8d3c06               lea edi, [esi + eax]
// 0042fe82  8b4314               mov eax, dword ptr [ebx + 0x14]
// 0042fe85  03c0                 add eax, eax
// 0042fe87  03c0                 add eax, eax
// 0042fe89  8d140e               lea edx, [esi + ecx]
// 0042fe8c  2bc2                 sub eax, edx
// 0042fe8e  03c1                 add eax, ecx
// 0042fe90  c1f802               sar eax, 2
// 0042fe93  83c408               add esp, 8
// 0042fe96  8d0c8500000000       lea ecx, [eax*4]
// 0042fe9d  8d2c39               lea ebp, [ecx + edi]
// 0042fea0  85c0                 test eax, eax
// 0042fea2  760d                 jbe 0x42feb1
// 0042fea4  51                   push ecx
// 0042fea5  52                   push edx
// 0042fea6  51                   push ecx
// 0042fea7  57                   push edi
// 0042fea8  ff155ce98900         call dword ptr [0x89e95c]
// 0042feae  83c410               add esp, 0x10
// 0042feb1  8b542410             mov edx, dword ptr [esp + 0x10]
// 0042feb5  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0042feb9  3bd0                 cmp edx, eax
// 0042febb  7743                 ja 0x42ff00
// 0042febd  8b4310               mov eax, dword ptr [ebx + 0x10]
// 0042fec0  c1fe02               sar esi, 2
// 0042fec3  8d0cb500000000       lea ecx, [esi*4]
// 0042feca  8d3c29               lea edi, [ecx + ebp]
// 0042fecd  85f6                 test esi, esi
// 0042fecf  7611                 jbe 0x42fee2
// 0042fed1  51                   push ecx
// 0042fed2  50                   push eax
// 0042fed3  51                   push ecx
// 0042fed4  55                   push ebp
// 0042fed5  ff155ce98900         call dword ptr [0x89e95c]
// 0042fedb  8b542420             mov edx, dword ptr [esp + 0x20]
// 0042fedf  83c410               add esp, 0x10
// 0042fee2  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0042fee6  2bca                 sub ecx, edx
// 0042fee8  7408                 je 0x42fef2
// 0042feea  8b542410             mov edx, dword ptr [esp + 0x10]
// 0042feee  33c0                 xor eax, eax
// 0042fef0  f3ab                 rep stosd dword ptr es:[edi], eax
// 0042fef2  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0042fef6  85d2                 test edx, edx
// 0042fef8  7662                 jbe 0x42ff5c
// 0042fefa  8bca                 mov ecx, edx
// 0042fefc  8bfd                 mov edi, ebp
// 0042fefe  eb58                 jmp 0x42ff58
// 0042ff00  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 0042ff03  8d3c8500000000       lea edi, [eax*4]
// 0042ff0a  8bc7                 mov eax, edi
// 0042ff0c  c1f802               sar eax, 2
// 0042ff0f  85c0                 test eax, eax
// 0042ff11  7611                 jbe 0x42ff24
// 0042ff13  03c0                 add eax, eax
// 0042ff15  03c0                 add eax, eax
// 0042ff17  50                   push eax
// 0042ff18  51                   push ecx
// 0042ff19  50                   push eax
// 0042ff1a  55                   push ebp
// 0042ff1b  ff155ce98900         call dword ptr [0x89e95c]
// 0042ff21  83c410               add esp, 0x10
// 0042ff24  8b4310               mov eax, dword ptr [ebx + 0x10]
// 0042ff27  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0042ff2b  8d0c07               lea ecx, [edi + eax]
// 0042ff2e  2bf1                 sub esi, ecx
// 0042ff30  03f0                 add esi, eax
// 0042ff32  c1fe02               sar esi, 2
// 0042ff35  8d04b500000000       lea eax, [esi*4]
// 0042ff3c  8d3c28               lea edi, [eax + ebp]
// 0042ff3f  85f6                 test esi, esi
// 0042ff41  760d                 jbe 0x42ff50
// 0042ff43  50                   push eax
// 0042ff44  51                   push ecx
// 0042ff45  50                   push eax
// 0042ff46  55                   push ebp
// 0042ff47  ff155ce98900         call dword ptr [0x89e95c]
// 0042ff4d  83c410               add esp, 0x10
// 0042ff50  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0042ff54  85c9                 test ecx, ecx
// 0042ff56  7604                 jbe 0x42ff5c
// 0042ff58  33c0                 xor eax, eax
// 0042ff5a  f3ab                 rep stosd dword ptr es:[edi], eax
// 0042ff5c  8b4310               mov eax, dword ptr [ebx + 0x10]
// 0042ff5f  85c0                 test eax, eax
// 0042ff61  7409                 je 0x42ff6c
// 0042ff63  50                   push eax
// 0042ff64  e8c98a2e00           call 0x718a32
// 0042ff69  83c404               add esp, 4
// 0042ff6c  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0042ff70  015314               add dword ptr [ebx + 0x14], edx
// 0042ff73  5f                   pop edi
// 0042ff74  5e                   pop esi
// 0042ff75  896b10               mov dword ptr [ebx + 0x10], ebp
// 0042ff78  5d                   pop ebp
// 0042ff79  5b                   pop ebx
// 0042ff7a  83c408               add esp, 8
// 0042ff7d  c20400               ret 4
// standard library deque<pod40> (function ?_Growmap@?$deque@UE@@V?$allocator@UE@@@std@@@std@@IAEXI@Z)

// stl: deque<pod40>
struct E { int v[10]; };
#include <deque>
template class std::deque<E>;
