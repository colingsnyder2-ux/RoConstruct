// from server: 100% by auto
// roc 2008-06 006711f0  unit: RBX::AdornRbxGfx  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006711f0
//
// 006711f0  83ec14               sub esp, 0x14
// 006711f3  53                   push ebx
// 006711f4  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 006711f8  55                   push ebp
// 006711f9  56                   push esi
// 006711fa  8be9                 mov ebp, ecx
// 006711fc  57                   push edi
// 006711fd  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 00671200  8b7704               mov esi, dword ptr [edi + 4]
// 00671203  807e3500             cmp byte ptr [esi + 0x35], 0
// 00671207  b001                 mov al, 1
// 00671209  88442410             mov byte ptr [esp + 0x10], al
// 0067120d  7526                 jne 0x671235
// 0067120f  90                   nop 
// 00671210  8d460c               lea eax, [esi + 0xc]
// 00671213  50                   push eax
// 00671214  53                   push ebx
// 00671215  8bfe                 mov edi, esi
// 00671217  ff155c238000         call dword ptr [0x80235c]
// 0067121d  83c408               add esp, 8
// 00671220  88442410             mov byte ptr [esp + 0x10], al
// 00671224  84c0                 test al, al
// 00671226  7404                 je 0x67122c
// 00671228  8b36                 mov esi, dword ptr [esi]
// 0067122a  eb03                 jmp 0x67122f
// 0067122c  8b7608               mov esi, dword ptr [esi + 8]
// 0067122f  807e3500             cmp byte ptr [esi + 0x35], 0
// 00671233  74db                 je 0x671210
// 00671235  8b7500               mov esi, dword ptr [ebp]
// 00671238  897c2418             mov dword ptr [esp + 0x18], edi
// 0067123c  89742414             mov dword ptr [esp + 0x14], esi
// 00671240  84c0                 test al, al
// 00671242  7458                 je 0x67129c
// 00671244  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 00671247  8b11                 mov edx, dword ptr [ecx]
// 00671249  89542420             mov dword ptr [esp + 0x20], edx
// 0067124d  85f6                 test esi, esi
// 0067124f  7404                 je 0x671255
// 00671251  3bf6                 cmp esi, esi
// 00671253  7406                 je 0x67125b
// 00671255  ff1590288000         call dword ptr [0x802890]
// 0067125b  3b7c2420             cmp edi, dword ptr [esp + 0x20]
// 0067125f  752e                 jne 0x67128f
// 00671261  53                   push ebx
// 00671262  57                   push edi
// 00671263  6a01                 push 1
// 00671265  8d442428             lea eax, [esp + 0x28]
// 00671269  50                   push eax
// 0067126a  8bcd                 mov ecx, ebp
// 0067126c  e8dff5ffff           call 0x670850
// 00671271  5f                   pop edi
// 00671272  8bc8                 mov ecx, eax
// 00671274  8b11                 mov edx, dword ptr [ecx]
// 00671276  8b442424             mov eax, dword ptr [esp + 0x24]
// 0067127a  8b4904               mov ecx, dword ptr [ecx + 4]
// 0067127d  5e                   pop esi
// 0067127e  5d                   pop ebp
// 0067127f  8910                 mov dword ptr [eax], edx
// 00671281  894804               mov dword ptr [eax + 4], ecx
// 00671284  c6400801             mov byte ptr [eax + 8], 1
// 00671288  5b                   pop ebx
// 00671289  83c414               add esp, 0x14
// 0067128c  c20800               ret 8
// 0067128f  8d4c2414             lea ecx, [esp + 0x14]
// 00671293  e888ecffff           call 0x66ff20
// 00671298  8b742414             mov esi, dword ptr [esp + 0x14]
// 0067129c  8b542418             mov edx, dword ptr [esp + 0x18]
// 006712a0  83c20c               add edx, 0xc
// 006712a3  53                   push ebx
// 006712a4  52                   push edx
// 006712a5  ff155c238000         call dword ptr [0x80235c]
// 006712ab  83c408               add esp, 8
// 006712ae  84c0                 test al, al
// 006712b0  740e                 je 0x6712c0
// 006712b2  8b442410             mov eax, dword ptr [esp + 0x10]
// 006712b6  53                   push ebx
// 006712b7  57                   push edi
// 006712b8  50                   push eax
// 006712b9  8d4c2428             lea ecx, [esp + 0x28]
// 006712bd  51                   push ecx
// 006712be  ebaa                 jmp 0x67126a
// 006712c0  8b442428             mov eax, dword ptr [esp + 0x28]
// 006712c4  8b542418             mov edx, dword ptr [esp + 0x18]
// 006712c8  5f                   pop edi
// 006712c9  8930                 mov dword ptr [eax], esi
// 006712cb  5e                   pop esi
// 006712cc  5d                   pop ebp
// 006712cd  895004               mov dword ptr [eax + 4], edx
// 006712d0  c6400800             mov byte ptr [eax + 8], 0
// 006712d4  5b                   pop ebx
// 006712d5  83c414               add esp, 0x14
// 006712d8  c20800               ret 8
// standard library map_str<pod12> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod12>
struct E { int v[3]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
