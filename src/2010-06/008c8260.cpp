// from server: 100% by auto
// roc 2010-06 008c8260  unit: RBX::AdornRbxGfx  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008c8260
//
// 008c8260  83ec14               sub esp, 0x14
// 008c8263  53                   push ebx
// 008c8264  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 008c8268  55                   push ebp
// 008c8269  56                   push esi
// 008c826a  8be9                 mov ebp, ecx
// 008c826c  57                   push edi
// 008c826d  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 008c8270  8b7704               mov esi, dword ptr [edi + 4]
// 008c8273  807e3900             cmp byte ptr [esi + 0x39], 0
// 008c8277  b001                 mov al, 1
// 008c8279  88442410             mov byte ptr [esp + 0x10], al
// 008c827d  7526                 jne 0x8c82a5
// 008c827f  90                   nop 
// 008c8280  8d460c               lea eax, [esi + 0xc]
// 008c8283  50                   push eax
// 008c8284  53                   push ebx
// 008c8285  8bfe                 mov edi, esi
// 008c8287  ff151ca59e00         call dword ptr [0x9ea51c]
// 008c828d  83c408               add esp, 8
// 008c8290  88442410             mov byte ptr [esp + 0x10], al
// 008c8294  84c0                 test al, al
// 008c8296  7404                 je 0x8c829c
// 008c8298  8b36                 mov esi, dword ptr [esi]
// 008c829a  eb03                 jmp 0x8c829f
// 008c829c  8b7608               mov esi, dword ptr [esi + 8]
// 008c829f  807e3900             cmp byte ptr [esi + 0x39], 0
// 008c82a3  74db                 je 0x8c8280
// 008c82a5  8b7500               mov esi, dword ptr [ebp]
// 008c82a8  897c2418             mov dword ptr [esp + 0x18], edi
// 008c82ac  89742414             mov dword ptr [esp + 0x14], esi
// 008c82b0  84c0                 test al, al
// 008c82b2  7458                 je 0x8c830c
// 008c82b4  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 008c82b7  8b11                 mov edx, dword ptr [ecx]
// 008c82b9  89542420             mov dword ptr [esp + 0x20], edx
// 008c82bd  85f6                 test esi, esi
// 008c82bf  7404                 je 0x8c82c5
// 008c82c1  3bf6                 cmp esi, esi
// 008c82c3  7406                 je 0x8c82cb
// 008c82c5  ff150ca99e00         call dword ptr [0x9ea90c]
// 008c82cb  3b7c2420             cmp edi, dword ptr [esp + 0x20]
// 008c82cf  752e                 jne 0x8c82ff
// 008c82d1  53                   push ebx
// 008c82d2  57                   push edi
// 008c82d3  6a01                 push 1
// 008c82d5  8d442428             lea eax, [esp + 0x28]
// 008c82d9  50                   push eax
// 008c82da  8bcd                 mov ecx, ebp
// 008c82dc  e82ff3ffff           call 0x8c7610
// 008c82e1  5f                   pop edi
// 008c82e2  8bc8                 mov ecx, eax
// 008c82e4  8b11                 mov edx, dword ptr [ecx]
// 008c82e6  8b442424             mov eax, dword ptr [esp + 0x24]
// 008c82ea  8b4904               mov ecx, dword ptr [ecx + 4]
// 008c82ed  5e                   pop esi
// 008c82ee  5d                   pop ebp
// 008c82ef  8910                 mov dword ptr [eax], edx
// 008c82f1  894804               mov dword ptr [eax + 4], ecx
// 008c82f4  c6400801             mov byte ptr [eax + 8], 1
// 008c82f8  5b                   pop ebx
// 008c82f9  83c414               add esp, 0x14
// 008c82fc  c20800               ret 8
// 008c82ff  8d4c2414             lea ecx, [esp + 0x14]
// 008c8303  e858eaffff           call 0x8c6d60
// 008c8308  8b742414             mov esi, dword ptr [esp + 0x14]
// 008c830c  8b542418             mov edx, dword ptr [esp + 0x18]
// 008c8310  83c20c               add edx, 0xc
// 008c8313  53                   push ebx
// 008c8314  52                   push edx
// 008c8315  ff151ca59e00         call dword ptr [0x9ea51c]
// 008c831b  83c408               add esp, 8
// 008c831e  84c0                 test al, al
// 008c8320  740e                 je 0x8c8330
// 008c8322  8b442410             mov eax, dword ptr [esp + 0x10]
// 008c8326  53                   push ebx
// 008c8327  57                   push edi
// 008c8328  50                   push eax
// 008c8329  8d4c2428             lea ecx, [esp + 0x28]
// 008c832d  51                   push ecx
// 008c832e  ebaa                 jmp 0x8c82da
// 008c8330  8b442428             mov eax, dword ptr [esp + 0x28]
// 008c8334  8b542418             mov edx, dword ptr [esp + 0x18]
// 008c8338  5f                   pop edi
// 008c8339  8930                 mov dword ptr [eax], esi
// 008c833b  5e                   pop esi
// 008c833c  5d                   pop ebp
// 008c833d  895004               mov dword ptr [eax + 4], edx
// 008c8340  c6400800             mov byte ptr [eax + 8], 0
// 008c8344  5b                   pop ebx
// 008c8345  83c414               add esp, 0x14
// 008c8348  c20800               ret 8
// standard library map_str<pod16> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod16>
struct E { int v[4]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
