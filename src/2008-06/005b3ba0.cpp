// from server: 100% by auto
// roc 2008-06 005b3ba0  unit: RBX::VHat::?$FactoryProduct  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005b3ba0
//
// 005b3ba0  83ec0c               sub esp, 0xc
// 005b3ba3  53                   push ebx
// 005b3ba4  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 005b3ba8  55                   push ebp
// 005b3ba9  56                   push esi
// 005b3baa  57                   push edi
// 005b3bab  8bf9                 mov edi, ecx
// 005b3bad  8b7718               mov esi, dword ptr [edi + 0x18]
// 005b3bb0  8b4604               mov eax, dword ptr [esi + 4]
// 005b3bb3  80782d00             cmp byte ptr [eax + 0x2d], 0
// 005b3bb7  b101                 mov cl, 1
// 005b3bb9  884c2410             mov byte ptr [esp + 0x10], cl
// 005b3bbd  751f                 jne 0x5b3bde
// 005b3bbf  8b13                 mov edx, dword ptr [ebx]
// 005b3bc1  3b500c               cmp edx, dword ptr [eax + 0xc]
// 005b3bc4  8bf0                 mov esi, eax
// 005b3bc6  0f9cc1               setl cl
// 005b3bc9  884c2410             mov byte ptr [esp + 0x10], cl
// 005b3bcd  84c9                 test cl, cl
// 005b3bcf  7404                 je 0x5b3bd5
// 005b3bd1  8b00                 mov eax, dword ptr [eax]
// 005b3bd3  eb03                 jmp 0x5b3bd8
// 005b3bd5  8b4008               mov eax, dword ptr [eax + 8]
// 005b3bd8  80782d00             cmp byte ptr [eax + 0x2d], 0
// 005b3bdc  74e3                 je 0x5b3bc1
// 005b3bde  8b17                 mov edx, dword ptr [edi]
// 005b3be0  8bee                 mov ebp, esi
// 005b3be2  896c2418             mov dword ptr [esp + 0x18], ebp
// 005b3be6  89542414             mov dword ptr [esp + 0x14], edx
// 005b3bea  84c9                 test cl, cl
// 005b3bec  7452                 je 0x5b3c40
// 005b3bee  8b4718               mov eax, dword ptr [edi + 0x18]
// 005b3bf1  8b28                 mov ebp, dword ptr [eax]
// 005b3bf3  85d2                 test edx, edx
// 005b3bf5  7404                 je 0x5b3bfb
// 005b3bf7  3bd2                 cmp edx, edx
// 005b3bf9  7406                 je 0x5b3c01
// 005b3bfb  ff1590288000         call dword ptr [0x802890]
// 005b3c01  8d4c2414             lea ecx, [esp + 0x14]
// 005b3c05  3bf5                 cmp esi, ebp
// 005b3c07  752a                 jne 0x5b3c33
// 005b3c09  53                   push ebx
// 005b3c0a  56                   push esi
// 005b3c0b  6a01                 push 1
// 005b3c0d  51                   push ecx
// 005b3c0e  8bcf                 mov ecx, edi
// 005b3c10  e88bf6ffff           call 0x5b32a0
// 005b3c15  5f                   pop edi
// 005b3c16  8bc8                 mov ecx, eax
// 005b3c18  8b11                 mov edx, dword ptr [ecx]
// 005b3c1a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005b3c1e  8b4904               mov ecx, dword ptr [ecx + 4]
// 005b3c21  5e                   pop esi
// 005b3c22  5d                   pop ebp
// 005b3c23  894804               mov dword ptr [eax + 4], ecx
// 005b3c26  c6400801             mov byte ptr [eax + 8], 1
// 005b3c2a  8910                 mov dword ptr [eax], edx
// 005b3c2c  5b                   pop ebx
// 005b3c2d  83c40c               add esp, 0xc
// 005b3c30  c20800               ret 8
// 005b3c33  e818970d00           call 0x68d350
// 005b3c38  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 005b3c3c  8b542414             mov edx, dword ptr [esp + 0x14]
// 005b3c40  8b450c               mov eax, dword ptr [ebp + 0xc]
// 005b3c43  3b03                 cmp eax, dword ptr [ebx]
// 005b3c45  7d31                 jge 0x5b3c78
// 005b3c47  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005b3c4b  53                   push ebx
// 005b3c4c  56                   push esi
// 005b3c4d  51                   push ecx
// 005b3c4e  8d542420             lea edx, [esp + 0x20]
// 005b3c52  52                   push edx
// 005b3c53  8bcf                 mov ecx, edi
// 005b3c55  e846f6ffff           call 0x5b32a0
// 005b3c5a  5f                   pop edi
// 005b3c5b  8bc8                 mov ecx, eax
// 005b3c5d  8b11                 mov edx, dword ptr [ecx]
// 005b3c5f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005b3c63  8b4904               mov ecx, dword ptr [ecx + 4]
// 005b3c66  5e                   pop esi
// 005b3c67  5d                   pop ebp
// 005b3c68  894804               mov dword ptr [eax + 4], ecx
// 005b3c6b  c6400801             mov byte ptr [eax + 8], 1
// 005b3c6f  8910                 mov dword ptr [eax], edx
// 005b3c71  5b                   pop ebx
// 005b3c72  83c40c               add esp, 0xc
// 005b3c75  c20800               ret 8
// 005b3c78  8b442420             mov eax, dword ptr [esp + 0x20]
// 005b3c7c  5f                   pop edi
// 005b3c7d  5e                   pop esi
// 005b3c7e  896804               mov dword ptr [eax + 4], ebp
// 005b3c81  5d                   pop ebp
// 005b3c82  c6400800             mov byte ptr [eax + 8], 0
// 005b3c86  8910                 mov dword ptr [eax], edx
// 005b3c88  5b                   pop ebx
// 005b3c89  83c40c               add esp, 0xc
// 005b3c8c  c20800               ret 8
// standard library map_int<string> (function ?insert@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
