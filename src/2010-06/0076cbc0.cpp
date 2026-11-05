// from server: 100% by auto
// roc 2010-06 0076cbc0  unit: RBX::ChatOutput  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0076cbc0
//
// 0076cbc0  83ec14               sub esp, 0x14
// 0076cbc3  53                   push ebx
// 0076cbc4  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 0076cbc8  55                   push ebp
// 0076cbc9  56                   push esi
// 0076cbca  8be9                 mov ebp, ecx
// 0076cbcc  57                   push edi
// 0076cbcd  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 0076cbd0  8b7704               mov esi, dword ptr [edi + 4]
// 0076cbd3  807e4d00             cmp byte ptr [esi + 0x4d], 0
// 0076cbd7  b001                 mov al, 1
// 0076cbd9  88442410             mov byte ptr [esp + 0x10], al
// 0076cbdd  7526                 jne 0x76cc05
// 0076cbdf  90                   nop 
// 0076cbe0  8d460c               lea eax, [esi + 0xc]
// 0076cbe3  50                   push eax
// 0076cbe4  53                   push ebx
// 0076cbe5  8bfe                 mov edi, esi
// 0076cbe7  ff151ca59e00         call dword ptr [0x9ea51c]
// 0076cbed  83c408               add esp, 8
// 0076cbf0  88442410             mov byte ptr [esp + 0x10], al
// 0076cbf4  84c0                 test al, al
// 0076cbf6  7404                 je 0x76cbfc
// 0076cbf8  8b36                 mov esi, dword ptr [esi]
// 0076cbfa  eb03                 jmp 0x76cbff
// 0076cbfc  8b7608               mov esi, dword ptr [esi + 8]
// 0076cbff  807e4d00             cmp byte ptr [esi + 0x4d], 0
// 0076cc03  74db                 je 0x76cbe0
// 0076cc05  8b7500               mov esi, dword ptr [ebp]
// 0076cc08  897c2418             mov dword ptr [esp + 0x18], edi
// 0076cc0c  89742414             mov dword ptr [esp + 0x14], esi
// 0076cc10  84c0                 test al, al
// 0076cc12  7458                 je 0x76cc6c
// 0076cc14  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 0076cc17  8b11                 mov edx, dword ptr [ecx]
// 0076cc19  89542420             mov dword ptr [esp + 0x20], edx
// 0076cc1d  85f6                 test esi, esi
// 0076cc1f  7404                 je 0x76cc25
// 0076cc21  3bf6                 cmp esi, esi
// 0076cc23  7406                 je 0x76cc2b
// 0076cc25  ff150ca99e00         call dword ptr [0x9ea90c]
// 0076cc2b  3b7c2420             cmp edi, dword ptr [esp + 0x20]
// 0076cc2f  752e                 jne 0x76cc5f
// 0076cc31  53                   push ebx
// 0076cc32  57                   push edi
// 0076cc33  6a01                 push 1
// 0076cc35  8d442428             lea eax, [esp + 0x28]
// 0076cc39  50                   push eax
// 0076cc3a  8bcd                 mov ecx, ebp
// 0076cc3c  e88ffaffff           call 0x76c6d0
// 0076cc41  5f                   pop edi
// 0076cc42  8bc8                 mov ecx, eax
// 0076cc44  8b11                 mov edx, dword ptr [ecx]
// 0076cc46  8b442424             mov eax, dword ptr [esp + 0x24]
// 0076cc4a  8b4904               mov ecx, dword ptr [ecx + 4]
// 0076cc4d  5e                   pop esi
// 0076cc4e  5d                   pop ebp
// 0076cc4f  8910                 mov dword ptr [eax], edx
// 0076cc51  894804               mov dword ptr [eax + 4], ecx
// 0076cc54  c6400801             mov byte ptr [eax + 8], 1
// 0076cc58  5b                   pop ebx
// 0076cc59  83c414               add esp, 0x14
// 0076cc5c  c20800               ret 8
// 0076cc5f  8d4c2414             lea ecx, [esp + 0x14]
// 0076cc63  e8e8e3ffff           call 0x76b050
// 0076cc68  8b742414             mov esi, dword ptr [esp + 0x14]
// 0076cc6c  8b542418             mov edx, dword ptr [esp + 0x18]
// 0076cc70  83c20c               add edx, 0xc
// 0076cc73  53                   push ebx
// 0076cc74  52                   push edx
// 0076cc75  ff151ca59e00         call dword ptr [0x9ea51c]
// 0076cc7b  83c408               add esp, 8
// 0076cc7e  84c0                 test al, al
// 0076cc80  740e                 je 0x76cc90
// 0076cc82  8b442410             mov eax, dword ptr [esp + 0x10]
// 0076cc86  53                   push ebx
// 0076cc87  57                   push edi
// 0076cc88  50                   push eax
// 0076cc89  8d4c2428             lea ecx, [esp + 0x28]
// 0076cc8d  51                   push ecx
// 0076cc8e  ebaa                 jmp 0x76cc3a
// 0076cc90  8b442428             mov eax, dword ptr [esp + 0x28]
// 0076cc94  8b542418             mov edx, dword ptr [esp + 0x18]
// 0076cc98  5f                   pop edi
// 0076cc99  8930                 mov dword ptr [eax], esi
// 0076cc9b  5e                   pop esi
// 0076cc9c  5d                   pop ebp
// 0076cc9d  895004               mov dword ptr [eax + 4], edx
// 0076cca0  c6400800             mov byte ptr [eax + 8], 0
// 0076cca4  5b                   pop ebx
// 0076cca5  83c414               add esp, 0x14
// 0076cca8  c20800               ret 8
// standard library map_str<pod36> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod36>
struct E { int v[9]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
