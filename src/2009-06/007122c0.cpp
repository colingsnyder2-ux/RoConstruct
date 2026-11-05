// from server: 100% by auto
// roc 2009-06 007122c0  unit: W4_D3DFORMAT::?$EnumDesc  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007122c0
//
// 007122c0  83ec0c               sub esp, 0xc
// 007122c3  53                   push ebx
// 007122c4  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 007122c8  55                   push ebp
// 007122c9  56                   push esi
// 007122ca  57                   push edi
// 007122cb  8bf9                 mov edi, ecx
// 007122cd  8b7718               mov esi, dword ptr [edi + 0x18]
// 007122d0  8b4604               mov eax, dword ptr [esi + 4]
// 007122d3  80781500             cmp byte ptr [eax + 0x15], 0
// 007122d7  b101                 mov cl, 1
// 007122d9  884c2410             mov byte ptr [esp + 0x10], cl
// 007122dd  751f                 jne 0x7122fe
// 007122df  8b13                 mov edx, dword ptr [ebx]
// 007122e1  3b500c               cmp edx, dword ptr [eax + 0xc]
// 007122e4  8bf0                 mov esi, eax
// 007122e6  0f92c1               setb cl
// 007122e9  884c2410             mov byte ptr [esp + 0x10], cl
// 007122ed  84c9                 test cl, cl
// 007122ef  7404                 je 0x7122f5
// 007122f1  8b00                 mov eax, dword ptr [eax]
// 007122f3  eb03                 jmp 0x7122f8
// 007122f5  8b4008               mov eax, dword ptr [eax + 8]
// 007122f8  80781500             cmp byte ptr [eax + 0x15], 0
// 007122fc  74e3                 je 0x7122e1
// 007122fe  8b17                 mov edx, dword ptr [edi]
// 00712300  8bee                 mov ebp, esi
// 00712302  896c2418             mov dword ptr [esp + 0x18], ebp
// 00712306  89542414             mov dword ptr [esp + 0x14], edx
// 0071230a  84c9                 test cl, cl
// 0071230c  7452                 je 0x712360
// 0071230e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00712311  8b28                 mov ebp, dword ptr [eax]
// 00712313  85d2                 test edx, edx
// 00712315  7404                 je 0x71231b
// 00712317  3bd2                 cmp edx, edx
// 00712319  7406                 je 0x712321
// 0071231b  ff15ace98900         call dword ptr [0x89e9ac]
// 00712321  8d4c2414             lea ecx, [esp + 0x14]
// 00712325  3bf5                 cmp esi, ebp
// 00712327  752a                 jne 0x712353
// 00712329  53                   push ebx
// 0071232a  56                   push esi
// 0071232b  6a01                 push 1
// 0071232d  51                   push ecx
// 0071232e  8bcf                 mov ecx, edi
// 00712330  e83bfdffff           call 0x712070
// 00712335  5f                   pop edi
// 00712336  8bc8                 mov ecx, eax
// 00712338  8b11                 mov edx, dword ptr [ecx]
// 0071233a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0071233e  8b4904               mov ecx, dword ptr [ecx + 4]
// 00712341  5e                   pop esi
// 00712342  5d                   pop ebp
// 00712343  894804               mov dword ptr [eax + 4], ecx
// 00712346  c6400801             mov byte ptr [eax + 8], 1
// 0071234a  8910                 mov dword ptr [eax], edx
// 0071234c  5b                   pop ebx
// 0071234d  83c40c               add esp, 0xc
// 00712350  c20800               ret 8
// 00712353  e89837f9ff           call 0x6a5af0
// 00712358  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0071235c  8b542414             mov edx, dword ptr [esp + 0x14]
// 00712360  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00712363  3b03                 cmp eax, dword ptr [ebx]
// 00712365  7331                 jae 0x712398
// 00712367  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0071236b  53                   push ebx
// 0071236c  56                   push esi
// 0071236d  51                   push ecx
// 0071236e  8d542420             lea edx, [esp + 0x20]
// 00712372  52                   push edx
// 00712373  8bcf                 mov ecx, edi
// 00712375  e8f6fcffff           call 0x712070
// 0071237a  5f                   pop edi
// 0071237b  8bc8                 mov ecx, eax
// 0071237d  8b11                 mov edx, dword ptr [ecx]
// 0071237f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00712383  8b4904               mov ecx, dword ptr [ecx + 4]
// 00712386  5e                   pop esi
// 00712387  5d                   pop ebp
// 00712388  894804               mov dword ptr [eax + 4], ecx
// 0071238b  c6400801             mov byte ptr [eax + 8], 1
// 0071238f  8910                 mov dword ptr [eax], edx
// 00712391  5b                   pop ebx
// 00712392  83c40c               add esp, 0xc
// 00712395  c20800               ret 8
// 00712398  8b442420             mov eax, dword ptr [esp + 0x20]
// 0071239c  5f                   pop edi
// 0071239d  5e                   pop esi
// 0071239e  896804               mov dword ptr [eax + 4], ebp
// 007123a1  5d                   pop ebp
// 007123a2  c6400800             mov byte ptr [eax + 8], 0
// 007123a6  8910                 mov dword ptr [eax], edx
// 007123a8  5b                   pop ebx
// 007123a9  83c40c               add esp, 0xc
// 007123ac  c20800               ret 8
// standard library map_ptr<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@PAUT@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@PAUT@@@std@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAUK@@PAUT@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@PAUT@@@std@@@4@$0A@@std@@@std@@_N@2@ABU?$pair@QAUK@@PAUT@@@2@@Z)

// stl: map_ptr<ptr>
struct T; typedef T* E;
#include <map>
struct K; template class std::map<K*, E>;
