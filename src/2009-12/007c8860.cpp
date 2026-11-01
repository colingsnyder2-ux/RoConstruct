// from server: 100% by auto
// roc 2009-12 007c8860  unit: RBX::ScoreHud  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007c8860
//
// 007c8860  83ec0c               sub esp, 0xc
// 007c8863  53                   push ebx
// 007c8864  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 007c8868  55                   push ebp
// 007c8869  56                   push esi
// 007c886a  57                   push edi
// 007c886b  8bf9                 mov edi, ecx
// 007c886d  8b7718               mov esi, dword ptr [edi + 0x18]
// 007c8870  8b4604               mov eax, dword ptr [esi + 4]
// 007c8873  80783100             cmp byte ptr [eax + 0x31], 0
// 007c8877  b101                 mov cl, 1
// 007c8879  884c2410             mov byte ptr [esp + 0x10], cl
// 007c887d  751f                 jne 0x7c889e
// 007c887f  8b13                 mov edx, dword ptr [ebx]
// 007c8881  3b500c               cmp edx, dword ptr [eax + 0xc]
// 007c8884  8bf0                 mov esi, eax
// 007c8886  0f92c1               setb cl
// 007c8889  884c2410             mov byte ptr [esp + 0x10], cl
// 007c888d  84c9                 test cl, cl
// 007c888f  7404                 je 0x7c8895
// 007c8891  8b00                 mov eax, dword ptr [eax]
// 007c8893  eb03                 jmp 0x7c8898
// 007c8895  8b4008               mov eax, dword ptr [eax + 8]
// 007c8898  80783100             cmp byte ptr [eax + 0x31], 0
// 007c889c  74e3                 je 0x7c8881
// 007c889e  8b17                 mov edx, dword ptr [edi]
// 007c88a0  8bee                 mov ebp, esi
// 007c88a2  896c2418             mov dword ptr [esp + 0x18], ebp
// 007c88a6  89542414             mov dword ptr [esp + 0x14], edx
// 007c88aa  84c9                 test cl, cl
// 007c88ac  7452                 je 0x7c8900
// 007c88ae  8b4718               mov eax, dword ptr [edi + 0x18]
// 007c88b1  8b28                 mov ebp, dword ptr [eax]
// 007c88b3  85d2                 test edx, edx
// 007c88b5  7404                 je 0x7c88bb
// 007c88b7  3bd2                 cmp edx, edx
// 007c88b9  7406                 je 0x7c88c1
// 007c88bb  ff1560b79800         call dword ptr [0x98b760]
// 007c88c1  8d4c2414             lea ecx, [esp + 0x14]
// 007c88c5  3bf5                 cmp esi, ebp
// 007c88c7  752a                 jne 0x7c88f3
// 007c88c9  53                   push ebx
// 007c88ca  56                   push esi
// 007c88cb  6a01                 push 1
// 007c88cd  51                   push ecx
// 007c88ce  8bcf                 mov ecx, edi
// 007c88d0  e88bf4ffff           call 0x7c7d60
// 007c88d5  5f                   pop edi
// 007c88d6  8bc8                 mov ecx, eax
// 007c88d8  8b11                 mov edx, dword ptr [ecx]
// 007c88da  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007c88de  8b4904               mov ecx, dword ptr [ecx + 4]
// 007c88e1  5e                   pop esi
// 007c88e2  5d                   pop ebp
// 007c88e3  894804               mov dword ptr [eax + 4], ecx
// 007c88e6  c6400801             mov byte ptr [eax + 8], 1
// 007c88ea  8910                 mov dword ptr [eax], edx
// 007c88ec  5b                   pop ebx
// 007c88ed  83c40c               add esp, 0xc
// 007c88f0  c20800               ret 8
// 007c88f3  e868afd4ff           call 0x513860
// 007c88f8  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 007c88fc  8b542414             mov edx, dword ptr [esp + 0x14]
// 007c8900  8b450c               mov eax, dword ptr [ebp + 0xc]
// 007c8903  3b03                 cmp eax, dword ptr [ebx]
// 007c8905  7331                 jae 0x7c8938
// 007c8907  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007c890b  53                   push ebx
// 007c890c  56                   push esi
// 007c890d  51                   push ecx
// 007c890e  8d542420             lea edx, [esp + 0x20]
// 007c8912  52                   push edx
// 007c8913  8bcf                 mov ecx, edi
// 007c8915  e846f4ffff           call 0x7c7d60
// 007c891a  5f                   pop edi
// 007c891b  8bc8                 mov ecx, eax
// 007c891d  8b11                 mov edx, dword ptr [ecx]
// 007c891f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007c8923  8b4904               mov ecx, dword ptr [ecx + 4]
// 007c8926  5e                   pop esi
// 007c8927  5d                   pop ebp
// 007c8928  894804               mov dword ptr [eax + 4], ecx
// 007c892b  c6400801             mov byte ptr [eax + 8], 1
// 007c892f  8910                 mov dword ptr [eax], edx
// 007c8931  5b                   pop ebx
// 007c8932  83c40c               add esp, 0xc
// 007c8935  c20800               ret 8
// 007c8938  8b442420             mov eax, dword ptr [esp + 0x20]
// 007c893c  5f                   pop edi
// 007c893d  5e                   pop esi
// 007c893e  896804               mov dword ptr [eax + 4], ebp
// 007c8941  5d                   pop ebp
// 007c8942  c6400800             mov byte ptr [eax + 8], 0
// 007c8946  8910                 mov dword ptr [eax], edx
// 007c8948  5b                   pop ebx
// 007c8949  83c40c               add esp, 0xc
// 007c894c  c20800               ret 8
// standard library map_ptr<pod32> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@_N@2@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod32>
struct E { int v[8]; };
#include <map>
struct K; template class std::map<K*, E>;
