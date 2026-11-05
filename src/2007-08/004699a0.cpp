// from server: 100% by auto
// roc 2007-08 004699a0  unit: RBX::LDraw2Lua::LDraw2RobloxColorMap  size: 243 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004699a0
//
// 004699a0  83ec0c               sub esp, 0xc
// 004699a3  53                   push ebx
// 004699a4  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 004699a8  55                   push ebp
// 004699a9  56                   push esi
// 004699aa  8be9                 mov ebp, ecx
// 004699ac  57                   push edi
// 004699ad  8b7d04               mov edi, dword ptr [ebp + 4]
// 004699b0  8b7704               mov esi, dword ptr [edi + 4]
// 004699b3  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 004699b7  b001                 mov al, 1
// 004699b9  88442410             mov byte ptr [esp + 0x10], al
// 004699bd  7526                 jne 0x4699e5
// 004699bf  90                   nop 
// 004699c0  8d460c               lea eax, [esi + 0xc]
// 004699c3  50                   push eax
// 004699c4  53                   push ebx
// 004699c5  8bfe                 mov edi, esi
// 004699c7  ff1520e67700         call dword ptr [0x77e620]
// 004699cd  83c408               add esp, 8
// 004699d0  84c0                 test al, al
// 004699d2  88442410             mov byte ptr [esp + 0x10], al
// 004699d6  7404                 je 0x4699dc
// 004699d8  8b36                 mov esi, dword ptr [esi]
// 004699da  eb03                 jmp 0x4699df
// 004699dc  8b7608               mov esi, dword ptr [esi + 8]
// 004699df  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 004699e3  74db                 je 0x4699c0
// 004699e5  84c0                 test al, al
// 004699e7  8bf7                 mov esi, edi
// 004699e9  89742418             mov dword ptr [esp + 0x18], esi
// 004699ed  896c2414             mov dword ptr [esp + 0x14], ebp
// 004699f1  7442                 je 0x469a35
// 004699f3  8b4d04               mov ecx, dword ptr [ebp + 4]
// 004699f6  3b39                 cmp edi, dword ptr [ecx]
// 004699f8  752e                 jne 0x469a28
// 004699fa  53                   push ebx
// 004699fb  57                   push edi
// 004699fc  6a01                 push 1
// 004699fe  8d542420             lea edx, [esp + 0x20]
// 00469a02  52                   push edx
// 00469a03  8bcd                 mov ecx, ebp
// 00469a05  e886fbffff           call 0x469590
// 00469a0a  5f                   pop edi
// 00469a0b  8bc8                 mov ecx, eax
// 00469a0d  8b11                 mov edx, dword ptr [ecx]
// 00469a0f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00469a13  8b4904               mov ecx, dword ptr [ecx + 4]
// 00469a16  5e                   pop esi
// 00469a17  5d                   pop ebp
// 00469a18  894804               mov dword ptr [eax + 4], ecx
// 00469a1b  c6400801             mov byte ptr [eax + 8], 1
// 00469a1f  8910                 mov dword ptr [eax], edx
// 00469a21  5b                   pop ebx
// 00469a22  83c40c               add esp, 0xc
// 00469a25  c20800               ret 8
// 00469a28  8d4c2414             lea ecx, [esp + 0x14]
// 00469a2c  e8ef991100           call 0x583420
// 00469a31  8b742418             mov esi, dword ptr [esp + 0x18]
// 00469a35  8d560c               lea edx, [esi + 0xc]
// 00469a38  53                   push ebx
// 00469a39  52                   push edx
// 00469a3a  ff1520e67700         call dword ptr [0x77e620]
// 00469a40  83c408               add esp, 8
// 00469a43  84c0                 test al, al
// 00469a45  7431                 je 0x469a78
// 00469a47  8b442410             mov eax, dword ptr [esp + 0x10]
// 00469a4b  53                   push ebx
// 00469a4c  57                   push edi
// 00469a4d  50                   push eax
// 00469a4e  8d4c2420             lea ecx, [esp + 0x20]
// 00469a52  51                   push ecx
// 00469a53  8bcd                 mov ecx, ebp
// 00469a55  e836fbffff           call 0x469590
// 00469a5a  5f                   pop edi
// 00469a5b  8bc8                 mov ecx, eax
// 00469a5d  8b11                 mov edx, dword ptr [ecx]
// 00469a5f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00469a63  8b4904               mov ecx, dword ptr [ecx + 4]
// 00469a66  5e                   pop esi
// 00469a67  5d                   pop ebp
// 00469a68  894804               mov dword ptr [eax + 4], ecx
// 00469a6b  c6400801             mov byte ptr [eax + 8], 1
// 00469a6f  8910                 mov dword ptr [eax], edx
// 00469a71  5b                   pop ebx
// 00469a72  83c40c               add esp, 0xc
// 00469a75  c20800               ret 8
// 00469a78  8b442420             mov eax, dword ptr [esp + 0x20]
// 00469a7c  8b542414             mov edx, dword ptr [esp + 0x14]
// 00469a80  5f                   pop edi
// 00469a81  897004               mov dword ptr [eax + 4], esi
// 00469a84  5e                   pop esi
// 00469a85  5d                   pop ebp
// 00469a86  c6400800             mov byte ptr [eax + 8], 0
// 00469a8a  8910                 mov dword ptr [eax], edx
// 00469a8c  5b                   pop ebx
// 00469a8d  83c40c               add esp, 0xc
// 00469a90  c20800               ret 8
// standard library map_str<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@2@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
