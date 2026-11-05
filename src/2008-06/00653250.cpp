// from server: 100% by auto
// roc 2008-06 00653250  unit: RBX::ScoreHud  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00653250
//
// 00653250  83ec14               sub esp, 0x14
// 00653253  53                   push ebx
// 00653254  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 00653258  55                   push ebp
// 00653259  56                   push esi
// 0065325a  8be9                 mov ebp, ecx
// 0065325c  57                   push edi
// 0065325d  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 00653260  8b7704               mov esi, dword ptr [edi + 4]
// 00653263  807e4900             cmp byte ptr [esi + 0x49], 0
// 00653267  b001                 mov al, 1
// 00653269  88442410             mov byte ptr [esp + 0x10], al
// 0065326d  7526                 jne 0x653295
// 0065326f  90                   nop 
// 00653270  8d460c               lea eax, [esi + 0xc]
// 00653273  50                   push eax
// 00653274  53                   push ebx
// 00653275  8bfe                 mov edi, esi
// 00653277  ff155c238000         call dword ptr [0x80235c]
// 0065327d  83c408               add esp, 8
// 00653280  88442410             mov byte ptr [esp + 0x10], al
// 00653284  84c0                 test al, al
// 00653286  7404                 je 0x65328c
// 00653288  8b36                 mov esi, dword ptr [esi]
// 0065328a  eb03                 jmp 0x65328f
// 0065328c  8b7608               mov esi, dword ptr [esi + 8]
// 0065328f  807e4900             cmp byte ptr [esi + 0x49], 0
// 00653293  74db                 je 0x653270
// 00653295  8b7500               mov esi, dword ptr [ebp]
// 00653298  897c2418             mov dword ptr [esp + 0x18], edi
// 0065329c  89742414             mov dword ptr [esp + 0x14], esi
// 006532a0  84c0                 test al, al
// 006532a2  7458                 je 0x6532fc
// 006532a4  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 006532a7  8b11                 mov edx, dword ptr [ecx]
// 006532a9  89542420             mov dword ptr [esp + 0x20], edx
// 006532ad  85f6                 test esi, esi
// 006532af  7404                 je 0x6532b5
// 006532b1  3bf6                 cmp esi, esi
// 006532b3  7406                 je 0x6532bb
// 006532b5  ff1590288000         call dword ptr [0x802890]
// 006532bb  3b7c2420             cmp edi, dword ptr [esp + 0x20]
// 006532bf  752e                 jne 0x6532ef
// 006532c1  53                   push ebx
// 006532c2  57                   push edi
// 006532c3  6a01                 push 1
// 006532c5  8d442428             lea eax, [esp + 0x28]
// 006532c9  50                   push eax
// 006532ca  8bcd                 mov ecx, ebp
// 006532cc  e86ff5ffff           call 0x652840
// 006532d1  5f                   pop edi
// 006532d2  8bc8                 mov ecx, eax
// 006532d4  8b11                 mov edx, dword ptr [ecx]
// 006532d6  8b442424             mov eax, dword ptr [esp + 0x24]
// 006532da  8b4904               mov ecx, dword ptr [ecx + 4]
// 006532dd  5e                   pop esi
// 006532de  5d                   pop ebp
// 006532df  8910                 mov dword ptr [eax], edx
// 006532e1  894804               mov dword ptr [eax + 4], ecx
// 006532e4  c6400801             mov byte ptr [eax + 8], 1
// 006532e8  5b                   pop ebx
// 006532e9  83c414               add esp, 0x14
// 006532ec  c20800               ret 8
// 006532ef  8d4c2414             lea ecx, [esp + 0x14]
// 006532f3  e8483ef3ff           call 0x587140
// 006532f8  8b742414             mov esi, dword ptr [esp + 0x14]
// 006532fc  8b542418             mov edx, dword ptr [esp + 0x18]
// 00653300  83c20c               add edx, 0xc
// 00653303  53                   push ebx
// 00653304  52                   push edx
// 00653305  ff155c238000         call dword ptr [0x80235c]
// 0065330b  83c408               add esp, 8
// 0065330e  84c0                 test al, al
// 00653310  740e                 je 0x653320
// 00653312  8b442410             mov eax, dword ptr [esp + 0x10]
// 00653316  53                   push ebx
// 00653317  57                   push edi
// 00653318  50                   push eax
// 00653319  8d4c2428             lea ecx, [esp + 0x28]
// 0065331d  51                   push ecx
// 0065331e  ebaa                 jmp 0x6532ca
// 00653320  8b442428             mov eax, dword ptr [esp + 0x28]
// 00653324  8b542418             mov edx, dword ptr [esp + 0x18]
// 00653328  5f                   pop edi
// 00653329  8930                 mov dword ptr [eax], esi
// 0065332b  5e                   pop esi
// 0065332c  5d                   pop ebp
// 0065332d  895004               mov dword ptr [eax + 4], edx
// 00653330  c6400800             mov byte ptr [eax + 8], 0
// 00653334  5b                   pop ebx
// 00653335  83c414               add esp, 0x14
// 00653338  c20800               ret 8
// standard library map_str<pod32> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
