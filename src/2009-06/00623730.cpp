// from server: 100% by auto
// roc 2009-06 00623730  unit: ArchiveBinder  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00623730
//
// 00623730  83ec14               sub esp, 0x14
// 00623733  53                   push ebx
// 00623734  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 00623738  55                   push ebp
// 00623739  56                   push esi
// 0062373a  8be9                 mov ebp, ecx
// 0062373c  57                   push edi
// 0062373d  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 00623740  8b7704               mov esi, dword ptr [edi + 4]
// 00623743  807e3100             cmp byte ptr [esi + 0x31], 0
// 00623747  b001                 mov al, 1
// 00623749  88442410             mov byte ptr [esp + 0x10], al
// 0062374d  7526                 jne 0x623775
// 0062374f  90                   nop 
// 00623750  8d460c               lea eax, [esi + 0xc]
// 00623753  50                   push eax
// 00623754  53                   push ebx
// 00623755  8bfe                 mov edi, esi
// 00623757  ff15e0e48900         call dword ptr [0x89e4e0]
// 0062375d  83c408               add esp, 8
// 00623760  88442410             mov byte ptr [esp + 0x10], al
// 00623764  84c0                 test al, al
// 00623766  7404                 je 0x62376c
// 00623768  8b36                 mov esi, dword ptr [esi]
// 0062376a  eb03                 jmp 0x62376f
// 0062376c  8b7608               mov esi, dword ptr [esi + 8]
// 0062376f  807e3100             cmp byte ptr [esi + 0x31], 0
// 00623773  74db                 je 0x623750
// 00623775  8b7500               mov esi, dword ptr [ebp]
// 00623778  897c2418             mov dword ptr [esp + 0x18], edi
// 0062377c  89742414             mov dword ptr [esp + 0x14], esi
// 00623780  84c0                 test al, al
// 00623782  7458                 je 0x6237dc
// 00623784  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 00623787  8b11                 mov edx, dword ptr [ecx]
// 00623789  89542420             mov dword ptr [esp + 0x20], edx
// 0062378d  85f6                 test esi, esi
// 0062378f  7404                 je 0x623795
// 00623791  3bf6                 cmp esi, esi
// 00623793  7406                 je 0x62379b
// 00623795  ff15ace98900         call dword ptr [0x89e9ac]
// 0062379b  3b7c2420             cmp edi, dword ptr [esp + 0x20]
// 0062379f  752e                 jne 0x6237cf
// 006237a1  53                   push ebx
// 006237a2  57                   push edi
// 006237a3  6a01                 push 1
// 006237a5  8d442428             lea eax, [esp + 0x28]
// 006237a9  50                   push eax
// 006237aa  8bcd                 mov ecx, ebp
// 006237ac  e87ffdffff           call 0x623530
// 006237b1  5f                   pop edi
// 006237b2  8bc8                 mov ecx, eax
// 006237b4  8b11                 mov edx, dword ptr [ecx]
// 006237b6  8b442424             mov eax, dword ptr [esp + 0x24]
// 006237ba  8b4904               mov ecx, dword ptr [ecx + 4]
// 006237bd  5e                   pop esi
// 006237be  5d                   pop ebp
// 006237bf  8910                 mov dword ptr [eax], edx
// 006237c1  894804               mov dword ptr [eax + 4], ecx
// 006237c4  c6400801             mov byte ptr [eax + 8], 1
// 006237c8  5b                   pop ebx
// 006237c9  83c414               add esp, 0x14
// 006237cc  c20800               ret 8
// 006237cf  8d4c2414             lea ecx, [esp + 0x14]
// 006237d3  e8d8fbffff           call 0x6233b0
// 006237d8  8b742414             mov esi, dword ptr [esp + 0x14]
// 006237dc  8b542418             mov edx, dword ptr [esp + 0x18]
// 006237e0  83c20c               add edx, 0xc
// 006237e3  53                   push ebx
// 006237e4  52                   push edx
// 006237e5  ff15e0e48900         call dword ptr [0x89e4e0]
// 006237eb  83c408               add esp, 8
// 006237ee  84c0                 test al, al
// 006237f0  740e                 je 0x623800
// 006237f2  8b442410             mov eax, dword ptr [esp + 0x10]
// 006237f6  53                   push ebx
// 006237f7  57                   push edi
// 006237f8  50                   push eax
// 006237f9  8d4c2428             lea ecx, [esp + 0x28]
// 006237fd  51                   push ecx
// 006237fe  ebaa                 jmp 0x6237aa
// 00623800  8b442428             mov eax, dword ptr [esp + 0x28]
// 00623804  8b542418             mov edx, dword ptr [esp + 0x18]
// 00623808  5f                   pop edi
// 00623809  8930                 mov dword ptr [eax], esi
// 0062380b  5e                   pop esi
// 0062380c  5d                   pop ebp
// 0062380d  895004               mov dword ptr [eax + 4], edx
// 00623810  c6400800             mov byte ptr [eax + 8], 0
// 00623814  5b                   pop ebx
// 00623815  83c414               add esp, 0x14
// 00623818  c20800               ret 8
// standard library map_str<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod8>
struct E { int v[2]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
