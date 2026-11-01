// from server: 100% by auto
// roc 2009-12 00689be0  unit: TextXmlWriter  size: 350 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00689be0
//
// 00689be0  51                   push ecx
// 00689be1  8b542408             mov edx, dword ptr [esp + 8]
// 00689be5  53                   push ebx
// 00689be6  8bd9                 mov ebx, ecx
// 00689be8  8b4314               mov eax, dword ptr [ebx + 0x14]
// 00689beb  b9ffffff0f           mov ecx, 0xfffffff
// 00689bf0  2bc8                 sub ecx, eax
// 00689bf2  3bca                 cmp ecx, edx
// 00689bf4  7305                 jae 0x689bfb
// 00689bf6  e855340300           call 0x6bd050
// 00689bfb  8bc8                 mov ecx, eax
// 00689bfd  d1e9                 shr ecx, 1
// 00689bff  83f908               cmp ecx, 8
// 00689c02  7305                 jae 0x689c09
// 00689c04  b908000000           mov ecx, 8
// 00689c09  55                   push ebp
// 00689c0a  56                   push esi
// 00689c0b  57                   push edi
// 00689c0c  3bd1                 cmp edx, ecx
// 00689c0e  7311                 jae 0x689c21
// 00689c10  beffffff0f           mov esi, 0xfffffff
// 00689c15  2bf1                 sub esi, ecx
// 00689c17  3bc6                 cmp eax, esi
// 00689c19  7706                 ja 0x689c21
// 00689c1b  894c2418             mov dword ptr [esp + 0x18], ecx
// 00689c1f  8bd1                 mov edx, ecx
// 00689c21  8b6b18               mov ebp, dword ptr [ebx + 0x18]
// 00689c24  03c2                 add eax, edx
// 00689c26  6a00                 push 0
// 00689c28  50                   push eax
// 00689c29  c1ed02               shr ebp, 2
// 00689c2c  e80f6ddaff           call 0x430940
// 00689c31  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 00689c34  89442418             mov dword ptr [esp + 0x18], eax
// 00689c38  8d34ad00000000       lea esi, [ebp*4]
// 00689c3f  8d3c06               lea edi, [esi + eax]
// 00689c42  8b4314               mov eax, dword ptr [ebx + 0x14]
// 00689c45  03c0                 add eax, eax
// 00689c47  03c0                 add eax, eax
// 00689c49  8d140e               lea edx, [esi + ecx]
// 00689c4c  2bc2                 sub eax, edx
// 00689c4e  03c1                 add eax, ecx
// 00689c50  c1f802               sar eax, 2
// 00689c53  8d0c8500000000       lea ecx, [eax*4]
// 00689c5a  83c408               add esp, 8
// 00689c5d  03f9                 add edi, ecx
// 00689c5f  85c0                 test eax, eax
// 00689c61  7614                 jbe 0x689c77
// 00689c63  51                   push ecx
// 00689c64  52                   push edx
// 00689c65  8b542418             mov edx, dword ptr [esp + 0x18]
// 00689c69  51                   push ecx
// 00689c6a  8d0416               lea eax, [esi + edx]
// 00689c6d  50                   push eax
// 00689c6e  ff15c0b79800         call dword ptr [0x98b7c0]
// 00689c74  83c410               add esp, 0x10
// 00689c77  8b442418             mov eax, dword ptr [esp + 0x18]
// 00689c7b  3be8                 cmp ebp, eax
// 00689c7d  773d                 ja 0x689cbc
// 00689c7f  8b4310               mov eax, dword ptr [ebx + 0x10]
// 00689c82  c1fe02               sar esi, 2
// 00689c85  8bce                 mov ecx, esi
// 00689c87  8d148d00000000       lea edx, [ecx*4]
// 00689c8e  8d343a               lea esi, [edx + edi]
// 00689c91  85c9                 test ecx, ecx
// 00689c93  760d                 jbe 0x689ca2
// 00689c95  52                   push edx
// 00689c96  50                   push eax
// 00689c97  52                   push edx
// 00689c98  57                   push edi
// 00689c99  ff15c0b79800         call dword ptr [0x98b7c0]
// 00689c9f  83c410               add esp, 0x10
// 00689ca2  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00689ca6  2bcd                 sub ecx, ebp
// 00689ca8  7406                 je 0x689cb0
// 00689caa  33c0                 xor eax, eax
// 00689cac  8bfe                 mov edi, esi
// 00689cae  f3ab                 rep stosd dword ptr es:[edi], eax
// 00689cb0  85ed                 test ebp, ebp
// 00689cb2  7664                 jbe 0x689d18
// 00689cb4  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00689cb8  8bcd                 mov ecx, ebp
// 00689cba  eb58                 jmp 0x689d14
// 00689cbc  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 00689cbf  8d2c8500000000       lea ebp, [eax*4]
// 00689cc6  8bc5                 mov eax, ebp
// 00689cc8  c1f802               sar eax, 2
// 00689ccb  85c0                 test eax, eax
// 00689ccd  7611                 jbe 0x689ce0
// 00689ccf  03c0                 add eax, eax
// 00689cd1  03c0                 add eax, eax
// 00689cd3  50                   push eax
// 00689cd4  51                   push ecx
// 00689cd5  50                   push eax
// 00689cd6  57                   push edi
// 00689cd7  ff15c0b79800         call dword ptr [0x98b7c0]
// 00689cdd  83c410               add esp, 0x10
// 00689ce0  8b4310               mov eax, dword ptr [ebx + 0x10]
// 00689ce3  8b542410             mov edx, dword ptr [esp + 0x10]
// 00689ce7  8d0c28               lea ecx, [eax + ebp]
// 00689cea  2bf1                 sub esi, ecx
// 00689cec  03f0                 add esi, eax
// 00689cee  c1fe02               sar esi, 2
// 00689cf1  8d04b500000000       lea eax, [esi*4]
// 00689cf8  8d3c10               lea edi, [eax + edx]
// 00689cfb  85f6                 test esi, esi
// 00689cfd  760d                 jbe 0x689d0c
// 00689cff  50                   push eax
// 00689d00  51                   push ecx
// 00689d01  50                   push eax
// 00689d02  52                   push edx
// 00689d03  ff15c0b79800         call dword ptr [0x98b7c0]
// 00689d09  83c410               add esp, 0x10
// 00689d0c  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00689d10  85c9                 test ecx, ecx
// 00689d12  7604                 jbe 0x689d18
// 00689d14  33c0                 xor eax, eax
// 00689d16  f3ab                 rep stosd dword ptr es:[edi], eax
// 00689d18  8b4310               mov eax, dword ptr [ebx + 0x10]
// 00689d1b  5f                   pop edi
// 00689d1c  5e                   pop esi
// 00689d1d  5d                   pop ebp
// 00689d1e  85c0                 test eax, eax
// 00689d20  7409                 je 0x689d2b
// 00689d22  50                   push eax
// 00689d23  e8329b1600           call 0x7f385a
// 00689d28  83c404               add esp, 4
// 00689d2b  8b442404             mov eax, dword ptr [esp + 4]
// 00689d2f  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00689d33  014b14               add dword ptr [ebx + 0x14], ecx
// 00689d36  894310               mov dword ptr [ebx + 0x10], eax
// 00689d39  5b                   pop ebx
// 00689d3a  59                   pop ecx
// 00689d3b  c20400               ret 4
// standard library deque<ptr> (function ?_Growmap@?$deque@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEXI@Z)

// stl: deque<ptr>
struct T; typedef T* E;
#include <deque>
template class std::deque<E>;
