// from server: 100% by auto
// roc 2007-08 0056afb0  unit: ArchiveBinder  size: 243 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0056afb0
//
// 0056afb0  83ec0c               sub esp, 0xc
// 0056afb3  53                   push ebx
// 0056afb4  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0056afb8  55                   push ebp
// 0056afb9  56                   push esi
// 0056afba  8be9                 mov ebp, ecx
// 0056afbc  57                   push edi
// 0056afbd  8b7d04               mov edi, dword ptr [ebp + 4]
// 0056afc0  8b7704               mov esi, dword ptr [edi + 4]
// 0056afc3  807e3100             cmp byte ptr [esi + 0x31], 0
// 0056afc7  b001                 mov al, 1
// 0056afc9  88442410             mov byte ptr [esp + 0x10], al
// 0056afcd  7526                 jne 0x56aff5
// 0056afcf  90                   nop 
// 0056afd0  8d460c               lea eax, [esi + 0xc]
// 0056afd3  50                   push eax
// 0056afd4  53                   push ebx
// 0056afd5  8bfe                 mov edi, esi
// 0056afd7  ff1520e67700         call dword ptr [0x77e620]
// 0056afdd  83c408               add esp, 8
// 0056afe0  84c0                 test al, al
// 0056afe2  88442410             mov byte ptr [esp + 0x10], al
// 0056afe6  7404                 je 0x56afec
// 0056afe8  8b36                 mov esi, dword ptr [esi]
// 0056afea  eb03                 jmp 0x56afef
// 0056afec  8b7608               mov esi, dword ptr [esi + 8]
// 0056afef  807e3100             cmp byte ptr [esi + 0x31], 0
// 0056aff3  74db                 je 0x56afd0
// 0056aff5  84c0                 test al, al
// 0056aff7  8bf7                 mov esi, edi
// 0056aff9  89742418             mov dword ptr [esp + 0x18], esi
// 0056affd  896c2414             mov dword ptr [esp + 0x14], ebp
// 0056b001  7442                 je 0x56b045
// 0056b003  8b4d04               mov ecx, dword ptr [ebp + 4]
// 0056b006  3b39                 cmp edi, dword ptr [ecx]
// 0056b008  752e                 jne 0x56b038
// 0056b00a  53                   push ebx
// 0056b00b  57                   push edi
// 0056b00c  6a01                 push 1
// 0056b00e  8d542420             lea edx, [esp + 0x20]
// 0056b012  52                   push edx
// 0056b013  8bcd                 mov ecx, ebp
// 0056b015  e896fdffff           call 0x56adb0
// 0056b01a  5f                   pop edi
// 0056b01b  8bc8                 mov ecx, eax
// 0056b01d  8b11                 mov edx, dword ptr [ecx]
// 0056b01f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0056b023  8b4904               mov ecx, dword ptr [ecx + 4]
// 0056b026  5e                   pop esi
// 0056b027  5d                   pop ebp
// 0056b028  894804               mov dword ptr [eax + 4], ecx
// 0056b02b  c6400801             mov byte ptr [eax + 8], 1
// 0056b02f  8910                 mov dword ptr [eax], edx
// 0056b031  5b                   pop ebx
// 0056b032  83c40c               add esp, 0xc
// 0056b035  c20800               ret 8
// 0056b038  8d4c2414             lea ecx, [esp + 0x14]
// 0056b03c  e84ffbffff           call 0x56ab90
// 0056b041  8b742418             mov esi, dword ptr [esp + 0x18]
// 0056b045  8d560c               lea edx, [esi + 0xc]
// 0056b048  53                   push ebx
// 0056b049  52                   push edx
// 0056b04a  ff1520e67700         call dword ptr [0x77e620]
// 0056b050  83c408               add esp, 8
// 0056b053  84c0                 test al, al
// 0056b055  7431                 je 0x56b088
// 0056b057  8b442410             mov eax, dword ptr [esp + 0x10]
// 0056b05b  53                   push ebx
// 0056b05c  57                   push edi
// 0056b05d  50                   push eax
// 0056b05e  8d4c2420             lea ecx, [esp + 0x20]
// 0056b062  51                   push ecx
// 0056b063  8bcd                 mov ecx, ebp
// 0056b065  e846fdffff           call 0x56adb0
// 0056b06a  5f                   pop edi
// 0056b06b  8bc8                 mov ecx, eax
// 0056b06d  8b11                 mov edx, dword ptr [ecx]
// 0056b06f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0056b073  8b4904               mov ecx, dword ptr [ecx + 4]
// 0056b076  5e                   pop esi
// 0056b077  5d                   pop ebp
// 0056b078  894804               mov dword ptr [eax + 4], ecx
// 0056b07b  c6400801             mov byte ptr [eax + 8], 1
// 0056b07f  8910                 mov dword ptr [eax], edx
// 0056b081  5b                   pop ebx
// 0056b082  83c40c               add esp, 0xc
// 0056b085  c20800               ret 8
// 0056b088  8b442420             mov eax, dword ptr [esp + 0x20]
// 0056b08c  8b542414             mov edx, dword ptr [esp + 0x14]
// 0056b090  5f                   pop edi
// 0056b091  897004               mov dword ptr [eax + 4], esi
// 0056b094  5e                   pop esi
// 0056b095  5d                   pop ebp
// 0056b096  c6400800             mov byte ptr [eax + 8], 0
// 0056b09a  8910                 mov dword ptr [eax], edx
// 0056b09c  5b                   pop ebx
// 0056b09d  83c40c               add esp, 0xc
// 0056b0a0  c20800               ret 8
// standard library map_str<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod8>
struct E { int v[2]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
