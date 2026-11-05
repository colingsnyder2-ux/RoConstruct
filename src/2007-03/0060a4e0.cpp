// from server: 100% by auto
// roc 2007-03 0060a4e0  unit: seg_00600000  size: 243 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0060a4e0
//
// 0060a4e0  83ec0c               sub esp, 0xc
// 0060a4e3  53                   push ebx
// 0060a4e4  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0060a4e8  55                   push ebp
// 0060a4e9  56                   push esi
// 0060a4ea  8be9                 mov ebp, ecx
// 0060a4ec  57                   push edi
// 0060a4ed  8b7d04               mov edi, dword ptr [ebp + 4]
// 0060a4f0  8b7704               mov esi, dword ptr [edi + 4]
// 0060a4f3  807e3500             cmp byte ptr [esi + 0x35], 0
// 0060a4f7  b001                 mov al, 1
// 0060a4f9  88442410             mov byte ptr [esp + 0x10], al
// 0060a4fd  7526                 jne 0x60a525
// 0060a4ff  90                   nop 
// 0060a500  8d460c               lea eax, [esi + 0xc]
// 0060a503  50                   push eax
// 0060a504  53                   push ebx
// 0060a505  8bfe                 mov edi, esi
// 0060a507  ff15e0e67700         call dword ptr [0x77e6e0]
// 0060a50d  83c408               add esp, 8
// 0060a510  84c0                 test al, al
// 0060a512  88442410             mov byte ptr [esp + 0x10], al
// 0060a516  7404                 je 0x60a51c
// 0060a518  8b36                 mov esi, dword ptr [esi]
// 0060a51a  eb03                 jmp 0x60a51f
// 0060a51c  8b7608               mov esi, dword ptr [esi + 8]
// 0060a51f  807e3500             cmp byte ptr [esi + 0x35], 0
// 0060a523  74db                 je 0x60a500
// 0060a525  84c0                 test al, al
// 0060a527  8bf7                 mov esi, edi
// 0060a529  89742418             mov dword ptr [esp + 0x18], esi
// 0060a52d  896c2414             mov dword ptr [esp + 0x14], ebp
// 0060a531  7442                 je 0x60a575
// 0060a533  8b4d04               mov ecx, dword ptr [ebp + 4]
// 0060a536  3b39                 cmp edi, dword ptr [ecx]
// 0060a538  752e                 jne 0x60a568
// 0060a53a  53                   push ebx
// 0060a53b  57                   push edi
// 0060a53c  6a01                 push 1
// 0060a53e  8d542420             lea edx, [esp + 0x20]
// 0060a542  52                   push edx
// 0060a543  8bcd                 mov ecx, ebp
// 0060a545  e8b6f6ffff           call 0x609c00
// 0060a54a  5f                   pop edi
// 0060a54b  8bc8                 mov ecx, eax
// 0060a54d  8b11                 mov edx, dword ptr [ecx]
// 0060a54f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0060a553  8b4904               mov ecx, dword ptr [ecx + 4]
// 0060a556  5e                   pop esi
// 0060a557  5d                   pop ebp
// 0060a558  894804               mov dword ptr [eax + 4], ecx
// 0060a55b  c6400801             mov byte ptr [eax + 8], 1
// 0060a55f  8910                 mov dword ptr [eax], edx
// 0060a561  5b                   pop ebx
// 0060a562  83c40c               add esp, 0xc
// 0060a565  c20800               ret 8
// 0060a568  8d4c2414             lea ecx, [esp + 0x14]
// 0060a56c  e8bfd8ffff           call 0x607e30
// 0060a571  8b742418             mov esi, dword ptr [esp + 0x18]
// 0060a575  8d560c               lea edx, [esi + 0xc]
// 0060a578  53                   push ebx
// 0060a579  52                   push edx
// 0060a57a  ff15e0e67700         call dword ptr [0x77e6e0]
// 0060a580  83c408               add esp, 8
// 0060a583  84c0                 test al, al
// 0060a585  7431                 je 0x60a5b8
// 0060a587  8b442410             mov eax, dword ptr [esp + 0x10]
// 0060a58b  53                   push ebx
// 0060a58c  57                   push edi
// 0060a58d  50                   push eax
// 0060a58e  8d4c2420             lea ecx, [esp + 0x20]
// 0060a592  51                   push ecx
// 0060a593  8bcd                 mov ecx, ebp
// 0060a595  e866f6ffff           call 0x609c00
// 0060a59a  5f                   pop edi
// 0060a59b  8bc8                 mov ecx, eax
// 0060a59d  8b11                 mov edx, dword ptr [ecx]
// 0060a59f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0060a5a3  8b4904               mov ecx, dword ptr [ecx + 4]
// 0060a5a6  5e                   pop esi
// 0060a5a7  5d                   pop ebp
// 0060a5a8  894804               mov dword ptr [eax + 4], ecx
// 0060a5ab  c6400801             mov byte ptr [eax + 8], 1
// 0060a5af  8910                 mov dword ptr [eax], edx
// 0060a5b1  5b                   pop ebx
// 0060a5b2  83c40c               add esp, 0xc
// 0060a5b5  c20800               ret 8
// 0060a5b8  8b442420             mov eax, dword ptr [esp + 0x20]
// 0060a5bc  8b542414             mov edx, dword ptr [esp + 0x14]
// 0060a5c0  5f                   pop edi
// 0060a5c1  897004               mov dword ptr [eax + 4], esi
// 0060a5c4  5e                   pop esi
// 0060a5c5  5d                   pop ebp
// 0060a5c6  c6400800             mov byte ptr [eax + 8], 0
// 0060a5ca  8910                 mov dword ptr [eax], edx
// 0060a5cc  5b                   pop ebx
// 0060a5cd  83c40c               add esp, 0xc
// 0060a5d0  c20800               ret 8
// standard library map_str<pod12> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod12>
struct E { int v[3]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
