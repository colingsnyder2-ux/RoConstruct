// from server: 100% by auto
// roc 2010-06 004463d0  unit: RBX::Reflection::M::?$TypedPropertyDescriptor  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004463d0
//
// 004463d0  83ec0c               sub esp, 0xc
// 004463d3  53                   push ebx
// 004463d4  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 004463d8  55                   push ebp
// 004463d9  56                   push esi
// 004463da  57                   push edi
// 004463db  8bf9                 mov edi, ecx
// 004463dd  8b7718               mov esi, dword ptr [edi + 0x18]
// 004463e0  8b4604               mov eax, dword ptr [esi + 4]
// 004463e3  80781500             cmp byte ptr [eax + 0x15], 0
// 004463e7  b101                 mov cl, 1
// 004463e9  884c2410             mov byte ptr [esp + 0x10], cl
// 004463ed  751f                 jne 0x44640e
// 004463ef  8b13                 mov edx, dword ptr [ebx]
// 004463f1  3b500c               cmp edx, dword ptr [eax + 0xc]
// 004463f4  8bf0                 mov esi, eax
// 004463f6  0f92c1               setb cl
// 004463f9  884c2410             mov byte ptr [esp + 0x10], cl
// 004463fd  84c9                 test cl, cl
// 004463ff  7404                 je 0x446405
// 00446401  8b00                 mov eax, dword ptr [eax]
// 00446403  eb03                 jmp 0x446408
// 00446405  8b4008               mov eax, dword ptr [eax + 8]
// 00446408  80781500             cmp byte ptr [eax + 0x15], 0
// 0044640c  74e3                 je 0x4463f1
// 0044640e  8b17                 mov edx, dword ptr [edi]
// 00446410  8bee                 mov ebp, esi
// 00446412  896c2418             mov dword ptr [esp + 0x18], ebp
// 00446416  89542414             mov dword ptr [esp + 0x14], edx
// 0044641a  84c9                 test cl, cl
// 0044641c  7452                 je 0x446470
// 0044641e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00446421  8b28                 mov ebp, dword ptr [eax]
// 00446423  85d2                 test edx, edx
// 00446425  7404                 je 0x44642b
// 00446427  3bd2                 cmp edx, edx
// 00446429  7406                 je 0x446431
// 0044642b  ff150ca99e00         call dword ptr [0x9ea90c]
// 00446431  8d4c2414             lea ecx, [esp + 0x14]
// 00446435  3bf5                 cmp esi, ebp
// 00446437  752a                 jne 0x446463
// 00446439  53                   push ebx
// 0044643a  56                   push esi
// 0044643b  6a01                 push 1
// 0044643d  51                   push ecx
// 0044643e  8bcf                 mov ecx, edi
// 00446440  e8eb4b3400           call 0x78b030
// 00446445  5f                   pop edi
// 00446446  8bc8                 mov ecx, eax
// 00446448  8b11                 mov edx, dword ptr [ecx]
// 0044644a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0044644e  8b4904               mov ecx, dword ptr [ecx + 4]
// 00446451  5e                   pop esi
// 00446452  5d                   pop ebp
// 00446453  894804               mov dword ptr [eax + 4], ecx
// 00446456  c6400801             mov byte ptr [eax + 8], 1
// 0044645a  8910                 mov dword ptr [eax], edx
// 0044645c  5b                   pop ebx
// 0044645d  83c40c               add esp, 0xc
// 00446460  c20800               ret 8
// 00446463  e8d8372c00           call 0x709c40
// 00446468  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0044646c  8b542414             mov edx, dword ptr [esp + 0x14]
// 00446470  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00446473  3b03                 cmp eax, dword ptr [ebx]
// 00446475  7331                 jae 0x4464a8
// 00446477  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0044647b  53                   push ebx
// 0044647c  56                   push esi
// 0044647d  51                   push ecx
// 0044647e  8d542420             lea edx, [esp + 0x20]
// 00446482  52                   push edx
// 00446483  8bcf                 mov ecx, edi
// 00446485  e8a64b3400           call 0x78b030
// 0044648a  5f                   pop edi
// 0044648b  8bc8                 mov ecx, eax
// 0044648d  8b11                 mov edx, dword ptr [ecx]
// 0044648f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00446493  8b4904               mov ecx, dword ptr [ecx + 4]
// 00446496  5e                   pop esi
// 00446497  5d                   pop ebp
// 00446498  894804               mov dword ptr [eax + 4], ecx
// 0044649b  c6400801             mov byte ptr [eax + 8], 1
// 0044649f  8910                 mov dword ptr [eax], edx
// 004464a1  5b                   pop ebx
// 004464a2  83c40c               add esp, 0xc
// 004464a5  c20800               ret 8
// 004464a8  8b442420             mov eax, dword ptr [esp + 0x20]
// 004464ac  5f                   pop edi
// 004464ad  5e                   pop esi
// 004464ae  896804               mov dword ptr [eax + 4], ebp
// 004464b1  5d                   pop ebp
// 004464b2  c6400800             mov byte ptr [eax + 8], 0
// 004464b6  8910                 mov dword ptr [eax], edx
// 004464b8  5b                   pop ebx
// 004464b9  83c40c               add esp, 0xc
// 004464bc  c20800               ret 8
// standard library map_ptr<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@PAUT@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@PAUT@@@std@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAUK@@PAUT@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@PAUT@@@std@@@4@$0A@@std@@@std@@_N@2@ABU?$pair@QAUK@@PAUT@@@2@@Z)

// stl: map_ptr<ptr>
struct T; typedef T* E;
#include <map>
struct K; template class std::map<K*, E>;
