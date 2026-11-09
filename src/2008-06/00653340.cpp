// from server: 100% by auto
// roc 2008-06 00653340  unit: RBX::ScoreHud  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00653340
//
// 00653340  83ec0c               sub esp, 0xc
// 00653343  53                   push ebx
// 00653344  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00653348  55                   push ebp
// 00653349  56                   push esi
// 0065334a  57                   push edi
// 0065334b  8bf9                 mov edi, ecx
// 0065334d  8b7718               mov esi, dword ptr [edi + 0x18]
// 00653350  8b4604               mov eax, dword ptr [esi + 4]
// 00653353  80783100             cmp byte ptr [eax + 0x31], 0
// 00653357  b101                 mov cl, 1
// 00653359  884c2410             mov byte ptr [esp + 0x10], cl
// 0065335d  751f                 jne 0x65337e
// 0065335f  8b13                 mov edx, dword ptr [ebx]
// 00653361  3b500c               cmp edx, dword ptr [eax + 0xc]
// 00653364  8bf0                 mov esi, eax
// 00653366  0f92c1               setb cl
// 00653369  884c2410             mov byte ptr [esp + 0x10], cl
// 0065336d  84c9                 test cl, cl
// 0065336f  7404                 je 0x653375
// 00653371  8b00                 mov eax, dword ptr [eax]
// 00653373  eb03                 jmp 0x653378
// 00653375  8b4008               mov eax, dword ptr [eax + 8]
// 00653378  80783100             cmp byte ptr [eax + 0x31], 0
// 0065337c  74e3                 je 0x653361
// 0065337e  8b17                 mov edx, dword ptr [edi]
// 00653380  8bee                 mov ebp, esi
// 00653382  896c2418             mov dword ptr [esp + 0x18], ebp
// 00653386  89542414             mov dword ptr [esp + 0x14], edx
// 0065338a  84c9                 test cl, cl
// 0065338c  7452                 je 0x6533e0
// 0065338e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00653391  8b28                 mov ebp, dword ptr [eax]
// 00653393  85d2                 test edx, edx
// 00653395  7404                 je 0x65339b
// 00653397  3bd2                 cmp edx, edx
// 00653399  7406                 je 0x6533a1
// 0065339b  ff1590288000         call dword ptr [0x802890]
// 006533a1  8d4c2414             lea ecx, [esp + 0x14]
// 006533a5  3bf5                 cmp esi, ebp
// 006533a7  752a                 jne 0x6533d3
// 006533a9  53                   push ebx
// 006533aa  56                   push esi
// 006533ab  6a01                 push 1
// 006533ad  51                   push ecx
// 006533ae  8bcf                 mov ecx, edi
// 006533b0  e88bf6ffff           call 0x652a40
// 006533b5  5f                   pop edi
// 006533b6  8bc8                 mov ecx, eax
// 006533b8  8b11                 mov edx, dword ptr [ecx]
// 006533ba  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006533be  8b4904               mov ecx, dword ptr [ecx + 4]
// 006533c1  5e                   pop esi
// 006533c2  5d                   pop ebp
// 006533c3  894804               mov dword ptr [eax + 4], ecx
// 006533c6  c6400801             mov byte ptr [eax + 8], 1
// 006533ca  8910                 mov dword ptr [eax], edx
// 006533cc  5b                   pop ebx
// 006533cd  83c40c               add esp, 0xc
// 006533d0  c20800               ret 8
// 006533d3  e888ddffff           call 0x651160
// 006533d8  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 006533dc  8b542414             mov edx, dword ptr [esp + 0x14]
// 006533e0  8b450c               mov eax, dword ptr [ebp + 0xc]
// 006533e3  3b03                 cmp eax, dword ptr [ebx]
// 006533e5  7331                 jae 0x653418
// 006533e7  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006533eb  53                   push ebx
// 006533ec  56                   push esi
// 006533ed  51                   push ecx
// 006533ee  8d542420             lea edx, [esp + 0x20]
// 006533f2  52                   push edx
// 006533f3  8bcf                 mov ecx, edi
// 006533f5  e846f6ffff           call 0x652a40
// 006533fa  5f                   pop edi
// 006533fb  8bc8                 mov ecx, eax
// 006533fd  8b11                 mov edx, dword ptr [ecx]
// 006533ff  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00653403  8b4904               mov ecx, dword ptr [ecx + 4]
// 00653406  5e                   pop esi
// 00653407  5d                   pop ebp
// 00653408  894804               mov dword ptr [eax + 4], ecx
// 0065340b  c6400801             mov byte ptr [eax + 8], 1
// 0065340f  8910                 mov dword ptr [eax], edx
// 00653411  5b                   pop ebx
// 00653412  83c40c               add esp, 0xc
// 00653415  c20800               ret 8
// 00653418  8b442420             mov eax, dword ptr [esp + 0x20]
// 0065341c  5f                   pop edi
// 0065341d  5e                   pop esi
// 0065341e  896804               mov dword ptr [eax + 4], ebp
// 00653421  5d                   pop ebp
// 00653422  c6400800             mov byte ptr [eax + 8], 0
// 00653426  8910                 mov dword ptr [eax], edx
// 00653428  5b                   pop ebx
// 00653429  83c40c               add esp, 0xc
// 0065342c  c20800               ret 8
// standard library map_ptr<pod32> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@_N@2@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod32>
struct E { int v[8]; };
#include <map>
struct K; template class std::map<K*, E>;
