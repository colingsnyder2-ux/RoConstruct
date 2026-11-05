// from server: 100% by auto
// roc 2007-08 00547210  unit: RBX::MD5HasherImpl  size: 243 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00547210
//
// 00547210  83ec0c               sub esp, 0xc
// 00547213  53                   push ebx
// 00547214  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00547218  55                   push ebp
// 00547219  56                   push esi
// 0054721a  8be9                 mov ebp, ecx
// 0054721c  57                   push edi
// 0054721d  8b7d04               mov edi, dword ptr [ebp + 4]
// 00547220  8b7704               mov esi, dword ptr [edi + 4]
// 00547223  807e3d00             cmp byte ptr [esi + 0x3d], 0
// 00547227  b001                 mov al, 1
// 00547229  88442410             mov byte ptr [esp + 0x10], al
// 0054722d  7526                 jne 0x547255
// 0054722f  90                   nop 
// 00547230  8d460c               lea eax, [esi + 0xc]
// 00547233  50                   push eax
// 00547234  53                   push ebx
// 00547235  8bfe                 mov edi, esi
// 00547237  ff1520e67700         call dword ptr [0x77e620]
// 0054723d  83c408               add esp, 8
// 00547240  84c0                 test al, al
// 00547242  88442410             mov byte ptr [esp + 0x10], al
// 00547246  7404                 je 0x54724c
// 00547248  8b36                 mov esi, dword ptr [esi]
// 0054724a  eb03                 jmp 0x54724f
// 0054724c  8b7608               mov esi, dword ptr [esi + 8]
// 0054724f  807e3d00             cmp byte ptr [esi + 0x3d], 0
// 00547253  74db                 je 0x547230
// 00547255  84c0                 test al, al
// 00547257  8bf7                 mov esi, edi
// 00547259  89742418             mov dword ptr [esp + 0x18], esi
// 0054725d  896c2414             mov dword ptr [esp + 0x14], ebp
// 00547261  7442                 je 0x5472a5
// 00547263  8b4d04               mov ecx, dword ptr [ebp + 4]
// 00547266  3b39                 cmp edi, dword ptr [ecx]
// 00547268  752e                 jne 0x547298
// 0054726a  53                   push ebx
// 0054726b  57                   push edi
// 0054726c  6a01                 push 1
// 0054726e  8d542420             lea edx, [esp + 0x20]
// 00547272  52                   push edx
// 00547273  8bcd                 mov ecx, ebp
// 00547275  e8c6f8ffff           call 0x546b40
// 0054727a  5f                   pop edi
// 0054727b  8bc8                 mov ecx, eax
// 0054727d  8b11                 mov edx, dword ptr [ecx]
// 0054727f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00547283  8b4904               mov ecx, dword ptr [ecx + 4]
// 00547286  5e                   pop esi
// 00547287  5d                   pop ebp
// 00547288  894804               mov dword ptr [eax + 4], ecx
// 0054728b  c6400801             mov byte ptr [eax + 8], 1
// 0054728f  8910                 mov dword ptr [eax], edx
// 00547291  5b                   pop ebx
// 00547292  83c40c               add esp, 0xc
// 00547295  c20800               ret 8
// 00547298  8d4c2414             lea ecx, [esp + 0x14]
// 0054729c  e8ffe0ffff           call 0x5453a0
// 005472a1  8b742418             mov esi, dword ptr [esp + 0x18]
// 005472a5  8d560c               lea edx, [esi + 0xc]
// 005472a8  53                   push ebx
// 005472a9  52                   push edx
// 005472aa  ff1520e67700         call dword ptr [0x77e620]
// 005472b0  83c408               add esp, 8
// 005472b3  84c0                 test al, al
// 005472b5  7431                 je 0x5472e8
// 005472b7  8b442410             mov eax, dword ptr [esp + 0x10]
// 005472bb  53                   push ebx
// 005472bc  57                   push edi
// 005472bd  50                   push eax
// 005472be  8d4c2420             lea ecx, [esp + 0x20]
// 005472c2  51                   push ecx
// 005472c3  8bcd                 mov ecx, ebp
// 005472c5  e876f8ffff           call 0x546b40
// 005472ca  5f                   pop edi
// 005472cb  8bc8                 mov ecx, eax
// 005472cd  8b11                 mov edx, dword ptr [ecx]
// 005472cf  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005472d3  8b4904               mov ecx, dword ptr [ecx + 4]
// 005472d6  5e                   pop esi
// 005472d7  5d                   pop ebp
// 005472d8  894804               mov dword ptr [eax + 4], ecx
// 005472db  c6400801             mov byte ptr [eax + 8], 1
// 005472df  8910                 mov dword ptr [eax], edx
// 005472e1  5b                   pop ebx
// 005472e2  83c40c               add esp, 0xc
// 005472e5  c20800               ret 8
// 005472e8  8b442420             mov eax, dword ptr [esp + 0x20]
// 005472ec  8b542414             mov edx, dword ptr [esp + 0x14]
// 005472f0  5f                   pop edi
// 005472f1  897004               mov dword ptr [eax + 4], esi
// 005472f4  5e                   pop esi
// 005472f5  5d                   pop ebp
// 005472f6  c6400800             mov byte ptr [eax + 8], 0
// 005472fa  8910                 mov dword ptr [eax], edx
// 005472fc  5b                   pop ebx
// 005472fd  83c40c               add esp, 0xc
// 00547300  c20800               ret 8
// standard library map_str<pod20> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod20>
struct E { int v[5]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
