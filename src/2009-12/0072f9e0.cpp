// from server: 100% by auto
// roc 2009-12 0072f9e0  unit: G3D::$$A6AXVVector3::?$signal::slot  size: 349 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0072f9e0
//
// 0072f9e0  51                   push ecx
// 0072f9e1  8b542408             mov edx, dword ptr [esp + 8]
// 0072f9e5  53                   push ebx
// 0072f9e6  8bd9                 mov ebx, ecx
// 0072f9e8  8b4314               mov eax, dword ptr [ebx + 0x14]
// 0072f9eb  b9ffffff0f           mov ecx, 0xfffffff
// 0072f9f0  2bc8                 sub ecx, eax
// 0072f9f2  3bca                 cmp ecx, edx
// 0072f9f4  7305                 jae 0x72f9fb
// 0072f9f6  e855d6f8ff           call 0x6bd050
// 0072f9fb  8bc8                 mov ecx, eax
// 0072f9fd  d1e9                 shr ecx, 1
// 0072f9ff  83f908               cmp ecx, 8
// 0072fa02  7305                 jae 0x72fa09
// 0072fa04  b908000000           mov ecx, 8
// 0072fa09  55                   push ebp
// 0072fa0a  56                   push esi
// 0072fa0b  57                   push edi
// 0072fa0c  3bd1                 cmp edx, ecx
// 0072fa0e  7311                 jae 0x72fa21
// 0072fa10  beffffff0f           mov esi, 0xfffffff
// 0072fa15  2bf1                 sub esi, ecx
// 0072fa17  3bc6                 cmp eax, esi
// 0072fa19  7706                 ja 0x72fa21
// 0072fa1b  894c2418             mov dword ptr [esp + 0x18], ecx
// 0072fa1f  8bd1                 mov edx, ecx
// 0072fa21  8b6b18               mov ebp, dword ptr [ebx + 0x18]
// 0072fa24  03c2                 add eax, edx
// 0072fa26  6a00                 push 0
// 0072fa28  50                   push eax
// 0072fa29  d1ed                 shr ebp, 1
// 0072fa2b  e8100fd0ff           call 0x430940
// 0072fa30  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 0072fa33  89442418             mov dword ptr [esp + 0x18], eax
// 0072fa37  8d34ad00000000       lea esi, [ebp*4]
// 0072fa3e  8d3c06               lea edi, [esi + eax]
// 0072fa41  8b4314               mov eax, dword ptr [ebx + 0x14]
// 0072fa44  03c0                 add eax, eax
// 0072fa46  03c0                 add eax, eax
// 0072fa48  8d140e               lea edx, [esi + ecx]
// 0072fa4b  2bc2                 sub eax, edx
// 0072fa4d  03c1                 add eax, ecx
// 0072fa4f  c1f802               sar eax, 2
// 0072fa52  8d0c8500000000       lea ecx, [eax*4]
// 0072fa59  83c408               add esp, 8
// 0072fa5c  03f9                 add edi, ecx
// 0072fa5e  85c0                 test eax, eax
// 0072fa60  7614                 jbe 0x72fa76
// 0072fa62  51                   push ecx
// 0072fa63  52                   push edx
// 0072fa64  8b542418             mov edx, dword ptr [esp + 0x18]
// 0072fa68  51                   push ecx
// 0072fa69  8d0416               lea eax, [esi + edx]
// 0072fa6c  50                   push eax
// 0072fa6d  ff15c0b79800         call dword ptr [0x98b7c0]
// 0072fa73  83c410               add esp, 0x10
// 0072fa76  8b442418             mov eax, dword ptr [esp + 0x18]
// 0072fa7a  3be8                 cmp ebp, eax
// 0072fa7c  773d                 ja 0x72fabb
// 0072fa7e  8b4310               mov eax, dword ptr [ebx + 0x10]
// 0072fa81  c1fe02               sar esi, 2
// 0072fa84  8bce                 mov ecx, esi
// 0072fa86  8d148d00000000       lea edx, [ecx*4]
// 0072fa8d  8d343a               lea esi, [edx + edi]
// 0072fa90  85c9                 test ecx, ecx
// 0072fa92  760d                 jbe 0x72faa1
// 0072fa94  52                   push edx
// 0072fa95  50                   push eax
// 0072fa96  52                   push edx
// 0072fa97  57                   push edi
// 0072fa98  ff15c0b79800         call dword ptr [0x98b7c0]
// 0072fa9e  83c410               add esp, 0x10
// 0072faa1  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0072faa5  2bcd                 sub ecx, ebp
// 0072faa7  7406                 je 0x72faaf
// 0072faa9  33c0                 xor eax, eax
// 0072faab  8bfe                 mov edi, esi
// 0072faad  f3ab                 rep stosd dword ptr es:[edi], eax
// 0072faaf  85ed                 test ebp, ebp
// 0072fab1  7664                 jbe 0x72fb17
// 0072fab3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0072fab7  8bcd                 mov ecx, ebp
// 0072fab9  eb58                 jmp 0x72fb13
// 0072fabb  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 0072fabe  8d2c8500000000       lea ebp, [eax*4]
// 0072fac5  8bc5                 mov eax, ebp
// 0072fac7  c1f802               sar eax, 2
// 0072faca  85c0                 test eax, eax
// 0072facc  7611                 jbe 0x72fadf
// 0072face  03c0                 add eax, eax
// 0072fad0  03c0                 add eax, eax
// 0072fad2  50                   push eax
// 0072fad3  51                   push ecx
// 0072fad4  50                   push eax
// 0072fad5  57                   push edi
// 0072fad6  ff15c0b79800         call dword ptr [0x98b7c0]
// 0072fadc  83c410               add esp, 0x10
// 0072fadf  8b4310               mov eax, dword ptr [ebx + 0x10]
// 0072fae2  8b542410             mov edx, dword ptr [esp + 0x10]
// 0072fae6  8d0c28               lea ecx, [eax + ebp]
// 0072fae9  2bf1                 sub esi, ecx
// 0072faeb  03f0                 add esi, eax
// 0072faed  c1fe02               sar esi, 2
// 0072faf0  8d04b500000000       lea eax, [esi*4]
// 0072faf7  8d3c10               lea edi, [eax + edx]
// 0072fafa  85f6                 test esi, esi
// 0072fafc  760d                 jbe 0x72fb0b
// 0072fafe  50                   push eax
// 0072faff  51                   push ecx
// 0072fb00  50                   push eax
// 0072fb01  52                   push edx
// 0072fb02  ff15c0b79800         call dword ptr [0x98b7c0]
// 0072fb08  83c410               add esp, 0x10
// 0072fb0b  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0072fb0f  85c9                 test ecx, ecx
// 0072fb11  7604                 jbe 0x72fb17
// 0072fb13  33c0                 xor eax, eax
// 0072fb15  f3ab                 rep stosd dword ptr es:[edi], eax
// 0072fb17  8b4310               mov eax, dword ptr [ebx + 0x10]
// 0072fb1a  5f                   pop edi
// 0072fb1b  5e                   pop esi
// 0072fb1c  5d                   pop ebp
// 0072fb1d  85c0                 test eax, eax
// 0072fb1f  7409                 je 0x72fb2a
// 0072fb21  50                   push eax
// 0072fb22  e8333d0c00           call 0x7f385a
// 0072fb27  83c404               add esp, 4
// 0072fb2a  8b442404             mov eax, dword ptr [esp + 4]
// 0072fb2e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0072fb32  014b14               add dword ptr [ebx + 0x14], ecx
// 0072fb35  894310               mov dword ptr [ebx + 0x10], eax
// 0072fb38  5b                   pop ebx
// 0072fb39  59                   pop ecx
// 0072fb3a  c20400               ret 4
// standard library deque<double> (function ?_Growmap@?$deque@NV?$allocator@N@std@@@std@@IAEXI@Z)

// stl: deque<double>
typedef double E;
#include <deque>
template class std::deque<E>;
