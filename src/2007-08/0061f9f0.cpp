// from server: 100% by auto
// roc 2007-08 0061f9f0  unit: RBX::ScoreHud  size: 243 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0061f9f0
//
// 0061f9f0  83ec0c               sub esp, 0xc
// 0061f9f3  53                   push ebx
// 0061f9f4  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0061f9f8  55                   push ebp
// 0061f9f9  56                   push esi
// 0061f9fa  8be9                 mov ebp, ecx
// 0061f9fc  57                   push edi
// 0061f9fd  8b7d04               mov edi, dword ptr [ebp + 4]
// 0061fa00  8b7704               mov esi, dword ptr [edi + 4]
// 0061fa03  807e3500             cmp byte ptr [esi + 0x35], 0
// 0061fa07  b001                 mov al, 1
// 0061fa09  88442410             mov byte ptr [esp + 0x10], al
// 0061fa0d  7526                 jne 0x61fa35
// 0061fa0f  90                   nop 
// 0061fa10  8d460c               lea eax, [esi + 0xc]
// 0061fa13  50                   push eax
// 0061fa14  53                   push ebx
// 0061fa15  8bfe                 mov edi, esi
// 0061fa17  ff1520e67700         call dword ptr [0x77e620]
// 0061fa1d  83c408               add esp, 8
// 0061fa20  84c0                 test al, al
// 0061fa22  88442410             mov byte ptr [esp + 0x10], al
// 0061fa26  7404                 je 0x61fa2c
// 0061fa28  8b36                 mov esi, dword ptr [esi]
// 0061fa2a  eb03                 jmp 0x61fa2f
// 0061fa2c  8b7608               mov esi, dword ptr [esi + 8]
// 0061fa2f  807e3500             cmp byte ptr [esi + 0x35], 0
// 0061fa33  74db                 je 0x61fa10
// 0061fa35  84c0                 test al, al
// 0061fa37  8bf7                 mov esi, edi
// 0061fa39  89742418             mov dword ptr [esp + 0x18], esi
// 0061fa3d  896c2414             mov dword ptr [esp + 0x14], ebp
// 0061fa41  7442                 je 0x61fa85
// 0061fa43  8b4d04               mov ecx, dword ptr [ebp + 4]
// 0061fa46  3b39                 cmp edi, dword ptr [ecx]
// 0061fa48  752e                 jne 0x61fa78
// 0061fa4a  53                   push ebx
// 0061fa4b  57                   push edi
// 0061fa4c  6a01                 push 1
// 0061fa4e  8d542420             lea edx, [esp + 0x20]
// 0061fa52  52                   push edx
// 0061fa53  8bcd                 mov ecx, ebp
// 0061fa55  e8b6f6ffff           call 0x61f110
// 0061fa5a  5f                   pop edi
// 0061fa5b  8bc8                 mov ecx, eax
// 0061fa5d  8b11                 mov edx, dword ptr [ecx]
// 0061fa5f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0061fa63  8b4904               mov ecx, dword ptr [ecx + 4]
// 0061fa66  5e                   pop esi
// 0061fa67  5d                   pop ebp
// 0061fa68  894804               mov dword ptr [eax + 4], ecx
// 0061fa6b  c6400801             mov byte ptr [eax + 8], 1
// 0061fa6f  8910                 mov dword ptr [eax], edx
// 0061fa71  5b                   pop ebx
// 0061fa72  83c40c               add esp, 0xc
// 0061fa75  c20800               ret 8
// 0061fa78  8d4c2414             lea ecx, [esp + 0x14]
// 0061fa7c  e8cfdfffff           call 0x61da50
// 0061fa81  8b742418             mov esi, dword ptr [esp + 0x18]
// 0061fa85  8d560c               lea edx, [esi + 0xc]
// 0061fa88  53                   push ebx
// 0061fa89  52                   push edx
// 0061fa8a  ff1520e67700         call dword ptr [0x77e620]
// 0061fa90  83c408               add esp, 8
// 0061fa93  84c0                 test al, al
// 0061fa95  7431                 je 0x61fac8
// 0061fa97  8b442410             mov eax, dword ptr [esp + 0x10]
// 0061fa9b  53                   push ebx
// 0061fa9c  57                   push edi
// 0061fa9d  50                   push eax
// 0061fa9e  8d4c2420             lea ecx, [esp + 0x20]
// 0061faa2  51                   push ecx
// 0061faa3  8bcd                 mov ecx, ebp
// 0061faa5  e866f6ffff           call 0x61f110
// 0061faaa  5f                   pop edi
// 0061faab  8bc8                 mov ecx, eax
// 0061faad  8b11                 mov edx, dword ptr [ecx]
// 0061faaf  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0061fab3  8b4904               mov ecx, dword ptr [ecx + 4]
// 0061fab6  5e                   pop esi
// 0061fab7  5d                   pop ebp
// 0061fab8  894804               mov dword ptr [eax + 4], ecx
// 0061fabb  c6400801             mov byte ptr [eax + 8], 1
// 0061fabf  8910                 mov dword ptr [eax], edx
// 0061fac1  5b                   pop ebx
// 0061fac2  83c40c               add esp, 0xc
// 0061fac5  c20800               ret 8
// 0061fac8  8b442420             mov eax, dword ptr [esp + 0x20]
// 0061facc  8b542414             mov edx, dword ptr [esp + 0x14]
// 0061fad0  5f                   pop edi
// 0061fad1  897004               mov dword ptr [eax + 4], esi
// 0061fad4  5e                   pop esi
// 0061fad5  5d                   pop ebp
// 0061fad6  c6400800             mov byte ptr [eax + 8], 0
// 0061fada  8910                 mov dword ptr [eax], edx
// 0061fadc  5b                   pop ebx
// 0061fadd  83c40c               add esp, 0xc
// 0061fae0  c20800               ret 8
// standard library map_str<pod12> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod12>
struct E { int v[3]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
